#ifndef MY_HASH_H_
#define MY_HASH_H_
#include <iostream>
using namespace std;

template <typename KeyType, typename ValueType>
class Hash{
    public:
    struct element{                         //Элементы помимо ключ-значение обладают состоянием
        KeyType key;
        ValueType value;
        short state=0;
    };
    class iterator{
        public:
        element * pointer;
        iterator();
        iterator(element *ptr);
        iterator& operator++();
        element& operator*();
        bool operator!=(const iterator& other);
    };

    Hash();
    ~Hash();

    void insert (KeyType key,ValueType value);
    bool erase (KeyType key);
    ValueType get(KeyType key);
    size_t size();
    bool contains(KeyType value);
    void print();
    iterator begin();
    iterator end();
    ValueType& operator[](KeyType key);
    
    private:
    void rehash();
    size_t Hash_function(KeyType key);
    size_t _table_size;
    size_t _size;
    element * _table;
};
#include "hash.tpp"
#endif //MY_HASH_H_
