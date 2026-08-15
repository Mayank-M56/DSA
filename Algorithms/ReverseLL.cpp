/*
Time Complexity : O(n)
Space Complexity : O(1)

Reverse Linked List : Iterative Approach

    Observation :
        -Every "Node" stores address of its next "Node".
        -To reverse the Linked List, direction of every "next" connection needs to be changed.
        -Changing "curr->next" directly will lose address of next "Node", thus three pointers are required.

    Approach :
        -Use "prev", "curr" and "nex" pointers.
        -Initially "prev" is NULL because first "Node" will become the last "Node".
        -Save next "Node" using "nex" before breaking current connection.
        -Make current "Node" point towards previous "Node".
        -Move "prev" and "curr" forward and repeat until "curr" becomes NULL.
        -Eventually "prev" points to the new head of the reversed Linked List.
*/
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* reverseLL(Node* head);

void printLL(Node* head);

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original Linked List : ";
    printLL(head);

    head = reverseLL(head);

    cout << "\nReversed Linked List : ";
    printLL(head);

    return 0;
}

Node* reverseLL(Node* head) {
    Node* prev = NULL; //Initially nothing exists before "head", thus "prev" is NULL.
    Node* curr = head; //Start from "head", because reversal begins from first "Node".
    Node* nex = NULL; //Will temporarily store address of next "Node" before breaking current connection.

    while(curr != NULL) { //Continue until every "Node" is reversed and "curr" reaches NULL.
        nex = curr->next; //Save address of next "Node", otherwise it will be lost after reversing current "Node".
        curr->next = prev; //Reverse current "Node" by making it point towards previous "Node".
        prev = curr; //Move "prev" forward, because current "Node" is now part of reversed Linked List.
        curr = nex; //Move "curr" forward using previously saved address to continue reversal.
    }

    return prev; //"prev" is now pointing at the last "Node" of original Linked List, which becomes new "head".
}

void printLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";
}
