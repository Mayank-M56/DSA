#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) { //Constructor that take parameter as data.
        data = value; 
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head; //For every new linked lists, have one head created initially.
    int size = 0;

public:
    LinkedList() { //Constructor
        head = NULL; //And that "head" is NULL initially.
    }

    void pushBack(int value) { //Take data to store in list.
        Node* newNode = new Node(value); //New pointer which DataType(Node) is created in heap. "newNode" got an address where a Node is created and stored data via constructor call.
        
        if(head == NULL) { //For newly created Linked List which "head" is NULL
            head = newNode; //"head" got recently created Node.
            size++;
            return; //That's it, now "head" has something to show.
        }

        Node* temp = head; //"temp" gets address that "head" has, because "temp" will use to travel Node to Node.
        while(temp->next != NULL) { //Since every "Node" object contains "data" and "next". "temp" has address where first "Node" exists with "data" and "next". So "temp->next" have some address or NULL, loop will execute till NULL hit.
            temp = temp->next; //If "temp->next" hasn't NULL, then update "temp", again "temp" gets another address of forward node.
        }
        temp->next = newNode; //Finally NULL hits, means "temp->next" is pointing to the last node of the Linked List which "next" has NULL. So it's time to add a "Node", "newNode"(an Address) should be assigned to "temp->next"(an Empty address).
    
        size++;
    }

    void pushFront(int value) { //Going to be a new "head".
        Node* newNode = new Node(value); //New "Node" creation.

        newNode->next = head; //Store previous "head" address into "next" of newly created "Node", now new "Node" connected to Linked List because it has address of next Node in its "next".
        head = newNode; //Need to declare new "head", since "newNode" is also an address and became first "Node" of Linked List, so this address must be "head".
    
        size++;
    }

    void popBack() {
        if(head == NULL) return; //Linked List is empty, nothing to pop.

        if(head->next == NULL) { //If Linked List has only one "Node".
            delete head; //Remember "head" is variable that has an address where next(or last) node exist. So need to free memory that is occupied in heap.
            head = NULL; //Then assign NULL for smooth functioning.
            size--;
            return; 
        }
        
        Node* temp = head; //If Linked List has more than one "Node". 
        while((temp->next)->next != NULL) { //Accessing second "Node" from the address of last "Node" because we need to pop last "Node", if we are at last "Node" then we won't get address to "delete" because last "Node" address was stored in its previous "next" of "Node".
            temp = temp->next;
        }
        delete temp->next; //Remember "temp->next" is an address where next node exist.
        temp->next = NULL;

        size--;
    }

    void popFront() {
        if(head == NULL) return;
        
        Node* temp = head;
        head = head->next;
        delete temp;

        size--;
    }

    void pushMiddle(int value, int location) {
    if(location > size+1 || location < 1) return; //Invalid call if given "location" is much more or less than "size".

    if(location == 1) { //Means insert "Node" at first position.
        pushFront(value);
        return;
    }

    if(location == size+1) { //Means insert "Node" at last position.
        pushBack(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;

    for(int i = 1; i < location-1; i++) { //Stop "temp" at one position before given "location".
        temp = temp->next; //Move "temp" to next "Node" using its "next" address.
    }

    newNode->next = temp->next; //New "Node" first gets address of current next "Node", so connection with remaining list doesn't break.
    temp->next = newNode; //Now previous "Node" points to new "Node", completing insertion.
    size++;
}

    void popMiddle(int location) {
        if(location > size || location < 1) return; //Invalid call if given "location" doesn't exist in current Linked List.

        if(location == 1) return popFront(); //Only because current and calling methods, both are "void".

        if(location == size) return popBack(); //If last "Node" needs to be removed, use already created "popBack()" method.

        Node* temp = head;

        for(int i = 1; i < location-1; i++) { //Stop "temp" at one position before the "Node" which needs to be removed.
            temp = temp->next;
        }

        Node* temp2 = temp->next; //"temp2" stores address of the "Node" which needs to be removed.
        temp->next = temp2->next; //Previous "Node" now points to next "Node", skipping the "Node" which needs to be removed.
        delete temp2; //Free memory of removed "Node" from heap.
        size--;
    }

    void printList() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
};

int main() {
    return 0;
}
