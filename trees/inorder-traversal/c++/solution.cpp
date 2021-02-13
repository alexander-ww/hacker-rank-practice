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
                if(data <= root->data) {
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
         * Prints the in-order traversal.
         *
         * <p>
         * This method accepts a pointer to the
         * root node of a binary tree and prints
         * the tree in order.
         * </p>
         *
         * @param root The provided root node.
         *
         * Complexity:
         * - O(n) time
         * - O(n) space
         */
        void inOrder(Node *root) {
            if (root != nullptr) {
                if (root->left != nullptr) {
                    inOrder(root->left);
                    cout << root->data << " ";
                    inOrder(root->right);
                }
                else {
                    cout << root->data << " ";
                    inOrder(root->right);
                }
            }
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
  
    myTree.inOrder(root);
    cout << endl;
    return 0;
}
