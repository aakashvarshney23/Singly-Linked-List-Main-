#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
    node (int x): val(x), next(nullptr) {}

};

class MyLinkedList {
private:
    node *head;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *temp = new node(val);
        temp->next = head;
        head = temp;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (head == nullptr)
            addAtHead(val);
        else if (head != nullptr) {
            node *temp = new node(val);
            node *track = head;
            while (track->next != nullptr) {
                track = track->next;
            }
            track->next = temp;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list,
     * the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node *temp = new node(val);
        node *prev = head;
        node *next_node = head;
        if (index == 1)
            addAtHead(val);

        else if ((index == size()))
            addAtTail(val);

        else if (index > size()|| (index == 0))
            cout << "The node cannot be inserted because the index is too large" << endl;

        else {
            for (int i = 2; i < index; i++){
                prev = prev->next;
            }
            next_node = prev->next;
            prev->next = temp;
            temp->next = next_node;
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node *prev = head;
        node *next_node = head;
        if (index > size())
            cout << "Invalid";
        else if (index == 1)
            head = head->next;
        else if (index <= size()){
            for (int i =2; i < index; i++){
                prev = prev->next;
            }
            next_node = prev->next;
            prev->next = next_node->next;
        }

    }

    int size() {
        int count = 0;
        node *temp = head;
        do{
            count++;
            temp = temp->next;
        }
        while (temp != nullptr);
        return count;
    }

    void print(){
        node *temp = head;
        do{
            cout << temp->val << "->";
            temp = temp->next;
        }
        while (temp != nullptr);
    }
};


int main() {
    MyLinkedList a;
    a.addAtTail(1);
    a.addAtTail(2);
    a.addAtTail(3);
    a.addAtTail(4);
    a.addAtTail(5);
    a.addAtIndex(0, 18);
    a.deleteAtIndex(5);
    cout << "Size of the linked list is: " << a.size() << endl;
    a.print();
}