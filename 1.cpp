#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "s/stack.h"
using namespace std;
bool lowdiff(string a,string b){
    if(a.size()!=b.size())
        return false;
    int diff=0;
    for(int i;i<a.size();i++)
        if(a[i]!=b[i])
            diff++;
    return diff==1;
}

int main(){
    fstream xml_file("1.xml");
    Stack<string> expression;
    string input;
    size_t open_count=0,close_count=0;
    while(getline(xml_file,input,'>')){
        string new_tag(input+">");
        if(new_tag[1]=='/')
            close_count++;
        else
            open_count++;
        expression.PUSH(new_tag);
    }
    xml_file.close();
    expression.INVERSE();
    expression.PRINT();
    if((open_count+close_count)%2!=0){             //Первый случай - ошибка со скобкой или /
        cout<<"wrong tag number"<<endl;
        auto count=[](string &a,char b){
            size_t result=0;
            for(auto i:a)
                if(i==b)
                    result++;
            return result;
        };
        ofstream output("2.xml");
        while(expression.size()>0){
        string tag=expression.PEEK();
        cout<<tag<<endl;
        if(count(tag,'<')>1 or count(tag,'>')>1){
            auto iter=tag.begin();
            if(count(tag,'<')>1){
                iter=find(tag.begin()+1,tag.end(),'<');
                iter--;
                *iter='>';
            }
            else{
                iter=find(tag.begin(),tag.end(),'>');
                iter--;
                *iter='<';
            }
        }
        output<<tag;
        expression.POP();
        }
    }
    else{
    Stack <string> xml;
    Stack <string> out;
    while(expression.size()>0){
        string tag=expression.PEEK();
        string xml_tag=xml.PEEK();
        string out_string =expression.PEEK();
        bool is_right=true;
        if(tag[1]=='/'){
            tag=tag.substr(2,tag.size()-3);
            xml_tag=xml_tag.substr(1,xml_tag.size()-2);
            if(xml_tag!=tag)
                out_string="</"+xml_tag+">";
            xml.POP();
        }
        else{
            xml.PUSH(tag);
        }
        out.PUSH(out_string);
        expression.POP();
    }
    out.INVERSE();
    ofstream outputf("2.xml");
    while(out.size()>0){
        outputf<<out.PEEK();
        out.POP();
    }
    }
}