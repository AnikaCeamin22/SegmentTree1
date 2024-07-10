#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
const int N=3e5+9;
int  v[N];
ll seg[4*N];

//Tree Build
void build(int node, int b, int e)
{
    if(b==e)
    {
        seg[node]=v[b];
        return;
    }
    int l=2*node, r=2*node+1;
    int mid=(b+e)/2;
    build(l,b,mid);
    build(r,mid+1,e);
    seg[node]=seg[l]+seg[r];  //change this
    return;
}

//update in node i =x
void upd(int node, int b, int e, int i, ll x)
{
    if(b>i  || e<i) return;
    if(b==i && b==e)
    {
        seg[node]=x;
        return;
    }
    int l=2*node,r=2*node+1;
    int mid=(b+e)/2;
    upd(l,b,mid,i,x);
    upd(r,mid+1,e,i,x);
    seg[node]=seg[l]+seg[r]; //change this
    return;
}

//query from i to j
ll query(int node, int b, int  e, int  i, int  j)
{
    if(b>j || e<i) return 0; //change this
    if(b>=i && e<=j) return seg[node];
    int l=2*node,r=2*node+1;
    int mid=(b+e)/2;
    return query(l,b,mid,i,j)+query(r,mid+1,e,i,j); //change this
}

int main()
{
    ll n=5,q;
    //cin>>n>>q;
    for(int i=1; i<=n; i++) v[i]=i;
    build(1,1,n);
    cout<<seg[1]<<endl;
    cout<<query(1,1,n,2,4)<<endl;
    upd(1,1,n,2,10);
    cout<<seg[1]<<endl;
    cout<<query(1,1,n,2,4)<<endl;
//     while(q--)
//     {
//         ll a,b,c;
//         cin>>a>>b>>c;
//         if(a==1)
//           upd(1,1,n,++b,c);
//         else if(a==2){
//                ll ans=query(1,1,n,++b,c);
//            cout<<ans<<endl;
//         }

     //}
    return  0;
}
