//#include<bits/stdc++.h>
#include<iostream>
#define pi 3.14159265359
#define ll long long
#define ull unsigned long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
using namespace std;
#include<string.h>

//aditya ranaut- phoenix_aditya

void solve()
{
    string s;
    cin>>s;

    int a=0,b=0,c=0;
    for(int i=0;i<s.length();i++){
        char temp=s[i];
        if(temp=='A')a++;
        if(temp=='B')b++;
        if(temp=='C')c++;
    }
   // cout<<a<<b<<c<<endl;
    if((a+c)==b){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}



int main()
{
    speed;
    wh(t)
    solve();
    
    return 0;
}