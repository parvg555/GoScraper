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
    int n;
    cin>>n;
    int arr[n];
    f(i,0,n)
    cin>>arr[i];
    int total=0;
    
    f(i,0,n)
    total+=arr[i];
    
    int i=0;
    int ans=INT_MAX;
    while(i<(1<<n))
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {sum+=arr[j];}
        }
        int z=max(total-sum,sum);
        ans=min(ans,z);
        i++;
    }
    
    cout<<ans<<endl;
    
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
