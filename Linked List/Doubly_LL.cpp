#include<iostream>
using namespace std;

/*
Time Complexity :
    pushFront()  : O(1)
    pushMiddle() : O(n)
    pushBack()   : O(1)
    popFront()   : O(1)
    popMiddle()  : O(n)
    popBack()    : O(1)
    display()    : O(n)

Space Complexity : O(n) //For storing "Node"s.
*/

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class DoublyLL {
private:
    Node* head;
    Node* tail;
    int size = 0;

public:
    DoublyLL() {
        head = tail = NULL;
    }

    void pushFront(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) head = tail = newNode; //If List is empty, new "Node" becomes both "head" and "tail".
        else {
            head->prev = newNode; //Current "head" should point back to new "Node".
            newNode->next = head; //New "Node" should point towards current "head".
            head = newNode; //Move "head" to new "Node".
        }

        size++; //One new "Node" is added.
    }

    void pushMiddle(int value, int location) {
        if(location < 1 || location > size+1) return; //Valid locations are from 1 to size+1 because new "Node" can be inserted at last position also.

        if(location == 1) pushFront(value); //If location is 1, new "Node" becomes first "Node".
        else if(location == size+1) pushBack(value); //If location is size+1, new "Node" becomes last "Node".
        else {
            Node* newNode = new Node(value);
            Node* temp = head;

            for(int i = 1; i < location-1; i++) { //Move "temp" to the "Node" just before the required location.
                temp = temp->next;
            }

            newNode->next = temp->next; //New "Node" points towards next "Node".
            newNode->prev = temp; //New "Node" points back towards previous "Node".
            (temp->next)->prev = newNode; //Next "Node" now points back towards new "Node".
            temp->next = newNode; //Previous "Node" now points towards new "Node".

            size++; //One new "Node" is added.
        }
    }

    void pushBack(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) head = tail = newNode; //If List is empty, new "Node" becomes both "head" and "tail".
        else {
            tail->next = newNode; //Current "tail" points towards new "Node".
            newNode->prev = tail; //New "Node" points back towards current "tail".
            tail = newNode; //Move "tail" to new "Node".
        }

        size++; //One new "Node" is added.
    }

    void popFront() {
        if(head == NULL) {
            cout << "List is already empty.\n";
            return;
        } else if(size == 1) {
            delete head; //Delete the only "Node".
            head = tail = NULL; //List is now empty, so both "head" and "tail" point to NULL.
            size--;
        } else {
            Node* temp = head;
            head = head->next; //Move "head" to second "Node".
            head->prev = NULL; //New "head" should not point to deleted "Node".
            delete temp; //Delete old "head".

            size--; //One "Node" is removed.
        }
    }

    void popMiddle(int location) {
        if(location < 1 || location > size) return; //Location must contain an existing "Node".

        if(location == 1) return popFront(); //If first "Node" is required, use popFront().
        if(location == size) return popBack(); //If last "Node" is required, use popBack().

        Node* temp = head;

        for(int i = 1; i < location; i++) { //Move "temp" to the "Node" which needs to be deleted.
            temp = temp->next;
        }

        temp->next->prev = temp->prev; //Next "Node" now points back to previous "Node".
        temp->prev->next = temp->next; //Previous "Node" now points towards next "Node".
        delete temp; //Delete the required "Node".

        size--; //One "Node" is removed.
    }

    void popBack() {
        if(head == NULL) {
            cout << "List is already empty.\n";
            return;
        } else if(size == 1) {
            delete head; //Delete the only "Node".
            head = tail = NULL; //List is now empty.
            size--;
            return;
        } else {
            Node* temp = tail;
            tail = tail->prev; //Move "tail" to previous "Node".
            tail->next = NULL; //New "tail" should not point to deleted "Node".
            delete temp; //Delete old "tail".

            size--; //One "Node" is removed.
        }
    }

    void display() {
        Node* temp = head;

        cout << "Data in LL : ";

        while(temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next; //Move towards next "Node".
        }

        cout << "NULL\n";
    }
};


int main() {
    int input;
    DoublyLL list;

    do {
        cout << "Select the Option : \n";
        cout << "\t1. Display List\n\t2. Push Front\n\t3. Push Middle\n\t4. Push Back\n\t5. Pop Front\n\t6. Pop Middle\n\t7. Pop Back\n\t8. Exit";
        cout << "\nEnter : ";

        cin >> input;

        int data;
        int location;

        switch(input) {
            case 1:
                list.display();
                break;

            case 2:
                cout << "Enter data to be stored : ";
                cin >> data;
                list.pushFront(data);
                break;

            case 3:
                cout << "Enter data to be stored : ";
                cin >> data;

                cout << "At what Location : ";
                cin >> location;

                list.pushMiddle(data, location);
                break;

            case 4:
                cout << "Enter data to be stored : ";
                cin >> data;
                list.pushBack(data);
                break;

            case 5:
                list.popFront();
                break;

            case 6:
                cout << "At what Location : ";
                cin >> location;

                list.popMiddle(location);
                break;

            case 7:
                list.popBack();
                break;
        }

        cout << "___________________________\n";

    } while(input != 8);

    return 0;
}
