#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int sum=0;
        int ans=0;
        int ansStart=0;
        int ansEnd=0;
        int s=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum<0)
            {
                s=i+1;
                sum=0;
            }
            if(ans<sum)
            {
                ansStart=s;
                ansEnd=i;
                ans=sum;
            }
        }
        if(sum>0 && ans<sum)
        {
                    ansStart=s;
                    ansEnd=n-1;
                    ans=sum;
        }
        cout<<ans<<" "<<ansStart<<" "<<ansEnd<<"\n";
    }
    return 0;
}
