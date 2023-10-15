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
const ll N = 1e+3;
float pi = 3.141592653589793238462643383279502884197;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
ll dp[N][N];
ll knapsack(ll i, ll w,vector<ll>&a, vector<ll>&b)
{
    if(i<0 or w==0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    ll x=knapsack(i-1,w,a,b);
    ll y=0;
    if(w>=b[i]) y=knapsack(i-1,w-b[i],a,b)+a[i];
    return dp[i][w]=max(x,y);
}
void solve()
{
    mem(dp,-1);
    ll n,w; cin>>n>>w;
    vector<ll>a(n),b(n);
    for(ll i=0; i<n; ++i) cin>>a[i]>>b[i];
    cout<<knapsack(n,w,a,b);
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