#include "queue.h"
#include <iostream>

using namespace std;

//node function detailing pointers
Node::Node(int val, Node* next) {
    this->val = val;
    this->next = next;
}

//pushback function to add to end of list
void Queue::pushBack(int val) {
    if (count == 0) {
        head = new Node(val, nullptr);;
        count++;
    }
    else {
        head->next = new Node(val, head->next);
        count++;
    }
}

//pop function to remove from the top of the list
void Queue::pop() {
    if (count == 0) {
        return;
    }
    else {
        Node* tempPtr = head;
        head = head->next;
        delete tempPtr;
        count--;
    }
}

//displays the item at the top
int Queue::getTop() {
    return head->val;
}

//displays true if queue is empty
bool Queue::isEmpty() {
    return count == 0;
}

//displays size of queue
int Queue::getSize() {
    return count;
}

//starting points
Queue::Queue() {
    count = 0;
    head = nullptr;
}
