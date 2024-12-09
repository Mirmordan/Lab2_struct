#include "list.h"
#include <iostream>
using namespace std;

template <typename Type>  //Конструкторы ноды
List<Type>::Node::Node(){
     _next=nullptr;
};

template <typename Type>
List<Type>::Node::Node(Type value){
    _next=nullptr;
    _value=value;
};

template <typename Type> //Конструктор списка
List <Type>::List(){
    _size=0;
    _tail=_head=nullptr;
}
template <typename Type> //Конструктор списка
List <Type>::~List(){
    Node * delete_pointer=_head;
    while(delete_pointer){
        Node * next_node=delete_pointer->_next;
        delete delete_pointer;
        delete_pointer=next_node;
    }
}

template <typename Type>    
void List <Type>::POP(){
    if (_size==0)
        return;
    Node * delete_node=_head;
    if(_size==1){
        _head=nullptr;
        _tail=nullptr;
    }
    else
        _head=_head->_next;
    delete delete_node;
    _size--;
}

template <typename Type>    
void List <Type>::POP_BACK(){
    if (_size==0)
        return;
    Node * delete_node=_tail;
    if(_size==1){
        _head=nullptr;
        _tail=nullptr;
    }
    else{
        Node* search_pointer=_head;
        while(search_pointer->_next!=_tail)
            search_pointer=search_pointer->_next;
        search_pointer->_next=nullptr;
        _tail=search_pointer;
    }
    delete delete_node;
    _size--;
}

template <typename Type>    
void List <Type>::PUSH(Type value){
    if (_size==0){
        _head=new Node(value);
        _tail=_head;
    }
    else {
        Node *new_node= new Node(value);
        new_node->_next=_head;
        _head=new_node;
    }
    _size++;
}

template <typename Type>    
void List <Type>::PUSH_SORTED(Type value){
    Node *new_node=new Node(value);
    Node ** insert_pointer = &_head;
    while((*insert_pointer)!=nullptr){
        if((*insert_pointer)->_value>value){
            new_node->_next=(*insert_pointer);
            *insert_pointer=new_node;
            return;
        }
        insert_pointer=&((*insert_pointer)->_next);
    }
    _tail=new_node;
    *insert_pointer=new_node;
    new_node->_next=nullptr;
    _size++;
}

template <typename Type> // Добавление в хвост
void List <Type>::PUSH_BACK(Type value){
    if (_size==0)
        _tail=_head=new Node(value);
    else {
        _tail->_next=new Node(value);
        _tail=_tail->_next;
    }
    _size++;
}

template <typename Type>
size_t List <Type>::size(){
    return _size;
}

template <typename Type>        //Конструкторы итератора
List <Type>::iterator::iterator(){
    pointer=nullptr;
};

template <typename Type>              
List <Type>::iterator::iterator(Node* node){
    pointer=node;
};

template <typename Type>                       //Начало списка
typename List <Type>::iterator List <Type>::begin(){
    return iterator(_head);
};

template <typename Type>                      //Конец
typename List <Type>::iterator List <Type>::end(){
    return iterator(nullptr);
};

template <typename Type>                //Операторы итератора
typename List <Type>::iterator& List <Type>::iterator::operator++(){
    pointer=pointer->_next;
    return *this;
};

template <typename Type>
Type& List <Type>::iterator::operator*(){
    return pointer->_value;
};

template <typename Type>
bool List <Type>::iterator::operator!=(const iterator& other){
    if(pointer!=other.pointer)
        return true;
    return false;
};