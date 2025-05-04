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


bool isPrime(int t){
    int i=2;
    if(t<=1){
        return false;
    }
    while(i*i<=t){
        if(t%i==0){
            return false;
        }
        i++;
    }
    return true;
}

void solve(){
    ld x,k;
    cin>>x>>k;
    int digit=1;
    int num=9;
    while(x>num){
        num=num*10;
        num=num+9;
        digit++;
    }
    int final_num=0;
    for(int i=0;i<k;i++){
        final_num=final_num+x*pow(10,digit*i);
    }
    if(k!=1 && x!=1){
        cout<<"NO";
        return;
    }
    if(k==1){
        cout<<(isPrime(final_num)?"YES":"NO");
        return;
    }
    cout << ((k == 2) ? "YES" : "NO");
}