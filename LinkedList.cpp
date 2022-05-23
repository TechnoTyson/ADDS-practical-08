#include "LinkedList.h"
#include <stdlib.h>
#include <iostream>
#include <limits>
LinkedList::LinkedList(){
    this->head = NULL;
}

void LinkedList::addFront(int newItem){
    //Create new node that points to next node the old head
    Node* newHead = new Node(newItem, head);
    //Change head to new Node
    head = newHead;
    //Return void
    return;
}

void LinkedList::addEnd(int newItem){
    //Create new node that points to NULL
    Node * newHead = new Node(newItem, NULL);
    //Setup temp nextNode pointer
    Node* tempNode = head;
    //Find last thing in the LinkedList
    while(tempNode->getNext() != NULL){
        tempNode = tempNode->getNext();
    }
    tempNode->setNext(newHead);

    return;
}

void LinkedList::addAtPosition(int position, int newItem){
    if (position < 1){
        return addFront(newItem);
    }
    //Create new node that points to null
    Node* newHead = new Node(newItem, NULL);
    //Setup temp nextNode pointer
    Node* before = head;
    Node* after = head;
    
    //Run loop to set nextNode for new pointer
    for(int i = 0; i < position - 2; i++){
        if (before->getNext() == NULL){
            break;
        }
        else {
            before = before->getNext();
        }
    }
    after = before->getNext();
    //Point element before to new item in list
    before->setNext(newHead);
    //Point new item to element after
    newHead->setNext(after);
    return; 
}

int LinkedList::search(int item){
    //Run while loop to find item
    Node* tempNode = head;
    int position = 1;
    while(tempNode->getData() != item){
        tempNode = tempNode->getNext();
        //Check if last item
        if (tempNode == NULL){
            std::cout << "0 ";
            return 0;
        }
        position++;
    }
    std::cout << position << " ";
    return position;
}

void LinkedList::deleteFront(){
    //set head to second element
    Node* tempHead = head;
    head = head->getNext();
    delete tempHead;
    return;
}

void LinkedList::deleteEnd(){
    //setup temp Node to delete
    Node* tempNode = head->getNext();
    Node* newEnd = head;
    while(tempNode->getNext() != NULL){
        tempNode = tempNode->getNext();
        newEnd = newEnd->getNext();
    }  
    newEnd->setNext(NULL);
    delete tempNode;
    return;
}

void LinkedList::deletePosition(int position){
    if (position < 1){
        std::cout << "outside range";
        return;
    }
    //setup temp Node to delete
    Node* before = head;
    Node* tempNode = head;

    for(int i = 1; i < position - 1; i++){
        if (before->getNext() == NULL){
            std::cout << "outside range";
            return;
        }
        else {
            before = before->getNext();
        }
    }
    tempNode = before->getNext();
    before->setNext(tempNode->getNext());
    delete tempNode;
    return;
}

int LinkedList::getItem(int position){
    Node* tempNode = head;
    for (int i = 1; i <= position - 1; i++){
        tempNode = tempNode->getNext();
        if (tempNode == NULL){
            std::cout << std::numeric_limits<int> ::max() << " ";
            return std::numeric_limits<int> :: max();
        }
    }
    std::cout << tempNode->getData() << " ";
    return tempNode->getData();
}

void LinkedList::printItems(){
    Node* tempNode = head;
    while (tempNode != NULL){
        std::cout << tempNode->getData();
        std::cout << " ";
        tempNode = tempNode->getNext();
    }
    return;
}

LinkedList::LinkedList(int* elements, int size){
    head = NULL;
    for(int i = size-1; i >= 0; i--){
        head = new Node(elements[i], head);
    }
}

LinkedList::~LinkedList(){
    Node* tempNode = head;
    Node* oldNode;
    while (tempNode != NULL){
        oldNode = tempNode;
        tempNode = tempNode->getNext();
        delete oldNode;
    }    
    delete tempNode;
}