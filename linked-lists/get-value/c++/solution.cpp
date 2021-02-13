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
 * Gets the node at a given position.
 *
 * <p>
 * This method accepts a node representing the
 * head of a singly-linked list and a position from
 * the tail of the list. Upon the receipt of these
 * inputs, the method acquires the value at the
 * node in the specified position in the list.
 * </p>
 *
 * @param head The provided head of the list.
 * @param positionFromTail The provided position from the tail.
 *
 * @return The value of the node at the given tail position.
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {

    int data = 0;

    // get the list size
    // O(n) time and O(1) space
    int size = 0;
    SinglyLinkedListNode* c = head;
    while (c != nullptr) {
        size += 1;
        c = c->next;
    }

    // compute the tail position
    // O(n) time and O(1) space
    int count = 0;
    int position = (size - 1) - positionFromTail;
    c = head;
    while (c != nullptr) {
        if (count == position) {
            data = c->data;
            break;
        }
        c = c->next;
        count += 1;
    }

    return data;
}

int main()
{

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
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

        int result = getNode(llist->head, position);

        cout << result << endl;
    }

    return 0;
}
