#include "s/array.h"
#include <iostream>
using namespace std;                 // number 2
template <typename iterator>
void print_subsums(iterator begin,iterator end,int target_sum){
    Array<int> sums;       //Массив частичных сумм
    sums.push_back(0);

    int size=end-begin;  //Проверка на размер
    if(size==0)
        return;
    
    for(auto it=begin;it!=end;++it){    //Получение частичных сумм
        sums.push_back(sums.back()+*it);
    }
    for(size_t i=0;i<size;i++){
        for(size_t j=i+1;j<size+1;j++){
            if(sums[j]-sums[i]==target_sum){
                for(auto it=begin+i;it!=begin+j;++it)
                    cout<<*it<<" ";
                cout<<endl;
            }
        }
    }

}
int main(){
    cout<<"Array:"<<endl;
    string input;
    getline(cin,input);
    stringstream input_stream(input);
    int num;
    Array<int> array;
    while(input_stream>>num)
        array.push_back(num);
    cout<<"Sum:"<<endl;
    cin>>num;
    print_subsums(array.begin(),array.end(),num);
}