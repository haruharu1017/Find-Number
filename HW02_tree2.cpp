#include <iostream>
#include <sstream>
using namespace std;

template <class Item>
class binaryTreeNode //construct the binary tree node structure
{
    public:
    Item dataField;
    binaryTreeNode *leftField;
    binaryTreeNode *rightField;
    binaryTreeNode(const Item& item): dataField(item),leftField(nullptr),rightField(nullptr){}
};

template <class Item>
void insertBST(binaryTreeNode<Item> *& root, const Item& val) // the BST insert function
{
    if(root==nullptr){
        root=new binaryTreeNode<Item>(val);
        return;
    }
    
    if(val<root->dataField){
        insertBST(root->leftField, val);
    }else{
        insertBST(root->rightField, val);
    }
} 

template <class Item>
bool searchBST(binaryTreeNode<Item> * root, const Item& val) //the BST search function
{
    if(root==nullptr){
        return false;
    }

    if(root->dataField==val){
        return true;
    }else if(val<root->dataField){
        return searchBST(root->leftField, val);
    }else{
        return searchBST(root->rightField, val);
    }
}

int main()
{
    //initialize the vars to be used
    int X=0;
    int placard=0;
    string text1, text2;
    binaryTreeNode<int>* root=nullptr;

    //prompt the users to input the number
    cout<<"enter the number on the placard: ";
    getline(cin, text1);
    stringstream s(text1); //Challenge: I searched the function to extract integer from a string
    while(s>>placard){
        insertBST(root, placard);
    }

    cout<<"enter the number X: ";
    getline(cin, text2);
    stringstream S(text2);

    //print the result
    while(S>>X){
        if(searchBST(root, X)){
            cout<<"YES ";
        }else{
            cout<<"NO ";
        }
    }
}