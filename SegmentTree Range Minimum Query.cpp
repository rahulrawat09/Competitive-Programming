#include <bits/stdc++.h>

using namespace std;

void buildtree(auto& ST,int s,int e,int index,auto& arr)
{
    if(s==e)
    {
        ST[index]=arr[s];
        return;
    }
    int mid=(s+e)/2;

    buildtree(ST,s,mid,2*index+1,arr);
    buildtree(ST,mid+1,e,2*index+2,arr);

    ST[index]=min(ST[2*index+1],ST[2*index+2]);
}

int getmin(auto& ST,int s,int e,int qs,int qe,int index)
{
    if(qe<s||qs>e) return INT_MAX;
    if(qs<=s&&qe>=e) return ST[index];

    int mid=(s+e)/2;

    return min(getmin(ST,s,mid,qs,qe,2*index+1),getmin(ST,mid+1,e,qs,qe,2*index+2));
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<int> ST(2*n,INT_MAX);

    for(int i=0;i<n;i++) cin>>arr[i];

    buildtree(ST,0,n-1,0,arr);

    //for(int i=0;i<2*n-1;i++) cout<<ST[i]<<" "; // uncomment this to see Segment Tree
    cout<<"\nEnter the range and get minimum :";
    int x,y;
    cin>>x>>y;

    cout<<getmin(ST,0,n-1,x-1,y-1,0);

    return 0;
}
