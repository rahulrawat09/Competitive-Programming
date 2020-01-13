#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

struct trie
{
    int num;
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
    if(root==nullptr)
        root=newnode();

    trie* temp=root;

    for(int i=0;i<s.length();i++)
    {
        if(temp->tm.find(s[i])==temp->tm.end())
            temp->tm[s[i]]=newnode();
        temp=temp->tm[s[i]];
    }
    temp->num=temp->num+1;
}

int search(trie* root,string& s)  // returns number of words
{
    if(root==nullptr) return 0;

    trie* temp=root;

    for(int i=0;i<s.length();i++)
    {
        temp=temp->tm[s[i]];
        if(temp==nullptr)
            return 0;
    }
    return temp->num;
}

int main()
{
    int n;
    cin>>n;

    string s[n]; // words
    trie* root=nullptr;

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        insert(root,s[i]);
    }

    string x;  // string to be searched
    cin>>x;

    cout<<search(root,x);

    return 0;
}
