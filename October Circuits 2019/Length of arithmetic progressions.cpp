#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcdEx(ll a, ll b, ll *x, ll *y){if(!a){*x=0;*y=1;return b;}
ll x1,y1,gcd=gcdEx(b%a,a,&x1,&y1); *x=y1-(b/a)*x1;*y=x1; return gcd;}
ll modI(ll b, ll m)      {ll x,y;gcdEx(b,m,&x,&y);return (x%m+m)%m;}
 
typedef pair<ll, ll>      pii;
typedef vector<ll>         vi;
typedef vector<pii>         vii;
typedef set<ll>            si;
typedef map<string, ll>    msi;
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define loop(i,b,n)           for(ll i=b;i<n;i++)
#define loopv(b,n,a)         for(ll i=b;i<n;i+=a)
#define loopr(b,n)           for(ll i=n;i>=0;i--)
 
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
 
#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); \
                      cerr << "\n\n" << "Time elapsed: " << \
                      (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
                      return 0
#define mp                  make_pair
#define ff                  first
#define ss                  second
#define pb                  push_back
#define MOD                 1000000007
#define modA(a,b)           (((a%MOD)+(b%MOD))%MOD)
#define modS(a,b)           (((((a%MOD)-(b%MOD))%MOD)<0)?(int)(MOD+((a%MOD)-(b%MOD))%MOD):(int)(((a%MOD)-(b%MOD))%MOD))
#define modM(a,b)           (ll)((((ll)(a%MOD))*((ll)(b%MOD)))%MOD)
#define modD(a,b)           ((modI(b,MOD)*(a%MOD))%MOD)
 
#define trace1(x)                  cerr<<#x<<": "<<x<<endl
#define trace2(x, y)               cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)            cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)         cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)      cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<end
ll modP(ll x, ll y)         {ll r=1; x%=MOD; while(y>0){if(y&1){r=(r*x)%MOD;}
y=y>>1; x=(x*x)%MOD;} return r;}
ll min(ll a,ll b ) {     if(a<b)     return a;     else    return b;  }
ll max(ll a,ll b ) {     if(a>b)     return a;     else    return b;  }
 
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
cout.tie(0);
#ifndef ONLINE_JUDGE
 freopen("input.txt","r",stdin);
 #endif // ONLINE_JUDGE
 ll n,t,ans,x,y,a,b;
 cin>>n>>t;
vi v(n);
vi difference(n);
map<ll,vector<pair<ll,ll> > > diff;
loop(i,0,n)
{
cin>>v[i];
if(i>0)
difference[i]=(v[i]-v[i-1]);
}
 
ll st=0,en=1;
loop(i,1,n-1)
{
       if(difference[i]==difference[i+1])
       {
           en++;
       }
       else
       {
           diff[difference[i]].pb({st,en});
           st=i;
           en=i+1;
       }
}
diff[difference[n-1]].pb({st,en});
if(n>=3)
{difference[0]=difference[1];
 
}
make_unique(difference);
n=difference.size();
loop(i,0,n)
{
   // cout<<difference[i]<<"\n";
sort(all(diff[difference[i]]));
   // loop(j,0,diff[difference[i]].size())
   // cout<<diff[difference[i]][j].ff<<" "<<diff[difference[i]][j].ss<<"\n";
}
 
 while(t--)
{
 
      ans=0;
ll l,r,d,cur=1;
cin>>l>>r>>d;
l-=1;
r-=1;
 
if(diff.find(d)==diff.end())
{
    cout<<1<<"\n";
    continue;
}
n=diff[d].size();
if(l>diff[d][n-1].ss)
{
    cout<<1<<"\n";
    continue;
}
if(r<diff[d][0].ff)
{
    cout<<1<<"\n";
    continue;
}
//cout<<"n="<<n<<"\n";
for(ll i=0;i<n;i++)
{
if(l>diff[d][i].ss)
{
continue;
}
if(r<diff[d][i].ff)
{
    continue;
}
x=diff[d][i].ff;
y=diff[d][i].ss;
//cout<<x<<" "<<y<<"\n";
if(l>diff[d][i].ff)
{
    x=l;
}
if(r<diff[d][i].ss)
{
    y=r;
}
if(y<x)
    x=y;
ans=max(ans,(y-x));
}
// trace2(l,r); trace2(x,y);
cout<<ans+1<<"\n";
    // cout<<ans<<"\n";
 }
 
    return 0;
}
