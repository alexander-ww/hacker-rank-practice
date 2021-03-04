import math
import os
import random
import re
import sys

class Node:
    """ A node in a graph.

    The Node class represents a node
    in a graph. A node has a value and
    a list of associated child nodes.
    """

    # constructor
    def __init__(self, value):
        self.__value = value
        self.__children = set()

    # gets the value or ID
    def get_value(self):
        return self.__value

    # adds a child node ID
    def add_child(self, child):
        self.__children.add(child)

    # gets the child node ID
    def get_children(self):
        return self.__children

def build_graph(n, edges):
    """ Builds a graph.

    This method accepts a positive integer
    representing the number of nodes in
    the graph and a list of edges between
    those nodes in the graph. Upon the receipt
    of these inputs, the method constructs
    the indicated graph as an unordered
    map of node indices to node pointers.
    This map is produced as output.

    :param n: The number of nodes.
    :type n: int
    :param edges: The edges in the graph.
    :type edges: list of <list of <int>>
    :return: The graph as an unordered map.
    :rtype: dict of <int, Node>

    Complexity:
    - O(|V| + |E|) time
    - O(|V| + |E|) space
    """

    # graph as an unordered map
    map = dict()

    # add the nodes to the graph
    #
    # Complexity:
    # - O(|V|) time
    # - O(|V|) space
    #
    for i in range(0, n):
        node = Node(i)
        map[i] = node

    # add the edges to the graph
    #
    # Complexity:
    # - O(|E|) time
    # - O(|E|) space
    #
    for edge in edges:
        src = edge[0] - 1
        dst = edge[1] - 1
        map[src].add_child(dst)
        map[dst].add_child(src)

    return map

def get_visited(root, visited, graph):
    """ Gets all nodes able to be visited from a root node.

    This method accepts the ID of a root
    node, a reference to the IDs of nodes
    that have already been visited, a
    reference to the IDs of nodes that
    remain to be visited, and reference
    to a graph as an unordered map of node
    IDs to node pointers. Upon the receipt
    of these inputs, the method applies
    depth first search (DFS) in order to
    determine the set of all graph nodes
    that are able to be visited from the
    provided root node.

    :param root: The ID of the provided root node.
    :type root: int
    :param visited: The reference to the visited node IDs.
    :type visited: set of <int>
    :param graph: The reference to the graph.
    :type graph: dict of <int, Node>
    :return: The visited nodes.
    :rtype: set of <int>

    Complexity:
    - O(|V| + |E|) time
    - O(|V|) space
    """

    # handle visited node
    if root in visited:
        return visited

    # handle unvisited node
    else:

        # indicate visit to node
        visited.add(root)

        # process children of node
        for child in graph[root].get_children():

            # process unvisited children
            visited = get_visited(child, visited, graph)

    return visited

def get_disjoint_graph_sizes(n, edges):
    """ Gets the sizes of the disjoint graphs.

    This method accepts a positive integer
    representing the number of nodes in the
    graph and a list of eges that are in the
    graph. Upon the receipt of these inputs,
    the method uses a set of visited nodes,
    a set of remaining nodes, and DFS to
    determine the number of disjoint graphs
    in the graph and the number of nodes
    that each of those disjoint graphs
    contain. The result is a list of node
    sizes for each of those disjoint graphs.

    :param n: The number of nodes in the graph.
    :type n: int
    :param edges: The edges in the graph.
    :type edges: list of <list of <int>>
    :return: The node sizes of each of the disjoint graphs.
    :rtype: int

    Complexity:
    - O(|V| + |E|) time
    - O(|V| + |E|) space
    """

    # build the graph
    #
    # Complexity:
    # - O(|V| + |E|) time
    # - O(|V| + |E|) space
    #
    graph = build_graph(n, edges)

    # build the set of remaining cities
    #
    # Complexity:
    # - O(|V|) time
    # - O(|V|) space
    #
    remaining = set()
    for key in graph.keys():
        remaining.add(key)

    # initialize the set of visited cities
    visited = set()

    # store the subgraph sizes
    graph_sizes = list()

    # process through all remaining cities
    #
    # Complex:
    # - O(|V| + |E|) time
    # - O(|V| + |E|) space
    #
    while remaining:

        # get a root node
        root = 0
        for i in remaining:
            root = i
            break

        # process the subgraph of the root
        visited = get_visited(root, visited, graph)

        # remove visited nodes
        for node in visited:
            remaining.remove(node)

        # record the subgraph size
        graph_sizes.append(len(visited))

        # reset visited for the next subgraph
        visited = set()

    return graph_sizes

def roadsAndLibraries(n, c_lib, c_road, cities):
    """ Determine the minimum cost for library access.

    This method accepts a positive integer
    representing the number of cities, a
    positive integer representing the cost
    per library, a positive integer representing
    the cost per road, and a list of potential
    bi-directional roads between cities. Upon
    the receipt of these inputs, the function
    determines the optimal construction of
    libraries and roads such that the cost
    for ensuring that all citizens have library
    access is minimal.

    :param n: The number of cities.
    :type n: int
    :param c_lib: The cost per library.
    :type c_lib: int
    :param c_road: The cost per road.
    :type c_road: int
    :param cities: The potential bi-directional roads between cities.
    :type cities: list of <list of <int>>
    :return: The minimum cost for ensuring library access.
    :rtype: int

    Complexity:
    - O(|V| + |E|) time
    - O(|V| + |E|) space
    """

    # default cost
    cost = 0

    # libraries cost less than roads
    #
    # When the libraries cost less than the
    # roads, then we want to prefer building
    # libraries instead of roads. This means
    # that the construction for minimum cost
    # will not involve building a single road.
    # Consequently, we simply build a library
    # for every city.
    #
    # Complexity:
    # - O(1) time
    # - O(1) space
    #
    if c_lib < c_road:
        cost = c_lib * n

    # roads cost less than libraries
    #
    # When the roads cost less than the
    # libraries, then we want to prefer
    # building roads instead of libraries.
    # This means that the construction for
    # minimum cost will involve having one
    # library build for each disjoint graph
    # of cities. It also means that the
    # construction will involve having the
    # minimum number of roads to fully connect
    # the nodes in each disjoint graph, which
    # is the minimum spanning tree size, which
    # is n - 1 roads with n being the number
    # of nodes in the disjoint graph.
    #
    # Complexity:
    # - O(|V| + |E|) time
    # - O(|V| + |E|) space
    #
    else:

        # get the disjoint graph info
        graph_sizes = get_disjoint_graph_sizes(n, cities)
        graphs = len(graph_sizes)

        # add a library to each disjoint graph
        cost = c_lib * graphs

        # add roads in each disjoint graph
        for size in graph_sizes:
            cost += (size - 1) * c_road

    return cost

if __name__ == '__main__':
    q = int(input())

    for q_itr in range(q):
        nmC_libC_road = input().split()

        n = int(nmC_libC_road[0])
        m = int(nmC_libC_road[1])
        c_lib = int(nmC_libC_road[2])
        c_road = int(nmC_libC_road[3])

        cities = []

        for _ in range(m):
            cities.append(list(map(int, input().rstrip().split())))

        result = roadsAndLibraries(n, c_lib, c_road, cities)
        print(str(result))
