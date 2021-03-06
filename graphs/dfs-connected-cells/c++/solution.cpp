#include <string>
#include <vector>
#include <iostream>
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

        int dfs(int root,
                int current_size,
                unordered_set<int> &visited) {

            if (visited.find(root) != visited.end()) {
                return current_size;
            }

            else {
                visited.insert(root);
                for (int child: this->nodes[root]->get_children()) {
                    if (child == root) {
                        current_size += 1;
                    }
                    else {
                        if (visited.find(child) == visited.end()) {
                            current_size += 1;
                            current_size = dfs(child, current_size, visited);
                        }
                    }
                }
                return current_size;
            }
        }

    public:
        Graph(vector<vector<int>> grid) {
    
            // setup empty nodes
            this->nodes = unordered_map<int, Node*>();

            // build the graph nodes
            int node_id = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid.at(i).size(); j++) {
                    int value = grid.at(i).at(j);
                    if (value == 1) {
                        Node* node = new Node(node_id);
                        this->nodes[node_id] = node;
                    }
                    node_id += 1;
                }
            }

            // add horizontal edge connections (bidirectional)
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid.at(i).size() - 1; j++) {
                    int curr_value = grid.at(i).at(j);
                    int next_value = grid.at(i).at(j + 1);
                    if (curr_value == 1 && next_value == 1) {
                        node_id = i * grid.at(i).size() + j;
                        int src_node_id = node_id;
                        int dst_node_id = src_node_id + 1;
                        this->nodes[src_node_id]->add_child(dst_node_id);
                        this->nodes[dst_node_id]->add_child(src_node_id);
                    }
                }
            }

            // add vertical edge connections (bidirectional)
            for (int i = 0; i < grid.size() - 1; i++) {
                for (int j = 0; j < grid.at(i).size(); j++) {
                    int curr_value = grid.at(i).at(j);
                    int next_value = grid.at(i + 1).at(j);
                    if (curr_value == 1 && next_value == 1) {
                        int src_node_id = i * grid.at(i).size() + j;
                        int dst_node_id = (i + 1) * grid.at(i + 1).size() + j;
                        this->nodes[src_node_id]->add_child(dst_node_id);
                        this->nodes[dst_node_id]->add_child(src_node_id);
                    }
                }
            }

            // add left diagonal edge connections (bidirectional)
            for (int i = 0; i < grid.size() - 1; i++) {
                for (int j = 0; j < grid.at(i).size(); j++) {
                    if (j - 1 >= 0) {
                        int curr_value = grid.at(i).at(j);
                        int next_value = grid.at(i + 1).at(j - 1);
                        if (curr_value == 1 && next_value == 1) {
                            int src_node_id = i * grid.at(i).size() + j;
                            int dst_node_id = (i + 1) * grid.at(i + 1).size() + j - 1;
                            this->nodes[src_node_id]->add_child(dst_node_id);
                            this->nodes[dst_node_id]->add_child(src_node_id);
                        }
                    }
                }
            }

            // add right diagonal edge connections (bidirectional)
            for (int i = 0; i < grid.size() - 1; i++) {
                for (int j = 0; j < grid.at(i).size(); j++) {
                    if (j + 1 < grid.at(i).size()) {
                        int curr_value = grid.at(i).at(j);
                        int next_value = grid.at(i + 1).at(j + 1);
                        if (curr_value == 1 && next_value == 1) {
                            int src_node_id = i * grid.at(i).size() + j;
                            int dst_node_id = (i + 1) * grid.at(i + 1).size() + j + 1;
                            this->nodes[src_node_id]->add_child(dst_node_id);
                            this->nodes[dst_node_id]->add_child(src_node_id);
                        }
                    }
                }
            }
        }

        bool has_nodes() {
            bool no_nodes = true;
            for (pair<int, Node*> entry: this->nodes) {
                no_nodes = false;
                break;
            }
            return !no_nodes;
        }

        int region_size() {

            // build the current maximum size
            int max_size = 0;

            // build the set of remaining nodes
            unordered_set<int> remaining = unordered_set<int>();
            for (pair<int, Node*> node: this->nodes) {
                remaining.insert(node.first);
            }

            // explore all disjoint regions
            while (!remaining.empty()) {

                // select a root node
                int root = 0;
                for (int node: remaining) {
                    root = node;
                    break;
                }

                // reset the visited set
                unordered_set<int> visited = unordered_set<int>();

                // explore the size of a region
                int current_size = dfs(root, 1, visited);
                for (int node: visited) {
                    remaining.erase(node);
                }

                // update the maximum region size
                if (current_size > max_size) {
                    max_size = current_size;
                }
            }

            return max_size;
        }
};

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    Graph* graph = new Graph(grid);
    int size = 0;
    if (graph->has_nodes()) {
        size = graph->region_size();
    }
    return size;
}

int main() {

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);
    cout << res << endl;
    return 0;
}
