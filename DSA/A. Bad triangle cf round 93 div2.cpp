#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

//aditya ranaut- phoenix_aditya


const int mxn=1e4+4;// this is correct
int arr[5*mxn];

void solve()
{
    ll n;
    cin>>n;
    
    // this array input not working

    f(i,0,n)
    cin>>arr[i];
    
   if(arr[0]+arr[1]<=arr[n-1])
       cout<<1<<" "<<2<<" "<<n<<endl;
    else
    cout<<-1<<endl;
    
}


// Main function.
int main()
{
    speed;
    wh(t)
     {solve();}
    
    return 0;
}
