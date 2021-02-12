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
 * Inserts a node into a sorted doubly-linked list.
 *
 * <p>
 * This method accepts a node to the head of a
 * doubly-linked list and a data value for the node
 * to insert. Upon the receipt of these inputs, the
 * method inserts the new node into the doubly
 * linked list and returns the head of the modified
 * list as output.
 * </p>
 *
 * @param head The head of the doubly-linked list.
 * @param data The data of the node to insert.
 *
 * @return The head of the modified list.
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {

    // store inserted list
    DoublyLinkedListNode* inserted = head;
    DoublyLinkedListNode* toInsert = new DoublyLinkedListNode(data);

    // handle empty list
    if (inserted == nullptr) {
        inserted = toInsert;
    }

    // handle non-empty list
    else {

        // indicate if insertion occurred
        bool alreadyInserted = false;

        // iterate through list
        // O(n) time and O(1) space
        while (inserted != nullptr) {

            // handle insertion
            if (inserted->data >= data) {

                // handle insertion between nodes
                if (inserted->prev != nullptr) {
                    DoublyLinkedListNode* prev = inserted->prev;
                    inserted->prev->next = toInsert;
                    inserted->prev = toInsert;
                    toInsert->next = inserted;
                    toInsert->prev = prev;
                }

                // handle insertion before first node
                else {
                    inserted->prev = toInsert;
                    toInsert->next = inserted;
                }

                // update insertion status
                alreadyInserted = true;
            }

            // handle full traversal without insertion
            if (inserted->next == nullptr && !alreadyInserted) {
                inserted->next = toInsert;
                toInsert->prev = inserted;
                alreadyInserted = true;
            }

            // handle insertion (rewind to head)
            if (alreadyInserted) {
                while (inserted != nullptr) {
                    if (inserted->prev != nullptr) {
                        inserted = inserted->prev;
                    }
                    else {
                        break;
                    }
                }
                break;
            }

            // update list pointer
            inserted = inserted->next;
        }
    }

    return inserted;
}

int main()
{

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

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ");
        cout << endl;

        free_doubly_linked_list(llist1);
    }

    return 0;
}
