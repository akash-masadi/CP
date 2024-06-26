#include <bits/stdc++.h>
using namespace std;
void myprint(vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << '\n';
};

void bucketSort(vector<int>& vec) {
    int t=vec.size();
    vector<vector<int>> buckets(t);
    int maxVal=*max_element(vec.begin(),vec.end())+1;
    for(int i=0;i<t;i++)
    {
        float curr = vec[i];
        float val = curr/maxVal;
        int idx = val*t;
        cout<<vec[i]<<" -- > " <<val<<" -- "<<idx<<'\n';
        buckets[idx].push_back(vec[i]);
        if(buckets[idx].size()>1)
        {
            int j=buckets[idx].size()-2;
            while(buckets[idx][j]>curr && j>=0)
            {
                buckets[idx][j+1]=buckets[idx][j];
                j--;
            }
            buckets[idx][j+1]=vec[i];
        }
    }
    int i=0;
    for(int idx=0;idx<t;idx++)
    {
        for(int j:buckets[idx])
        {
            vec[i]=j;
            i++;
        }
    }
};

int main() {
    // vector<int> vec = {99999, 83, 17, 46, 56, 4888, 12, 1};
    vector<int> vec = {1000, 2, 300, 5000, 1, 700, 2500, 3, 1500, 100};
    // vector<int> vec = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68, 45, 34, 89, 56, 90, 11, 37, 84, 5, 44, 77, 55, 66, 88, 22, 33, 99, 58, 29, 74, 87, 63, 35, 92, 6, 40, 81, 19, 50, 25, 43, 54, 98, 30, 13, 75, 85, 48, 71, 4, 27, 95, 20, 79, 60, 93, 46, 36, 83, 57, 70, 3, 31, 62, 80, 47, 9, 73, 7, 38, 59, 76, 8, 32, 91, 14, 86, 49, 18, 69, 53, 82, 64, 1, 15, 41, 65, 42, 61, 10, 67, 16, 24, 2, 28, 52, 96, 51, 100, 97};
    myprint(vec);
    bucketSort(vec);
    myprint(vec);

    return 0;
}
