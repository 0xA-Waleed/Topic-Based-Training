#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) (int)v.size()
#define ll long long int
#define PB push_back

void solve(){ 
	ll n,t; cin >> n >> t;
	vector<ll> v(n);
	rep(i,0,n) cin >> v[i];
	ll l = 1, r = 2e18, ans = 2e18;
	while(l <= r){
		ll m = l + (r-l)/2;
		ll cnt = 0;
		rep(i,0,n){
			cnt += m/v[i];
			if(cnt >= 1e9){
				break;
			}
		}
		if(cnt >= t){
			ans = m;
			r = m-1;
		}else{
			l = m+1;
		}
	}
	cout << ans << '\n';
}

int main(){
	int testcase = 1;
	//cin >> testcase;
	while(testcase--){
		solve();
	}
}