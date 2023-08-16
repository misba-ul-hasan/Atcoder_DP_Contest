//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define pb push_back
#define eb emplace_back
#define mod 1000000007
#define maxN 1000005
#define endl '\n'
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pii pair<ll,ll>
#define dekhao(tc,ans) cout<<"Case "<<tc<<": "<<ans<<"\n"
#define google(tc,ans) cout<<"Case #"<<tc<<": "<<ans<<"\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bitcount __builtin_popcountll
#define min_heap priority_queue<ll,vector<ll>,greater<ll>>
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const double pi=acos(-1.0);
#define INF 1e18
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll binpow(ll b,ll p){ll res=1;while(p){if(p%2==0){b*=b;p/=2;}else{res*=b;p--;}}return res;}
ll binpowwithmod(ll b,ll p){ll res=1;while(p){if(p%2==0){b=(b%mod*b%mod)%mod;p/=2;}else{res=(res%mod*b%mod)%mod;p--;}}return (res%mod);}
ll dx[]={+1,+0,+0,-1};
ll dy[]={+0,-1,+1,+0};
//mp.reserve(32768); //updated unorederd_map !
//mp.max_load_factor(0.25);
double dp[3000][3000];
double p[3000];
ll n;
double prob(ll n,ll h)
{
    if(h<0) return 0;
    if(h>n) return 0;
    if(n==0) return h==0;
    if(dp[n][h]!=-1) return dp[n][h];
    return dp[n][h]=p[n-1]*prob(n-1,h-1)+(1-p[n-1])*prob(n-1,h);
}
void solve(int tc)
{
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(ll i=0;i<3000;i++)
    {
        for(ll j=0;j<3000;j++)
        {
            dp[i][j]=-1;
        }
    }
    // dp[0][0]=(1-p[0]);
    // dp[0][1]=p[0];
    // for(ll i=1;i<n;i++)
    // {
    //     for(ll j=0;j<3000;j++)
    //     {
    //         dp[i][j]+=(1-p[i])*dp[i-1][j];
    //         if(j>0)
    //         {
    //             dp[i][j]+=(p[i]*dp[i-1][j-1]);
    //         }
    //     }
    // }
    double ans=0;
    for(ll i=n/2+1;i<=n;i++)
    {
        ans+=prob(n,i);
    }
    cout<<fixed<<setprecision(9)<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=1;
    solve(tc);
    return 0;
}