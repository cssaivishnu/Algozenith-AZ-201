#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

const int N = 100010;

struct edge {
    int u, v, w;
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    edge E[m];
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E[i].u = a;
        E[i].v = b;
        E[i].w = -c;
    }

    ll dist[n + 1];
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e18;
    }
    dist[1] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int u = E[j].u;
            int v = E[j].v;
            int w = E[j].w;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    bool neg = false;
    for(int i = 0; i < m; i++) {
        int u = E[i].u;
        int v = E[i].v;
        int w = E[i].w;
        if(dist[v] > dist[u] + w) {
            neg = true;
            break;
        }
    }

    if(neg) cout << "-1\n";
    else {
        assert(dist[n] != 1e18);
        cout << -dist[n] << "\n";
    }
}