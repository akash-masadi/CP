//https://www.naukri.com/code360/problems/maximum-xor_973113?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    Node* arr[2];
    bool flag;

    Node() {
        arr[0] = nullptr;
        arr[1] = nullptr;
    }

    bool containsKey(int i) {
        return arr[i] != nullptr;
    }

    void create(int i) {
        arr[i] = new Node();
    }

    Node* get(int i) {
        return arr[i];
    }
};

int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2) {
    Node* root = new Node();

    // Build the Trie with arr1
    for (int i = 0; i < n; i++) {
        Node* node = root;
        for (int j = 31; j >= 0; j--) {
            int currentBit = (arr1[i] >> j) & 1;
            if (!node->containsKey(currentBit)) {
                node->create(currentBit);
            }
            node = node->get(currentBit);
        }
    }

    int ans = 0;
    // Check the maximum XOR with elements from arr2
    for (int i = 0; i < m; i++) {
        int currAns = 0;
        Node* node = root;
        for (int j = 31; j >= 0; j--) 
        {
            int currentBit = (arr2[i] >> j) & 1;
            if (node->containsKey(!currentBit)) 
            {
                currAns |= (1 << j);
                node = node->get(!currentBit);
            } 
            else 
            {
                node = node->get(currentBit);
            }
        }
        ans = max(currAns, ans);
    }

    return ans;
}