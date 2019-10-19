/*Range sum queries using Segment Trees 
    Input the array
        input queries in form of ranges to get their sum 
           input updates to keep the tree updated */


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

void updatevalue(auto& ST,int index,int s,int e,int diff,int i)
{
    if(i<s||i>e) return;
    
    ST[index]+=diff;
    
    if(s!=e)
    {
        int mid=(s+e)/2;
        updatevalue(ST,2*mid+1,s,mid,diff,i);
        updatevalue(ST,2*mid+2,mid+1,e,diff,i);
    }
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
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    buildtree(ST,0,0,n-1,arr);
    cout<<"\n\n\t\tCONGRATS! TREE HAS BEEN BUILT!!!\n\n ";
    
    //for(int i=0;i<2*n;i++) cout<<i<<" "<<ST[i]<<endl;  // remove comment to output tree
    
    int q;
    cout<<"Enter 1 for query, 2 for value update, or any other to exit:";
    cin>>q;
    
    while(q==1||q==2)
    {
        switch(q)
        {
            case 1: cout<<"\nEnter range of query to get the sum :";
                    int x,y;
                    cin>>x>>y;
                    cout<<"\nSUM : "<<query(ST,0,0,n-1,x-1,y-1);
                    cout<<"\n\nEnter 1 for query, 2 for value update, 3 to exit:";
                    cin>>q;
                    break;
            
            case 2: cout<<"\nEnter index and value to be updated:";
                    int u,v;
                    cin>>u>>v;
                    updatevalue(ST,0,0,n-1,v-arr[u-1],u-1);
                    arr[u-1]=v;
                    cout<<"\n\nEnter 1 for query, 2 for value update, 3 to exit:";
                    cin>>q;
                    break;
            default:
                    break;
        }
    
    }
}
