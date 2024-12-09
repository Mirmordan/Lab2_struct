#include <iostream>
#include "stack.h"
using namespace std;

template <typename Type>
void Stack<Type>::PRINT(){
    Node *print_node=_head;
    while(print_node!=nullptr){
        cout<<print_node->value<<" ";
        print_node=print_node->next;
    }
    cout<<endl;
};

template <typename Type>
void Stack<Type>::PUSH(Type value){
    Node *new_node=new Node(value);
    new_node->next=_head;
    _head=new_node;
    _size++;
};

template <typename Type>
void Stack<Type>::POP(){
    if(_size==0)
        return;
    Node *delete_node=_head;
    _head=delete_node->next;
    delete delete_node;
    _size--;
};

template <typename Type>
Type Stack<Type>::PEEK(){
    if(_size==0)
        return Type();
    return _head->value;
    
};

template <typename Type>
void Stack<Type>::INVERSE(){
    if(_size==0)
        return;
    Node *previous_node=nullptr;
    while(true){
        Node *next_node=_head->next;
        _head->next=previous_node;
        previous_node=_head;
        if(next_node!=nullptr)
            _head=next_node;
        else
            break;
    }
};

template <typename Type>
unsigned Stack<Type>::size(){
    return _size;
};

template <typename Type>
Stack<Type>::Stack(){
    _head=nullptr;
    _size=0;
};

template <typename Type>
Stack<Type>::Node::Node(){
    next=nullptr;
};

template <typename Type>
Stack<Type>::Node::Node(Type value){
    this->value=value;
    next=nullptr;
};