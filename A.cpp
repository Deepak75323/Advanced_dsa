#include<bits/stdc++.h>
using namespace std;
#define int long long int


int mod=1e9+7;
int solve(int n,vector<int>&dp)
{
    if(n==0)
    return 1;

    if(dp[n]!=0)
    return dp[n];

    int ans=0;

    for(int i=1;i<=6;i++)
    {   
        if(i<=n)
        ans+=solve(n-i,dp);
        ans%=mod;
    }

    return dp[n]=ans;


}

int32_t main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
   cout<<solve(n,dp)<<endl;
}