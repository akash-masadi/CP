#include <bits/stdc++.h>
using namespace std;
void myprint(vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << '\n';
};

void bucketSort(std::vector<int>& vec) {
    int maxVal = 0;
    for (int val : vec) {
        maxVal = max(maxVal, val);
    }
    maxVal++;

    map<float, int> mp;
    vector<vector<float>> v(vec.size());

    for (int i = 0; i < vec.size(); i++) {
        float t = (1.0f*vec[i]) / maxVal;
        mp[t] = vec[i];
        int idx = (t * vec.size());
        v[idx].push_back(t);
    }

    for (int i = 0; i < vec.size(); i++) {
        sort(v[i].begin(), v[i].end());
    }

    int idx = 0;
    for (int i = 0; i < vec.size();i++) {
        for (float t : v[i]) {
            vec[idx++] = mp[t];
        }
    }
};

int main() {
    vector<int> vec = {99999, 83, 17, 46, 56, 4888, 12, 1};

    myprint(vec);
    bucketSort(vec);
    myprint(vec);

    return 0;
}
