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
	ll n,k,sum=0; cin >> n >> k;
	vector<ll> v(n);
	rep(i,0,n){
		cin >> v[i];
		sum += v[i];
	}
	ll l = 1, r = sum, ans = LLONG_MAX;
	while(l <= r){
		ll m = l + (r-l)/2;
		ll cnt = 1, s = 0, mx = LLONG_MIN;
		rep(i,0,n){
			if(v[i] > m){
				cnt = LLONG_MAX;
				break;
			}
			if(s+v[i] > m){
				cnt++;
				s = v[i];
			}else{
				s += v[i];
			}
			mx = max(mx,s);
		}
		if(cnt > k){
			l = m+1;
		}else{
			ans = min(ans,mx);
			r = m-1;
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