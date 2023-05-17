#include <iostream>

// Node class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Method to add a node at the end of the linked list
    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Iterator class for iterating through the linked list
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* start) : current(start) {}

        int operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main() {
    LinkedList myList;
    myList.addNode(10);
    myList.addNode(20);
    myList.addNode(30);

    // Iterate over the linked list using the iterator
    for (const auto& item : myList) {
        std::cout << item << " ";
    }

    return 0;
}
