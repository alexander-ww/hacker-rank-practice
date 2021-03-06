import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static class Node {

        private int id;
        private Set<Integer> children;

        public Node(int id) {
            this.id = id;
            this.children = new HashSet<Integer>();
        }

        public int getId() {
            return this.id;
        }

        public void addChild(int child) {
            this.children.add(Integer.valueOf(child));
        }

        public Set<Integer> getChildren() {
            return this.children;
        }
    }

    private static class Graph {

        private Map<Integer, Node> nodes;

        public Graph(int[][] grid) {

            // setup empty nodes
            this.nodes = new HashMap<Integer, Node>();

            // build the graph nodes
            int nodeId = 0;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    int value = grid[i][j];
                    if (value == 1) {
                        Node node = new Node(nodeId);
                        this.nodes.put(Integer.valueOf(nodeId), node);
                    }
                    nodeId += 1;
                }
            }

            // add horizontal edge connections (bidirectional)
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length - 1; j++) {
                    int currValue = grid[i][j];
                    int nextValue = grid[i][j + 1];
                    if (currValue == 1 && nextValue == 1) {
                        nodeId = i * grid[i].length + j;
                        int srcNodeId = nodeId;
                        int dstNodeId = srcNodeId + 1;
                        this.nodes.get(Integer.valueOf(srcNodeId)).addChild(dstNodeId);
                        this.nodes.get(Integer.valueOf(dstNodeId)).addChild(srcNodeId);
                    }
                }
            }

            // add vertical edge connections (bidirectional)
            for (int i = 0; i < grid.length - 1; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    int currValue = grid[i][j];
                    int nextValue = grid[i + 1][j];
                    if (currValue == 1 && nextValue == 1) {
                        int srcNodeId = i * grid[i].length + j;
                        int dstNodeId = (i + 1) * grid[i + 1].length + j;
                        this.nodes.get(Integer.valueOf(srcNodeId)).addChild(dstNodeId);
                        this.nodes.get(Integer.valueOf(dstNodeId)).addChild(srcNodeId);
                    }
                }
            }

            // add left diagonal edge connections (bidirectional)
            for (int i = 0; i < grid.length - 1; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    if (j - 1 >= 0) {
                        int currValue = grid[i][j];
                        int nextValue = grid[i + 1][j - 1];
                        if (currValue == 1 && nextValue == 1) {
                            int srcNodeId = i * grid[i].length + j;
                            int dstNodeId = (i + 1) * grid[i + 1].length + j - 1;
                            this.nodes.get(Integer.valueOf(srcNodeId)).addChild(dstNodeId);
                            this.nodes.get(Integer.valueOf(dstNodeId)).addChild(srcNodeId);
                        }
                    }
                }
            }

            // add right diagonal edge connections (bidirectional)
            for (int i = 0; i < grid.length - 1; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    if (j + 1 < grid[i].length) {
                        int currValue = grid[i][j];
                        int nextValue = grid[i + 1][j + 1];
                        if (currValue == 1 && nextValue == 1) {
                            int srcNodeId = i * grid[i].length + j;
                            int dstNodeId = (i + 1) * grid[i + 1].length + j + 1;
                            this.nodes.get(Integer.valueOf(srcNodeId)).addChild(dstNodeId);
                            this.nodes.get(Integer.valueOf(dstNodeId)).addChild(srcNodeId);
                        }
                    }
                }
            }
        }

        private Set<Integer> dfs(int root, Set<Integer> visited) {

            if (visited.contains(Integer.valueOf(root))) {
                return visited;
            }

            else {
                visited.add(Integer.valueOf(root));
                for (Integer child: this.nodes.get(Integer.valueOf(root)).getChildren()) {
                    if (!visited.contains(child)) {
                        visited = dfs(child.intValue(), visited);
                    }
                }
                return visited;
            }
        }

        public boolean hasNodes() {
            boolean noNodes = true;
            for (Integer nodeId: this.nodes.keySet()) {
                noNodes = false;
                break;
            }
            return !noNodes;
        }

        public int regionSize() {

            // build the current maximum size
            int maxSize = 0;

            // build the set of remaining nodes
            Set<Integer> remaining = new HashSet<Integer>();
            for (Integer nodeId: this.nodes.keySet()) {
                remaining.add(nodeId);
            }

            // explore all disjoint regions
            while (!remaining.isEmpty()) {

                // select a root node
                int root = 0;
                for (Integer node: remaining) {
                    root = node.intValue();
                    break;
                }

                // reset the visited set
                Set<Integer> visited = new HashSet<Integer>();

                // explore the size of a region
                visited = dfs(root, visited);

                int currentSize = 0;
                for (Integer node: visited) {
                    currentSize += 1;
                    remaining.remove(node);
                }

                // update the maximum region size
                if (currentSize > maxSize) {
                    maxSize = currentSize;
                }
            }

            return maxSize;
        }
    }

    // Complete the maxRegion function below.
    static int maxRegion(int[][] grid) {
        Graph graph = new Graph(grid);
        int size = 0;
        if (graph.hasNodes()) {
            size = graph.regionSize();
        }
        return size;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[][] grid = new int[n][m];

        for (int i = 0; i < n; i++) {
            String[] gridRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < m; j++) {
                int gridItem = Integer.parseInt(gridRowItems[j]);
                grid[i][j] = gridItem;
            }
        }

        int res = maxRegion(grid);
        System.out.println(String.valueOf(res));
        scanner.close();
    }
}
