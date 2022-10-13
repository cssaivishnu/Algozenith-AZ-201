#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += mod;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
	if (b & 1) {
	  res = mul(res, a);
	}
	a = mul(a, a);
	b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
	int t = b / a;
	b -= t * a; swap(a, b);
	u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}

int fact[N];

void pre() {
	fact[0] = 1;
	for(int i = 1; i < N; i++)
		fact[i] = mul(fact[i - 1], i);
	return;
}

signed main()
{
	//freopen("IN", "r", stdin);
	//freopen("OUT", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	pre();

	int T; cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int ans = mul(n, n - 1);
		ans = mul(ans, n - 2);
		ans = mul(ans, n - 3);
		ans = mul(ans, inv(24));
		cout << ans << "\n";
	}

	return 0;
}