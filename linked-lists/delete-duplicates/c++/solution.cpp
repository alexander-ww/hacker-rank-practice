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
 * Removes duplicates.
 *
 * <p>
 * This method accepts a linked list node
 * representing the head of a linked list and
 * removes all duplicates from the linked list.
 * </p>
 *
 * @param head The head of the linked list.
 *
 * @return The head of the list with duplicates removed.
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {

    // revise list
    SinglyLinkedListNode* revisedHead = nullptr;
    SinglyLinkedListNode* revised = nullptr;

    // handle empty list
    if (head == nullptr) {
        revisedHead = head;
    }

    // handle non-empty list
    else {

        // iterate through list
        // O(n) time and O(1) space
        int previous = -1;
        SinglyLinkedListNode* current = head;
        while (current != nullptr) {
            if (current->data != previous) {
                if (revised == nullptr) {
                    revised = current;
                    revisedHead = revised;
                }
                else {
                    revised->next = current;
                    revised = revised->next;
                }
            }
            else {
                if (current->next == nullptr) {
                    revised->next = nullptr;
                    revised = revised->next;
                }
            }
            previous = current->data;
            current = current->next;
        }
    }

    return revisedHead;
}

int main()
{

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        SinglyLinkedListNode* llist1 = removeDuplicates(llist->head);

        print_singly_linked_list(llist1, " ");
        cout << endl;

        free_singly_linked_list(llist1);
    }

    return 0;
}
