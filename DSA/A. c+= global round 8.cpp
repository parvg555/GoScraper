#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

void solve()
{
    ll a, b, n;
    cin>>a>>b>>n;
    
    if(a<b)
    swap(a, b);
    int counter=0;
    while(1)
    {
        if(a>n || b>n)
        break;
        
        else
        {
            if(b<=n && b<=n)
            {
                b+=a;
                counter++;
//                cout<<b<<" ";
            }
            if(a<=n && b<=n)
            {
                a+=b;
                counter++;
//                cout<<a<<" ";
            }
            
            
        }
    }
    cout<<counter<<endl;
}



int main()
{
    speed;
    wh(t)
     {solve();}
    
    return 0;
}
