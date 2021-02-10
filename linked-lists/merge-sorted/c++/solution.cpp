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
 * Merges two sorted singly-linked lists.
 *
 * <p>
 * This method accepts two singly-linked list
 * nodes that are the heads of two sorted
 * singly-linked lists. Upon the receipt of
 * these inputs, the method merges the two
 * singly-linked list nodes into one singly-linked
 * list and returns the node that is the head of
 * the merged list.
 * </p>
 *
 * @param head1 The head to the first sorted list.
 * @param head2 The head to the second sorted list.
 *
 * @return The sorted singly-linked list.
 *
 * Complexity:
 * - O(n) time
 * - O(1) space
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    // initialize variables
    // O(1) time and O(1) space
    SinglyLinkedListNode* c1 = head1;
    SinglyLinkedListNode* c2 = head2;
    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* merged = nullptr;

    // finished status
    bool finished = false;

    // check both as null
    // O(1) time and O(1) space
    bool bothNull = c1 == nullptr && c2 == nullptr;

    // handle both as null
    // O(1) time and O(1) space
    if (bothNull) {
        head = nullptr;
        finished = true;
    }

    // handle one as null
    // O(1) time and O(1) space
    else if (c1 == nullptr) {
        head = c2;
        finished = true;
    }

    // handle one as null
    // O(1) time and O(1) space
    else if (c2 == nullptr) {
        head = c1;
        finished = true;
    }

    // handle both non-null
    // O(n) time and O(1) space
    else {

        while (!finished) {

            // handle null head
            if (head == nullptr) {
                if (c1->data <= c2->data) {
                    head = c1;
                    c1 = c1->next;
                }
                else {
                    head = c2;
                    c2 = c2->next;
                }
                merged = head;
            }

            // handle populated head
            else {

                // handle full merge
                if (c1 == nullptr && c2 == nullptr) {
                    finished = true;
                }

                // handle full merge
                else if (c1 != nullptr && c2 == nullptr) {
                    merged->next = c1;
                    c1 = c1->next;
                    finished = true;
                }

                // handle full merge
                else if (c1 == nullptr && c2 != nullptr) {
                    merged->next = c2;
                    c2 = c2->next;
                    finished = true;
                }

                // handle performing merge by data
                else {
                    if (c1->data <= c2->data) {
                        merged->next = c1;
                        c1 = c1->next;
                        merged = merged->next;
                    }
                    else {
                        merged->next = c2;
                        c2 = c2->next;
                        merged = merged->next;
                    }
                }
            }
        }
    }

    return head;
}

int main()
{

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
          SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ");
        cout << endl;

        free_singly_linked_list(llist3);
    }

    return 0;
}

