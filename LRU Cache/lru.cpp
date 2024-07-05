// #include <iostream>
// #include <string>
// using namespace std;
#include<bits/stdc++.h>
using namespace std;
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class LRUCache {
public:
    // DLL node class
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    // Required members
    int capacity;
    int size;
    Node* dummy;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    // Constructor 
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->dummy = new Node(-1, -1);
        this->head = dummy;
        this->tail = dummy;
    }

    // Debug print
    void print(string s) {
        cout << s << '\n';
        Node* temp = dummy->next;
        while (temp) {
            cout << temp->key << " -> " << temp->val << '\t';
            temp = temp->next;
        }
        cout << "\n\n";
    }

    void joinAtTail(Node* curr) {
        if (tail == curr) return;

        // Remove the curr node
        if (curr->next) {
            curr->next->prev = curr->prev; // Link next with prev
        }
        curr->prev->next = curr->next; // Link prev to next node

        // Rejoin at the tail
        tail->next = curr;
        curr->prev = tail;
        curr->next = NULL;
        tail = curr;
    }

    void reduceSize() 
    {
        if (head->next) 
        {
            mp.erase(head->next->key); // Remove from the map
            Node* temp = head->next;
            head->next = temp->next; // Remove the link
            if (temp->next) 
            {
                temp->next->prev = head;
            } 
            else 
            {
                tail = head; // If we removed the last node
            }
            delete temp;
            size--;
        }
    }

    int get(int key) {
        /*
            1. Check in the hashmap
            2. If Yes, update its position to the tail
            3. While re-positioning, when tail == req node no change
        */
        // print("before get " + to_string(key));
        if (mp.find(key) != mp.end()) {
            Node* curr = mp[key];
            if (tail != curr) 
            {
                joinAtTail(curr);
            }
            // print("after get " + to_string(key));
            return curr->val;
        }
        // print("after get " + to_string(key));
        return -1;
    }

    void insert(int key, int value) 
    {
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void put(int key, int value) {
        /*
            1. Check for existence of the node
            2. If yes, just update the value, get it to the top
        */
        // print("before put " + to_string(key) + " - " + to_string(value));
        if (mp.find(key) != mp.end()) 
        {
            Node* curr = mp[key];
            curr->val = value;
            joinAtTail(curr);
        } else {
            if (size >= capacity) {
                reduceSize();
            }
            insert(key, value);
        }
        // print("after put " + to_string(key) + " - " + to_string(value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */



int main() {
    // Create an LRUCache with a capacity of 2
    LRUCache* cache = new LRUCache(2);

    // Insert some values
    cache->put(1, 1); // Cache is {1=1}
    cache->put(2, 2); // Cache is {1=1, 2=2}

    // Access some values
    cout << "get(1): " << cache->get(1) << endl; // Returns 1, Cache is {2=2, 1=1}

    // Insert more values
    cache->put(3, 3); // LRU key 2 evicted, Cache is {1=1, 3=3}

    // Access some values
    cout << "get(2): " << cache->get(2) << endl; // Returns -1 (not found)

    // Insert more values
    cache->put(4, 4); // LRU key 1 evicted, Cache is {3=3, 4=4}

    // Access some values
    cout << "get(1): " << cache->get(1) << endl; // Returns -1 (not found)
    cout << "get(3): " << cache->get(3) << endl; // Returns 3
    cout << "get(4): " << cache->get(4) << endl; // Returns 4

    // Clean up
    delete cache;

    return 0;
}
