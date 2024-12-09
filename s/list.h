#ifndef MYONEWAYLIST_H_
#define MYONEWAYLIST_H_
#include <iostream>
using namespace std;
template <typename Type>
class List{
    struct Node{
        Node * _next;
        Type _value;
        Node();
        Node(Type value);
    };
    class iterator{
        public:
        Node* pointer;
        iterator();
        iterator(Node* node);
        iterator& operator++();
        Type& operator*();
        bool operator!=(const iterator& other);
    };
    
    public:
    List();
    ~List();
    void PUSH_SORTED(Type value);
    void PUSH(Type value);
    void PUSH_BACK(Type value);
    void POP();
    void POP_BACK();
    void PRINT();
    iterator begin();
    iterator end();
    size_t size();
    private:
    Node*_head;
    Node*_tail;
    size_t _size;
};
#include "list.tpp"

#endif // MYONEWAYLIST_H_