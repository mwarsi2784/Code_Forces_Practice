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


template <typename T>
class SegmentTree {
    public:
    int n;
    std::vector<T> tree;
    std::function<T(T, T)> combine;
    T default_value;
    void build(const std::vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2 + 1, tl, tm);
            build(arr, v * 2 + 2, tm + 1, tr);
            tree[v] = combine(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return default_value;
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return combine(query(v * 2 + 1, tl, tm, l, std::min(r, tm)), query(v * 2 + 2, tm + 1, tr, std::max(l, tm + 1), r));
    }
    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2 + 1, tl, tm, pos, new_val);
            }
            else {
                update(v * 2 + 2, tm + 1, tr, pos, new_val);
            }
            tree[v] = combine(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
    SegmentTree(const std::vector<T>& arr, T default_val, std::function<T(T, T)> comb)
        : n(arr.size()), default_value(default_val), combine(comb) {
        tree.resize(4 * n, default_value);
        build(arr, 0, 0, n - 1);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    void update(int pos, T new_val) {
        update(0, 0, n - 1, pos, new_val);
    }
};

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SegmentTree<int> maxi(a, INT_MIN, [](int a,int b){return max(a,b);});
    SegmentTree<int> sum(a, 0, [](int a,int b){return (a+b);});
    
    cout<<maxi.query(0,n-1)<<" ";
    for(int i=2;i<n;i++){
        int ind= n - (i - 1);
        int s=sum.query(ind,n-1);
        int m=maxi.query(0,ind-1);
        cout<<s+m<<" ";
    }
    if(n!=1) cout<<sum.query(0,n-1);
}