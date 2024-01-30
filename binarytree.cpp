#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class BinaryTree{
    public:
    int i=-1;
    Node* buildTree(int nodes[]){
        i++;
        if(nodes[i]==-1){
            return NULL;
        }   

        Node* newNode = new Node(nodes[i]);
        newNode->left=buildTree(nodes);
        newNode->right=buildTree(nodes);

        return newNode;
    }
};

void preorder(Node* root){
    if(root==NULL){
        cout<<"-1 ";
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        cout<<"-1 ";
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        cout<<"-1 ";
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            cout<<endl;
        }
    }
}

int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    BinaryTree* tree = new BinaryTree();
    Node* root=tree->buildTree(nodes);
    //preorder(root);
    //inorder(root);
    //postorder(root);
    levelOrder(root);
}