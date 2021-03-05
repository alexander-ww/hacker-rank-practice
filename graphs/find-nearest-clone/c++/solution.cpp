#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> split_string(string);

/**
 * A colored graph node.
 *
 * <p>
 * The Node class represents
 * a node in a graph that has
 * an ID and an associated color.
 * </p>
 */
class Node {

    private:

        // The ID of the graph node.
        int id;

        // The color of the graph node.
        long color;

        // The children of the graph node.
        unordered_set<int> children;

    public:

        /**
         * Constructor.
         *
         * <p>
         * This method accepts an ID
         * value and a color value as
         * input and constructs an
         * instance of a graph node.
         * </p>
         *
         * @param id The ID of the node.
         * @param color The color of the node.
         *
         * @return The graph node.
         */
        Node(int id, long color) {
            this->id = id;
            this->color = color;
            this->children = unordered_set<int>();
        }

        /**
         * Gets the node ID.
         *
         * <p>
         * This method acquires the
         * ID of the graph node.
         * </p>
         *
         * @return The node ID.
         */
        int getId() {
            return this->id;
        }

        /**
         * Gets the node color.
         *
         * <p>
         * This method acquires the
         * color of the graph node.
         * </p>
         *
         * @return The node color.
         */
        long getColor() {
            return this->color;
        }

        /**
         * Gets the node children.
         *
         * <p>
         * This method acquires the
         * children of the graph node.
         * </p>
         *
         * @return The children of the node.
         */
        unordered_set<int> getChildren() {
            return this->children;
        }

        /**
         * Adds a child node.
         *
         * <p>
         * This method accepts an integer
         * representing the ID of a child
         * node and adds the child to the
         * set of children maintained by
         * the node.
         * </p>
         *
         * @param child The child to add.
         */
        void addChild(int child) {
            this->children.insert(child);
        }
};

/**
 * Builds a graph.
 *
 * <p>
 * This method accepts information about the
 * number of nodes in the graph, the source
 * nodes of the edges in the graph, the
 * destination nodes of the edges in the
 * graph, and the colors to associate with
 * nodes based on their ID values. Upon the
 * receipt of these inputs, the method builds
 * a graph as an unordered map of node IDs to
 * node object pointers.
 * </p>
 *
 * @param graph_nodes The number of graph nodes.
 * @param graph_from The source nodes for edges.
 * @param graph_to The destination nodes for edges.
 * @param ids The colors for nodes.
 *
 * @return The graph as an unordered map.
 *
 * Complexity:
 * - O(|V| + |E|) time
 * - O(|V| + |E|) space
 */
unordered_map<int, Node*> buildGraph(int graph_nodes,
                                     vector<int> graph_from,
                                     vector<int> graph_to,
                                     vector<long> ids) {

    // setup empty graph
    unordered_map<int, Node*> graph = unordered_map<int, Node*>();

    // add nodes to the graph
    for (int i = 0; i < graph_nodes; i++) {
        Node* node = new Node(i, ids.at(i));
        graph[i] = node;
    }

    // add edges to the graph
    for (int i = 0; i < graph_from.size(); i++) {

        // get endpoints of edge
        int src = graph_from.at(i) - 1;
        int dst = graph_to.at(i) - 1;

        // add child for directed edge
        graph.at(src)->addChild(dst);
    }

    return graph;
}

/**
 * Builds a color to node ID map.
 *
 * <p>
 * This method accepts the number of nodes in
 * the graph and an unordered map representing
 * the graph. Upon the receipt of these inputs,
 * the method constructs a map between colors
 * and the IDs of nodes that have those colors.
 * <p>
 *
 * @param graph_nodes The number of graph nodes.
 * @param graph The map of node IDs to node object pointers.
 *
 * @return The color to node ID map.
 *
 * Complexity:
 * - O(|V|) time
 * - O(|V|) space
 */
unordered_map<long, vector<int>>
    buildColorMap(int graph_nodes,
                  unordered_map<int, Node*> graph) {

    // setup empty color map
    unordered_map<long, vector<int>> colorMap =
        unordered_map<long, vector<int>>();

    // store nodes by color in map
    for (int i = 0; i < graph_nodes; i++) {

        // get the color of the current node
        long color = graph.at(i)->getColor();

        // handle no instance of the color
        if (colorMap.find(color) == colorMap.end()) {
            colorMap[color] = vector<int>();
            colorMap.at(color).push_back(i);
        }

        // handle an instance of the color
        else {
            colorMap.at(color).push_back(i);
        }
    }

    return colorMap;
}

/**
 * Checks if a color is present.
 *
 * <p>
 * This method accepts a color and a color
 * map as input. Upon the receipt of these
 * two inputs, the method determines whether
 * the provided color is present in the color
 * map. If the color is present, then a value
 * of true is returned; Otherwise, a value of
 * false is returned.
 * </p>
 *
 * @param color The color to locate.
 * @param colorMap The color map to use.
 *
 * @return True if the color is present; False otherwise.
 *
 * Complexity:
 * - O(1) time
 * - O(1) space
 */
bool isColorPresent(long color,
                    unordered_map<long, vector<int>> colorMap) {

    // default result
    bool present = false;

    // check if color is present
    if (colorMap.find(color) != colorMap.end()) {
        present = true;
    }

    return present;
}

/**
 * Determine if a color has edges.
 *
 * <p>
 * This method accepts a color, an unordered map
 * representing a graph, and an unordered map
 * representing the nodes that are implementing
 * certain colors. Upon the receipt of these
 * inputs, the method determines whether the
 * provided color has any nodes that have edges
 * to other nodes of the same color. If there is
 * a node of the given color that does have edges,
 * then a value of true is returned; Otherwise, a
 * value of false is returned.
 * </p>
 *
 * @param color The color to check in the graph.
 * @param graph The unordered map representing the graph.
 * @param colorMap The color map to use.
 *
 * @return True if there are edges; False otherwise.
 *
 * Complexity:
 * - O(|V|) time
 * - O(|V|) space
 */
bool colorHasEdges(long color,
                   unordered_map<int, Node*> graph,
                   unordered_map<long, vector<int>> colorMap) {

    // default result
    bool hasEdges = false;

    // get the implementing nodes
    vector<int> colorNodes = vector<int>();

    // handle having nodes
    if (colorMap.find(color) != colorMap.end()) {
        colorNodes = colorMap.at(color);
    }

    // check for any children
    for (int colorNode: colorNodes) {

        // count the number of children
        int children = graph.at(colorNode)->getChildren().size();

        // handle finding children
        if (children > 0) {
            hasEdges = true;
            break;
        }
    }

    return hasEdges;
}

/**
 * Determines if a node pair is possible.
 *
 * <p>
 * This method accepts a color, an unordered map
 * representing a graph, and an unordered map
 * representing the nodes that are implementing
 * certain colors. Upon the receipt of these inputs,
 * the method determines whether a pair of color
 * nodes is possible for path formation. If there
 * is a possible pair, then a value of true is
 * returned; Otherwise, a value of false is returned.
 * </p>
 *
 * @param color The color to check in the graph.
 * @param graph The unordered map representing the graph.
 * @param colorMap The color map to use.
 *
 * @return True if a pair is possible; False otherwise.
 *
 * Complexity:
 * - O(|V|) time
 * - O(|V|) space
 */
bool isNodePairPossible(long color,
                        unordered_map<int, Node*> graph,
                        unordered_map<long, vector<int>> colorMap) {

    // determine if edges exist
    bool hasEdges = colorHasEdges(color, graph, colorMap);

    // check for sufficient node count
    bool sufficientCount = false;
    if (colorMap.find(color) != colorMap.end()) {
        sufficientCount = colorMap.at(color).size() >= 2;
    }

    // determine if a pair is possible
    bool pairPossible = hasEdges && sufficientCount;

    return pairPossible;
}

/**
 * Gets source nodes for a color.
 *
 * <p>
 * This method accepts a color, an unordered map
 * representing a graph, and an unordered map
 * representing the nodes that are implementing
 * certain colors. Upon the receipt of these
 * inputs, the method returns the nodes for the
 * provided color that have children, and that
 * are consequently able to be used as potential
 * sources.
 * </p>
 *
 * @param color The color to check in the graph.
 * @param graph The unordered map representing the graph.
 * @param colorMap The color map to use.
 *
 * @return The source nodes for the provided color.
 *
 * Complexity:
 * - O(|V|) time
 * - O(|V|) space
 */
vector<int> getSourceNodes(long color,
                           unordered_map<int, Node*> graph,
                           unordered_map<long, vector<int>> colorMap) {

    // default source nodes
    vector<int> sourceNodes = vector<int>();

    // handle existing set of nodes
    if (colorMap.find(color) != colorMap.end()) {

        // get the color nodes
        vector<int> colorNodes = colorMap.at(color);

        // add only color nodes with children
        for (int colorNode: colorNodes) {
            int children = graph.at(colorNode)->getChildren().size();
            if (children > 0) {
                sourceNodes.push_back(colorNode);
            }
        }
    }

    return sourceNodes;
}

/**
 * Finds path sizes from a source.
 *
 * <p>
 * This method accepts an ID for a source
 * node, a current path size, a set of IDs
 * for destination nodes, an unordered map
 * representing a graph, a set of visited
 * node IDs, and current minimum path size.
 * Upon the receipt of these inputs, the
 * method applies the DFS algorithm to
 * record the minimum path size from the
 * source to its identified destinations.
 * </p>
 *
 * @param source The ID of the source node.
 * @param pathSize The current path size.
 * @param destinations The set of destination node IDs.
 * @param graph The unordered map representing the graph.
 * @param visited The current set of visited node IDs.
 * @param minPathSize The current minimum path size.
 *
 * @return The minimum path size.
 *
 * Complexity:
 * - O(|V| + |E|) time
 * - O(|V| + |E|) space
 */
long findMinPathSize(int source,
                     long pathSize,
                     unordered_set<int> destinations,
                     unordered_map<int, Node*> graph,
                     unordered_set<int> &visited,
                     long &minPathSize) {

    // handle visited source
    if (visited.find(source) != visited.end()) {
        return minPathSize;
    }

    // handle unvisited source
    else {

        // indicate visit to source
        visited.insert(source);

        // check for immediate destinations
        bool hasDestination = false;
        for (int child: graph.at(source)->getChildren()) {

            // handle arrival at a destination (no need to go further)
            if (destinations.find(child) != destinations.end()) {
                if (pathSize + 1 < minPathSize) {
                    minPathSize = pathSize + 1;
                }
                hasDestination = true;
                visited.insert(child);
                break;
            }
        }

        // iterate through all children (continue path)
        if (!hasDestination) {
            for (int child: graph.at(source)->getChildren()) {
                if (visited.find(child) == visited.end()) {
                    minPathSize = findMinPathSize(child,
                                                  pathSize + 1,
                                                  destinations,
                                                  graph,
                                                  visited,
                                                  minPathSize);
                }
            }
        }

        return minPathSize;
    }
}

/**
 * Finds the shortest path between nodes of the given color.
 *
 * <p>
 * This method accepts an indication of the number of nodes
 * in the graph, an indication of the source nodes of edges in
 * the graph, an indication of the destination nodes of edges
 * in the graph, an indication of the color assignments to nodes,
 * and an indication of the color of the nodes for which to find
 * the shortest path. Upon the receipt of these inputs, this method
 * makes use of a variant of the DFS algorithm to determine the
 * shortest path between any two nodes of the given color. If
 * a shortest path can be found, then its length is returned;
 * Otherwise, a value of -1 is returned.
 * </p>
 *
 * @param graph_nodes The number of nodes in the graph.
 * @param graph_from The source nodes for edges in the graph.
 * @param graph_to The destination nodes for edges in the graph.
 * @param ids The colors for nodes.
 * @param val The color value to use when searching for the shortest path.
 *
 * @return The length of the shortest path or -1.
 *
 * Complexity:
 * - O(|V| (|V| * |E|)) time
 * - O(|V| + |E|) space
 */
int findShortest(int graph_nodes,
                 vector<int> graph_from,
                 vector<int> graph_to,
                 vector<long> ids,
                 int val) {

    // get selected color
    long color = (long) val;

    // build the graph
    unordered_map<int, Node*> graph;
    graph = buildGraph(graph_nodes, graph_from, graph_to, ids);

    // build the color map
    unordered_map<long, vector<int>> colorMap;
    colorMap = buildColorMap(graph_nodes, graph);

    // check if color is present
    bool colorPresent = isColorPresent(color, colorMap);

    // handle color not being present
    if (!colorPresent) {
        return -1;
    }

    // check if pair is possible
    bool pairPossible = isNodePairPossible(color, graph, colorMap);

    // handle no possible pair
    if (!pairPossible) {
        return -1;
    }

    // get the source nodes (for the color)
    vector<int> sourceNodes;
    sourceNodes = getSourceNodes(color, graph, colorMap);

    // get destination nodes (for the color)
    unordered_set<int> destinationNodes = unordered_set<int>();
    vector<int> colorNodes = colorMap.at(color);

    for (int colorNode: colorNodes) {
        destinationNodes.insert(colorNode);
    }

    // iterate through all sources
    long pathSize = 0;
    long minPathSize = LONG_MAX;
    long currentMinPathSize = minPathSize;
    unordered_set<int> visited = unordered_set<int>();

    for (int sourceNode: sourceNodes) {
        
        // get the minimum path size for the current source
        currentMinPathSize = findMinPathSize(sourceNode,
                                             pathSize,
                                             destinationNodes,
                                             graph,
                                             visited,
                                             minPathSize);

        // update the minimum path size
        if (currentMinPathSize < minPathSize) {
            minPathSize = currentMinPathSize;
        }
    }

    // handle no path between nodes of the same color
    if (minPathSize == LONG_MAX) {
        return -1;
    }

    return minPathSize;
}

int main()
{
    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);
    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);
        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);
    cout << ans << endl;

    return 0;
}

vector<string> split_string(string input_string) {

    string::iterator new_end =
        unique(input_string.begin(),
               input_string.end(),
                [] (const char &x, const char &y) {
                    return x == y and x == ' ';
                });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    return splits;
}
