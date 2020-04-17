#include <iostream>
using namespace std;

struct Node{
    int Value;
    Node* Right;
    Node* Left;
};

class BST{
    Node* m_Root;
    void Post_Print(Node* root)const{
        if(root != nullptr){
            Post_Print(root->Left);
            Post_Print(root->Right);
            cout<<root->Value<<endl;
        }
    }
    void Insert(Node*& root, int value){
        if(root == nullptr){
            root = new Node;
            root->Value = value;
            root->Left = nullptr;
            root->Right = nullptr;
        }
        
        else if(root->Value > value){
            Insert(root->Left, value);
        }
        else if (root->Value < value){
            Insert(root->Right, value);
        }
    }
public:
    BST(){m_Root = nullptr;}
    void Print()const{Post_Print(m_Root);}
    void Add(int value){Insert(m_Root, value);}
};


int main(){
    BST bst; int value;
    while(cin>>value){
        bst.Add(value);
    }
    
    bst.Print();
}
