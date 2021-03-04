import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    /**
     * A node in a graph.
     *
     * <p>
     * The Node class represents a node
     * in a graph. A node has a value and
     * a list of associated child nodes.
     * </p>
     */
    private static class Node {

        // value or ID of the node
        private Integer value;

        // child IDs of the node
        private Collection<Integer> children;

        // constructor
        public Node(int value) {
            this.value = Integer.valueOf(value);
            this.children = new ArrayList<Integer>();
        }

        // gets the value or ID
        public int getValue() {
            return this.value.intValue();
        }

        // adds a child node ID
        public void addChild(int child) {
            children.add(Integer.valueOf(child));
        }

        // gets the child node ID
        Collection<Integer> getChildren() {
            return this.children;
        }
    }

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
    public static Map<Integer, Node> buildGraph(int n, int[][] edges) {

        // graph as an unordered map
        Map<Integer, Node> map = new HashMap<Integer, Node>();

        // add the nodes to the graph
        //
        // Complexity:
        // - O(|V|) time
        // - O(|V|) space
        //
        for (int i = 0; i < n; i++) {
            Node node = new Node(i);
            map.put(Integer.valueOf(i), node);
        }

        // add the edges to the graph
        //
        // Complexity:
        // - O(|E|) time
        // - O(|E|) space
        //
        for (int[] edge: edges) {
            Integer src = Integer.valueOf(edge[0] - 1);
            Integer dst = Integer.valueOf(edge[1] - 1);
            map.get(src).addChild(dst);
            map.get(dst).addChild(src);
        }

        return map;
    }

    /**
     * Gets all nodes able to be visited from a root node.
     *
     * <p>
     * The <i>getVisited</i> method accepts the ID of
     * a root node, a reference to the IDs of nodes that
     * have already been visited, and a reference
     * to a graph as an unordered map of node IDs to
     * node pointers. Upon the receipt of these inputs,
     * the method applies breadth first search (DFS) in
     * order determine the set of all graph nodes that
     * are able to be visited from the provided root node.
     * The method also updates the set of remaining
     * nodes by using its passed reference.
     * </p>
     *
     * @param root The ID of the provided root node.
     * @param visited The reference to the visited node IDs.
     * @param graph The reference to the graph.
     *
     * @return The visited nodes.
     *
     * Complexity:
     * - O(|V| + |E|) time
     * - O(|V|) space
     */
    public static Set<Integer> getVisited(Integer root,
                                          Set<Integer> visited,
                                          Map<Integer, Node> graph) {

        // handle visited node
        if (visited.contains(root)) {
            return visited;
        }

        // handle unvisited node
        else {

            // indicate visit to node
            visited.add(root);

            // process children of node
            for (Integer child: graph.get(root).getChildren()) {

                // process unvisited children
                if (!visited.contains(child)) {
                    visited = getVisited(child, visited, graph);
                }
            }
        }

        return visited;
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
     * DFS to determine the number of disjoint graphs in the
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
    public static Collection<Long> getDisjointGraphSizes(int n, int[][] edges) {

        // build the graph
        //
        // Complexity:
        // - O(|V| + |E|) time
        // - O(|V| + |E|) space
        //
        Map<Integer, Node> graph = buildGraph(n, edges);

        // build the set of remaining cities
        //
        // Complexity:
        // - O(|V|) time
        // - O(|V|) space
        //
        Set<Integer> remaining = new HashSet<Integer>();
        for (Integer key: graph.keySet()) {
            remaining.add(key);
        }

        // initialize the set of visited cities
        Set<Integer> visited = new HashSet<Integer>();

        // store the subgraph sizes
        Collection<Long> graphSizes = new ArrayList<Long>();

        // process through all remaining cities
        //
        // Complexity:
        // O(|V| + |E|) time
        // O(|V| + |E|) space
        //
        while (!remaining.isEmpty()) {

            // get a root node
            Integer root = Integer.valueOf(0);
            for (Integer i: remaining) {
                root = i;
                break;
            }

            // process the subgraph of the root
            visited = getVisited(root, visited, graph);

            // remove visited nodes
            for (Integer node: visited) {
                remaining.remove(node);
            }

            // record the subgraph size
            graphSizes.add(Long.valueOf(visited.size()));

            // reset visited for the next subgraph
            visited = new HashSet<Integer>();
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
    static long roadsAndLibraries(int n, int c_lib, int c_road, int[][] cities) {

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
            Collection<Long> graphSizes = getDisjointGraphSizes(n, cities);
            long graphs = (long) graphSizes.size();

            // add a library to each disjoint graph
            cost = ((long) c_lib) * graphs;

            // add roads in each disjoint graph
            for (Long size: graphSizes) {
                cost += (size.longValue() - 1) * ((long) c_road);
            }
        }

        return cost;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String[] nmC_libC_road = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nmC_libC_road[0]);
            int m = Integer.parseInt(nmC_libC_road[1]);
            int c_lib = Integer.parseInt(nmC_libC_road[2]);
            int c_road = Integer.parseInt(nmC_libC_road[3]);

            int[][] cities = new int[m][2];

            for (int i = 0; i < m; i++) {
                String[] citiesRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < 2; j++) {
                    int citiesItem = Integer.parseInt(citiesRowItems[j]);
                    cities[i][j] = citiesItem;
                }
            }

            long result = roadsAndLibraries(n, c_lib, c_road, cities);
            System.out.println(String.valueOf(result));
        }

        scanner.close();
    }
}
