#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"
using namespace std;

template <typename KeyType, typename ValueType>
Hash<KeyType,ValueType>::Hash(){
    _table_size=8;
    _size=0;
    _table=new element[8];
    for(int i=0;i<_table_size;i++)
        _table[i].state=0;
    _table[7].state=-2;
}

template <typename KeyType, typename ValueType>
Hash<KeyType,ValueType>::~Hash(){
    delete[] _table;
}


template <typename KeyType, typename ValueType>
void Hash<KeyType,ValueType>::insert (KeyType key,ValueType value){
    if((_size*1.5)>_table_size)
        rehash();
    size_t index=Hash_function(key);
    size_t del_index=index;
    while (_table[index].state!=0 and _table[index].key!=key){
        index=(index+1)%_table_size;
        if(_table[index].state==-1)
            del_index=index;
    }
    if(_table[index].key!=key and del_index!=Hash_function(key)%_table_size)
        index=del_index;
    _table[index].key=key;
    _table[index].value=value;
    _table[index].state=1;
}

template <typename KeyType, typename ValueType>
bool Hash<KeyType,ValueType>::erase (KeyType key){
    size_t index=Hash_function(key);
    while (_table[index].state!=0 and _table[index].key!=key)
        index=(index+1)%_table_size;
    if (_table[index].state==0)
        return false;
    else 
        _table[index].state=-1;
        _size--;
        return true;
}

template <typename KeyType, typename ValueType>
bool Hash<KeyType,ValueType>::contains(KeyType key){
    size_t index=Hash_function(key);
    while (_table[index].state!=0 and _table[index].key!=key)
        index=(index+1)%_table_size;
    if(_table[index].key==key and _table[index].state==1)
        return true;
    return false;
}

template <typename KeyType, typename ValueType>
ValueType Hash<KeyType,ValueType>::get(KeyType key){
    size_t index=Hash_function(key);
    while (_table[index].state!=0 and _table[index].key!=key)
        index=(index+1)%_table_size;
    if(_table[index].key==key and _table[index].state==1)
        return _table[index].value;
    else
        return ValueType();
}

template <typename KeyType, typename ValueType>
size_t Hash<KeyType,ValueType>::size(){
    return _size;
}

template <typename KeyType, typename ValueType>
void Hash<KeyType,ValueType>::print(){
    for(size_t i=0;i<_table_size;i++){
        if(_table[i].state!=20)
            cout<<_table[i].key<<" "<<_table[i].value<<" "<<_table[i].state<<endl;
    }
}

template <typename KeyType, typename ValueType>
size_t Hash<KeyType,ValueType>::Hash_function(KeyType key){
    if(is_same <KeyType,string>::value or is_same <KeyType,int>::value){
        hash<KeyType> h;
        size_t index = h(key);
        return index%_table_size;
    }
}

template <typename KeyType, typename ValueType>
ValueType& Hash<KeyType,ValueType>::operator[](KeyType key){
    if((_size*1.5)>_table_size)
        rehash();
    size_t index=Hash_function(key);
    while (_table[index].state!=0 and _table[index].key!=key)
        index=(index+1)%_table_size;
    if(_table[index].key==key and _table[index].state==1)
        return _table[index].value;
    else {

        _size++;
        _table[index].key=key;
        _table[index].state=1;
        return _table[index].value;
    }
        
}

template <typename KeyType, typename ValueType>
void Hash<KeyType,ValueType>::rehash(){
    element *old_table=_table;
    size_t old_size=_table_size;
    _table_size*=1.7;
    _size=0;
    _table=new element[_table_size];
    for(int i=0;i<_table_size;i++)
        _table[i].state=0;
    _table[_table_size-1].state=-2;
    for(size_t i=0;i<old_size;i++)
        if(old_table[i].state==1)
            insert(old_table[i].key,old_table[i].value);
}

template <typename KeyType, typename ValueType>
Hash<KeyType,ValueType>::iterator::iterator(){
pointer=nullptr;
}
template <typename KeyType, typename ValueType>
Hash<KeyType,ValueType>::iterator::iterator(element *ptr){
pointer=ptr;
}
template <typename KeyType, typename ValueType>
typename Hash<KeyType,ValueType>::iterator& Hash<KeyType,ValueType>::iterator::operator++(){
    do
    pointer++;
    while(pointer->state!=1 and pointer->state!=-2);
};

template <typename KeyType, typename ValueType>
typename Hash<KeyType,ValueType>::element& Hash<KeyType,ValueType>::iterator::operator*(){
    return *pointer;
};

template <typename KeyType, typename ValueType>
bool Hash<KeyType,ValueType>::iterator::operator!=(const iterator& other){
    return other.pointer!=pointer;
};

template <typename KeyType, typename ValueType>
typename Hash<KeyType,ValueType>::iterator Hash<KeyType,ValueType>::begin(){
    return iterator(_table);
};

template <typename KeyType, typename ValueType>
typename Hash<KeyType,ValueType>::iterator Hash<KeyType,ValueType>::end(){
    return iterator(_table+(_table_size-1));
};