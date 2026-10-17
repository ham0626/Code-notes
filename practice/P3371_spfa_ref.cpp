#include <bits/stdc++.h>
using namespace std;
// P3371 弱化版: 单源最短路模板, 规模小(n<=2000), 用 SPFA 跑最短路即可
// 本质 = P2850 板子去掉"负环计数", 只留距离松弛
const int MAXN = 2010, MAXM = 500010, INF = 0x7fffffff;
int head[MAXN], nxt[MAXM], to[MAXM], wt[MAXM], ecnt;
int dis[MAXN], inq[MAXN];
int n, m, s;

void add(int u, int v, int w) {
    to[++ecnt] = v; wt[ecnt] = w;
    nxt[ecnt] = head[u]; head[u] = ecnt;
}

void spfa() {
    for (int i = 1; i <= n; ++i) dis[i] = INF, inq[i] = 0;
    dis[s] = 0; inq[s] = 1;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        if (dis[u] == INF) continue;   // 防溢出: 不可达点不松弛
        for (int e = head[u]; e; e = nxt[e]) {
            int v = to[e];
            if (dis[v] > dis[u] + wt[e]) {
                dis[v] = dis[u] + wt[e];
                if (!inq[v]) { inq[v] = 1; q.push(v); }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 0, u, v, w; i < m; ++i) { cin >> u >> v >> w; add(u, v, w); }
    spfa();
    for (int i = 1; i <= n; ++i) cout << dis[i] << (i == n ? '\n' : ' ');
    return 0;
}
