#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define wh(t) ll t;cin>>t;while(t--)
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define f(i,a,b) for(ll i=a;i<b;++i)

// aditya ranaut - phoenix_aditya


void solve(){
    string s;
    cin>>s;

    bool red=false, green=false, blue=false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='r') red=true;
        if(s[i]=='g') green=true;
        if(s[i]=='b') blue=true;

        if(s[i]=='R' && !red){
            cout<<"NO\n";
            return;
        }
        if(s[i]=='G' && !green){
            cout<<"NO\n";
            return;
        }
        if(s[i]=='B' && !blue){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    fast;
    wh(t)
        solve();
    
    return 0;
}