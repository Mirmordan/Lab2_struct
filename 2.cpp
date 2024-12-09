#include "s/set.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

using namespace std;

class Parser{
    string request;
    string base_filename;
    public:
    Parser(int argc,char* argv[]);
    void parse();
    string get_struct(string base_filename,string struct_filename);
};

int main(int argc, char *argv[]){
    Parser parser(argc,argv);
    parser.parse();
}

Parser::Parser(int argc,char* argv[]){
    string unit;
    base_filename="file.data";
    for(int i=1;i<argc;i++){
        unit=argv[i];
        if(unit.substr(0,6)=="--file"){
            base_filename=argv[i+1];
            i++;
            continue;
        }
        if(unit=="--query"){
            request=argv[i+1];
            i++;
            continue;
        }
        i++;
    }
};

string Parser::get_struct(string base_filename,string struct_filename){
    string input,unit;
    ifstream base_file(base_filename);
    while(getline(base_file,input)){
        stringstream input_stream(input);
        input_stream>>unit;
        if(unit==struct_filename){
            input_stream>>unit;
            base_file.close();
            return unit;
        }
    }
    throw logic_error("Can't found struct file.");
    base_file.close();
    return "array";
}

void Parser::parse(){
    stringstream request_string(request);
    string command, struct_filename,key,value;
    int number;
    request_string>>command;
    request_string>>struct_filename;
    string struct_type=get_struct(base_filename,struct_filename);
    
    if (struct_type=="set"){
        Set<int> myset;
        myset.open(struct_filename);
        if(command=="SETADD"){
            request_string>>number;
            myset.insert(number);
        }
        if(command=="SETDEL"){
            request_string>>number;
            myset.erase(number);
        }
        if(command=="SET_AT"){
            request_string>>number;
            if(myset.contains(number))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        if(command=="PRINT")
            myset.print();
        myset.close(struct_filename);
    }
}
