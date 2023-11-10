#pragma once 

//linked list for queue
struct Node {
    int val;
    Node* next;

    Node(int val, Node* next);
};

//class queue with public and private attributes + methods
class Queue {
private:
    Node* head;
    int count;

public:
    void pushBack(int val);
    void pop();
    int getTop();
    bool isEmpty();
    int getSize();

    Queue();
};

