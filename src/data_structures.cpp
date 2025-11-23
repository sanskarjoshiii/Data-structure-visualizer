#include "data_structures.h"
#include <algorithm>
#include <cmath>

// ==================== ARRAY ====================

Array::Array() {}

Array::~Array() {
    clear();
}

bool Array::insert(int value, int position) {
    if (position < 0 || position > (int)arr.size() || arr.size() >= MAX_SIZE) {
        return false;
    }
    arr.insert(arr.begin() + position, value);
    return true;
}

bool Array::deleteAt(int position) {
    if (position < 0 || position >= (int)arr.size()) {
        return false;
    }
    arr.erase(arr.begin() + position);
    return true;
}

bool Array::deleteByValue(int value) {
    auto it = std::find(arr.begin(), arr.end(), value);
    if (it != arr.end()) {
        arr.erase(it);
        return true;
    }
    return false;
}

int Array::linearSearch(int value) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == value) {
            return (int)i;
        }
    }
    return -1;
}

int Array::binarySearch(int value) {
    if (arr.empty()) return -1;
    
    // Array must be sorted for binary search
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());
    
    int left = 0, right = (int)sortedArr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedArr[mid] == value) {
            // Find original position
            for (size_t i = 0; i < arr.size(); i++) {
                if (arr[i] == value) return (int)i;
            }
            return mid;
        } else if (sortedArr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

std::vector<int> Array::traverse() {
    return arr;
}

bool Array::update(int position, int newValue) {
    if (position < 0 || position >= (int)arr.size()) {
        return false;
    }
    arr[position] = newValue;
    return true;
}

crow::json::wvalue Array::toJSON() {
    crow::json::wvalue result;
    result["type"] = "array";
    result["values"] = arr;
    result["size"] = (int)arr.size();
    return result;
}

void Array::clear() {
    arr.clear();
}

int Array::size() {
    return (int)arr.size();
}

bool Array::isEmpty() {
    return arr.empty();
}

bool Array::isFull() {
    return arr.size() >= MAX_SIZE;
}

// ==================== STACK (ARRAY) ====================

StackArray::StackArray(int cap) : capacity(cap), top(-1) {
    stack = new int[capacity];
}

StackArray::~StackArray() {
    delete[] stack;
}

bool StackArray::push(int value) {
    if (isFull()) return false;
    stack[++top] = value;
    return true;
}

bool StackArray::pop() {
    if (isEmpty()) return false;
    top--;
    return true;
}

int StackArray::peek() {
    if (isEmpty()) return -1;
    return stack[top];
}

bool StackArray::isEmpty() {
    return top == -1;
}

bool StackArray::isFull() {
    return top >= capacity - 1;
}

int StackArray::getSize() {
    return top + 1;
}

crow::json::wvalue StackArray::toJSON() {
    crow::json::wvalue result;
    result["type"] = "stack_array";
    std::vector<int> values;
    for (int i = 0; i <= top; i++) {
        values.push_back(stack[i]);
    }
    result["values"] = values;
    result["size"] = top + 1;
    result["top"] = top;
    return result;
}

void StackArray::clear() {
    top = -1;
}

bool StackArray::checkParentheses(const std::string& expression) {
    StackArray stack(expression.length());
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) return false;
            char top = stack.peek();
            if ((c == ')' && top == '(') || 
                (c == ']' && top == '[') || 
                (c == '}' && top == '{')) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

std::string StackArray::reverseString(const std::string& str) {
    StackArray stack(str.length());
    for (char c : str) {
        stack.push(c);
    }
    std::string result;
    while (!stack.isEmpty()) {
        result += (char)stack.peek();
        stack.pop();
    }
    return result;
}

// ==================== STACK (LINKED LIST) ====================

StackLinkedList::StackLinkedList() : top(nullptr) {}

StackLinkedList::~StackLinkedList() {
    clear();
}

void StackLinkedList::push(int value) {
    StackNode* newNode = new StackNode(value);
    newNode->next = top;
    top = newNode;
}

bool StackLinkedList::pop() {
    if (isEmpty()) return false;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return true;
}

int StackLinkedList::peek() {
    if (isEmpty()) return -1;
    return top->data;
}

bool StackLinkedList::isEmpty() {
    return top == nullptr;
}

int StackLinkedList::getSize() {
    int count = 0;
    StackNode* temp = top;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

crow::json::wvalue StackLinkedList::toJSON() {
    crow::json::wvalue result;
    result["type"] = "stack_linkedlist";
    std::vector<int> values;
    StackNode* temp = top;
    while (temp) {
        values.push_back(temp->data);
        temp = temp->next;
    }
    result["values"] = values;
    result["size"] = (int)values.size();
    return result;
}

void StackLinkedList::clear() {
    while (top) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

bool StackLinkedList::checkParentheses(const std::string& expression) {
    StackLinkedList stack;
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) return false;
            char top = stack.peek();
            if ((c == ')' && top == '(') || 
                (c == ']' && top == '[') || 
                (c == '}' && top == '{')) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

std::string StackLinkedList::reverseString(const std::string& str) {
    StackLinkedList stack;
    for (char c : str) {
        stack.push(c);
    }
    std::string result;
    while (!stack.isEmpty()) {
        result += (char)stack.peek();
        stack.pop();
    }
    return result;
}

// ==================== QUEUE (NORMAL) ====================

Queue::Queue(int cap) : capacity(cap), front(-1), rear(-1) {
    queue = new int[capacity];
}

Queue::~Queue() {
    delete[] queue;
}

bool Queue::enqueue(int value) {
    if (isFull()) return false;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    return true;
}

bool Queue::dequeue() {
    if (isEmpty()) return false;
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return true;
}

int Queue::getFront() {
    if (isEmpty()) return -1;
    return queue[front];
}

int Queue::getRear() {
    if (isEmpty()) return -1;
    return queue[rear];
}

bool Queue::isEmpty() {
    return front == -1;
}

bool Queue::isFull() {
    return rear >= capacity - 1;
}

int Queue::getSize() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

crow::json::wvalue Queue::toJSON() {
    crow::json::wvalue result;
    result["type"] = "queue";
    std::vector<int> values;
    if (!isEmpty()) {
        for (int i = front; i <= rear; i++) {
            values.push_back(queue[i]);
        }
    }
    result["values"] = values;
    result["size"] = getSize();
    result["front"] = front;
    result["rear"] = rear;
    return result;
}

void Queue::clear() {
    front = rear = -1;
}

// ==================== CIRCULAR QUEUE ====================

CircularQueue::CircularQueue(int cap) : capacity(cap), front(-1), rear(-1) {
    queue = new int[capacity];
}

CircularQueue::~CircularQueue() {
    delete[] queue;
}

bool CircularQueue::enqueue(int value) {
    if (isFull()) return false;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }
    queue[rear] = value;
    return true;
}

bool CircularQueue::dequeue() {
    if (isEmpty()) return false;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    return true;
}

int CircularQueue::getFront() {
    if (isEmpty()) return -1;
    return queue[front];
}

int CircularQueue::getRear() {
    if (isEmpty()) return -1;
    return queue[rear];
}

bool CircularQueue::isEmpty() {
    return front == -1;
}

bool CircularQueue::isFull() {
    return (rear + 1) % capacity == front;
}

int CircularQueue::getSize() {
    if (isEmpty()) return 0;
    if (rear >= front) {
        return rear - front + 1;
    } else {
        return capacity - front + rear + 1;
    }
}

crow::json::wvalue CircularQueue::toJSON() {
    crow::json::wvalue result;
    result["type"] = "circular_queue";
    std::vector<int> values;
    if (!isEmpty()) {
        int i = front;
        do {
            values.push_back(queue[i]);
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
    }
    result["values"] = values;
    result["size"] = getSize();
    result["front"] = front;
    result["rear"] = rear;
    return result;
}

void CircularQueue::clear() {
    front = rear = -1;
}

// ==================== DEQUE ====================

Deque::Deque(int cap) : capacity(cap), front(-1), rear(-1) {
    deque = new int[capacity];
}

Deque::~Deque() {
    delete[] deque;
}

bool Deque::pushFront(int value) {
    if (isFull()) return false;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + capacity) % capacity;
    }
    deque[front] = value;
    return true;
}

bool Deque::pushRear(int value) {
    if (isFull()) return false;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }
    deque[rear] = value;
    return true;
}

bool Deque::popFront() {
    if (isEmpty()) return false;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    return true;
}

bool Deque::popRear() {
    if (isEmpty()) return false;
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + capacity) % capacity;
    }
    return true;
}

int Deque::getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

int Deque::getRear() {
    if (isEmpty()) return -1;
    return deque[rear];
}

bool Deque::isEmpty() {
    return front == -1;
}

bool Deque::isFull() {
    return (rear + 1) % capacity == front;
}

int Deque::getSize() {
    if (isEmpty()) return 0;
    if (rear >= front) {
        return rear - front + 1;
    } else {
        return capacity - front + rear + 1;
    }
}

crow::json::wvalue Deque::toJSON() {
    crow::json::wvalue result;
    result["type"] = "deque";
    std::vector<int> values;
    if (!isEmpty()) {
        int i = front;
        do {
            values.push_back(deque[i]);
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
    }
    result["values"] = values;
    result["size"] = getSize();
    result["front"] = front;
    result["rear"] = rear;
    return result;
}

void Deque::clear() {
    front = rear = -1;
}

// ==================== PRIORITY QUEUE ====================

PriorityQueue::PriorityQueue() {}

PriorityQueue::~PriorityQueue() {
    clear();
}

void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            std::swap(heap[parent], heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(int index) {
    int size = heap.size();
    while (true) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < size && heap[largest] < heap[left]) {
            largest = left;
        }
        if (right < size && heap[largest] < heap[right]) {
            largest = right;
        }
        
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void PriorityQueue::enqueue(int value, int priority) {
    heap.push_back(PriorityNode(value, priority));
    heapifyUp(heap.size() - 1);
}

bool PriorityQueue::dequeue() {
    if (isEmpty()) return false;
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        heapifyDown(0);
    }
    return true;
}

int PriorityQueue::peek() {
    if (isEmpty()) return -1;
    return heap[0].data;
}

bool PriorityQueue::isEmpty() {
    return heap.empty();
}

int PriorityQueue::getSize() {
    return (int)heap.size();
}

crow::json::wvalue PriorityQueue::toJSON() {
    crow::json::wvalue result;
    result["type"] = "priority_queue";
    std::vector<int> dataValues;
    std::vector<int> priorities;
    for (const auto& node : heap) {
        dataValues.push_back(node.data);
        priorities.push_back(node.priority);
    }
    result["data"] = dataValues;
    result["priorities"] = priorities;
    result["size"] = (int)heap.size();
    return result;
}

void PriorityQueue::clear() {
    heap.clear();
}

