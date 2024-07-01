/*
https://leetcode.com/problems/longest-palindromic-subsequence/
*/

#include<bits/stdc++.h>	
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> prev(n), cur(n);
        
        for(int i = 0; i < n; i++){
            cur[i] = 1;
            for(int j = i-1; j >= 0; j--){
                if(s[i] == s[j]){
                    cur[j] = 2 + prev[j+1];
                }else{
                    cur[j] = max(prev[j], cur[j+1]);
                }
            }
            prev = cur;
        }

        return prev[0];
    }
};

/*
	b a b b b
b	1 0 0 0 0 
a	1 1
b	2 1 1
b	4 2 2 1
b	4 3 3 2 1





	b b b a b
b	1 1 1 1 1
a	1 1 1 2 2
b	1 2 2 2 3
b   1 2 3 3 3
b   1 2 3 3 4  //bbbb
*/


