//https://www.naukri.com/code360/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
#include <bits/stdc++.h> 
using namespace std;
class Trie {
    class Node
    {
    public:
        Node* arr[26];
        int countPrefix;
        int flag;
        Node()
        {
            countPrefix=0;
            flag=0;
        }
        // check for availabilty
        bool containsKey(char c)
        {
            return arr[c-'a']!=NULL;
        }
        // to get the node
        Node* get (char c)
        {
            return arr[c-'a'];
        }
        void create(char c)
        {
            countPrefix=0;
            arr[c-'a']=new Node();
        }
        void remove(char c)
        {
            countPrefix--;
            delete arr[c-'a'];
            arr[c-'a']=NULL;
        }
        // increase the character count
        void increment()
        {
            countPrefix++;
        }
        // decrease the character count
        void decrement()
        {
            countPrefix--;
        }
        // get the character count;
        int getCount()
        {
            return countPrefix;
        }
        // count the words ending here at this node
        void set()
        {
            flag++; // denotes the ending part
        }
        int getFlag()
        {
            return flag;
        }
        // count the words ending here at this node
        void unset()
        {
            flag--; // denotes the ending part
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
        // cout<<"Insert :\n";
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node -> containsKey(word[i]))
            {
                node->create(word[i]);
            }
            node -> increment();
            node = node -> get(word[i]);
            // cout<<word<<" -> "<<word[i]<<" = "<<node->getCount(word[i])<<"\n";
        }
        node -> set();
        // cout<<node->flag<<"\n\n";
    }

    /** Returns if the word is in the trie. */
    int countWordsEqualTo(string word) 
    {
        // cout<<"Checkig :\n";
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            // cout<<word<<" -> "<<word[i]<<" = "<<node->getCount(word[i])<<" | "<<node->getFlag()<<"\n";
            node = node -> get(word[i]);
        }
        // cout<<"\n";
        return node->getFlag();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    int countWordsStartingWith(string word) 
    {
        Node* node = root;
        int ans=1e9;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            ans = min(ans,node->getCount()); 
            node = node -> get(word[i]);
        }
        return ans;
    }
    void erase(string word)
    {
        Node* node = root;
        Node* next = root;
        for(int i=0;i<word.length();i++)
        {

            next = node -> get(word[i]);

            node -> decrement();

            if(node->getCount()==0)
            {
                node->remove(word[i]);
            }
            node=next;
        }
        node -> unset();
    }
};

/*
Insert :
coding -> c = 0
coding -> o = 0
coding -> d = 0
coding -> i = 0
coding -> n = 0
coding -> g = 0
1

Insert :
ninja -> n = 0
ninja -> i = 0
ninja -> n = 0
ninja -> j = 0
ninja -> a = 0
1

Checkig :
coding -> c = 1 | 0
coding -> o = 1 | 0
coding -> d = 1 | 0
coding -> i = 1 | 0
coding -> n = 1 | 0
coding -> g = 1 | 0

1
1
Insert :
samsung -> s = 0
samsung -> a = 0
samsung -> m = 0
samsung -> s = 0
samsung -> u = 0
samsung -> n = 0
samsung -> g = 0
1

Insert :
samsung -> s = 0
samsung -> a = 0
samsung -> m = 0
samsung -> s = 0
samsung -> u = 0
samsung -> n = 0
samsung -> g = 0
2

Insert :
vivo -> v = 0
vivo -> i = 0
vivo -> v = 0
vivo -> o = 0
1

Checkig :
samsung -> s = 2 | 0
samsung -> a = 2 | 0
samsung -> m = 2 | 0
samsung -> s = 2 | 0
samsung -> u = 2 | 0
samsung -> n = 2 | 0
samsung -> g = 2 | 0
1
0
*/