from Tower import Tower


def main():
    pole_counter = None
    disk_counter = None

    print("-----------------------------------------------------------------\n\t\t\t"
          "Tower of Hanoi\n-----------------------------------------------------------------\n\n")
    print("Game details:\tThe objective of this game is to\nmove the disks(in this case numbers) from pole A\n"
          "to the end pole. In this version a disk may be moved to any pole.\n"
          "Disks with larger numbers may not sit on top of disks with\n"
          "smaller numbers. A maximum of 5 poles may be used\n"
          "and a minimum of 3 poles may be used. A minimum of 2 disks may be used.\n"
          "------------------------------------------------------------------\n")
    while type(pole_counter) != int:
        pole_counter = input("How many poles would you like to have? (3 - 5) ")
        if pole_counter.isdigit():
            pole_counter = int(pole_counter)

    while type(disk_counter) != int:
        disk_counter = input("How many disks would you like to have? ")
        if disk_counter.isdigit():
            disk_counter = int(disk_counter)

    if pole_counter > 5:
        pole_counter = 5
    elif pole_counter < 3:
        pole_counter = 3

    if disk_counter < 2:
        disk_counter = 2

    tower = Tower(pole_count=pole_counter, node_count=disk_counter)

    tower.print_tower()
    if pole_counter == 3:
        print("Minimum moves to complete game: {}\n".format(2 ** disk_counter - 1))

    tower.play_game()

    tower.game_finished()


if __name__ == '__main__':
    main()
