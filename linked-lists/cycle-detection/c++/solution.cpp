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
 * Determines if a list has a cycle.
 *
 * <p>
 * This method accepts the head of a linked list
 * as input and determines whether the linked
 * list contains any cycles. There is a fast pointer
 * and a slow pointer, and if the two catch up to
 * each other then there is a cycle (because this
 * would be impossible if there were not a cycle).
 * </p>
 *
 * @param head The provided head of a linked list.
 *
 * @return True if there is a cycle; False otherwise
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
bool has_cycle(SinglyLinkedListNode* head) {

    // default status
    // O(1) time and O(1) space
    bool cycle = false;

    // maintain list tracking
    // O(1) time and O(1) space
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    // handle non-empty list
    if (head != nullptr) {

        // iterate through list
        // O(n) time and O(1) space
        while (fast != nullptr && fast->next != nullptr) {

            // update the slow pointer
            // O(1) time
            slow = slow->next;

            // update the fast pointer
            // O(1) time
            fast = fast->next->next;

            // check if cycle is present
            // O(1) time
            if (slow == fast) {
                cycle = true;
                break;
            }
        }
    }

    return cycle;
}

int main() {

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
      
        SinglyLinkedListNode* extra = new SinglyLinkedListNode(-1);
        SinglyLinkedListNode* temp = llist->head;
      
        for (int i = 0; i < llist_count; i++) {
            if (i == index) {
                extra = temp;
            }
            if (i != llist_count-1) {
                temp = temp->next;
            }
        }
      
        temp->next = extra;

        bool result = has_cycle(llist->head);

        cout << result << endl;
    }

    return 0;
}
