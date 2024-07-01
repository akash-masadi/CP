#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        class djs
        {
        public:
            vector<int> parent;
            vector<int> rank;
            djs(int n)
            {
                parent.resize(n+2);
                rank.resize(n+2,0);
                for(int i=0;i<=n;i++)   parent[i]=i;
            }
            int find(int u)
            {
                if(u==parent[u]) 
                    return u;
                return parent[u]=find(parent[u]);
            }
            bool union_both(int u,int v)
            {
                int uPar=find(u);
                int vPar=find(v);
                if(uPar == vPar) return true; // no need to add that edge && remove that edge
                if(rank[uPar]>rank[vPar])
                {
                    parent[vPar] = uPar; 
                }
                else if (rank[uPar]<rank[vPar])
                {
                    parent[uPar] = vPar;
                }
                else
                {
                    parent[uPar]=vPar;
                    rank[vPar]++;
                }
                return false;
            }
            void print()
            {
                for(int i=0;i<parent.size();i++) cout<<i<<" - > "<<parent[i]<<" Rank: "<<rank[i]<<'\n';
            }
        };
        int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
            djs* alice = new djs(n); 
            djs* bob = new djs(n); 
            int removed_Edges=0;
            int bob_edges=0,alice_edges=0;
            // cout<<"Alice :\n";
            // alice->print();
            // cout<<"Bob :\n";
            // bob->print();
            for(int i=0;i<edges.size();i++)
            {
                int type = edges[i][0];
                int u = edges[i][1];
                int v = edges[i][2];
    
                if(type==3)
                {
                    bool aAlready = alice->union_both(u,v);
                    bool bAlready = bob->union_both(u,v);
                    if(aAlready && bAlready)
                    {
                        removed_Edges+=1;
                    }
                    else if(aAlready) // if it is true that means removed_Edges B formed a edge
                    {
                        removed_Edges+=1;
                        bob_edges++; // b++;
                    }
                    else if(bAlready) //if it is true that means removed_Edges A formed a edge
                    {
                        removed_Edges+=1;
                        alice_edges++;
                    }
                    else /// So 2 false that means removed_Edges A and B formed a edge
                    {
                        bob_edges++;
                        alice_edges++;
                    }
                }
                else if(type==2)
                {
                    if(bob->union_both(u,v))
                    {
                        removed_Edges+=1;
                    }
                    else
                    {
                        bob_edges++;
                    }
                }
                else
                {
                    if(alice->union_both(u,v))
                    {
                        removed_Edges+=1;
                    }
                    else
                    {
                        alice_edges+=1;
                    }
                }
                cout<<"Alice :\n";
                alice->print();
                cout<<"Bob :\n";
                bob->print();
            }
            return alice_edges==n-1 && bob_edges==n-1 ? removed_Edges : -1;
        }
    };
    