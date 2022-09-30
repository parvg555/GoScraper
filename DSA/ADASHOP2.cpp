using namespace std;
#include<iostream>
 int mover;

struct point{
    int a,b;
};
int in=0;

void up(point &x)
{
    if(x.a<8 && x.b<8)
    { x.a=x.a+1;
    x.b=x.b+1;
        cout<<x.a<<" "<<x.b<<endl;}
    
}
void down(point &x)
{
    if(x.a>1 && x.b>1)
    {x.a=x.a-1;
    x.b=x.b-1;
        cout<<x.a<<" "<<x.b<<endl;}
}
void left(point &x)
{
    if(x.a>1 && x.b<8)
    {x.a=x.a-1;
    x.b=x.b+1;
        cout<<x.a<<" "<<x.b<<endl;}
}
void right(point &x)
{
    if(x.a<8 && x.b>1)
    {x.a=x.a+1;
    x.b=x.b-1;
        cout<<x.a<<" "<<x.b<<endl;}
    
}
int main()
{
    mover=0;
    
    int t;
    cin>>t;
    while(t--)
    {
        
         
        point x;
        
        cin>>x.a>>x.b;
        cout<<"18"<<endl;
        
        while(x.a!=8 || x.b!=8)
            up(x);
        down(x);
        right(x);
        
        for(int i=0;i<6;i++)
            down(x);
        
        up(x);
        right(x);
        
        for(int i=0;i<3;i++)
        up(x);
        
        down(x);
        right(x);
        
        down(x);
        
        for(int i=0;i<6;i++)
            left(x);
        
        
        up(x);
        right(x);
        up(x);
        
        down(x);
        down(x);
        down(x);
        right(x);
        down(x);
        
        for(int i=0;i<5;i++)
            up(x);
      
        
        
        
    }
    
    return 0;
}
