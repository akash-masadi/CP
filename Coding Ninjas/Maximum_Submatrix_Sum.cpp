// This code effectively finds the maximum sum submatrix in a 2D matrix with a time complexity of O(N*N*M)
// Extenede Kadane's algorithm
#include <bits/stdc++.h>
using namespace std;

int kadanes(vector<int> arr, int n) {
    int ans = INT_MIN;
    int sum = 0;
    for (int i=0;i<n;i++) 
    {
        sum += arr[i];
        ans = max(sum, ans);
        sum = max(sum, 0); // whenever ans becomes zero or less change to zero; 
    }
    return ans;
}

int maxSumSubmatrix(vector<vector<int>>& mat, int n, int m) {
    int ans = INT_MIN;
    vector<int> rsum(m, 0);
    for (int rr = 0; rr < n; rr++) 
    {
        fill(rsum.begin(), rsum.end(), 0);
        for (int r = rr; r < n; r++) 
        {
            for (int c = 0; c < m; c++) 
            {
                rsum[c] += mat[r][c];
            }
            ans = max(ans, kadanes(rsum, m));
        }
    }
    return ans;
}

int main() {
    int n = 4, m = 5;
    vector<vector<int>> mat = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };

    int result = maxSumSubmatrix(mat, n, m); // Output :- 29
    cout << "Maximum sum submatrix: " << result << endl;

    return 0;
}