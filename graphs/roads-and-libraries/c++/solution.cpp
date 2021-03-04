#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> split_string(string);

/**
 * A node in a graph.
 *
 * <p>
 * The Node class represents a node
 * in a graph. A node has a value and
 * a list of associated child nodes.
 * </p>
 */
class Node {

    private:

        // value or ID of the node
        int value;

        // child IDs of the node
        vector<int> children;

    public:

        // constructor
        Node(int value) {
            this->value = value;
        }

        // gets the value or ID
        int getValue() {
            return this->value;
        }

        // adds a child node ID
        void addChild(int child) {
            this->children.push_back(child);
        }

        // gets the child node IDs
        vector<int> getChildren() {
            return this->children;
        }
};

/**
 * Builds a graph.
 *
 * <p>
 * The <i>buildGraph</i> method accepts
 * a positive integer representing the number
 * of nodes in the graph and a list of edges
 * between those nodes in the graph. Upon
 * the receipt of these inputs, the method
 * constructs the indicated graph as an
 * unordered map of node indices to node
 * pointers. This map is produced as output.
 * </p>
 *
 * @param n The number of nodes.
 * @param edges The edges in the graph.
 *
 * @return The graph as an unordered map.
 *
 * Complexity:
 * - O(|V| + |E|) time
 * - O(|V| + |E|) space
 */
unordered_map<int, Node*> buildGraph(int n, vector< vector<int> > edges) {

    // graph as an unordered map
    unordered_map<int, Node*> map = unordered_map<int, Node*>();

    // add the nodes to the graph
    //
    // Complexity:
    // - O(|V|) time
    // - O(|V|) space
    //
    for (int i = 0; i < n; i++) {
        Node* node = new Node(i);
        map[i] = node;
    }

    // add the edges to the graph
    //
    // Complexity:
    // - O(|E|) time
    // - O(|E|) space
    //
    for (vector<int> edge: edges) {
        int src = edge.at(0) - 1;
        int dst = edge.at(1) - 1;
        map.at(src)->addChild(dst);
        map.at(dst)->addChild(src);
    }

    return map;
}

/**
 * Gets all nodes able to be visited from a root node.
 *
 * <p>
 * The <i>getVisited</i> method accepts the ID of
 * a root node, a reference to the IDs of nodes that
 * have already been visited, a reference to the IDs
 * of nodes that remain to be visited, and a reference
 * to a graph as an unordered map of node IDs to
 * node pointers. Upon the receipt of these inputs,
 * the method applies breadth first search (BFS) in
 * order determine the set of all graph nodes that
 * are able to be visited from the provided root node.
 * The method also updates the set of remaining
 * nodes by using its passed reference.
 * </p>
 *
 * @param root The ID of the provided root node.
 * @param visited The reference to the visited node IDs.
 * @param remaining The reference to the remaining node IDs.
 * @param graph The reference to the graph.
 *
 * Complexity:
 * - O(|V| + |E|) time
 * - O(|V|) space
 */
void getVisited(int root,
                unordered_set<int> &visited,
                unordered_set<int> &remaining,
                unordered_map<int, Node*> &graph) {

    // handle unvisited node
    if (visited.find(root) == visited.end()) {

        // indicate visit to node
        visited.insert(root);

        // remove node from remaining
        remaining.erase(root);

        // process children of node
        for (int child: graph.at(root)->getChildren()) {

            // process unvisited children
            if (visited.find(child) == visited.end()) {
                getVisited(child, visited, remaining, graph);
            }
        }
    }
}

/**
 * Gets the sizes of the disjoint graphs.
 *
 * <p>
 * The <i>getDisjointGraphSizes</i> method accepts a
 * positive integer representing the number of nodes in
 * the graph and a list of edges that are in the graph.
 * Upon the receipt of these inputs, the method uses
 * a set of visited nodes, a set of remaining nodes, and
 * BFS to determine the number of disjoint graphs in the
 * graph and the number of nodes that each of those
 * disjoint graphs contain. The result is a list of node
 * sizes for each of those disjoint graphs.
 * </p>
 *
 * @param n The number of nodes in the graph.
 * @param edges The edges in the graph.
 *
 * @return The node sizes of each of the disjoint graphs.
 *
 * Complexity:
 * - O(|V| + |E|) time
 * - O(|V| + |E|) space
 */
vector<long> getDisjointGraphSizes(int n, vector< vector<int> > edges) {

    // build the graph
    //
    // Complexity:
    // - O(|V| + |E|) time
    // - O(|V| + |E|) space
    //
    unordered_map<int, Node*> graph = buildGraph(n, edges);

    // build the set of remaining cities
    //
    // Complexity:
    // - O(|V|) time
    // - O(|V|) space
    //
    unordered_set<int> remaining = unordered_set<int>();
    for (pair<int, Node*> p: graph) {
        remaining.insert(p.first);
    }

    // initialize the set of visited cities
    unordered_set<int> visited = unordered_set<int>();

    // store the subgraph sizes
    vector<long> graphSizes = vector<long>();

    // process through all remaining cities
    //
    // Complexity:
    // O(|V| + |E|) time
    // O(|V| + |E|) space
    //
    while (!remaining.empty()) {

        // get a root node
        int root = 0;
        for (int i: remaining) {
            root = i;
            break;
        }

        // process the subgraph of the root
        getVisited(root, visited, remaining, graph);

        // record the subgraph size
        graphSizes.push_back((long) visited.size());

        // reset visited for the next subgraph
        visited = unordered_set<int>();
    }

    return graphSizes;
}

/**
 * Determines the minimum cost for library access.
 *
 * <p>
 * The <i>roadsAndLibraries</i> function accepts a
 * positive integer representing the number of cities,
 * a positive integer representing the cost per library,
 * a positive integer representing the cost per road,
 * and a list of potential bi-directional roads between
 * cities. Upon the receipt of these inputs, the function
 * determines the optimal construction of libraries and
 * roads such that the cost for ensuring that all citizens
 * have library access is minimal.
 * </p>
 *
 * @param n The number of cities.
 * @param c_lib The cost per library.
 * @param c_road The cost per road.
 * @param cities The potential bi-directional roads between cities.
 *
 * @return The minimum cost for ensuring library acess.
 *
 * Complexity:
 * - O(|V| + |E|) time
 * - O(|V| + |E|) space
 */
long roadsAndLibraries(int n,
                       int c_lib,
                       int c_road,
                       vector< vector<int> > cities) {

    // default cost
    long cost = 0;

    // libraries cost less than roads
    //
    // When the libraries cost less than the
    // roads, then we want to prefer building
    // libraries instead of roads. This means
    // that the construction for minimum cost
    // will not involve building a single road.
    // Consequently, we simply build a library
    // for every city.
    //
    // Complexity:
    // - O(1) time
    // - O(1) space
    //
    if (c_lib < c_road) {
        cost = ((long) c_lib) * ((long) n);
    }

    // roads cost less than libraries
    //
    // When the roads cost less than the
    // libraries, then we want to prefer
    // building roads instead of libraries.
    // This means that the construction for
    // minimum cost will involve having one
    // library built for each disjoint graph
    // of cities. It also means that the
    // construction will involve having the
    // minimum number of roads to fully
    // connect the nodes in each disjoint
    // graph, which is the minimum spanning
    // tree size, which is n - 1 roads with
    // n being the number of nodes in the
    // disjoint graph.
    //
    // Complexity:
    // - O(|V| + |E|) time
    // - O(|V| + |E|) space
    //
    else {

        // get the disjoint graph info
        vector<long> graphSizes = getDisjointGraphSizes(n, cities);
        long graphs = (long) graphSizes.size();

        // add a library to each disjoint graph
        cost = ((long) c_lib) * graphs;

        // add roads in each disjoint graph
        for (long size: graphSizes) {
            cost += (size - 1) * ((long) c_road);
        }
    }

    return cost;
}

int main()
{

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);
        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);
        int m = stoi(nmC_libC_road[1]);
        int c_lib = stoi(nmC_libC_road[2]);
        int c_road = stoi(nmC_libC_road[3]);

        vector< vector<int> > cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout << result << endl;
    }

    return 0;
}

vector<string> split_string(string input_string) {

    string::iterator new_end =
        unique(input_string.begin(),
               input_string.end(),
               [] (const char &x, const char &y)
    {
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
