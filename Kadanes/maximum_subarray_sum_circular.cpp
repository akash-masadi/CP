#include <bits/stdc++.h>
using namespace std;

int kadaneMax(const vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}

int kadaneMin(const vector<int>& arr) {
    int min_current = arr[0];
    int min_global = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        min_current = min(arr[i], min_current + arr[i]);
        if (min_current < min_global) {
            min_global = min_current;
        }
    }
    return min_global;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Case 1: Maximum subarray sum for non-circular case
        int max_kadane = kadaneMax(arr);

        // Case 2: Maximum subarray sum for circular case
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        int min_kadane = kadaneMin(arr);
        int max_circular = total_sum - min_kadane;

        // If all numbers are negative, max_circular would be 0, which is incorrect.
        // Therefore, we only take max_circular into account if it is not 0.
        int result;
        if (max_circular == 0 || max_kadane < 0) {
            result = max_kadane;
        } else {
            result = max(max_kadane, max_circular);
        }

        cout << result << "\n";
    }
    return 0;
}
