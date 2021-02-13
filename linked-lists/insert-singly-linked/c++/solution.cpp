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
 * Inserts a node at a position.
 *
 * <p>
 * This method accepts the head of a singly-linked
 * list, the data for a node to insert, and the position
 * at which to insert the node. Upon the receipt of
 * these inputs, the method inserts the node with
 * the indicated data at the position in the singly
 * linked list. The head of the modified singly-linked
 * list is returned as output.
 * </p>
 *
 * @param head The provide head of the linked list.
 * @param data The data of the node to insert.
 * @param position The position at which to insert.
 *
 * @return The head of the modified list.
 *
 * Complexity:
 * - O(n) time
 * - O(1) time
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {

    // the node to insert
    SinglyLinkedListNode* insert = new SinglyLinkedListNode(data);

    // handle empty list
    if (head == nullptr) {
        head = insert;
    }

    // handle non-empty list
    else {
        int count = 1;
        bool inserted = false;
        SinglyLinkedListNode* current = head;
        SinglyLinkedListNode* previous = head;

        // iterate through list
        while (current->next != nullptr) {

            // update tracking
            previous = current;
            current = current->next;

            // handle at position
            if (count == position) {
                previous->next = insert;
                insert->next = current;
                inserted = true;
                break;
            }

            // update position
            count += 1;
        }

        // handle insert one node (head)
        if (!inserted && count == 0) {
            insert->next = head;
        }

        // handle insert one node (tail)
        if (!inserted && count > 0) {
            current->next = insert;
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

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ");
    cout << endl;

    free_singly_linked_list(llist_head);

    return 0;
}
