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
int isBalancedBST(Node* root);
Node* insert(Node* root,int data);
void level_order( Node* root);


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
        int size=q.size();
        while(size--)
        {
            Node* curr = q.front();
            q.pop();
            if(curr)
            {
                cout<<curr->data<<'\t';
                q.push(curr->left);
                q.push(curr->right);
            }
            else{
                cout<<"_\t";
            }
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int isBalancedBST(Node* root)
{
    if(!root) return 1;
    int l=  isBalancedBST(root->left);
    int r= isBalancedBST(root->right);
    if(l==-1 || r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return max(l,r)+1;
}


Node* make(vector<int> inorder,int l,int h)
{
    if(l>h) return nullptr;
    int mid=(l+h)/2;
    Node* root = new Node(inorder[mid]);
    root->left = make(inorder,l,mid-1); 
    root->right = make(inorder,mid+1,h);
    return root; 
}
Node* balance_BST(Node* root)
{
    if(!root) return root;
    vector<int> inorder;
    vector<Node*> st;
    Node* curr = root;
    while(true)
    {
        while(curr)
        {
            st.push_back(curr);
            curr=curr->left;
        }
        if(st.empty()) break;
        curr=st.back();
        st.pop_back();
        inorder.push_back(curr->data);
        curr=curr->right;
    }
    cout<<'\n';
    return make(inorder,0,inorder.size()-1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,data;
        cin>>n;
        Node* root=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>data;
            root=insert(root,data);
        }
        level_order(root);
        cout<<"Is this a BBST :"<<(isBalancedBST(root)!=-1)<<'\n';
        root =balance_BST(root);
        level_order(root);
        cout<<"Is this a BBST :"<<(isBalancedBST(root)!=-1)<<'\n';
    }
}








// int height(Node* root)
// {
//     if(root==nullptr) return 0;
//     return max(height(root->right),height(root->left))+1;
// }
// Node* rightRotate(Node* root)
// {
//     Node* save_left = root->left;
//     Node* save_left_right=save_left->right;
//     root->left=save_left_right;
//     save_left->right=root;
//     return save_left;
// }
// Node* leftRotate(Node* root)
// {
//     Node* save_right = root->right;
//     Node* save_right_left=save_right->left;
//     root->right=save_right_left;
//     save_right->left=root;
//     return save_right;
// }


// // convert it into Balanced Binary Search Tree

// Node* balance(Node* root)
// {
//     if(root==NULL) return root;
//     int left_height=height(root->left);
//     int right_height=height(root->right);
//     int balance_factor= left_height-right_height;
    
//     if(balance_factor>1) // left > right
//     {
//         // left -left or left right
//         if(height(root->left->left)>height(root->left->right))// left - left
//         {
//             return rightRotate(root);
//         }
//         else // left-right 
//         {
//             root->left = leftRotate(root->left);
//             return rightRotate(root);
//         }
//     }
//     if(balance_factor<-1) // right > left
//     {
//         // right - right || right - left
//         if(height(root->right->right)<height(root->right->left))
//         {
//             return leftRotate(root);
//         }
//         else // right - left
//         {
//             root->right=rightRotate(root->right);
//             return leftRotate(root);
//         }
//     }
//     return root;
// }

// Node* balance_BST(Node* root)
// {
//     if(!root) return root;
//     root->right = balance_BST(root->right);
//     root->left = balance_BST(root->left);
//     root=balance(root);
//     return root;
// }