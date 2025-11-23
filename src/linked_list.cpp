#include "linked_list.h"

// ==================== SINGLY LINKED LIST ====================

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

void SinglyLinkedList::insertAtBeginning(int value) {
    SinglyNode* newNode = new SinglyNode(value);
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::insertAtEnd(int value) {
    SinglyNode* newNode = new SinglyNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    SinglyNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void SinglyLinkedList::insertAtPosition(int value, int position) {
    if (position <= 0) {
        insertAtBeginning(value);
        return;
    }
    
    SinglyNode* newNode = new SinglyNode(value);
    SinglyNode* temp = head;
    
    for (int i = 0; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    
    if (!temp) {
        insertAtEnd(value);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

bool SinglyLinkedList::deleteAtBeginning() {
    if (!head) return false;
    SinglyNode* temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool SinglyLinkedList::deleteAtEnd() {
    if (!head) return false;
    if (!head->next) {
        delete head;
        head = nullptr;
        return true;
    }
    SinglyNode* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return true;
}

bool SinglyLinkedList::deleteAtPosition(int position) {
    if (!head || position < 0) return false;
    
    if (position == 0) {
        return deleteAtBeginning();
    }
    
    SinglyNode* temp = head;
    for (int i = 0; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    
    if (!temp || !temp->next) return false;
    
    SinglyNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return true;
}

bool SinglyLinkedList::deleteByValue(int value) {
    if (!head) return false;
    
    if (head->data == value) {
        return deleteAtBeginning();
    }
    
    SinglyNode* temp = head;
    while (temp->next && temp->next->data != value) {
        temp = temp->next;
    }
    
    if (!temp->next) return false;
    
    SinglyNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return true;
}

bool SinglyLinkedList::update(int oldValue, int newValue) {
    SinglyNode* temp = head;
    while (temp) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool SinglyLinkedList::search(int value) {
    SinglyNode* temp = head;
    while (temp) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

void SinglyLinkedList::reverse() {
    SinglyNode* prev = nullptr;
    SinglyNode* current = head;
    SinglyNode* next = nullptr;
    
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

crow::json::wvalue SinglyLinkedList::toJSON() {
    crow::json::wvalue result;
    std::vector<int> values;
    SinglyNode* temp = head;
    while (temp) {
        values.push_back(temp->data);
        temp = temp->next;
    }
    result["type"] = "singly";
    result["values"] = values;
    result["size"] = (int)values.size();
    return result;
}

void SinglyLinkedList::clear() {
    while (head) {
        SinglyNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int SinglyLinkedList::size() {
    int count = 0;
    SinglyNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ==================== DOUBLY LINKED LIST ====================

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::insertAtBeginning(int value) {
    DoublyNode* newNode = new DoublyNode(value);
    if (!head) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int value) {
    DoublyNode* newNode = new DoublyNode(value);
    if (!tail) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void DoublyLinkedList::insertAtPosition(int value, int position) {
    if (position <= 0) {
        insertAtBeginning(value);
        return;
    }
    
    DoublyNode* newNode = new DoublyNode(value);
    DoublyNode* temp = head;
    
    for (int i = 0; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    
    if (!temp || !temp->next) {
        insertAtEnd(value);
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

bool DoublyLinkedList::deleteAtBeginning() {
    if (!head) return false;
    DoublyNode* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    return true;
}

bool DoublyLinkedList::deleteAtEnd() {
    if (!tail) return false;
    DoublyNode* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    return true;
}

bool DoublyLinkedList::deleteAtPosition(int position) {
    if (!head || position < 0) return false;
    
    if (position == 0) {
        return deleteAtBeginning();
    }
    
    DoublyNode* temp = head;
    for (int i = 0; i < position && temp; i++) {
        temp = temp->next;
    }
    
    if (!temp) return false;
    
    if (temp == tail) {
        return deleteAtEnd();
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return true;
}

bool DoublyLinkedList::deleteByValue(int value) {
    DoublyNode* temp = head;
    while (temp && temp->data != value) {
        temp = temp->next;
    }
    
    if (!temp) return false;
    
    if (temp == head) return deleteAtBeginning();
    if (temp == tail) return deleteAtEnd();
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return true;
}

bool DoublyLinkedList::update(int oldValue, int newValue) {
    DoublyNode* temp = head;
    while (temp) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool DoublyLinkedList::search(int value) {
    DoublyNode* temp = head;
    while (temp) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

void DoublyLinkedList::reverse() {
    DoublyNode* temp = nullptr;
    DoublyNode* current = head;
    
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp) {
        head = temp->prev;
    }
}

crow::json::wvalue DoublyLinkedList::toJSON() {
    crow::json::wvalue result;
    std::vector<int> values;
    DoublyNode* temp = head;
    while (temp) {
        values.push_back(temp->data);
        temp = temp->next;
    }
    result["type"] = "doubly";
    result["values"] = values;
    result["size"] = (int)values.size();
    return result;
}

void DoublyLinkedList::clear() {
    while (head) {
        DoublyNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

int DoublyLinkedList::size() {
    int count = 0;
    DoublyNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ==================== CIRCULAR LINKED LIST ====================

CircularLinkedList::CircularLinkedList() : head(nullptr) {}

CircularLinkedList::~CircularLinkedList() {
    clear();
}

void CircularLinkedList::insertAtBeginning(int value) {
    SinglyNode* newNode = new SinglyNode(value);
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    
    SinglyNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void CircularLinkedList::insertAtEnd(int value) {
    SinglyNode* newNode = new SinglyNode(value);
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    
    SinglyNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
}

void CircularLinkedList::insertAtPosition(int value, int position) {
    if (position <= 0 || !head) {
        insertAtBeginning(value);
        return;
    }
    
    SinglyNode* newNode = new SinglyNode(value);
    SinglyNode* temp = head;
    
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            insertAtEnd(value);
            delete newNode;
            return;
        }
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

bool CircularLinkedList::deleteAtBeginning() {
    if (!head) return false;
    
    if (head->next == head) {
        delete head;
        head = nullptr;
        return true;
    }
    
    SinglyNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    SinglyNode* toDelete = head;
    head = head->next;
    temp->next = head;
    delete toDelete;
    return true;
}

bool CircularLinkedList::deleteAtEnd() {
    if (!head) return false;
    
    if (head->next == head) {
        delete head;
        head = nullptr;
        return true;
    }
    
    SinglyNode* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = head;
    return true;
}

bool CircularLinkedList::deleteAtPosition(int position) {
    if (!head || position < 0) return false;
    
    if (position == 0) {
        return deleteAtBeginning();
    }
    
    SinglyNode* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) return false;
    }
    
    if (temp->next == head) return false;
    
    SinglyNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return true;
}

bool CircularLinkedList::deleteByValue(int value) {
    if (!head) return false;
    
    if (head->data == value) {
        return deleteAtBeginning();
    }
    
    SinglyNode* temp = head;
    do {
        if (temp->next->data == value) {
            SinglyNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    
    return false;
}

bool CircularLinkedList::update(int oldValue, int newValue) {
    if (!head) return false;
    
    SinglyNode* temp = head;
    do {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    
    return false;
}

bool CircularLinkedList::search(int value) {
    if (!head) return false;
    
    SinglyNode* temp = head;
    do {
        if (temp->data == value) return true;
        temp = temp->next;
    } while (temp != head);
    
    return false;
}

void CircularLinkedList::reverse() {
    if (!head || head->next == head) return;
    
    SinglyNode* prev = nullptr;
    SinglyNode* current = head;
    SinglyNode* next = nullptr;
    
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    
    head->next = prev;
    head = prev;
}

crow::json::wvalue CircularLinkedList::toJSON() {
    crow::json::wvalue result;
    std::vector<int> values;
    
    if (head) {
        SinglyNode* temp = head;
        do {
            values.push_back(temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    
    result["type"] = "circular";
    result["values"] = values;
    result["size"] = (int)values.size();
    return result;
}

void CircularLinkedList::clear() {
    if (!head) return;
    
    SinglyNode* current = head;
    SinglyNode* next;
    
    do {
        next = current->next;
        delete current;
        current = next;
    } while (current != head);
    
    head = nullptr;
}

int CircularLinkedList::size() {
    if (!head) return 0;
    
    int count = 0;
    SinglyNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    
    return count;
}