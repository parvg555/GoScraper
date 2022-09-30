#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;
#include<string.h>

void solve()
{
    ll a,b;
    cin>>a>>b;
    
    // this is not working comparison
    if(a==b) //now it's working
        cout<<0<<endl;
    
    else if(a>b && a%b!=0)
        cout<<-1<<endl;
    
    else if(a<b && b%a!=0)
        cout<<-1<<endl;

    else if(a==0 || b==0)
        cout<<-1<<endl;
    
    
    else{
    if(b>a)
    {
        ll c=a;
        a=b;
        b=c;
    }
    int counter=0;
    
        ll val=a/b;
        
        while(val%8==0)
        {
            counter++;
            val=val/8;
        }
        while(val%4==0)
        {
            counter++;
            val=val/4;
        }
        while(val%2==0)
        {
            counter++;
            val=val/2;
        }
        if(val==1)
            cout<<counter<<endl;
        else
            cout<<-1<<endl;
    }
    
}



int main()
{
    speed;
    wh(t)
     {solve();}
    
    return 0;
}
