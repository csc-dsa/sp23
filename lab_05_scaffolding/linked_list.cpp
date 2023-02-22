#include "linked_list.h"
#include <iostream>

// O(1)
LinkedList::LinkedList(){
    this->head = nullptr;
    this->size = 0;
}

// O(1)
LinkedList::LinkedList(int data){
    this->head = new Node(data);
    this->size = 1;
}

// O(n)
LinkedList::LinkedList(std::vector<int> vec){
    if(vec.size() == 0){
        this->head = nullptr;
        this->size = 0;
    }else{
        this->head = new Node(vec[0]);
        Node* temp = this->head;

        for(int i = 1; i < vec.size(); i++){
            temp->next = new Node(vec[i]);
            temp = temp->next;
            // ->    de-reference + dot operator
            //temp = (*temp).next;
        }
    }
    this->size = vec.size();
}

LinkedList::~LinkedList(){
    // Use this instead of just deleting the head if the `Node` destructor does not delete its `next`
    /*
    Node* curr = this->head;
    Node* prev = nullptr;

    while(curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    */

   // If the `node` destructor destroys the Node it points to, you do not need the code above this line
   // Note: Be sure all of your `LinkedList` operations set a Node's `next` to `nullptr` before deleting it!
    delete this->head;

    this->head = nullptr;
}

// O(1)
void LinkedList::push_front(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
        // Assign tail
    }else{
        Node* tmp = new Node(data, this->head);
        //tmp->next = this->head;
        this->head = tmp;
    }
    this->size++;
}

// O(n)
// O(1) with a tail pointer
void LinkedList::push_back(int data){
    if(this->head == nullptr){
        this->head = new Node(data);
        // Assign tail
    }else{
        Node* tmp = this->head;

        while(tmp->next != nullptr){
            tmp = tmp->next;
        }

        tmp->next = new Node(data);
    }

    this->size++;
}

// O(n)
// O(1) if `idx` == 0
// O(1) if `idx` == len -1 & there is a tail pointer
void LinkedList::insert(int data, int idx){
    if(!this->head){    // this->head == nullptr
        this->head = new Node(data);
    }else if(idx == 0){
        this->push_front(data);
        return;
    }else if(this->size < idx){
        this->push_back(data);
        return;
    }else{
        Node* tmp = this->head;

        while(idx > 1){
            tmp = tmp->next;
            idx--;
        }
        Node* tmp2 = new Node(data, tmp->next);
        //tmp2->next = tmp->next;
        tmp->next = tmp2;
    }
    this->size++;
}

// O(n)
// O(1) if `idx` == 0
void LinkedList::remove(int data){
    Node* tmp = this->head;
    Node* prev = nullptr;

    // Search for the element in our list
    while(tmp != nullptr && tmp->data != data){
        prev = tmp;
        tmp = tmp->next;
    }

    // We found the element
    if(tmp != nullptr){
        // Special case: deleting the head
        if(tmp == this->head){
            this->head = tmp->next;
        }else{
            prev->next = tmp->next;
        }

        // Without this, the Node destructor will delete
        // every element in the list after 'temp'
        tmp->next = nullptr;
        delete tmp;
        
        this->size--;

    }else{
        std::cout << data << " does not exist!" << std::endl;
    }
}

// O(n)
bool LinkedList::contains(int data){
    Node* tmp = this->head;

    while(tmp != nullptr){
        if(tmp->data == data){
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}

// O(1)
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
