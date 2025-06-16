/********************* بسم الله الرحمن الرحيم ***********************/
/********************* ٱلْحَمْدُ لِلَّٰهِ رَبِّ ٱلْعَالَمِينَ ************************/
/******************* Prophet Muhammad صلى الله عليه وسلم ************/
/*********************** وَقُل رَّبِّ زِدْنِي عِلْمًا ***************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; //find_by_order() order_of_key()


//===========================================================================
#define int  long long
#define ld long double
#define nl cout<<"\n";
#define pb push_back
#define F first
#define S second
#define deb(x) cout << #x << "=" << x << "\n" 
#define deb2(x,y) cout << #x << "=" << x << "," << #y << "=" << y <<"\n" 
int gcd(int a, int b){if(b == 0) {return a;}else {return gcd(b, a % b);}}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
//===========================================================================


const int mod1 = 1000000007;
const int mod2 = 998244353;
void solve();



signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    t=1;
    cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }


    return 0;
}


int fun(vector<pair<int,pair<int,int>>> d){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<n;k++){
                int day1=d[i].S.S;
                int day1=d[j].S.S;
                int day1=d[k].S.F;
                int type=d[i].S.F
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    int t;
    vector<pair<int,pair<int,int>>> a(n),b(n),c(n),d;
    int a[n];
    int b[n];
    int c[n];
    for(int i=0;i<n;i++){
        cin>>t;
        a[i]={t,{1,i}};
    }
   for(int i=0;i<n;i++){
        cin>>t;
        b[i]={t,{2,i}};
    }
   for(int i=0;i<n;i++){
        cin>>t;
        c[i]={t,{3,i}};
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    for(int i=n-1;i>=n-3;i--){
        d.pb(a[i]);
    }
    for(int i=n-1;i>=n-3;i--){
        d.pb(b[i]);
    }
    for(int i=n-1;i>=n-3;i--){
        d.pb(c[i]);
    }
    cout<<fun(d);
}