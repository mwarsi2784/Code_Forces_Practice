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

bool haveCommonElement(const std::set<int>& set1, const std::set<int>& set2) {
    auto it1 = set1.begin();
    auto it2 = set2.begin();

    while (it1 != set1.end() && it2 != set2.end()) {
        if (*it1 == *it2) return true;
        if (*it1 < *it2) ++it1;
        else ++it2;
    }
    return false;
}


void solve(){
    int n,m;
    cin>>n>>m;
    set<int> s;
    map<int,int> f;
    int t;
    int a[n][m];
    bool evens1=true;
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
        cin>>a[i][j];
        s.insert(a[i][j]);
        f[a[i][j]]=1;
       } 
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if((a[i][j]==a[i+1][j]) || (a[i][j]==a[i][j+1])){
                f[a[i][j]]=2;
            }
        }
    }
    for(int j=0;j<m-1;j++){
        if(a[n-1][j]==a[n-1][j+1]){
            f[a[n-1][j]]=2;
        }
    }
    for(int i=0;i<n-1;i++){
        if(a[i][m-1]==a[i+1][m-1]){
            f[a[i][m-1]]=2;
        }
    }

    int ans=0;
    int mx=0;
    for(auto i:s){
        int temp=i;
        ans=ans+f[temp];
        // deb2(f[temp],temp);
        if(f[temp]>mx){
            mx=f[temp];
        }
    }
    // deb2(ans,mx);
    cout<<ans-mx;
}
