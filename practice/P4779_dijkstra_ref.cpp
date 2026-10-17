#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// P4779: 标准单源最短路模板, 边权非负, n<=1e5, m<=2e5
// 必须堆优化 Dijkstra, 裸 O(N^2) 会 TLE
const int MAXN = 100010, MAXM = 400010; // 有向边 2*m
const ll INF = 1e18;

int head[MAXN], nxt[MAXM], to[MAXM];
ll wt[MAXM], ecnt;
ll dis[MAXN];
int n, m, s;

void add(int u, int v, ll w) {
    to[++ecnt] = v; wt[ecnt] = w;
    nxt[ecnt] = head[u]; head[u] = ecnt;
}

void dijkstra() {
    for (int i = 1; i <= n; ++i) dis[i] = INF;
    dis[s] = 0;
    // 小根堆: 存 (距离, 点)
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dis[u]) continue;   // 懒删除: 过期堆顶直接跳过
        for (int e = head[u]; e; e = nxt[e]) {
            int v = to[e];
            if (dis[v] > dis[u] + wt[e]) {
                dis[v] = dis[u] + wt[e];
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 0, u, v; ll w; i < m; ++i) {
        cin >> u >> v >> w; add(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        if (dis[i] == INF) cout << "2147483647";
        else cout << dis[i];
        cout << (i == n ? '\n' : ' ');
    }
    return 0;
}
