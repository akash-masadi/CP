//https://www.naukri.com/code360/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
using namespace std;
class Trie 
{
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
        Node* get (char c)
        {
            return arr[c-'a'];
        }
        void create(char c)
        {
            arr[c-'a']=new Node();
        }
        void set()
        {
            flag=true; // denotes the ending part
        }
        bool isEnd()
        {
            return flag;
        }
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node -> containsKey(word[i]))
            {
                node->create(word[i]);
            }
            node = node -> get(word[i]);
        }
        node -> set();
    }
    
    bool check(string word)
    {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if(!node->isEnd())
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        } 
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie* trie = new Trie();
    for(int i=0;i<n;i++)
    {
        trie->insert(a[i]);
    }
    string ans = "";
    for(int i=0;i<n;i++)
    {
        if(trie->check(a[i]))
        {
            if(ans.length()<a[i].length())
            {
                ans=a[i];
            }
            else if(ans.length() == a[i].length() && a[i] < ans) 
            {
                ans=a[i];
            }
        }
    }
    return ans==""?"None":ans;
}