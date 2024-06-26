// ctrl+shift+b === to run

#include<bits/stdc++.h>
using namespace std;


/// BST Node
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};



// Insertion into BST
Node* insert(Node* root,int data)
{
    if(root==NULL)
    {
        return (Node*) new Node(data);
    }
    if(root->data>data)
    {
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

// Level order traversal
void level_order( Node* root)
{
    if(!root) return;
    cout<<"\nThe level order traversal : \n";
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<'\t';
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,data;
        cin>>n;
        Node* root;
        for(int i=0;i<n;i++)
        {
            cin>>data;
            root=insert(root,data);
        }
        level_order(root);
        // isBSt(root);
        // convert_into_BST(root);
    }


}