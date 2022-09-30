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
ll by2(ll n){
    ll counter =0;
    while(n%2==0){
        n/=2;
        counter++;
    }
    return counter;
}

void solve(){
    ll n;
    cin>>n;

    ll arr[n];
    f(i,0,n){cin>>arr[i];}

    sort(arr, arr+n);
    ll counter = 0;

    if(n==1){
        cout<<arr[0]<<endl;
        return;
    }
    f(i,0,n){
        if(arr[i]%2==0){
            counter += by2(arr[i]);
            arr[i] /= 2*by2(arr[i]);
        }
    }
    // f(i,0,n){
    //     cout<<arr[i]<<"  ";
    // }cout<<endl;
    sort(arr, arr+n);
    ll ans = 0;
    f(i,0,n-1){
        ans +=arr[i];
    }
    ll zz= pow(2,counter);
    ans+=zz*arr[n-1];
    arr[n-1]*=(zz);
    // f(i,0,n){
    //     cout<<arr[i]<<"  ";
    // }cout<<endl;
    cout<<ans<<endl;
}

int main(){
    fast;
    wh(t){
        solve();
    }
    return 0;
}