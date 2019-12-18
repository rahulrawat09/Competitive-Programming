/*

    Problem statement:

    https://www.spoj.com/problems/KQUERY/en/
    
    Solution: o(n*logn*logn) TLE, but still fast

*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

vector<int>  v(30001);
vector<vector<int>> ST(130000);

void mergenode(auto& v,const auto& a, const auto& b)
{
    int i=0,j=0;
    while(i<a.size()&&j<b.size())
    {
        if(a[i]<b[j])
        {
            v.pb(a[i]);
            i++;
        }
        else
        {
            v.pb(b[j]);
            j++;
        }
    }
    while(i<a.size())
    {
        v.pb(a[i]);
        i++;
    }
    while(j<b.size())
    {
        v.pb(b[j]);
        j++;
    }
}

void buildtree(int index,int l,int r)
{
    if(l==r)        //leaf node
    {
        ST[index].pb(v[l]);
        return ;
    }

    ll m=(l+r)/2;
    buildtree(2*index+1,l,m);
    buildtree(2*index+2,m+1,r);
    mergenode(ST[index],ST[2*index+1],ST[2*index+2]);

    return;
}

int query(int index,int l,int r,int i,int j,int k)
{
    if(j<l||i>r) //no overlap
    {
        return 0;
    }

    if(l>=i&&r<=j)    // complete overlap
    {
        return ST[index].size()-(upper_bound(ST[index].begin(),ST[index].end(),k)-ST[index].begin());
    }

    ll m=(l+r)/2;

    return query(2*index+1,l,m,i,j,k)+query(2*index+2,m+1,r,i,j,k);
}

int main()
{

    int n,q;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&v[i]);

    buildtree(0,0,n-1);
    scanf("%d",&q);

    while(q--)
    {
        int i,j,k;
        scanf("%d%d%d",&i,&j,&k);

        printf("%d\n",query(0,0,n-1,i-1,j-1,k));
    }

    return 0;
}
