/*
Problem: DQUERY on SPOJ 
  https://www.spoj.com/problems/DQUERY/
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct query
{
    int l;
    int r;
    int i;
};

int coun=0;
int blk=555;
query Q[200001];
int freq[1000001]={};
int ans[200001];

bool comp(query L,query L2)
{
    if(L.l/blk==L2.l/blk)
        return L.r<L2.r;
    return L.l/blk<L2.l/blk;
}

void add(int x)
{
    freq[x]++;
    if(freq[x]==1) coun++;
}


void remove(int x)
{
    freq[x]--;
    if(freq[x]==0) coun--;
}

int main()
{
    int n,q;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>q;

    for(int i=0;i<q;i++)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].i=i;
        Q[i].l--;
        Q[i].r--;
    }

    sort(Q,Q+q,comp);

    int ML=0,MR=-1;
    for(int i=0;i<q;i++)
    {
        int L=Q[i].l;
        int R=Q[i].r;

        while(ML<L)
        {
            remove(v[ML]);
            ML++;
        }
        while(ML>L)
        {
            ML--;
            add(v[ML]);
        }
        while(MR>R)
        {
            remove(v[MR]);
            MR--;
        }
        while(MR<R)
        {
            MR++;
            add(v[MR]);
        }

        ans[Q[i].i]=coun;
    }

    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;

    return 0;
}
