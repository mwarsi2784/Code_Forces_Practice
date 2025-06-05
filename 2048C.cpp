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

int binaryToDecimal(const std::string& binaryStr) {
    int result = 0;
    for (char bit : binaryStr) {
        result = result * 2 + (bit - '0');
    }
    return result;
}



void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int firstzero=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            firstzero=i;
            break;
        }
    }
    if(firstzero==-1){
        cout<<1<<" "<<n<<" 1 1";
        return;
    }

    int l=n-firstzero;
    int ans=-1;
    int a=binaryToDecimal(s);
    int l1,r1;
    // deb2(s,l);
    for(int i=0;i<firstzero;i++){
        int temp=binaryToDecimal(s.substr(i,l));
        if(a^temp>ans){
            l1=i+1;
            r1=l1+l;
            ans=a^temp;
        }
    }
    cout<<1<<" "<<n<<" "<<l1<<" "<<r1;
}