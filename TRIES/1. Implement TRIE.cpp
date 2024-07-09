/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
    https://www.naukri.com/code360/problems/implement-trie_631356?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
 */
#include <bits/stdc++.h> 
using namespace std;
class Trie {
    class Node
    {
    public:
        Node* arr[26];
        bool flag;
        Node()
        {
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

    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node -> get(word[i]);
        }
        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) 
    {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node -> get(word[i]);
        }
        return true;
    }
};