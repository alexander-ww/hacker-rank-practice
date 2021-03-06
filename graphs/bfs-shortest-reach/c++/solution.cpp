#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node {
    private:
        int id;
        unordered_set<int> children;

    public:
        Node(int id) {
            this->id = id;
            this->children = unordered_set<int>();
        }

        int get_id() {
            return this->id;
        }

        void add_child(int child) {
            this->children.insert(child);
        }

        unordered_set<int> get_children() {
            return this->children;
        }
};

class Graph {
    private:
        unordered_map<int, Node*> nodes;

        vector<int> get_depths(int root) {

            // initialize map of depths
            unordered_map<int, int> depths = unordered_map<int, int>();
            for (pair<int, Node*> entry: nodes) {
                depths[entry.first] = 0;
            }

            // initialize visited nodes
            unordered_set<int> visited = unordered_set<int>();

            // perform breadth first search
            bfs(root, visited, depths);

            // produce the list of depths
            vector<int> result = vector<int>();
            for (pair<int, int> entry: depths) {
                result.push_back(-1);
            }

            for (pair<int, int> entry: depths) {
                if (depths[entry.first] != 0) {
                    result.at(entry.first) = depths[entry.first];
                }
            }

            return result;
        }

        void bfs(int root,
                 unordered_set<int> &visited,
                 unordered_map<int, int> &depths) {

            // create a node queue
            queue<int> node_queue;

            // mark current as visited and queue it
            visited.insert(root);
            node_queue.push(root);

            // update the current depth
            depths[root] = 0;

            // declare the edge depth
            int edge_depth = 6;

            // continue until done traversing
            while (!node_queue.empty()) {

                // get the current node
                int node = node_queue.front();
                node_queue.pop();

                // queue up children of current node
                for (int child: this->nodes[node]->get_children()) {
                    if (visited.find(child) == visited.end()) {
                        visited.insert(child);
                        node_queue.push(child);
                        depths[child] = depths[node] + edge_depth;
                    }
                }
            }
        }

    public:
        Graph(int n) {
            this->nodes = unordered_map<int, Node*>();
            for (int i = 0; i < n; i++) {
                Node* node = new Node(i);
                this->nodes[i] = node;
            }
        }
    
        void add_edge(int u, int v) {
            this->nodes[u]->add_child(v);
            this->nodes[v]->add_child(u);
        }
    
        vector<int> shortest_reach(int start) {
            return get_depths(start);
        }
};

int main() {

    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
        int n, m;
        cin >> n;

        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;

        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;

            // add each edge to the graph
            graph.add_edge(u, v);
        }

        int startId;
        cin >> startId;
        startId--;

        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
