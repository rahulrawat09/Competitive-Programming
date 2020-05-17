// question link below
// https://codeforces.com/contest/1354/problem/D// question link below


#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
#define mp make_pair
#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(ST,0,sizeof(ST));
    cin>>n>>q;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[x]++;
    }

    buildtree(1,1,n);

    while(q--)
    {
        int x;
        cin>>x;

        if(x>0) updatevalue(1,1,n,x),v[x]++;
        else
        {
            int y=del(1,1,n,abs(x));
            v[y]--;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(v[i]>0)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}

