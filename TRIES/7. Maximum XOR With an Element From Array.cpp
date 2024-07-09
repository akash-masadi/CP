
//https://www.naukri.com/code360/problems/max-xor-queries_1382020?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=PROBLEM


#include <bits/stdc++.h> 
using namespace std;

// custom comparator for sorting
struct compare
{
	bool operator () ( vector<int> a,vector<int> b)
	{
		// sorting accdng to the bound
		return a[1]<=b[1];
	}
};
// Node implementation
class Node
{
	public:
	Node* a[2];
	Node()
	{
		a[0]=NULL;
		a[1]=NULL;
	}

	bool containsKey(int bit)
	{
		return a[bit]!=NULL;
	}

	void create (int bit)
	{
		a[bit] = new Node();
	} 

	Node* get(int bit)
	{
		return a[bit];
	}
};

// insert into Trie
void insert(Node* root,int a)
{
	Node* node = root;
	for(int i=31;i>=0;i--)
	{
		int current_bit = (a>>i)&1;
		// cout<<current_bit<<'\n';
		if(!node->containsKey(current_bit))
		{
			node->create(current_bit);
		}
		node = node->get(current_bit);
	}
}

// function to calculate the maximum XOR for the following number with respective TRIE
int find(Node* root,int a)
{
	int ans=0;
	Node* node = root;
	for(int i = 31;i>=0;i--)
	{
		int current_bit = (a>>i)&1;
		if(node->containsKey(!current_bit))
		{
			ans |= (1<<i);
			node = node->get(!current_bit);
		}
		else{
			node = node->get(current_bit); 
		}
	}
	return ans;

}
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<vector<int>> q;
	int n = queries.size();
	for(int i=0;i<n;i++)
	{
		queries[i].push_back(i);
		q.push_back(queries[i]);
	}
	// sorting the original array
	sort(arr.begin(),arr.end());
	// sorting q
	sort(q.begin(),q.end(),compare());
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<q[i][0]<<" - "<<q[i][1]<<" - "<<q[i][2]<<'\n';
	// }
	// trie root
	Node* root=new Node();

	// arr var
	int j=0;
	int m = arr.size();

	//answer vector
	vector<int>ans(n,-1);

	for(int i=0;i<n;i++)
	{
		// q[i]
		int original_index = q[i][2];
		if(q[i][1]<arr[0])
		{
			ans[original_index]=-1;
		}
		else
		{
			while(j<m && arr[j]<=q[i][1])
			{
				insert(root,arr[j]);
				j++;
			}

			int currMax = find(root,q[i][0]);
			ans[original_index]=currMax;
		}
	}
	return ans;
}