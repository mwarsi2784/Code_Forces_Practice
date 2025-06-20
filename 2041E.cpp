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
    // cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }


    return 0;
}


void solve(){
    int a,b;
    cin>>a>>b;
    int sum=3*a-b;
    int ans[3];
    ans[0]=b-1;
    ans[1]=b;
    ans[2]=b+1;
    if(sum>ans[0]+ans[2]){
        int diff=sum-(ans[0]+ans[2]);
        ans[2]=ans[2]+diff;
    }
    if(sum<ans[0]+ans[2]){
        int diff=(ans[0]+ans[2])-sum;
        ans[0]=ans[0]-diff;
    }
    cout<<"3\n";
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];

}