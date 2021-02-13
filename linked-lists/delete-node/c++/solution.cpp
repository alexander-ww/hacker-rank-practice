#include <cstdlib>
#include <iostream>

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
        SinglyLinkedListNode *next;

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
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

/**
 * Prints a singly linked list.
 *
 * <p>
 * This method accepts a singly linked list
 * node and a string representing a separator
 * to use. Upon the receipt of these inputs,
 * the method traverses the list from the provided
 * linked list node and prints the value of each
 * node to the console for viewing.
 * </p>
 *
 * @param node The provided linked list node.
 * @param sep The provided separator.
 */
void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;
        node = node->next;
        if (node) {
            cout << sep;
        }
    }
}

/**
 * Frees a linked list.
 *
 * <p>
 * This method accepts a pointer to a
 * singly linked list node as input and
 * traverses forward from that node to
 * deallocate the node and all subsequent
 * nodes from the heap.
 * </p>
 *
 * @param node The provided linked list node.
 */
void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

/**
 * Deletes a node.
 *
 * <p>
 * This method accepts a node representing the
 * head of a linked list and an integer representing
 * the index of the node that is to be removed.
 * Upon the receipt of these inputs, the method
 * iterates through the linked list and removes the
 * node at the position specified. The head of the
 * modified list is then returned.
 * </p>
 *
 * @param head The head of the linked list.
 * @param position The index of the node to remove.
 *
 * @return The head of the modified linked list.
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    // handle non-empty list
    if (head != nullptr) {

        // iterate through nodes
        int count = 0;
        SinglyLinkedListNode* previous = head;
        SinglyLinkedListNode* current = head;

        while (current != nullptr) {

            // handle position
            if (count == position) {

                // handle first node
                if (count == 0) {
                    head = current->next;
                }

                // handle last node
                else if (current->next == nullptr) {
                    previous->next = nullptr;
                }

                // handle in between nodes
                else {
                    previous->next = current->next;
                }
            }

            // update tracking
            previous = current;
            current = current->next;
            count += 1;
        }
    }

    return head;
}

int main()
{

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

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);

    print_singly_linked_list(llist1, " ");
    cout << endl;

    free_singly_linked_list(llist1);

    return 0;
}
