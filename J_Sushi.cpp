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
double dp[301][301][301];
void solve(int tc)
{
    ll n;
    cin>>n;
    ll cnt[4]={0};
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        cnt[x]++;
    }
    dp[0][0][0]=0;
    for(ll three=0;three<=n;three++)
    {
        for(ll two=0;two<=n;two++)
        {
            for(ll one=0;one<=n;one++)
            {
                ll zero=n-(one+two+three);
                if(one+two+three>n || zero==n) continue;
                double value=1;
                if(three>0) value+=(1.0*three)/n*dp[three-1][two+1][one];
                if(two>0) value+=(1.0*two)/n*dp[three][two-1][one+1];
                if(one>0) value+=(1.0*one)/n*dp[three][two][one-1];
                if(zero>0) value/=((1-1.0*zero/n));
                dp[three][two][one]=value;
            }
        }
    }
    cout<<fixed<<setprecision(9)<<dp[cnt[3]][cnt[2]][cnt[1]]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=1;
    solve(tc);
    return 0;
}