#pragma once

class Node{
    public:
        Node(int, Node*);
        int getData();
        Node* getNext();
        void setData(int);
        void setNext(Node*);
    private:
        int data;
        Node* next;
};