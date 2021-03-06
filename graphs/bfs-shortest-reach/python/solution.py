class Node:

    def __init__(self, id):
        self.__id = id
        self.__children = set()

    def get_id(self):
        return self.__id

    def add_child(self, child):
        self.__children.add(child)

    def get_children(self):
        return self.__children

class Graph:

    def __init__(self, size):
        self.__nodes = dict()
        for i in range(0, size):
            node = Node(i)
            self.__nodes[i] = node

    def add_edge(self, first, second):
        self.__nodes[first].add_child(second)
        self.__nodes[second].add_child(first)

    def shortest_reach(self, start_id):
        return self.__get_depths(start_id)

    def __get_depths(self, root):

        # perform breadth first search
        depths = self.__bfs(root)

        # produce the list of depths
        result = list()
        for node in depths.keys():
            result.append(-1)

        for node in depths.keys():
            if depths[node] != 0:
                result[node] = depths[node]

        return result

    def __bfs(self, root):

        # create a node queue
        queue = list()

        # initialize map of depths
        depths = dict()
        for node in self.__nodes.keys():
            depths[node] = 0

        # mark current as visited and queue it
        visited = set()
        visited.add(root)
        queue.append(root)

        # update the current depth
        depths[root] = 0

        # declare the edge depth
        edge_depth = 6

        # continue until done traversing
        while queue:

            # get the current node
            node = queue.pop(0)

            # queue up children of current node
            for child in self.__nodes[node].get_children():
                if child not in visited:
                    visited.add(child)
                    queue.append(child)
                    depths[child] = depths[node] + edge_depth

        return depths

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n, m = [int(value) for value in input().split()]
        graph = Graph(n)
        for i in range(m):
            x, y = [int(x) for x in input().split()]
            graph.add_edge(x - 1, y - 1)
        s = int(input())
        distances = graph.shortest_reach(s - 1)
        to_print = ""
        for i in range(0, n):
            if i != s - 1:
                to_print += str(distances[i]) + " "
        print(to_print)
