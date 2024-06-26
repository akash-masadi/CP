#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow1(double x, int n) {
        double ans = 1;
        if(n<0)
        {
            return 1 / ( myPow1(x, 0-(n+1))* x );
        }
        while(n)
        {
            if(n&1)
            {
                ans*=x;
            }
            x*=x;
            n/=2;
        }
        return ans;
    }
    double myPow1(double x, int n, double ans) 
    {
        // double ans = 1;
        if(n<0)
        {
            return 1 / ( myPow1(x, 0-(n+1), ans)* x );
        }
        if(n==0) return ans;
        if(n&1)
        {
            ans*=x;
        }
        x*=x;
        return myPow1(x, n/2, ans);
    }
};


int main()
{
    Solution s;
    cout<<s.myPow1(-1, -2147483648)<<endl;
    cout<<s.myPow1(1, -2147483648)<<endl;
    cout<<s.myPow1(-2, -2147483648)<<endl;
    cout<<s.myPow1(2.10000, 3)<<endl;
    cout<<s.myPow1(2.00000, -2)<<endl;
    return 0;
}
