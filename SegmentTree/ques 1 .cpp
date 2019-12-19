/*
problem statement
 https://www.spoj.com/problems/KGSS/
*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node
{
    int h1=0;
    int h2=0;
};

node ST[1000000];
int a[1000000];

node mergenode(node a,node b)
{
    node ans;
    int l=a.h1;
    int k=a.h2;

    if(b.h1>l)
    {
        k=l;
        l=b.h1;
    }
    else if(b.h1>k) k=b.h1;

    if(b.h2>l)
    {
        k=l;
        l=b.h2;
    }
    else if(b.h2>k) k=b.h2;

    ans.h1=l;
    ans.h2=k;

    return ans;
}

void update(int index,int l,int r,int x,int y)
{
    if(l==r)
    {
        if(l==x)
        {
            ST[index].h1=y;
            ST[index].h2=0;
        }
        return;
    }
    if(x>r||x<l) return;


    int m=(l+r)/2;
    update(2*index+1,l,m,x,y);
    update(2*index+2,m+1,r,x,y);

    ST[index]=mergenode(ST[2*index+1],ST[2*index+2]);

}

void build(int index,int l,int r)
{
    if(l==r)
    {
        ST[index].h1=a[l];
        ST[index].h2=0;
        return;
    }

    int m=(l+r)/2;
    build(2*index+1,l,m);
    build(2*index+2,m+1,r);

    ST[index]=mergenode(ST[2*index+1],ST[2*index+2]);
}

node query(int index,int l,int r,int ql,int qr)
{
    if(ql>r||qr<l)
    {
        node n;
        return n;
    }

    if(l>=ql&&r<=qr)
    {
        return ST[index];
    }

    int m=(l+r)/2;

    return mergenode(query(2*index+1,l,m,ql,qr),query(2*index+2,m+1,r,ql,qr));
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    build(0,0,n-1);

    cin>>q;
    while(q--)
    {
        char Q;
        int x,y;
        cin>>Q>>x>>y;

        if(Q=='Q')
        {
            node N=query(0,0,n-1,x-1,y-1);
            cout<<N.h1+N.h2<<endl;
        }
        else update(0,0,n-1,x-1,y);

    }

    return 0;
}
