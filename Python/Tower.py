from colorama import Fore
from colorama import Style

from TowerPole import TowerPole


class Tower:
    def __init__(self, pole_count, node_count):
        possible_names = list('ABCDEF')
        self.pole_count = pole_count
        self.node_count = node_count
        self.move_count = 0
        self.pole_names = possible_names[0:pole_count]
        empty = False
        self.poles = list()
        self.poles.append(TowerPole(node_count, empty, self.pole_names[0]))
        empty = True
        for i in range(1, pole_count):
            self.poles.append(TowerPole(node_count, empty, self.pole_names[i]))

    def print_tower(self):
        print("________________________________________________________________________________\n\n")
        temp_list = list()
        for pole in self.poles:
            temp_list.append(pole.get_node_list())
        temp_list = list(map(tuple, zip(*temp_list)))
        output = ""
        for nodes in temp_list:
            output += "\t"

            for i in range(0, self.pole_count):
                if nodes[i] == -1:
                    output += "|"
                else:
                    output += str(nodes[i])
                output += "\t\t"
            output += "\n"
        output += "\t"

        for i in range(0, self.pole_count):
            output += "_\t\t"
        output += "\n\t"
        for pole in self.poles:
            output += pole.get_pole_name() + "\t\t"
        output += "\n"

        print(output)

    def play_game(self):
        while not self.game_finished():
            pole_move_from = None
            pole_move_to = None

            while pole_move_from not in self.pole_names:
                pole_move_from = input("Which pole would you like to move the top disk from (A - " +
                                       self.poles[-1].get_pole_name() + ")? ").upper()
                if pole_move_from not in self.pole_names:
                    print(f"{Fore.RED}Invalid Pole ({pole_move_from}) Selected!\n{Style.RESET_ALL}")

            while pole_move_to not in self.pole_names:
                pole_move_to = input("Which pole would you like to move the top disk to (A - " +
                                     self.poles[-1].get_pole_name() + ")? ").upper()
                if pole_move_to not in self.pole_names:
                    print(f"{Fore.RED}Invalid Pole ({pole_move_to}) Selected!\n{Style.RESET_ALL}")

            if not self.poles[self.pole_names.index(pole_move_from.upper())].reallocate_pole(
                    self.poles[self.pole_names.index(pole_move_to.upper())]):
                print(f"{Fore.RED}Invalid move!\n{Style.RESET_ALL}")
                self.print_tower()
                continue
            self.move_count += 1
            print("")
            self.print_tower()
        print("________________________________________________________________________________\n\t\t\t\t"
              "Congratulations! Game completed in " +
              str(self.move_count) +
              " moves.\n________________________________________________________________________________")

    def game_finished(self):
        return self.poles[-1].check_pole_values()
