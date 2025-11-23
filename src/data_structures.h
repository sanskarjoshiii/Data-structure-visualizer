#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include "crow.h"

// Forward declarations
struct StackNode;

// ==================== ARRAY ====================
class Array {
private:
    std::vector<int> arr;
    static const int MAX_SIZE = 1000;
    
public:
    Array();
    ~Array();
    
    bool insert(int value, int position);
    bool deleteAt(int position);
    bool deleteByValue(int value);
    int linearSearch(int value);
    int binarySearch(int value);
    std::vector<int> traverse();
    bool update(int position, int newValue);
    crow::json::wvalue toJSON();
    void clear();
    int size();
    bool isEmpty();
    bool isFull();
};

// ==================== STACK (ARRAY) ====================
class StackArray {
private:
    int* stack;
    int top;
    int capacity;
    static const int DEFAULT_CAPACITY = 100;
    
public:
    StackArray(int cap = DEFAULT_CAPACITY);
    ~StackArray();
    
    bool push(int value);
    bool pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int getSize();
    crow::json::wvalue toJSON();
    void clear();
    
    // Applications
    static bool checkParentheses(const std::string& expression);
    static std::string reverseString(const std::string& str);
};

// ==================== STACK (LINKED LIST) ====================
class StackLinkedList {
private:
    StackNode* top;
    
public:
    StackLinkedList();
    ~StackLinkedList();
    
    void push(int value);
    bool pop();
    int peek();
    bool isEmpty();
    int getSize();
    crow::json::wvalue toJSON();
    void clear();
    
    // Applications
    static bool checkParentheses(const std::string& expression);
    static std::string reverseString(const std::string& str);
};

// ==================== QUEUE (NORMAL) ====================
class Queue {
private:
    int* queue;
    int front;
    int rear;
    int capacity;
    static const int DEFAULT_CAPACITY = 100;
    
public:
    Queue(int cap = DEFAULT_CAPACITY);
    ~Queue();
    
    bool enqueue(int value);
    bool dequeue();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
    int getSize();
    crow::json::wvalue toJSON();
    void clear();
};

// ==================== CIRCULAR QUEUE ====================
class CircularQueue {
private:
    int* queue;
    int front;
    int rear;
    int capacity;
    static const int DEFAULT_CAPACITY = 100;
    
public:
    CircularQueue(int cap = DEFAULT_CAPACITY);
    ~CircularQueue();
    
    bool enqueue(int value);
    bool dequeue();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
    int getSize();
    crow::json::wvalue toJSON();
    void clear();
};

// ==================== DEQUE (DOUBLE-ENDED QUEUE) ====================
class Deque {
private:
    int* deque;
    int front;
    int rear;
    int capacity;
    static const int DEFAULT_CAPACITY = 100;
    
public:
    Deque(int cap = DEFAULT_CAPACITY);
    ~Deque();
    
    bool pushFront(int value);
    bool pushRear(int value);
    bool popFront();
    bool popRear();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
    int getSize();
    crow::json::wvalue toJSON();
    void clear();
};

// ==================== PRIORITY QUEUE ====================
struct PriorityNode {
    int data;
    int priority;
    PriorityNode(int d, int p) : data(d), priority(p) {}
    bool operator<(const PriorityNode& other) const {
        return priority < other.priority; // Lower priority number = higher priority
    }
};

class PriorityQueue {
private:
    std::vector<PriorityNode> heap;
    
    void heapifyUp(int index);
    void heapifyDown(int index);
    
public:
    PriorityQueue();
    ~PriorityQueue();
    
    void enqueue(int value, int priority);
    bool dequeue();
    int peek();
    bool isEmpty();
    int getSize();
    crow::json::wvalue toJSON();
    void clear();
};

// Stack Node structure
struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val) : data(val), next(nullptr) {}
};

#endif

