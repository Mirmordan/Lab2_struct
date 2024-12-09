#ifndef MY_STACK_H_
#define MY_STACK_H_
template <typename Type>
class Stack{
    struct Node{
        Type value;
        Node* next;
        Node();
        Node(Type value);
    };
    public:
    Stack();
    void PUSH(Type value);
    void POP();
    unsigned size();
    Type PEEK();
    void PRINT();
    void INVERSE();
    private:
    Node * _head;
    unsigned _size;
};
#include "stack.tpp"



#endif //MY_STACK_H_