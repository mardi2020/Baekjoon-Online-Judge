#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

class Tree{
public:
    Tree(){
        Root = nullptr;
        Loc = nullptr;
    }
    void Insert(char pData, char lData, char rData){
        if(pData == 'A'){
            Node *PNode = new Node;
            PNode->left = nullptr; PNode->right =nullptr;
            PNode->data = pData;
            if(lData != '.'){
                Node* LNode = new Node;
                LNode->data = lData;
                LNode->left = nullptr;
                LNode->right = nullptr;
                PNode->left = LNode;
            }
            if(rData != '.'){
                Node* RNode = new Node;
                RNode->data = rData;
                RNode->left = nullptr;
                RNode->right = nullptr;
                PNode->right = RNode;
            }
            Root = PNode;
        }else{
            Search(Root, pData);
            if(lData != '.'){
                Node *left = new Node;
                left->data = lData;
                left->left = nullptr;
                left->right = nullptr;
                Loc->left = left;
            }
            if(rData != '.'){
                Node *right = new Node;
                right->data = rData;
                right->left = nullptr;
                right->right = nullptr;
                Loc->right = right;
            }
        }
    }
     void Search(Node* curr, char p){
        if(curr == nullptr)
            return;
        if(curr->data == p){
            Loc = curr;
        }else{
            Search(curr->left, p);
            Search(curr->right, p);
        }
    }
    
    void PrintPre(){Pre_order(Root);}
    void PrintPost(){Post_order(Root);}
    void PrintIn(){In_order(Root);}
    
private:
    void Pre_order(Node* root)const{
        if(root != nullptr){
            cout<<root->data;
            Pre_order(root->left);
            Pre_order(root->right);
        }
    }
    void In_order(Node* root)const{
        if(root != nullptr){
            In_order(root->left);
            cout<<root->data;
            In_order(root->right);
        }
    }
    void Post_order(Node* root)const{
        if(root != nullptr){
            Post_order(root->left);
            Post_order(root->right);
            cout<<root->data;
        }
    }
    // member variable
    Node* Root;
    Node* Loc;
};

int main(){
    int N; cin>>N;// N is the number of nodes
    Tree tree;
    char parent, left, right;
    
    while(N--){
        cin>>parent>>left>>right;
        tree.Insert(parent, left, right);
    }
    // Print 3 ways
    tree.PrintPre();
    cout<<endl;
    tree.PrintIn();
    cout<<endl;
    tree.PrintPost();
    cout<<endl;
    
}
