#include <stack>
#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {

    public:

        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if (data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }
                return root;
            }
        }

        /**
         * Writes post-order listing.
         *
         * <p>
         * This method prefers to visit right
         * nodes first and then visit left nodes.
         * </p>
         *
         * Complexity:
         * - O(n) time
         * - O(n) space
         */
        void postOrder(Node *root) {
            stack<int> stack;
            stack = postOrder(stack, root);
            while (!stack.empty()) {
                cout << stack.top() << " ";
                stack.pop();
            }
        }

        /**
         * Maintains a stack while traversing in post order.
         *
         * Complexity:
         * - O(n) time
         * - O(n) space
         */
        stack<int> postOrder(stack<int> stack, Node* node) {
            if (node != nullptr) {
                stack.push(node->data);
                stack = postOrder(stack, node->right);
                stack = postOrder(stack, node->left);
            }
            return stack;
        }
};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.postOrder(root);
    cout << endl;
    return 0;
}

