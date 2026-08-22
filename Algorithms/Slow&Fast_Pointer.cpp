/*
Time Complexity : O(n)
Space Complexity : O(1)

Find Middle Node of Linked List : Slow & Fast Pointer

    Observation :
        -Two pointers can traverse the same Linked List at different speeds.
        -"slow" moves one "Node" at a time, while "fast" moves two "Node" at a time.
        -Thus when "fast" reaches the end, "slow" will be at the middle.

    Approach :
        -Start both "slow" and "fast" from "head".
        -Move "slow" by one "Node" and "fast" by two "Node" in every iteration.
        -Continue until "fast" reaches NULL or its next "Node" becomes NULL.
        -At that moment, "slow" points to the middle "Node".
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

Node* middleNode(Node* head);
void printLL(Node* head);

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);
    head->next->next->next->next->next->next->next = new Node(80);
    head->next->next->next->next->next->next->next->next = new Node(90);

    cout << "Original LL : ";
    printLL(head);
    
    Node* Middle = middleNode(head);
    cout << "\nMiddle Node : " << Middle->data;

    return 0;
}

Node* middleNode(Node* head) {
    Node* slow = head; //Starts from "head" and moves one "Node" at a time.
    Node* fast = head; //Starts from "head" and moves two "Node" at a time.

    while(fast != NULL && fast->next != NULL) { //Continue while "fast" can safely move two "Node" forward.
        slow = slow->next; //Move "slow" one "Node" forward.
        fast = fast->next->next; //Move "fast" two "Node" forward.
    }

    return slow; //"fast" reached the end, so "slow" is now pointing to the middle "Node".
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}
