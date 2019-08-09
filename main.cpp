#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;

    node(int x) : val(x), next(nullptr) {}

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
        node *temp = head;
        if (temp != nullptr) {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
        }
        return temp->val;
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

        else if (index > size() || (index == 0))
            cout << "The node cannot be inserted because the index is too large" << endl;

        else {
            for (int i = 2; i < index; i++) {
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
        else if (index <= size()) {
            for (int i = 2; i < index; i++) {
                prev = prev->next;
            }
            next_node = prev->next;
            prev->next = next_node->next;
        }

    }

    // Shows the updated size of the linked list
    int size() {
        int count = 0;
        node *temp = head;
        if (temp == nullptr)
            return count;
        else {
            do {
                count++;
                temp = temp->next;
            } while (temp != nullptr);
        }
        return count;
    }

    // Prints the linked list with the arrows.
    void print() {
        node *temp = head;
        if (temp == nullptr)
            cout << "Empty list";
        else {

            do {

                cout << temp->val << "->";
                temp = temp->next;
            } while (temp != nullptr);
        }
        cout << "\n";
    }

    // Reverse a given singly linked list
    void reverse_linked_list() {
        node *temp = head;
        node *next = nullptr;
        node *prev = nullptr;
        while (temp != nullptr) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
    }

    // merge two sorted linked lists
    // The error here is that it terminates before reaching the null pointer. One of the element is left out.
    MyLinkedList mergeTwoLinkedList(MyLinkedList b) {
        MyLinkedList c;

        node *tempa = this->head;
        node *tempb = b.head;

        if (b.head == nullptr)
            return *this;
        if (this->head == nullptr)
            return b;

        if (tempa && tempb) {
            while (tempa && tempb)
                if ((tempa->val) <= (tempb->val)) {
                    c.addAtTail(tempa->val);
                    tempa = tempa->next;

                } else if ((tempa->val) >= (tempb->val)) {
                    c.addAtTail(tempb->val);
                    tempb = tempb->next;
                }
            while (tempa != nullptr)
            {
                c.addAtTail(tempa->val);
                tempa = tempa->next;
            }
            while (tempb != nullptr){
                c.addAtTail(tempb->val);
                tempb = tempb->next;
            }
            return c;
        }
    }
};


int main() {
    MyLinkedList a;
    MyLinkedList b;
    MyLinkedList c;
    a.addAtTail(1);
    a.addAtTail(21);
    a.addAtTail(31);
    a.addAtTail(40);
    a.addAtTail(50);
    a.addAtTail(61);
    b.addAtTail(17);
    b.addAtTail(81);
    b.addAtTail(82);
    b.addAtTail(83);
    b.addAtTail(84);
    a.print();
    b.print();
    cout << "A Size :" << a.size() << endl;
    cout << "B Size :" << b.size() << endl;
    c = b.mergeTwoLinkedList(a);
    c.print();
    cout << "C Size: " << c.size() << endl;

}