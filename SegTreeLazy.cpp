#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
#define en  "\n"
const int N=3e5;

class SegTree{
    vector<long long int>seg,lazy;
public:
    SegTree(int n)
    {
        seg.resize(4*n+9,0); // sz must be 4*n
        lazy.resize(4*n+9,0);
    }

    //Range operation
    void pushLazy(int node, int b, int e)//change
    {
        if(lazy[node]==0) return;
        // perform the main operations on specific node
        seg[node]=seg[node]+(e-b+1)*lazy[node];
        if(b!=e)
        {
            int l=2*node, r=2*node+1;
            lazy[l]=lazy[l]+lazy[node];
            lazy[r]=lazy[r]+lazy[node];
        }
        lazy[node]=0;
        return;
    }

    //build the SegmentTree
    void build(int node, int b, int e, vector<int>& v)
    {
        lazy[node]=0;
        if(b==e)
        {
            seg[node]=v[b]; //change
            return;
        }
        int l=2*node,r=2*node+1,mid=(b+e)/2;
        build(l,b,mid,v);
        build(r,mid+1,e,v);
        seg[node]=seg[l]+seg[r]; //change
        return;
    }

    //update segmentTree at indx=x
    void upd(int node, int b, int e, int i,int j, long long int x)
    {
        pushLazy(node, b,e);
        if(b>j || e<i) return;
        if(b>=i && e<=j)
        {
            lazy[node]=x; //change
            pushLazy(node,b,e);
            return;
        }
        int l=2*node, r=2*node+1,mid=(b+e)/2;
        upd(l,b,mid,i,j,x);
        upd(r,mid+1,e,i,j,x);
        seg[node]=seg[l]+seg[r]; //change
        return;
    }

    //query from i to j
    long long int query(int node, int b, int e, int i, int j)
    {
        pushLazy(node,b,e);
        if(b>j || e<i) return 0;
        if(b>=i && e<=j) return seg[node];
        int l=2*node, r=2*node+1,mid=(b+e)/2;
        long long int leftside=query(l,b,mid,i,j);
        long long int rightside=query(r,mid+1,e,i,j);
        return leftside+rightside; // change
    }
};

void Solve()
{
    int n=5;
    vector<int>v(n);
    for(int i=0; i<n; i++) v[i]=i+1;
    SegTree sg(n);
    sg.build(1,0,n-1,v);
    cout<<sg.query(1,0,n-1,2,4)<<endl;
    sg.upd(1,0,n-1,1,3,10);
    cout<<sg.query(1,0,n-1,1,2)<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T=1,t=0;
   // cin>>T;
    while(T--){
            t++;
    //cout<<"Case "<<t<<": ";
        Solve();
    }

    return 0;
}
