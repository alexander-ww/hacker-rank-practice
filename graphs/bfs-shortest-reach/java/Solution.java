import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static class Node {

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

        Set<Integer> getChildren() {
            return this.children;
        }
    }

    public static class Graph {

        private Map<Integer, Node> nodes;

        public Graph(int size) {
            this.nodes = new HashMap<Integer, Node>();
            for (int i = 0; i < size; i++) {
                Node node = new Node(i);
                this.nodes.put(Integer.valueOf(i), node);
            }
        }

        public void addEdge(int first, int second) {
            this.nodes.get(Integer.valueOf(first)).addChild(second);
            this.nodes.get(Integer.valueOf(second)).addChild(first);
        }
        
        public int[] shortestReach(int startId) { // 0 indexed
            int[] result = new int[nodes.size()];
            ArrayList<Integer> depths = getDepths(startId);
            int index = 0;
            for (Integer depth: depths) {
                result[index] = depth.intValue();
                index += 1;
            }
            return result;
        }

        private ArrayList<Integer> getDepths(int root) {

            // perform breadth first search
            Map<Integer, Integer> depths = bfs(root);

            // produce the list of depths
            ArrayList<Integer> result = new ArrayList<Integer>();
            for (Integer node: depths.keySet()) {
                result.add(Integer.valueOf(-1));
            }

            for (Integer node: depths.keySet()) {
                if (depths.get(node) != Integer.valueOf(0)) {
                    result.set(node.intValue(), depths.get(node));
                }
            }

            return result;
        }

        private Map<Integer, Integer> bfs(int root) {

            // create a node queue
            Queue<Integer> nodeQueue = new ArrayDeque<Integer>();

            // initialize map of depths
            Map<Integer, Integer> depths = new HashMap<Integer, Integer>();
            for (Integer node: nodes.keySet()) {
                depths.put(node, Integer.valueOf(0));
            }

            // mark current as visited and queue it
            Set<Integer> visited = new HashSet<Integer>();
            visited.add(root);
            nodeQueue.add(Integer.valueOf(root));

            // update the current depth
            depths.put(Integer.valueOf(root), Integer.valueOf(0));

            // declare the edge depth
            Integer edgeDepth = Integer.valueOf(6);

            // continue until done traversing
            while (!nodeQueue.isEmpty()) {

                // get the current node
                Integer node = nodeQueue.poll();

                // queue up children of current node
                for (Integer child: this.nodes.get(node).getChildren()) {
                    if (!visited.contains(child)) {
                        visited.add(child);
                        nodeQueue.add(child);
                        depths.put(child, depths.get(node) + edgeDepth);
                    }
                }
            }

            return depths;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
      
        int queries = scanner.nextInt();
        
        for (int t = 0; t < queries; t++) {
            
            // Create a graph of size n where each edge weight is 6:
            Graph graph = new Graph(scanner.nextInt());
            int m = scanner.nextInt();
            
            // read and set edges
            for (int i = 0; i < m; i++) {
                int u = scanner.nextInt() - 1;
                int v = scanner.nextInt() - 1;
                
                // add each edge to the graph
                graph.addEdge(u, v);
            }
            
            // Find shortest reach from node s
            int startId = scanner.nextInt() - 1;
            int[] distances = graph.shortestReach(startId);
 
            for (int i = 0; i < distances.length; i++) {
                if (i != startId) {
                    System.out.print(distances[i]);
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        
        scanner.close();
    }
}
