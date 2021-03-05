import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    /**
     * A colored graph node.
     *
     * <p>
     * The Node class represents
     * a node in a graph that has
     * an ID and an associated color.
     * </p>
     */
    private static class Node {

        // The ID of the graph node.
        private int id;

        // The color of the graph node.
        private long color;

        // The children of the graph node.
        private Set<Integer> children;

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
        public Node(int id, long color) {
            this.id = id;
            this.color = color;
            this.children = new HashSet<Integer>();
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
        public int getId() {
            return this.id;
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
        public long getColor() {
            return this.color;
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
        public Set<Integer> getChildren() {
            return this.children;
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
        public void addChild(int child) {
            this.children.add(Integer.valueOf(child));
        }
    }

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
    public static Map<Integer, Node> buildGraph(int graphNodes,
                                                int[] graphFrom,
                                                int[] graphTo,
                                                long[] ids) {

        // setup empty graph
        Map<Integer, Node> graph = new HashMap<Integer, Node>();

        // add nodes to the graph
        for (int i = 0; i < graphNodes; i++) {
            Node node = new Node(i, ids[i]);
            graph.put(Integer.valueOf(i), node);
        }

        // add edges to the graph
        for (int i = 0; i < graphFrom.length; i++) {

            // get endpoints of edge
            Integer src = Integer.valueOf(graphFrom[i] - 1);
            Integer dst = Integer.valueOf(graphTo[i] - 1);

            // add child for directed edge
            graph.get(src).addChild(dst);
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
    public static Map<Long, Collection<Integer>>
        buildColorMap(int graphNodes, Map<Integer, Node> graph) {

        // setup empty color map
        Map<Long, Collection<Integer>> colorMap =
            new HashMap<Long, Collection<Integer>>();

        // store nodes by color in map
        for (int i = 0; i < graphNodes; i++) {

            // get the color of the current node
            long color = graph.get(Integer.valueOf(i)).getColor();

            // handle no instance of the color
            if (colorMap.get(Long.valueOf(color)) == null) {
                colorMap.put(Long.valueOf(color), new ArrayList<Integer>());
                colorMap.get(Long.valueOf(color)).add(Integer.valueOf(i));
            }

            // handle an instance of the color
            else {
                colorMap.get(Long.valueOf(color)).add(Integer.valueOf(i));
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
    public static boolean isColorPresent(long color, Map<Long, Collection<Integer>> colorMap) {

        // default result
        boolean present = false;

        // check if color is present
        if (colorMap.get(Long.valueOf(color)) != null) {
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
    public static boolean colorHasEdges(long color,
                                        Map<Integer, Node> graph,
                                        Map<Long, Collection<Integer>> colorMap) {

        // default result
        boolean hasEdges = false;

        // get the implementing nodes
        Collection<Integer> colorNodes = new ArrayList<Integer>();

        // handle having nodes
        if (colorMap.get(Long.valueOf(color)) != null) {
            colorNodes = colorMap.get(Long.valueOf(color));
        }

        // check for any children
        for (Integer colorNode: colorNodes) {

            // count the number of children
            int children = graph.get(colorNode).getChildren().size();

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
    public static boolean isNodePairPossible(long color,
                                             Map<Integer, Node> graph,
                                             Map<Long, Collection<Integer>> colorMap) {

        // determine if edges exist
        boolean hasEdges = colorHasEdges(color, graph, colorMap);

        // check for sufficient node count
        boolean sufficientCount = false;
        if (colorMap.get(Long.valueOf(color)) != null) {
            sufficientCount = colorMap.get(Long.valueOf(color)).size() >= 2;
        }

        // determine if a pair is possible
        boolean pairPossible = hasEdges && sufficientCount;

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
    public static Collection<Integer> getSourceNodes(long color,
                                                     Map<Integer, Node> graph,
                                                     Map<Long, Collection<Integer>> colorMap) {

        // default source nodes
        Collection<Integer> sourceNodes = new ArrayList<Integer>();

        // handle existing set of nodes
        if (colorMap.get(Long.valueOf(color)) != null) {

            // get the color nodes
            Collection<Integer> colorNodes = colorMap.get(Long.valueOf(color));

            // add only color nodes with children
            for (Integer colorNode: colorNodes) {
                int children = graph.get(colorNode).getChildren().size();
                if (children > 0) {
                    sourceNodes.add(colorNode);
                }
            }
        }

        return sourceNodes;
    }

    /**
     * State for DFS traversal.
     *
     * <p>
     * The DFS state class provides
     * a means for storing traversal state.
     * </p>
     */
    private static class DfsState {

        // The minimum path size
        private long minPathSize;

        // The visited node IDs
        private Set<Integer> visited;

        /**
         * Constructor.
         *
         * <p>
         * This method accepts a minimum path
         * size and a set of visited node IDs. Upon
         * the receipt of these inputs, the method
         * constructs an instance of a DFS state.
         * </p>
         *
         * @param minPathSize The minimum path size.
         * @param visited The set of visited node IDs.
         */
        public DfsState(long minPathSize, Set<Integer> visited) {
            this.visited = visited;
            this.minPathSize = minPathSize;
        }

        /**
         * Gets the minimum path size.
         *
         * <p>
         * This method acquires the
         * minimum path size.
         * </p>
         *
         * @return The minimum path size.
         */
        public long getMinPathSize() {
            return this.minPathSize;
        }

        /**
         * Gets the visited node IDs.
         *
         * <p>
         * This method acquires the
         * set of visited node IDs.
         * </p>
         *
         * @return The set of visited node IDs.
         */
        public Set<Integer> getVisited() {
            return this.visited;
        }

        /**
         * Sets the minimum path size.
         *
         * <p>
         * This method accepts a minimum
         * path size as input and sets the
         * minimum path size of the DFS
         * traversal state instance accordingly.
         * </p>
         *
         * @param minPathSize The provided minimum path size.
         */
        public void setMinPathSize(long minPathSize) {
            this.minPathSize = minPathSize;
        }

        /**
         * Sets the visited set of node IDs.
         *
         * <p>
         * This method accepts as set of visited
         * node IDs as input and sets the visited
         * node IDs of the DFS traversal state
         * instance accordingly.
         * </p>
         *
         * @param visited The provided visited node IDs.
         */
        public void setVisited(Set<Integer> visited) {
            this.visited = visited;
        }
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
     * @param state The DFS traversal state.
     *
     * @return The DFS traversal state.
     *
     * Complexity:
     * - O(|V| + |E|) time
     * - O(|V| + |E|) space
     */
    static DfsState findMinPathSize(int source,
                                    long pathSize,
                                    Set<Integer> destinations,
                                    Map<Integer, Node> graph,
                                    DfsState state) {

        // handle visited source
        if (state.getVisited().contains(Integer.valueOf(source))) {
            return state;
        }

        // handle unvisited source
        else {

            // indicate visit to source
            Set<Integer> visited = state.getVisited();

            // update visited set
            visited.add(Integer.valueOf(source));

            // check for immediate destinations
            boolean hasDestination = false;
            for (Integer child: graph.get(Integer.valueOf(source)).getChildren()) {

                // handle arrival at a destination (no need to go further)
                if (destinations.contains(child)) {
                    if (pathSize + 1 < state.getMinPathSize()) {
                        long minPathSize = pathSize + 1;
                        state.setMinPathSize(minPathSize);
                    }
                    hasDestination = true;
                    visited.add(child);
                    break;
                }
            }

            // update visited
            state.setVisited(visited);

            // iterate through all children (continue path)
            if (!hasDestination) {
                for (Integer child: graph.get(Integer.valueOf(source)).getChildren()) {
                    if (!state.getVisited().contains(child)) {
                        state = findMinPathSize(child.intValue(),
                                                pathSize + 1,
                                                destinations,
                                                graph,
                                                state);
                    }
                }
            }

            return state;
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
    static int findShortest(int graphNodes,
                            int[] graphFrom,
                            int[] graphTo,
                            long[] ids,
                            int val) {

        // get selected color
        long color = (long) val;

        // build the graph
        Map<Integer, Node> graph =
            buildGraph(graphNodes, graphFrom, graphTo, ids);

        // build the color map
        Map<Long, Collection<Integer>> colorMap =
            buildColorMap(graphNodes, graph);

        // check if color is present
        boolean colorPresent = isColorPresent(color, colorMap);

        // handle color not being present
        if (!colorPresent) {
            return -1;
        }

        // check if pair is possible
        boolean pairPossible = isNodePairPossible(color, graph, colorMap);

        // handle no possible pair
        if (!pairPossible) {
            return -1;
        }

        // get the source nodes (for the color)
        Collection<Integer> sourceNodes =
            getSourceNodes(color, graph, colorMap);

        // get destination nodes (for the color)
        Set<Integer> destinationNodes = new HashSet<Integer>();
        Collection<Integer> dstNodes = colorMap.get(Long.valueOf(color));
        for (Integer dstNode: dstNodes) {
            destinationNodes.add(dstNode);
        }

        // iterate through all sources
        long pathSize = 0;
        long minPathSize = Long.MAX_VALUE;
        Set<Integer> visited = new HashSet<Integer>();

        for (Integer sourceNode: sourceNodes) {

            // prepare traversal state
            DfsState state = new DfsState(minPathSize, visited);

            // get the minimum path size for the current source
            state = findMinPathSize(sourceNode.intValue(),
                                    pathSize,
                                    destinationNodes,
                                    graph,
                                    state);

            // update the minimum path size
            if (state.getMinPathSize() < minPathSize) {
                minPathSize = state.getMinPathSize();
            }
        }

        // handle no path between nodes of the same color
        if (minPathSize == Long.MAX_VALUE) {
            return -1;
        }

        return (int) minPathSize;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        String[] graphNodesEdges = scanner.nextLine().split(" ");
        int graphNodes = Integer.parseInt(graphNodesEdges[0].trim());
        int graphEdges = Integer.parseInt(graphNodesEdges[1].trim());

        int[] graphFrom = new int[graphEdges];
        int[] graphTo = new int[graphEdges];

        for (int i = 0; i < graphEdges; i++) {
            String[] graphFromTo = scanner.nextLine().split(" ");
            graphFrom[i] = Integer.parseInt(graphFromTo[0].trim());
            graphTo[i] = Integer.parseInt(graphFromTo[1].trim());
        }

        long[] ids = new long[graphNodes];

        String[] idsItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < graphNodes; i++) {
            long idsItem = Long.parseLong(idsItems[i]);
            ids[i] = idsItem;
        }

        int val = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int ans = findShortest(graphNodes, graphFrom, graphTo, ids, val);
        System.out.println(String.valueOf(ans));
        scanner.close();
    }
}
