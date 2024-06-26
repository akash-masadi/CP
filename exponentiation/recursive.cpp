#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
        {
            return 1 / (myPow(x,abs(n+1)) * x);
        }
        if(n==0) return 1;
        double y = myPow(x,n/2);
        y*=y;
        if(n&1) y*=x;
        return y;
    }
};


int main()
{
    Solution s;
    cout<<s.myPow(-1, -2147483648)<<endl;
    cout<<s.myPow(1, -2147483648)<<endl;
    cout<<s.myPow(-2, -2147483648)<<endl;
    cout<<s.myPow(2.10000, 3)<<endl;
    cout<<s.myPow(2.00000, -2)<<endl;
    return 0;
}
