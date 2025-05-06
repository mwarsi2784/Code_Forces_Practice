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


void solve(){
    string p,s;
    cin>>p;
    cin>>s;
    vector<pair<char,int>> v1,v2;
    int i=0;
    while(i<p.size()){
        char curr=p[i];
        int cnt=0;
        while( i<p.size() && p[i]==curr){
            i++;
            cnt++;
        }
        v1.pb({curr,cnt});
    }
    i=0;
    while(i<s.size()){
        char curr=s[i];
        int cnt=0;
        while(i<s.size() && s[i]==curr){
            i++;
            cnt++;
        }
        v2.pb({curr,cnt});
    }
    if(v2.size()!=v1.size()){
        cout<<"NO";
        return;
    }
    for(int i=0;i<v2.size();i++){
        int cnt1=v1[i].S;
        int cnt2=v2[i].S;
        if(v1[i].F!=v2[i].F){
            cout<<"NO";
            return;
        }
        if(cnt2<cnt1 || cnt1*2<cnt2 ){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
}