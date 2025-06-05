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


bool isBetterXor(const std::string& s, const std::string& temp, const std::string& ans) {
    int lenS = s.size();
    int lenX = temp.size(); // same for temp and ans

    // Left pad temp and ans to match length of s
    std::string paddedTemp(lenS - lenX, '0');
    paddedTemp += temp;

    std::string paddedAns(lenS - lenX, '0');
    paddedAns += ans;

    // XOR bit-by-bit and compare the result as binary strings (MSB to LSB)
    for (int i = 0; i < lenS; i++) {
        char xorTemp = (s[i] != paddedTemp[i]) ? '1' : '0';
        char xorAns  = (s[i] != paddedAns[i])  ? '1' : '0';

        if (xorTemp > xorAns) return true;
        if (xorTemp < xorAns) return false;
    }

    // If all bits are equal
    return false;
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
    int l1,r1;
    string ans="";
    for(int i=0;i<firstzero;i++){
        string temp=s.substr(i,l);
        if(fun(s,temp,ans)){
            l1=i+1;
            r1=l1+l-1;
            ans=temp;
        }
    }
    cout<<1<<" "<<n<<" "<<l1<<" "<<r1;
}