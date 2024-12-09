#include "s/set.h"
#include "s/array.h"
#include <iostream>
#include <sstream>

using namespace std;
int main(){
    string input;
    getline(cin,input);
    stringstream input_stream(input);
    int number;
    Set<int> myset;
    Array<int> el_array;
    Array<bool> bool_array;
    while(input_stream>>number){
        if(!myset.contains(number)){
            myset.insert(number);
            el_array.push_back(number);
            bool_array.push_back(false);
        }
    }
    int min_dif=el_array[0];
    size_t iter=0;
    size_t curr_iter=0;
    while(bool_array.back()!=true){
        int first=0,second=0;
        for(int i=0;i<el_array.size();i++){
            if(bool_array[i])
                first+=el_array[i];
            else
                second+=el_array[i];
        }
        if(((first-second)*(first-second))<(min_dif*min_dif)){
            min_dif=first-second;
            iter=curr_iter;
        }
        curr_iter++;
        int i=0;
        while(true){

            if(bool_array[i]){
                bool_array[i]=false;
                i++;
            }
            else{
                bool_array[i]=true;
                break;
            }
        }

    }
    for(int i=0;i<bool_array.size();i++){
        bool_array[i]=iter%2;
        iter/=2;
    }
    Set<int> firsts,seconds;
    for(int i=0;i<el_array.size();i++){
            if(bool_array[i])
                firsts.insert(el_array[i]);
            else
                seconds.insert(el_array[i]);
        }
    firsts.print();
    seconds.print();
    cout<<"Разница "<<min_dif<<endl;

}