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

bool canBeDivisibleBy9(int a, int x_max, int y_max) {
    for (int i = 0; i <= x_max; ++i) {
        for (int j = 0; j <= y_max; ++j) {
            int sum = a + 2 * i + 6 * j;
            if (sum % 9 == 0) {
                return true;
            }
        }
    }
    return false;
}

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int sum=0;
    map<char,int> f;
    for(int i=0;i<n;i++){
        sum=sum+s[i]-'0';
        if(s[i]=='2'){
            f[s[i]]++;
        }else if(s[i]=='3'){
            f[s[i]]++;
        }
    }
    if(sum%9==0){
        cout<<"YES";
        return;
    }
    int req=sum%9;
    int x=f['2'];
    int y=f['3'];
    if(canBeDivisibleBy9(req,x,y)){
        cout<<"YES";
        return;
    }
    cout<<"NO";
}
