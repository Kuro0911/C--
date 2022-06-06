#include <bits/stdc++.h>

using namespace std;
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

int findPeak(int a[] , int mn , int mx , int n){
    int md = mn + (mx - mn)/2;
    if ((md == 0 || a[md-1] <= a[md]) && (md = n - 1 || a[md+1] <= a[md]))
    {
        return md;
    }
    else if (md > 0 && a[md - 1] > a[md])
    {
        return findPeak(a , mn , (md-1) , n);
    }
    else{
        return findPeak(a , (md+1) , mx , n);
    }
};
int find(int arr[] , int n){
    return findPeak(arr , 0  , n-1 , n);
};
void solve(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<find(a , n);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    #ifndef ONLINE_JUDGE
    cerr <<"Time :"<<1000*((double)clock()) / (double)CLOCKS_PER_SEC<<"ms";
    #endif
        return 0;
}