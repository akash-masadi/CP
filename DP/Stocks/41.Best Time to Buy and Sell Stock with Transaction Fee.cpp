/*

https://www.naukri.com/code360/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

*/

#include<bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices, int n, int fee)
{
	vector<int> ahead(2,0);
    for(int i=n-1;i>=0;i--)
    {
		vector<int> curr(2,0);
        curr[0] = max(ahead[0],ahead[1]-prices[i]);
        curr[1] = max(ahead[1],ahead[0]+prices[i]-fee);
		ahead=curr;
    }
    return ahead[0];
}
