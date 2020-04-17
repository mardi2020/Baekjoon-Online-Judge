#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Tree{
public:
    Tree(){
        Root = nullptr;
        Loc = nullptr;
        Count = 0;
    }
    Tree(int cnt){
        Root = nullptr;
        Loc = nullptr;
        Count = cnt;
    }
    void Insert(int Inorder[], int preorder[]){ // In order 기준
        if(Root == nullptr){ //first insert
            Node* newNode = new Node;
            newNode->data = preorder[Count];
            newNode->left = nullptr;
            newNode->right = nullptr;
            Root = newNode;
        }else{
            
        }
    }
    
    void PrintPre(){Pre_order(Root);}
    void PrintPost(){Post_order(Root);}
    void PrintIn(){In_order(Root);}
    
private:
    void Pre_order(Node* root)const{
        if(root != nullptr){
            cout<<root->data<<' ';
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
    int Count;
};

int main(){
    int N; cin>>N;// N is the number of nodes
    Tree tree(N);
    int inorder[N], postorder[N];
    
    for(int i = 0 ; i < N ; i++){
        cin>>inorder[i];
    }
    for(int i = 0; i < N ; i++){
        cin>>postorder[i];
    }
       
    
    // Pre order
    tree.PrintPre();
    
    
}
