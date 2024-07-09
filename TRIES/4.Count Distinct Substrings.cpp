//https://www.naukri.com/code360/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;

class Node
{
    public:
    vector<Node*> arr;
    bool flag;
    Node()
    {
        arr.resize(26,NULL);
        flag=false;
    }

    bool containsKey(char c)
    {
        return arr[c-'a']!=NULL;
    }
    bool set()
    {
        flag=true;
    }
    bool isSet()
    {
        return flag;
    }
    void create(char c)
    {
        arr[c-'a']=new Node();
    }
    Node* get(char c)
    {
        return arr[c-'a'];
    }
};
int countDistinctSubstrings(string &s)
{
    int ans=1;
    int n=s.length();
    Node* root = new Node();
    for(int i=0;i<n;i++)
    {
        Node* node = root;
        for(int j=i;j<n;j++)
        {
            if(!node->containsKey(s[j]))
            {
                // cout<<i<<" -> "<<j<<" | "<<s[j]<<'\n';
                ans++;
                node->create(s[j]);
            }
            node = node-> get(s[j]);
        }
    }
    return ans;
}
/*
0 -> 0 | a
0 -> 1 | b
0 -> 2 | a
0 -> 3 | b
a
ab
aba
abab

1 -> 1 | b
1 -> 2 | a
1 -> 3 | b
b
ba
bab

2 -> 3 | b
a
ab
9
*/


// naive approach
// class Trie
// {
//     private:
//     class Node
//     {
//         public:
//         vector<Node*> arr;
//         bool flag;
//         Node()
//         {
//             arr.resize(26,NULL);
//             flag=false;
//         }

//         bool containsKey(char c)
//         {
//             return arr[c-'a']!=NULL;
//         }
//         bool set()
//         {
//             flag=true;
//         }
//         bool isSet()
//         {
//             return flag;
//         }
//         void create(char c)
//         {
//             arr[c-'a']=new Node();
//         }
//         Node* get(char c)
//         {
//             return arr[c-'a'];
//         }
//     };
//     Node* root;
//     public:

//     Trie()
//     {
//         root=new Node(); 
//     }

//     bool insert(string w)
//     {
//         Node* node = root;
//         for(int i=0;i<w.length();i++)
//         {
//             if(!node->containsKey(w[i]))
//             {
//                 node->create(w[i]);
//             }
//             node = node->get(w[i]);
//         }
//         if(node->isSet()) return false;
//         node->set();
//         return true;
//     }
// };
// int countDistinctSubstrings(string &s)
// {
//     Trie trie;
//     int ans=1;
//     int n=s.length();
//     for(int i=0;i<n;i++)
//     {
//         string t="";
//         for(int j=i;j<n;j++)
//         {
//             t+=s[j];
//             // cout<<t;
//             if(trie.insert(t))
//             {
//                 // cout<<" -> Yes";
//                 ans+=1;
//             }
//             // cout<<'\n';
//         }
//     }
//     return ans;
// }