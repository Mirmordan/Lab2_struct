#include <iostream>
#include <sstream>
using namespace std;    //Number 6 !
class BinTree{
    struct Node{
        int value;
        Node*left;
        Node*right;
        Node();
        Node(int value);
    };
    public:
    BinTree();
    void PUSH(int value);
    void PRINT_LEAVES();
    private:
    void print_recursion(Node* node);
    Node *_root;
};
////////////////////////////////////////////////Сам вывод
void BinTree::print_recursion(Node* node){
    if(node->left!=nullptr)
        print_recursion(node->left);
    if(node->right!=nullptr)
        print_recursion(node->right);
    if(node->right==nullptr and node->left==nullptr)
        cout<<node->value<<" ";
}
void BinTree::PRINT_LEAVES(){
    if(_root!=nullptr)
        print_recursion(_root);
    cout<<endl;
}
////////////////////////////////////Вспомогательные методы
void BinTree::PUSH(int value){
    Node** input_node=&_root;
    while(*input_node!=nullptr)
        if((*input_node)->value<value)
            input_node=&(*input_node)->right;
        else
            input_node=&(*input_node)->left;
    *input_node=new Node(value);
}
BinTree::Node::Node(){
    left=right=nullptr;
}
BinTree::Node::Node(int value):Node(){
    this->value=value;
}
BinTree::BinTree(){
    _root=nullptr;
}


int main()
{
    cout<<"Введите элементы дерева"<<endl;
    string input;
    getline(cin,input);
    stringstream input_stream(input);
    int num;
    BinTree tree;
    while(input_stream>>num)
        tree.PUSH(num);
    tree.PRINT_LEAVES();
    return 0;
}

