#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * A linked list node.
 *
 * <p>
 * The SinglyLinkedListNode class
 * provides a means for representing
 * a node in a singly linked list.
 * </p>
 */
class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode* next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

/**
 * A linked list.
 *
 * <p>
 * The SinglyLinkedList class provides
 * a means for representing a singly
 * linked list.
 * </p>
 */
class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);
            if (!this->head) {
                this->head = node;
            }
            else {
                this->tail->next = node;
            }
            
            this->tail = node;
        }
};

/**
 * Frees a linked list.
 *
 * <p>
 * This method accepts a pointer to
 * a singly linked list node as input
 * and traverses forward from that
 * node to deallocate the node and
 * all subsequent nodes from the heap.
 * </p>
 */
void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

/**
 * Prints the list.
 *
 * <p>
 * This method accepts a pointer to
 * the head of the singly linked list
 * and prints the contents of the
 * singly linked list node-by-node.
 * </p>
 *
 * @param head The head of the list.
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* node = head;
    while (node != nullptr) {
        cout << node->data << endl;
        node = node->next;
    }
}

int main() {
    SinglyLinkedList* llist = new SinglyLinkedList();
    
    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist->insert_node(llist_item);
    }
    
    printLinkedList(llist->head);
    
    return 0;
}
