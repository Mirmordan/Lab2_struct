#ifndef MYARRAY_H_
#define MYARRAY_H_
#include <sstream> //size_t
template <typename Type>
class Array{
    public:
    class iterator{
        public:
        Type* pointer;
        iterator();
        iterator(Type *ptr);
        Type& operator*();
        bool operator!=(const iterator& other);
        ptrdiff_t operator-(const iterator& other);
        iterator operator+(const int other);
        iterator& operator++();
    };
    Array(std::size_t start_size);
    Array();
    void push(int index,Type input);
    void push_back(Type input);
    void erase (std::size_t index);
    std::size_t size();
    void print();
    Type& operator[](std::size_t index);
    Type& back();
    iterator begin();
    iterator end();
    /*
    void open(string struct_filename);
    void close(string struct_filename);
    */

    private:
    void resize();
    void check_index(std::size_t index);

    Type *array;
    std::size_t capacity; //Поля (вместимость, указатель на массив, число элементов)
    std::size_t _size;
};

#include "array.tpp"
#endif //MYARRAY_H_
