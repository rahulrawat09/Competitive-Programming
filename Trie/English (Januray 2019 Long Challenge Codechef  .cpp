#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll ans;

struct trie
{
    ll num;
    unordered_map<char,trie*> tm;
};

trie* newnode()
{
    trie* node=new trie;
    node->num=0;
    return node;
}

void insert(trie*& root,string& s)
{
    if(root==NULL)
        root=newnode();

    trie* temp=root;

    for(int i=0;i<s.length();i++)
    {
        if(temp->tm[s[i]]==NULL)
            temp->tm[s[i]]=newnode();
        temp=temp->tm[s[i]];
        temp->num++;
    }
}

int dfs(trie* root,ll d)
{
    ll cnt=0;
    for(auto& i:root->tm)
    {
        cnt+=dfs(i.second,d+1);
    }
    root->num-=cnt*2;
    ll c=(root->num)/2;
    cnt+=c;
    ans+=c*(d/2)*(d/2);
    return cnt;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        int n;
        cin>>n;
        string s[n];

        trie* root=NULL;
        for(int i=0;i<n;i++)  //input
        {
            cin>>s[i];
            
            string rev=s[i],final;
            reverse(rev.begin(),rev.end());
            for(int j=0;j<s[i].length();j++)
            {
                final.pb(s[i][j]);
                final.pb(rev[j]);
            }
            
            insert(root,final);
        }

        dfs(root,0);
        cout<<ans<<"\n";
    }

    return 0;
}
