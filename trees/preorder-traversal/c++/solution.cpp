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
         * Prints the pre-order traversal.
         *
         * <p>
         * The time bound is optimal since every
         * node has to be viewed once. The space
         * bound is not optimal since we can develop
         * an iterative solution that avoids use of the
         * stack.
         * </p>
         *
         * <p>
         * The optimal complexities for this
         * problem are O(n) time and O(1) space.
         * </p>
         *
         * Complexity:
         * - O(n) time
         * - O(n) space
         */
        void preOrder(Node *root) {
            if (root != nullptr) {
                cout << root->data << " ";
                preOrder(root->left);
                preOrder(root->right);
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
  
    myTree.preOrder(root);
    cout << endl;
    return 0;
}

