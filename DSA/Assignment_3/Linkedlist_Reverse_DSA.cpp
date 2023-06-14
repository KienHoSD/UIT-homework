/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

//###INSERT CODE HERE -
void insert_node(SinglyLinkedList* list, int node_data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

    if (!list->head) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Print linked list
void printLinkedList(SinglyLinkedList* list) {
    SinglyLinkedListNode* curr = list->head;
    while (curr != NULL) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
}

// Reverse linked list
SinglyLinkedListNode* reverseLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = llist->head;
    SinglyLinkedListNode* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    llist->tail = llist->head;
    llist->head = prev;
    return llist->head;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }


    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
