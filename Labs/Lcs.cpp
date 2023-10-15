#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "E:\Codes\debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define nl "\n"
#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define pb push_back
#define UB upper_bound
#define LB lower_bound
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
ll cs;
#define _case cout<<"Case "<<++cs<<": "
#define rev(v) reverse(v.begin(),v.end())
#define vf(v) (v).begin(),(v).end()
#define vr(v) (v).rbegin(),(v).rend()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
const ll infi = 1e18;
const ll mod = 1e9+7;
const ll N = 1e6+3;
float pi = 3.141592653589793238462643383279502884197;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
ll dp[1000][1000],mark[1000][1000];
int lcs(string a, string b,int i, int j)
{
    if(i==0 or j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i-1]==b[j-1]) 
    {
        mark[i][j]=1; // 1 for diagonal
        return dp[i][j]= lcs(a,b,i-1,j-1)+1;
    }
    else
    {
        ll left=lcs(a,b,i-1,j);
        ll right=lcs(a,b,i,j-1);
        if(left>right)
            mark[i][j]=2; // 2 for top
        else
            mark[i][j]=3; // 3 for left
        return dp[i][j]=max(left,right);
    }
}
void print(string a, string b,int i, int j)
{
    if(i==0 or j==0) return;
    if(mark[i][j]==1)
    {
        print(a,b,i-1,j-1);
        cout<<a[i-1];
    }
    else if(mark[i][j]==2)
    {
        print(a,b,i-1,j);
    }
    else
        print(a,b,i,j-1);
}
void solve()
{
    memset(dp,-1,sizeof dp);
    string a,b; cin>>a>>b;
    cout<<lcs(a,b,a.size(),b.size())<<nl;
    print(a,b,a.size(),b.size());
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--)
        {
            solve();
        }
    return 0;
}