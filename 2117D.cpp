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

std::pair<int, int> solveXY(int a, int b, int n) {
    int denominator = 1 - n * n;
    if (denominator == 0) return {-1, -1}; 

    double x = static_cast<double>(a - b * n) / denominator;
    double y = static_cast<double>(b - a * n) / denominator;

    if (std::floor(x) != x || std::floor(y) != y) {
        return {-1, -1};
    }

    return {static_cast<int>(x), static_cast<int>(y)};
}

void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int a=arr[1];
    int b=arr[n];
    pair<int,int> xy=solveXY(a,b,n);
    if(xy.F<0 || xy.S<0){
        cout<<"NO";
        return;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]-i*xy.F-(n-i+1)*xy.S!=0){
            cout<<"NO";
            return;
        }
    }
    // deb2(xy.F,xy.S);
    cout<<"YES";
}