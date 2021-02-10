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

        SinglyLinkedList() {
            this->head = nullptr;
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
 * Inserts a node at the tail of a list.
 *
 * <p>
 * This method accepts a node representing the
 * head of a linked list and a value for the data of
 * a new node to add to the end of the linked list.
 * Upon the receipt of these inputs, the method
 * adds the new node to the end of the linked list.
 * </p>
 *
 * @param head The provided linked list node.
 * @param data The provided data for the node to insert.
 *
 * @return The head of the modified linked list.
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

    // create last node
    SinglyLinkedListNode* last = new SinglyLinkedListNode(data);

    // handle empty list
    if (head == nullptr) {
        head = last;
    }

    // handle non-empty list
    else {

        // create a current node
        SinglyLinkedListNode* current = head;

        // navigate to the last node
        while (current->next != nullptr) {
            current = current->next;
        }

        // add the last node
        current->next = last;
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
    
      	SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head, "\n");
    cout << "\n";

    free_singly_linked_list(llist->head);

    return 0;
}
