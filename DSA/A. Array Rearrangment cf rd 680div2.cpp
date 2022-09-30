#include<bits/stdc++.h>
#include<chrono>
#include<string.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define m 1000000007
using namespace std;
using namespace std::chrono;

//aditya ranaut- phoenix_aditya

void solve()
{
    ll n,x;
    cin>>n>>x;
    ll a[n];
    ll b[n];
    
    f(i,0,n)
    cin>>a[i];
    
    f(i,0,n)
    cin>>b[i];
    
    sort(a,a+n);
    sort(b,b+n);
    reverse(b, b+n);
    bool ans=true;
    f(i,0,n)
    {
        if(a[i]+b[i]>x)
        {ans=false;break;}
    }
    if(ans)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}



int main()
{
    //    auto start = high_resolution_clock::now();
    
    speed;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    wh(t)
     {solve();}
    
    //    auto stop = high_resolution_clock::now();
    //    auto duration = duration_cast<microseconds>(stop - start);
    //
    //      cout << "Time taken by function: "
    //           << duration.count() << " microseconds" << endl;
    
    return 0;
}
