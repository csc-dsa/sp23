#include "node.h"

// Default constructor
Node::Node(){
    this->data = 0;
    this->next = nullptr;
}

Node::Node(int data){
    this->data = data;
    this->next = nullptr;
}

Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
}

Node::~Node(){
    if(this->next != nullptr){
        delete this->next;
    }
}