import math
import os
import random
import re
import sys

class Node:
    """ A colored graph node.

    The Node class represents
    a node in a graph that has
    an ID and an associated color.
    """

    def __init__(self, id, color):
        """ Constructor.

        This method accepts an ID
        value and a color value as
        input and consturcts an
        instance of a graph node.

        :param id The ID of the node.
        :type id: int
        :param color: The color of the node.
        :type color: int
        """

        self.__id = id
        self.__color = color
        self.__children = set()

    def get_id(self):
        """ Gets the node ID.

        This method acquires the
        ID of the graph node.

        :return: The node ID.
        :rtype: int
        """

        return self.__id

    def get_color(self):
        """ Get the node color.

        This method acquires the
        color of the graph node.

        :return: The node color.
        :rtype: int
        """

        return self.__color

    def get_children(self):
        """ Gets the node color.

        This method acquires the
        children of the graph node.

        :return: The children of the node.
        :rtype: list of <int>
        """

        return self.__children

    def add_child(self, child):
        """ Adds a child node.

        This method accepts an integer
        representing the ID of a child
        node and adds the child to the
        set of children maintained by
        the node.

        :param child: The child to add.
        :type child: int
        """

        self.__children.add(child)

def build_graph(graph_nodes, graph_from, graph_to, ids):
    """ Builds a graph.

    This method accepts information about the
    number of nodes in the graph, the source
    nodes of the edges in the graph, the
    destination nodes of the edges in the graph,
    and the colors to associate with nodes based
    on their ID values. Upon the receipt of these
    inputs, the method builds a graph as an
    unordered map of node IDs to node object
    pointers.

    :param graph_nodes: The number of graph nodes.
    :type graph_nodes: int
    :param graph_from: The source nodes for edges.
    :type graph_from: list of <int>
    :param graph_to: The destination nodes for edges.
    :type graph_to: list of <int>
    :param ids: The colors for nodes.
    :type ids: list of <int>
    :return: The graph as a dictionary.
    :rtype: dict of <int, Node>

    Complexity:
    - O(|V| + |E|) time
    - O(|V| + |E|) space
    """

    # setup empty graph
    graph = dict()

    # add nodes to the graph
    for i in range(0, graph_nodes):
        node = Node(i, ids[i])
        graph[i] = node

    # add edges to the graph
    for i in range(0, len(graph_from)):

        # get endpoints of edge
        src = graph_from[i] - 1
        dst = graph_to[i] - 1

        # add child for directed edge
        graph[src].add_child(dst)

    return graph

def build_color_map(graph_nodes, graph):
    """ Builds a color to node ID map.

    This method accepts the number of nodes
    in the graph and an unordered map representing
    the graph. Upon the receipt of these inputs,
    the method constructs a map between colors
    and the IDs of nodes that have those colors.

    :param graph_nodes The number of graph nodes.
    :type graph_nodes: int
    :param graph: The map of node IDs to node object pointers.
    :type graph: dict of <int, Node>
    :return: The color to node ID map.
    :rtype: dict of <int, Node>

    Complexity:
    - O(|V|) time
    - O(|V|) space
    """

    # setup empty color map
    color_map = dict()

    # store nodes by color in map
    for i in range(0, graph_nodes):

        # get the color of the current node
        color = graph[i].get_color()

        # handle instance of the color
        try:
            color_map[color]
            color_map[color].append(i)

        # handle no instance of the color
        except KeyError:
            color_map[color] = list()
            color_map[color].append(i)

    return color_map

def is_color_present(color, color_map):
    """ Checks if a color is present.

    This method accepts a color and a color
    map as input. Upon the receipt of these
    two inputs, the method determines whether
    the provided color is present in the color
    map. If the color is present, then a value
    of true is returned; Otherwise, a value of
    false is returned.

    :param color: The color to locate.
    :type color: int
    :param color_map: The color map to use.
    :type color_map: dict of <int, list of <int>>
    :return: True if the color is present; False otherwise.
    :rtype: bool

    Complexity:
    - O(1) time
    - O(1) space
    """

    # default result
    present = False

    # handle no color
    try:
        color_map[color]
        present = True

    # handle having color
    except KeyError:
        pass

    return present

def color_has_edges(color, graph, color_map):
    """ Determine if a color has edges.

    This method accepts a color, an unordered map
    representing a graph, and an unordered map
    representing the nodes that are implementing
    certain colors. Upon the receipt of these inputs,
    the method determines whether the provided color
    has any nodes that have edges to other nodes of
    the same color. If there is a node of the given
    color that does have edges, than a value of true
    is returned; Otherwise, a value of false is returned.

    :param color: The color to check in the graph.
    :type color: int
    :param graph: The unordered map representing the graph.
    :type graph: dict of <int, Node>
    :param color_map: The color map to use.
    :type color_map: dict of <int, list of <int>>
    :return: True if there are edges; False otherwise.
    :rtype: bool

    Complexity:
    - O(|V|) time
    - O(|V|) space
    """

    # default result
    has_edges = False

    # get the implementing nodes
    color_nodes = list()

    # handle having nodes
    try:
        color_map[color]
        color_nodes = color_map[color]

    # handle having no nodes
    except KeyError:
        pass

    # check for any children
    for color_node in color_nodes:

        # count the number of children
        children = len(graph[color_node].get_children())

        # handle finding children
        if children > 0:
            has_edges = True
            break

    return has_edges

def is_node_pair_possible(color, graph, color_map):
    """ Determines if a node pair is possible.

    This method accepts a color, an unordered map
    representing a graph, and an unordered map
    representing the nodes that are implementing
    certain colors. Upon the receipt of these inputs,
    the method determines whether a pair of color
    nodes is possible for path formation. If there
    is a possible pair, then a value of true is
    returned; Otherwise, a value of false is returned.

    :param color: The color to check in the graph.
    :type color: int
    :param graph: The unordered map representing the graph.
    :type graph: dict of <int, Node>
    :param color_map: The color map to use.
    :type color_map: dict of <int, list of <int>>
    :return: True if a pair is possible; False otherwise.
    :rtype: bool

    Complexity:
    - O(|V|) time
    - O(|V|) space
    """

    # determine if edges exist
    has_edges = color_has_edges(color, graph, color_map)

    # check for sufficient node count
    sufficient_count = False

    # handle no nodes
    try:
        color_map[color]
        sufficient_count = len(color_map[color]) >= 2

    # handle no nodes
    except KeyError:
        pass

    # determine if a pair is possible
    pair_possible = has_edges and sufficient_count

    return pair_possible

def get_source_nodes(color, graph, color_map):
    """ Gets source nodes for a color.

    This method accepts a color, an unordered map
    representing a graph, and an unordered map
    representing the nodes that are implementing
    certain colors. Upon the receipt of these
    inputs, the method returns the nodes for the
    provided color that have children, and that
    are consequently able to be used as potential
    sources.

    :param color: The color to check in the graph.
    :type color: int
    :param graph: The unordered map representing the graph.
    :type graph: dict of <int, Node>
    :param color_map: The color map to use.
    :type color_map: dict of <int, list of <int>>
    :return: The source nodes for the provided color.
    :rtype: list of <int>

    Complexity:
    - O(|V|) time
    - O(|V|) space
    """

    # default source nodes
    source_nodes = list()

    # handle nodes
    try:

        # get the color nodes
        color_nodes = color_map[color]

        # add only color nodes with children
        for color_node in color_nodes:
            children = len(graph[color_node].get_children())
            if children > 0:
                source_nodes.append(color_node)

    # handle no nodes
    except KeyError:
        pass

    return source_nodes

def find_min_path_size(source, path_size, destinations, graph, visited, min_path_size):
    """ Finds path sizes from a source.

    This method accepts an ID for a source
    node, a current path size, a set of IDs
    for destination nodes, an unordered map
    representing a graph, a set of visited
    node IDs, and current minimum path size.
    Upon the receipt of these inputs, the
    method applies the DFS algorithm to
    record the minimum path size from the
    source to its identified destinations.

    :param source: The ID of the source node.
    :type source: int
    :param path_size: The current path size.
    :type path_size: int
    :param destinations: The set of destination node IDs.
    :type destinations: set of <int>
    :param graph: The unordered map representing the graph.
    :type graph: dict of <int, Node>
    :param visited: The set of visited node IDs.
    :type visited: set of <int>
    :param min_path_size: The minimum path size.
    :type min_path_size: int
    :return: The minimum path size and the visited node IDs.
    :rtype: tuple of <int, set of <int>>

    Complexity:
    - O(|V| + |E|) time
    - O(|V| + |E|) space
    """

    # handle visited source
    if source in visited:
        return min_path_size, visited

    # handle unvisited source
    else:

        # indicate visit to source
        visited.add(source)

        # check for immediate destinations
        has_destination = False
        for child in graph[source].get_children():

            # handle arrival at a destination (no need to go further)
            if child in destinations:
                if path_size + 1 < min_path_size:
                    min_path_size = path_size + 1
                has_destination = True
                visited.add(child)
                break

        # iterate through all children (continue path)
        if not has_destination:
            for child in graph[source].get_children():
                if not child in visited:
                    min_path_size, visited = find_min_path_size(child, path_size + 1, destinations, graph, visited, min_path_size)

        return min_path_size, visited

def findShortest(graph_nodes, graph_from, graph_to, ids, val):
    """ Finds the shortest path between nodes of the given color.

    This method accepts an indication of the number of nodes
    in the graph, an indication of the source nodes of edges
    in the graph, an indication of the destination nodes of
    edges in the graph, an indication of the color assignments
    to nodes, and an indication of the color of the nodes for
    which to find the shortest path. Upon the receipt of these
    inputs, this method makes use of a variant of the DFS
    algorithm to determine the shortest path between any two
    nodes of the given color. If a shortest path can be found,
    then its length is returned; Otherwise, a value of -1 is
    returned.

    :param graph_nodes: The number of nodes in the graph.
    :type graph_nodes: int
    :param graph_from: The source nodes for edges in the graph.
    :type graph_from: list of <int>
    :param graph_to: The destination nodes for edges in the graph.
    :type graph_to: list of <int>
    :param ids: The colors for nodes.
    :type ids: list of <int>
    :param val: The color value to use when searching for the shortest path.
    :type val: int
    :return: The length of the shortest path or -1.
    :rtype: int

    Complexity:
    - O(|V| (|V| + |E|))
    - O(|V| + |E|)
    """

    # get selected color
    color = val

    # build the graph
    graph = build_graph(graph_nodes, graph_from, graph_to, ids)

    # build the color map
    color_map = build_color_map(graph_nodes, graph)

    # check if color is present
    color_present = is_color_present(color, color_map)

    # handle color not being present
    if not color_present:
        return -1

    # check if pair is possible
    pair_possible = is_node_pair_possible(color, graph, color_map)

    # handle no possible pair
    if not pair_possible:
        return -1

    # get the source nodes (for the color)
    source_nodes = get_source_nodes(color, graph, color_map)

    # get destination nodes (for the color)
    destination_nodes = set(color_map[color])

    # iterate through all sources
    path_size = 0
    visited = set()
    min_path_size = sys.maxsize
    current_min_path_size = sys.maxsize

    for source_node in source_nodes:

        # get the minimum path size for the current source
        current_min_path_size, visited = find_min_path_size(source_node, path_size, destination_nodes, graph, visited, min_path_size)

        # update the minimum path size
        if current_min_path_size < min_path_size:
            min_path_size = current_min_path_size

    # handle no path between nodes of the same color
    if min_path_size == sys.maxsize:
        return -1

    return min_path_size

if __name__ == '__main__':

    graph_nodes, graph_edges = map(int, input().split())

    graph_from = [0] * graph_edges
    graph_to = [0] * graph_edges

    for i in range(graph_edges):
        graph_from[i], graph_to[i] = map(int, input().split())

    ids = list(map(int, input().rstrip().split()))
    val = int(input())
    ans = findShortest(graph_nodes, graph_from, graph_to, ids, val)
    print(str(ans))
