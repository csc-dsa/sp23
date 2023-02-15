#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList(){

}


LinkedList::LinkedList(int data){

}


LinkedList::LinkedList(std::vector<int> vec){

}

LinkedList::~LinkedList(){

}


void LinkedList::push_front(int data){

}

void LinkedList::push_back(int data){

}

void LinkedList::insert(int data, int idx){

}

void LinkedList::remove(int data){

}


bool LinkedList::contains(int data){

}


int LinkedList::get_size(){
    return this->size;
}

// O(n)
std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}
