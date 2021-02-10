#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * A doubly-linked list node.
 *
 * <p>
 * The DoublyLinkedListNode class
 * provides a means for representing
 * a node in a doubly linked list.
 * </p>
 */
class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

/**
 * A doubly-linked list.
 *
 * <p>
 * The DoublyLinkedList class provides a
 * means for representing a doubly-linked list.
 * </p>
 */
class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

/**
 * Prints a doubly-linked list.
 *
 * <p>
 * This method accepts a doubly-linked list
 * node and a string representing a separator
 * to use. Upon the receipt of these inputs,
 * the method traverses the list from the
 * provided doubly-linked list node and
 * prints the value of each node to the
 * console for viewing.
 * </p>
 *
 * @param node The provided doubly-linked list node.
 * @param sep The provided separator.
 */
void print_doubly_linked_list(DoublyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
    cout << endl;
}

/**
 * Frees a doubly-linked list.
 *
 * <p>
 * This method accepts a pointer to a
 * doubly-linked list node as input and
 * traverses forward from that node to
 * deallocate the node and all subsequent
 * nodes from the heap.
 * </p>
 *
 * @param node The provided linked list node.
 */
void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

/**
 * Reverses a doubly linked list.
 *
 * <p>
 * This method accepts a node representing
 * the head of a doubly-linked list and reverses
 * the doubly linked list by swapping its previous
 * and next pointers. The produced result is the
 * head of the reversed doubly-linked list.
 * </p>
 *
 * @param head The head of the original list.
 *
 * @return The head of the reversed list.
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* reversed = head;

    // handle non-empty list
    if (reversed != nullptr) {

        // reverse previous and next pointers
        // O(n) time and O(1) space
        DoublyLinkedListNode* curr = reversed;
        DoublyLinkedListNode* next = nullptr;
        DoublyLinkedListNode* prev = nullptr;
        DoublyLinkedListNode* temp = nullptr;

        // traverse forward and swap pointers
        while (curr != nullptr) {

            // save previous and next
            prev = curr->prev;
            next = curr->next;

            // update current node
            curr->prev = next;
            curr->next = prev;

            // go to next node
            curr = next;
        }

        // rewind to head
        // O(n) time and O(1) space
        while (reversed != nullptr) {
            if (reversed->prev != nullptr) {
                reversed = reversed->prev;
            }
            else {
                break;
            }
        }
    }

    return reversed;
}

int main() {

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        DoublyLinkedListNode* llist1 = reverse(llist->head);

        print_doubly_linked_list(llist1, " ");

        free_doubly_linked_list(llist1);
    }

    return 0;
}
