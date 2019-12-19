#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> block(10000,INT_MAX);

void build(auto& v)
{
    int blk=sqrt(v.size());

    for(int i=0;i<v.size();i++)
    {
        block[i/blk]=min(v[i],block[i/blk]);
        //cout<<block[i/blk]<<" ";
    }
}

int querymin(auto& v,int l,int r)
{
    int m=INT_MAX;  //minimum
    int blk=sqrt(v.size());
    int lb=l/blk;
    int rb=r/blk;

    if(lb==rb)
    {
        for(int i=l;i<=r;i++) m=min(m,v[i]);
        return m;
    }

    for(int i=l;i<lb*blk+blk;i++) m=min(m,v[i]);
    for(int i=r;i>=rb*blk;i--) m=min(m,v[i]);
    for(int i=lb+1;i<rb;i++) m=min(m,block[i]);

    return m;
}

int main()
{
    int n,m;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    build(v);

    cout<<"\nEnter number of queries to get minimum in range:";
    cin>>m;

    while(m--)
    {
        int l,r;
        cin>>l>>r;

        cout<<querymin(v,l-1,r-1)<<endl;
    }
    return 0;
}
