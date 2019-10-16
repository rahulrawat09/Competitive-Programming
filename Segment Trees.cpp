/*Range sum queries using Segment Trees 
    Input the array
        Then, input queries in form of ranges to get their sum */


#include<bits/stdc++.h>
using namespace std;

void buildtree(auto& ST,int index,int s,int e,auto& arr)
{
    if(s==e)
    {
        ST[index]=arr[s];
    }
    else
    {
        int mid=(s+e)/2;
        buildtree(ST,2*index+1,s,mid,arr);
        buildtree(ST,2*index+2,mid+1,e,arr);
        
        ST[index]=ST[2*index+1]+ST[2*index+2];
    }
}

int query(auto& ST,int index,int s,int e,int qs,int qe)
{
    if(qe<s||qs>e) return 0;
    if(s>=qs&&e<=qe) return ST[index];
    
    int mid=(s+e)/2;
    
    return( query(ST,2*index+1,s,mid,qs,qe) + query(ST,2*index+2,mid+1,e,qs,qe) );
}

int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout<<"Enter number of elements in array :";
    int n;
    cin>>n;
    
    cout<<"\nEnter the array elements :\n";
    vector<int> arr(n);
    vector<int> ST(2*n,0);
    
    for(int i;i<n;i++)
    {
        cin>>arr[i];
    }
    
    buildtree(ST,0,0,n-1,arr);
    cout<<"\n\n\t\tCONGRATS! TREE HAS BEEN BUILT!!!\n\n Enter number of queries:";
    
    //for(int i=0;i<2*n;i++) cout<<i<<" "<<ST[i]<<endl;  // remove comment to output tree
    
    int q;
    cin>>q;
    
    for(int i=1;i<q+1;i++) 
    {
        int qs,qe;
        cout<<"\nEnter Query "<<i<<" :";
        cin>>qs>>qe;
        
        cout<<"\n\tSum :"<<query(ST,0,0,n-1,qs-1,qe-1)<<endl;
    }
}
