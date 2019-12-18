/*
Problem:
https://www.spoj.com/problems/HORRIBLE/
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void update(vector<ll>& ST,vector<ll>& lazy,int index,int l,int r,int ql,int qr,ll val)
{
    if(lazy[index]!=0)
    {
        ST[index]+=(r-l+1)*lazy[index];
        if(l!=r)
        {
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r)
    {
        ST[index]+=(r-l+1)*val;
        if(l!=r)
        {
            lazy[2*index+1]+=val;
            lazy[2*index+2]+=val;
        }
        return;
    }
    int m=(l+r)/2;

    update(ST,lazy,2*index+1,l,m,ql,qr,val);
    update(ST,lazy,2*index+2,m+1,r,ql,qr,val);

    ST[index]=ST[2*index+1]+ST[2*index+2];
}

ll query(vector<ll>& ST,vector<ll>& lazy,int index,int l,int r,int ql,int qr)
{
    if(lazy[index]!=0)
    {
        ST[index]+=(r-l+1)*lazy[index];
        if(l!=r)
        {
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(ql>r||qr<l) return 0;
    if(ql<=l&&qr>=r) return ST[index];

    int m=(l+r)/2;
    ll sum=query(ST,lazy,2*index+1,l,m,ql,qr)+query(ST,lazy,2*index+2,m+1,r,ql,qr);
    return sum;
}

void buildtree(vector<ll>& a,vector<ll>& ST,int index,int l,int r)
{
    if(l==r)
    {
        ST[index]=a[l];
        return;
    }

    int m=(l+r)/2;

    buildtree(a,ST,2*index+1,l,m);
    buildtree(a,ST,2*index+2,m+1,r);

    ST[index]=ST[2*index+1]+ST[2*index+2];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n,C;
        cin>>n>>C;

        vector<ll> a(n,0);
        vector<ll> ST(4*n,0);
        vector<ll> lazy(4*n,0);

        //buildtree(a,ST,0,0,n-1);  // not needed in this ques

        while(C--)
        {
            ll c,l,r,v;
            cin>>c;

            if(!c)
            {
                cin>>l>>r>>v;
                update(ST,lazy,0,0,n-1,l-1,r-1,v);
                continue;
            }
            cin>>l>>r;

            cout<<query(ST,lazy,0,0,n-1,l-1,r-1)<<endl;
        }
    }
}
