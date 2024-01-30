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

int sumAtK(Node* root,int k){
    if(root==NULL){
        return NULL;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level =0;
    int sum=0;
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if (!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main(){
    int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    BinaryTree* tree = new BinaryTree();
    Node* root=tree->buildTree(nodes);
    cout<<sumAtK(root,2);
}