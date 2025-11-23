#include "crow.h"
#include "linked_list.h"
#include "data_structures.h"
#include <fstream>
#include <sstream>

// Global data structure instances
SinglyLinkedList singlyList;
DoublyLinkedList doublyList;
CircularLinkedList circularList;

Array array;
StackArray stackArray;
StackLinkedList stackLinkedList;
Queue queue;
CircularQueue circularQueue;
Deque deque;
PriorityQueue priorityQueue;

int main() {
    crow::SimpleApp app;

    // ==================== SINGLY LINKED LIST ROUTES ====================

    CROW_ROUTE(app, "/api/singly/get")([](){
        return singlyList.toJSON(); // returns crow::json::wvalue or stringified JSON from your class [web:64][web:20];
    });

    CROW_ROUTE(app, "/api/singly/insert/beginning").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if (!x) return crow::response(400);
        int value = x["value"].i();
        singlyList.insertAtBeginning(value);
        crow::json::wvalue res; res["success"]=true; res["message"]="Inserted at beginning"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/insert/end").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if (!x) return crow::response(400);
        int value = x["value"].i();
        singlyList.insertAtEnd(value);
        crow::json::wvalue res; res["success"]=true; res["message"]="Inserted at end"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/insert/position").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if (!x) return crow::response(400);
        singlyList.insertAtPosition(x["value"].i(), x["position"].i());
        crow::json::wvalue res; res["success"]=true; res["message"]="Inserted at position"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/delete/beginning").methods("DELETE"_method)
    ([](){
        bool ok = singlyList.deleteAtBeginning();
        crow::json::wvalue res; res["success"]=ok; res["message"]= ok ? "Deleted from beginning":"List is empty"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/delete/end").methods("DELETE"_method)
    ([](){
        bool ok = singlyList.deleteAtEnd();
        crow::json::wvalue res; res["success"]=ok; res["message"]= ok ? "Deleted from end":"List is empty"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/delete/position/<int>").methods("DELETE"_method)
    ([](int position){
        bool ok = singlyList.deleteAtPosition(position);
        crow::json::wvalue res; res["success"]=ok; res["message"]= ok ? "Deleted from position":"Invalid position"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/delete/value/<int>").methods("DELETE"_method)
    ([](int value){
        bool ok = singlyList.deleteByValue(value);
        crow::json::wvalue res; res["success"]=ok; res["message"]= ok ? "Value deleted":"Value not found"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/update").methods("PUT"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if (!x) return crow::response(400);
        bool ok = singlyList.update(x["oldValue"].i(), x["newValue"].i());
        crow::json::wvalue res; res["success"]=ok; res["message"]= ok ? "Value updated":"Value not found"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/search/<int>")([](int value){
        crow::json::wvalue res; res["found"]=singlyList.search(value); res["value"]=value;
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/clear").methods("DELETE"_method)
    ([](){
        singlyList.clear();
        crow::json::wvalue res; res["success"]=true; res["message"]="List cleared"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    // ==================== DOUBLY LINKED LIST ROUTES ====================

    CROW_ROUTE(app, "/api/doubly/get")([](){ return doublyList.toJSON(); });

    CROW_ROUTE(app, "/api/doubly/insert/beginning").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        doublyList.insertAtBeginning(x["value"].i());
        crow::json::wvalue res; res["success"]=true; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/insert/end").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        doublyList.insertAtEnd(x["value"].i());
        crow::json::wvalue res; res["success"]=true; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/insert/position").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        doublyList.insertAtPosition(x["value"].i(), x["position"].i());
        crow::json::wvalue res; res["success"]=true; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/delete/beginning").methods("DELETE"_method)
    ([](){
        bool ok = doublyList.deleteAtBeginning();
        crow::json::wvalue res; res["success"]=ok; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/delete/end").methods("DELETE"_method)
    ([](){
        bool ok = doublyList.deleteAtEnd();
        crow::json::wvalue res; res["success"]=ok; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/delete/position/<int>").methods("DELETE"_method)
    ([](int position){
        bool ok = doublyList.deleteAtPosition(position);
        crow::json::wvalue res; res["success"]=ok; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/delete/value/<int>").methods("DELETE"_method)
    ([](int value){
        bool ok = doublyList.deleteByValue(value);
        crow::json::wvalue res; res["success"]=ok; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/update").methods("PUT"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = doublyList.update(x["oldValue"].i(), x["newValue"].i());
        crow::json::wvalue res; res["success"]=ok; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/search/<int>")([](int value){
        crow::json::wvalue res; res["found"]=doublyList.search(value);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/clear").methods("DELETE"_method)
    ([](){
        doublyList.clear();
        crow::json::wvalue res; res["success"]=true; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    // ==================== CIRCULAR LINKED LIST ROUTES ====================

    CROW_ROUTE(app, "/api/circular/get")([](){ return circularList.toJSON(); });

    CROW_ROUTE(app, "/api/circular/insert/beginning").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        circularList.insertAtBeginning(x["value"].i());
        crow::json::wvalue res; res["success"]=true; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/insert/end").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        circularList.insertAtEnd(x["value"].i());
        crow::json::wvalue res; res["success"]=true; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/insert/position").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        circularList.insertAtPosition(x["value"].i(), x["position"].i());
        crow::json::wvalue res; res["success"]=true; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/delete/beginning").methods("DELETE"_method)
    ([](){
        bool ok = circularList.deleteAtBeginning();
        crow::json::wvalue res; res["success"]=ok; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/delete/end").methods("DELETE"_method)
    ([](){
        bool ok = circularList.deleteAtEnd();
        crow::json::wvalue res; res["success"]=ok; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/delete/position/<int>").methods("DELETE"_method)
    ([](int position){
        bool ok = circularList.deleteAtPosition(position);
        crow::json::wvalue res; res["success"]=ok; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/delete/value/<int>").methods("DELETE"_method)
    ([](int value){
        bool ok = circularList.deleteByValue(value);
        crow::json::wvalue res; res["success"]=ok; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/update").methods("PUT"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = circularList.update(x["oldValue"].i(), x["newValue"].i());
        crow::json::wvalue res; res["success"]=ok; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/search/<int>")([](int value){
        crow::json::wvalue res; res["found"]=circularList.search(value);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/clear").methods("DELETE"_method)
    ([](){
        circularList.clear();
        crow::json::wvalue res; res["success"]=true; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/singly/reverse").methods("POST"_method)
    ([](){
        singlyList.reverse();
        crow::json::wvalue res; res["success"]=true; res["message"]="List reversed"; res["list"]=singlyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/doubly/reverse").methods("POST"_method)
    ([](){
        doublyList.reverse();
        crow::json::wvalue res; res["success"]=true; res["message"]="List reversed"; res["list"]=doublyList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/circular/reverse").methods("POST"_method)
    ([](){
        circularList.reverse();
        crow::json::wvalue res; res["success"]=true; res["message"]="List reversed"; res["list"]=circularList.toJSON();
        return crow::response(res);
    });

    // ==================== ARRAY ROUTES ====================

    CROW_ROUTE(app, "/api/array/get")([](){ return array.toJSON(); });

    CROW_ROUTE(app, "/api/array/insert").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = array.insert(x["value"].i(), x["position"].i());
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Inserted":"Invalid position"; res["array"]=array.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/array/delete/position/<int>").methods("DELETE"_method)
    ([](int position){
        bool ok = array.deleteAt(position);
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Deleted":"Invalid position"; res["array"]=array.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/array/delete/value/<int>").methods("DELETE"_method)
    ([](int value){
        bool ok = array.deleteByValue(value);
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Deleted":"Value not found"; res["array"]=array.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/array/search/linear/<int>")([](int value){
        int pos = array.linearSearch(value);
        crow::json::wvalue res; res["found"]=(pos>=0); res["position"]=pos; res["value"]=value;
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/array/search/binary/<int>")([](int value){
        int pos = array.binarySearch(value);
        crow::json::wvalue res; res["found"]=(pos>=0); res["position"]=pos; res["value"]=value;
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/array/traverse")([](){
        auto values = array.traverse();
        crow::json::wvalue res; res["values"]=values; res["size"]=(int)values.size();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/array/update").methods("PUT"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = array.update(x["position"].i(), x["value"].i());
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Updated":"Invalid position"; res["array"]=array.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/array/clear").methods("DELETE"_method)
    ([](){
        array.clear();
        crow::json::wvalue res; res["success"]=true; res["message"]="Array cleared"; res["array"]=array.toJSON();
        return crow::response(res);
    });

    // ==================== STACK (ARRAY) ROUTES ====================

    CROW_ROUTE(app, "/api/stack/array/get")([](){ return stackArray.toJSON(); });

    CROW_ROUTE(app, "/api/stack/array/push").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = stackArray.push(x["value"].i());
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Pushed":"Stack full"; res["stack"]=stackArray.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/array/pop").methods("POST"_method)
    ([](){
        bool ok = stackArray.pop();
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Popped":"Stack empty"; res["stack"]=stackArray.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/array/peek")([](){
        int val = stackArray.peek();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/array/clear").methods("DELETE"_method)
    ([](){
        stackArray.clear();
        crow::json::wvalue res; res["success"]=true; res["stack"]=stackArray.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/array/check-parentheses").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool valid = StackArray::checkParentheses(x["expression"].s());
        crow::json::wvalue res; res["valid"]=valid; res["expression"]=x["expression"].s();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/array/reverse-string").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        std::string reversed = StackArray::reverseString(x["str"].s());
        crow::json::wvalue res; res["original"]=x["str"].s(); res["reversed"]=reversed;
        return crow::response(res);
    });

    // ==================== STACK (LINKED LIST) ROUTES ====================

    CROW_ROUTE(app, "/api/stack/linkedlist/get")([](){ return stackLinkedList.toJSON(); });

    CROW_ROUTE(app, "/api/stack/linkedlist/push").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        stackLinkedList.push(x["value"].i());
        crow::json::wvalue res; res["success"]=true; res["message"]="Pushed"; res["stack"]=stackLinkedList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/linkedlist/pop").methods("POST"_method)
    ([](){
        bool ok = stackLinkedList.pop();
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Popped":"Stack empty"; res["stack"]=stackLinkedList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/linkedlist/peek")([](){
        int val = stackLinkedList.peek();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/linkedlist/clear").methods("DELETE"_method)
    ([](){
        stackLinkedList.clear();
        crow::json::wvalue res; res["success"]=true; res["stack"]=stackLinkedList.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/linkedlist/check-parentheses").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool valid = StackLinkedList::checkParentheses(x["expression"].s());
        crow::json::wvalue res; res["valid"]=valid; res["expression"]=x["expression"].s();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/stack/linkedlist/reverse-string").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        std::string reversed = StackLinkedList::reverseString(x["str"].s());
        crow::json::wvalue res; res["original"]=x["str"].s(); res["reversed"]=reversed;
        return crow::response(res);
    });

    // ==================== QUEUE ROUTES ====================

    CROW_ROUTE(app, "/api/queue/get")([](){ return queue.toJSON(); });

    CROW_ROUTE(app, "/api/queue/enqueue").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = queue.enqueue(x["value"].i());
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Enqueued":"Queue full"; res["queue"]=queue.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/dequeue").methods("POST"_method)
    ([](){
        bool ok = queue.dequeue();
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Dequeued":"Queue empty"; res["queue"]=queue.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/front")([](){
        int val = queue.getFront();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/rear")([](){
        int val = queue.getRear();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/clear").methods("DELETE"_method)
    ([](){
        queue.clear();
        crow::json::wvalue res; res["success"]=true; res["queue"]=queue.toJSON();
        return crow::response(res);
    });

    // ==================== CIRCULAR QUEUE ROUTES ====================

    CROW_ROUTE(app, "/api/queue/circular/get")([](){ return circularQueue.toJSON(); });

    CROW_ROUTE(app, "/api/queue/circular/enqueue").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = circularQueue.enqueue(x["value"].i());
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Enqueued":"Queue full"; res["queue"]=circularQueue.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/circular/dequeue").methods("POST"_method)
    ([](){
        bool ok = circularQueue.dequeue();
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Dequeued":"Queue empty"; res["queue"]=circularQueue.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/circular/front")([](){
        int val = circularQueue.getFront();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/circular/rear")([](){
        int val = circularQueue.getRear();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/circular/clear").methods("DELETE"_method)
    ([](){
        circularQueue.clear();
        crow::json::wvalue res; res["success"]=true; res["queue"]=circularQueue.toJSON();
        return crow::response(res);
    });

    // ==================== DEQUE ROUTES ====================

    CROW_ROUTE(app, "/api/deque/get")([](){ return deque.toJSON(); });

    CROW_ROUTE(app, "/api/deque/push/front").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = deque.pushFront(x["value"].i());
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Pushed at front":"Deque full"; res["deque"]=deque.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/deque/push/rear").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        bool ok = deque.pushRear(x["value"].i());
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Pushed at rear":"Deque full"; res["deque"]=deque.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/deque/pop/front").methods("POST"_method)
    ([](){
        bool ok = deque.popFront();
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Popped from front":"Deque empty"; res["deque"]=deque.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/deque/pop/rear").methods("POST"_method)
    ([](){
        bool ok = deque.popRear();
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Popped from rear":"Deque empty"; res["deque"]=deque.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/deque/front")([](){
        int val = deque.getFront();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/deque/rear")([](){
        int val = deque.getRear();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/deque/clear").methods("DELETE"_method)
    ([](){
        deque.clear();
        crow::json::wvalue res; res["success"]=true; res["deque"]=deque.toJSON();
        return crow::response(res);
    });

    // ==================== PRIORITY QUEUE ROUTES ====================

    CROW_ROUTE(app, "/api/queue/priority/get")([](){ return priorityQueue.toJSON(); });

    CROW_ROUTE(app, "/api/queue/priority/enqueue").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body); if(!x) return crow::response(400);
        priorityQueue.enqueue(x["value"].i(), x["priority"].i());
        crow::json::wvalue res; res["success"]=true; res["message"]="Enqueued"; res["queue"]=priorityQueue.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/priority/dequeue").methods("POST"_method)
    ([](){
        bool ok = priorityQueue.dequeue();
        crow::json::wvalue res; res["success"]=ok; res["message"]=ok?"Dequeued":"Queue empty"; res["queue"]=priorityQueue.toJSON();
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/priority/peek")([](){
        int val = priorityQueue.peek();
        crow::json::wvalue res; res["value"]=val; res["hasValue"]=(val!=-1);
        return crow::response(res);
    });

    CROW_ROUTE(app, "/api/queue/priority/clear").methods("DELETE"_method)
    ([](){
        priorityQueue.clear();
        crow::json::wvalue res; res["success"]=true; res["queue"]=priorityQueue.toJSON();
        return crow::response(res);
    });

    // Serve static HTML file
    CROW_ROUTE(app, "/index.html")([](){
        std::ifstream file("public/index.html");
        if (!file.is_open()) {
            return crow::response(404);
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        auto res = crow::response(buffer.str());
        res.set_header("Content-Type", "text/html");
        return res;
    });

    // Redirect root to index.html
    CROW_ROUTE(app, "/")([](){
        std::ifstream file("public/index.html");
        if (!file.is_open()) {
            crow::json::wvalue res;
            res["message"] = "Crow is running";
            res["status"] = "ok";
            return crow::response(res);
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        auto res = crow::response(buffer.str());
        res.set_header("Content-Type", "text/html");
        return res;
    });

    app.port(18080).multithreaded().run(); // standard Crow startup [web:2][web:64]
    return 0;
}
