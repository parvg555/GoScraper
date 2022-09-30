#include<bits/stdc++.h>
#include<chrono>
#include<string.h>
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
    
    stack<char> st;
    string s;
    cin>>s;
    char openbracket=s[0],closedbracket=s[s.size()-1], extra;
    
    for(char x:s){
        if(x!=openbracket && x!=closedbracket){
            extra=x;
            break;
        }
    }
    
    bool ans=false;
    
    
    for(char x: s){
        if(x==openbracket){
            st.push(x);
        }
        else if((x==closedbracket||x==extra) && !st.empty() && st.top()==openbracket){
            st.pop();
        }
        else
            st.push(x);
    }
    if(st.empty()){
        ans=true;
    }
    stack<char> st2;
    if(!ans){
        for(char x:s){
            if(x==openbracket || x==extra){
                st2.push(x);
            }
            else if(x==closedbracket && !st2.empty() && (st2.top()==openbracket || st2.top()==extra)){
                st2.pop();
            }
            else
                st2.push(x);
        }
    }
    if(st2.empty()){
        ans=true;
    }
    if(ans){
        cout<<"YES\n";
    }
    else
        cout<<"NO\n";
    
}

int main()
{
    //    auto start = high_resolution_clock::now();
    
    speed;
    wh(t){
    solve();
    }
    
    //    auto stop = high_resolution_clock::now();
    //    auto duration = duration_cast<microseconds>(stop - start);
    //
    //      cout << "Time taken by function: "
    //           << duration.count() << " microseconds" << endl;
    
    return 0;
}

