#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
const int N=3e5+9;

class SEGTree{
    vector<ll>seg;
public:
    SEGTree(int n)
    {
        seg.resize(4*n+9);
    }
//Tree Build
void build(int node, int b, int e, int v[ ])
{
    if(b==e)
    {
        seg[node]=v[b];
        return;
    }
    int l=2*node, r=2*node+1;
    int mid=(b+e)/2;
    build(l,b,mid,v);
    build(r,mid+1,e,v);
    seg[node]=min(seg[l],seg[r]);  //change this
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
    seg[node]=min(seg[l],seg[r]); //change this
    return;
}

//query from i to j
ll query(int node, int b, int  e, int  i, int  j)
{
    if(b>j || e<i) return 0; //change this
    if(b>=i && e<=j) return seg[node];
    int l=2*node,r=2*node+1;
    int mid=(b+e)/2;
    return min(query(l,b,mid,i,j),query(r,mid+1,e,i,j)); //change this
}
};


int main()
{
    int n1;
    cin>>n1;
    int v1[n1];
    for(int i=0; i<n1; i++) cin>>v1[i];
    SEGTree sg1(n1);
    sg1.build(1,0,n1-1,v1);

    ll n2;
    cin>>n2;
    int v2[n2];
    for(int i=0; i<n2; i++) cin>>v2[i];
    SEGTree sg2(n2);
    sg2.build(1,0,n2-1,v2);

    int q;
    cin>>q;
    while(q--)
    {
        int tp;
        cin>>tp;
        if(tp==1)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int z1=sg1.query(1,0,n1-1,x1,y2);
            int z2=sg2.query(1,0,n2-1,x2,y2);
            cout<<min(z1,z2)<<endl;
        }
        else if(tp==2)
        {
            int no,i,x;
            cin>>no>>i>>x;
            if(no==1)
            {
                sg1.upd(1,0,n1-1,i,x);
                v1[i]=x;
            }
            else if(no==2)
            {
                sg2.upd(1,0,n2-1,i,x);
                v2[i]=x;
            }
        }
    }

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
