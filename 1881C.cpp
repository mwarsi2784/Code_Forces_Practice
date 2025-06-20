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

pair<int,char> fun(char t1,char t2, char t3,char t4){
    int ans=0;
    char t=max(max(t1,t2),max(t3,t4));
    ans=ans+(t-t1)+(t-t2)+(t-t3)+(t-t4);
    return {ans,t};
}

void solve(){
    int n;
    cin>>n;
    char a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char t1=a[i][j];   //that element
            char t2=a[n-j-1][i];  
            char t3=a[n-i-1][n-j-1];
            char t4=a[j][n-i-1];
            pair<int,char> temp=fun(t1,t2,t3,t4);
            a[i][j]=temp.S;
            a[n-j-1][i]=temp.S;
            a[n-i-1][n-j-1]=temp.S;
            a[j][n-i-1]=temp.S;
            ans=ans+temp.F;
        }
    }
    cout<<ans;
}