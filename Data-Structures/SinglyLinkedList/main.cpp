#include <iostream>
#include <stdio.h>

struct Node{
    int data;
    Node *next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node *Head = nullptr;

    LinkedList(int x) {
        this->Head = new Node(x);
    }

    void addHead(int x) {
        Node *temp = new Node(x);
        temp->next = Head;
        Head = temp;
    }

    void addTail(int x) {
        Node *temp = Head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(x);
    }

    void printNode() {
        Node *temp = Head;
        while (temp != nullptr) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    void deleteNode(int x) {
        Node *temp = Head;
        if (temp == nullptr) return;
        while (temp != nullptr) {
            if (temp->next == nullptr ) {
                printf("\n**There is no such element \"%d\" in the linked list**\n",x);
                return;
            }
            if (temp->next->data == x) break;
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
};

int main() {
    LinkedList list = LinkedList(1);
    list.addHead(1);
    list.addHead(2);
    list.addHead(3);
    list.addHead(4);

    list.addTail(5);
    list.addTail(6);
    list.addTail(7);
    list.addTail(8);
    list.addTail(9);

    list.deleteNode(1);
    list.deleteNode(2);
    list.deleteNode(7);
    list.deleteNode(10);
    list.printNode();

    // The output wil be
    // **There is no such element "10" in the linked list**
    // ->4->3->1->5->6->8->9
    // This is the all functions and usages of singly linked list


}