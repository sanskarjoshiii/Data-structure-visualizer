#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>
#include <string>
#include "crow.h"

// Node structure for singly linked list
struct SinglyNode {
    int data;
    SinglyNode* next;
    SinglyNode(int val) : data(val), next(nullptr) {}
};

// Node structure for doubly linked list
struct DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Singly Linked List Class
class SinglyLinkedList {
private:
    SinglyNode* head;
    
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);
    bool deleteAtBeginning();
    bool deleteAtEnd();
    bool deleteAtPosition(int position);
    bool deleteByValue(int value);
    bool update(int oldValue, int newValue);
    bool search(int value);
    void reverse();
    crow::json::wvalue toJSON();
    void clear();
    int size();
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;
    
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);
    bool deleteAtBeginning();
    bool deleteAtEnd();
    bool deleteAtPosition(int position);
    bool deleteByValue(int value);
    bool update(int oldValue, int newValue);
    bool search(int value);
    void reverse();
    crow::json::wvalue toJSON();
    void clear();
    int size();
};

// Circular Linked List Class
class CircularLinkedList {
private:
    SinglyNode* head;
    
public:
    CircularLinkedList();
    ~CircularLinkedList();
    
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);
    bool deleteAtBeginning();
    bool deleteAtEnd();
    bool deleteAtPosition(int position);
    bool deleteByValue(int value);
    bool update(int oldValue, int newValue);
    bool search(int value);
    void reverse();
    crow::json::wvalue toJSON();
    void clear();
    int size();
};

#endif