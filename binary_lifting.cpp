#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

// finding the kth parent takes logn
int kthparent(int x,int k,vector<vector<int>>par)
{
    for(int i=log2(k);i>=0;i--)
    {
        if((1<<i)&k)
        {
            x=par[x][i];
        }
    }
    return x;
}


// for setting the parent of every node

void dfs(int idx,int p,unordered_map<int,vector<int>>&adj,vector<vector<int>>&par)
{
    par[idx][0]=p;
    for(auto nbr:adj[idx])
    {
        if(nbr==p)
        continue;

        dfs(nbr,idx,adj,par);
    }

}

void solve()
{  

    // preprocessing takes nlogn time complexity
    unordered_map<int,vector<int>>adj; 
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vector<vector<int>>par(n,vector<int>(log2(n)+5,-1));

    dfs(0,-1,adj,par);
    for(int i=1;i<log2(n)+5;i++)
    {
        for(int k=0;k<n;k++)
        {   
            int intermediate=par[k][i-1];
            if(intermediate!=-1)
            {
                par[k][i]=par[intermediate][i-1];
            }
        }
    }



   cout<<kthparent(5,1,par);


}

int32_t main()
{
    
#ifndef ONLINE_JUDGE
freopen("inputf.txt", "r", stdin);
freopen("outputf.txt", "w", stdout);
#endif

    int t;
    t=1;
    for(int i=0;i<t;i++)
    {
        solve();
    }
}