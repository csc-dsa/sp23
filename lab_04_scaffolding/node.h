#pragma once


// head
//  5  ->  3  ->  8  ->  6  -> X
// p1


class Node{
    private:
        int data;
        Node* next;

        friend class LinkedList;
    public:
        Node();
        // Overloading
        Node(int data);
        Node(int data, Node* next);
        ~Node();
};
