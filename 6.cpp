#include <iostream>
#include <algorithm>
#include "s/list.h"
#include "s/hash.h"
using namespace std;     //Number 7 !

int main(){
    Hash<string,string> tree;      //хэш-таблица с деревом и подсчётом
    Hash<string,int> child_count;
    int N;
    cin>>N;
    for(int i=0;i<N-1;i++){       //Ввод
        string parent,child;
        cin >>child>>parent;
        tree[child]=parent;
        child_count[parent]=0;
        child_count[child]=0;
    }
    
    for(auto &i:tree){             //Сам процесс назначения 
        string child=i.key;
        do{
        string parent=tree[child];
        child_count[parent]++;
        child=parent;
        }
        while(tree.contains(child));
    }

    List<string> list;            //Вывод
    for(auto i:child_count)
        list.PUSH_SORTED(i.key);
    for(auto i:list)
        cout<<i<<" "<<child_count[i]<<endl;
}