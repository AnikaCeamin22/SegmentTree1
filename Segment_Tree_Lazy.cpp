#include<bits/stdc++.h>
using namespace std;

const int N=5e5+9;
int a[N];
long long int t[4*N],Lazy[4*N];

//Rang change
inline void Push(int node, int b, int e) //change this
{
    if(Lazy[node]==0) return;
    t[node]=t[node]+(e-b+1)*Lazy[node];
    if(b!=e)
    {
        int l=node<<1,r=(node<<1)+1;
        Lazy[l]=Lazy[l]+Lazy[node];
        Lazy[r]=Lazy[r]+Lazy[node];
    }
    Lazy[node]=0;
    return;
}

//Tree Build
void build(int node, int b, int e)
{
    Lazy[node]=0; //change this
    if(b==e)
    {
        t[node]=a[b];
        return;
    }
    int l=2*node, r=2*node+1;
    int mid=(b+e)/2;
    build(l,b,mid);
    build(r,mid+1,e);
    t[node]=t[l]+t[r];
}

//update in node i =x
void upd(int node, int b, int e, int i, int j,  long long int x)
{
    Push(node,b,e);
    if(b>j  || e<i) return;
    if( b>=i && e<=j )
    {
        Lazy[node]=x; //set Lazy*******
        Push(node,b,e);
        return;
    }
    int l=2*node,r=2*node+1;
    int mid=(b+e)/2;
    upd(l,b,mid,i,j,x);
    upd(r,mid+1,e,i,j,x);
    t[node]=t[l]+t[r];
}

//query from i to j
long long int query(int node, int b, int e, int i, int j)
{
    Push(node,b,e);
    if(b>j || e<i) return 0; //return null
    if(b>=i && e<=j) return t[node];
    int l=2*node,r=2*node+1;
    int mid=(b+e)/2;
    return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);
}

int main()
{
    int n=5;
    //cin>>n;
    for(int i=1; i<=n; i++) { a[i]=i;  cout<<a[i]<<endl; }
    build(1,1,n);
    cout<<t[1]<<endl;
    cout<<query(1,1,n,1,3)<<endl;
    upd(1,1,n,2,3,10);
    cout<<query(1,1,n,1,3)<<endl;

    return 0;
}
