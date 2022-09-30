#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

//aditya ranaut- phoenix_aditya

const int mxn=65;
ll arr[mxn][mxn];
int checker[mxn];

void solve()
{
    memset(arr,0,sizeof(arr));
    memset(checker,0,sizeof(checker));
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
        
    for(int i=0;i<n;i++)
    {
        if(arr[0][i]==(i+1))
        {checker[i]=1;}
        else
            checker[i]=0;
    }
    
//    checker loop
//    for(int i=0;i<n;i++)
//       cout<<checker[i];
//    cout<<endl;
    
//    code working before this point
    
    int curr=checker[1];
    int ans=0;
    
    for(int i=1;i<n;i++)
    {
        if(checker[i]==curr)
            continue;
        else
        {
            ans+=1;
            curr=checker[i];
        }
    }
    if(curr==0)
        ans+=1;
    
    cout<<ans<<endl;
}



int main()
{
   speed;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    wh(t)
     {solve();}
    
    return 0;
}
