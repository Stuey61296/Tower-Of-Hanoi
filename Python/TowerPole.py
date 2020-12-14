class TowerPole:
    def __init__(self, node_count, empty, name):
        """

        :param node_count: int
        :param empty: bool
        :param name: str
        """
        self.node_count = node_count
        self.empty = empty
        self.name = name
        self.nodes = list()

        for i in range(1, node_count + 1):
            if not empty:
                self.nodes.append(i)
            else:
                self.nodes.append(-1)

    def get_node_list(self):
        return tuple(self.nodes)

    def reallocate_pole(self, tower_pole):
        for node in self.nodes:
            test_key = -1
            key = node
            for nde in tower_pole.nodes:
                if nde != -1:
                    test_key = nde
                    break
            if key != -1 and (test_key > key or test_key == -1):
                self.nodes[int(key) - 1] = -1
                tower_pole.nodes[int(key) - 1] = key
                return True
        return False

    def check_pole_values(self):
        """
        Checks the list of pole nodes to see if any value is equal to -1,
        if it is then the pole doesn't contain all disks
        :bool
        """
        for node in self.nodes:
            if node == -1:
                return False
        return True

    def get_node_count(self):
        return self.node_count

    def get_pole_name(self):
        return self.name
