// tag: Dijsktra

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Edge {
  int u, v;
  ll w;
  Edge(int _u = 0, int _v = 0, ll _w = 0) : u(_u), v(_v), w(_w) {}
  friend bool operator<(const Edge& a, const Edge& b) {
    return a.w < b.w;
  }
};

constexpr int mxN = 2e5 + 1;
int n, m, k, r, id[mxN];
vector<Edge> adj[mxN];
bool vis[mxN];
ll dis[mxN];

void dijsktra() {
  memset(dis, 0x3f3f3f3f, sizeof(dis));
  assert(dis[0] > 1e12 && dis[n] > 1e12);
  priority_queue<Edge> pq;
  for(int i = 0; i <= n; ++i)
    if(!id[i])
      dis[i] = 0;
  pq.emplace(0, 0, 0);
  while(!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if(vis[cur.v]) continue;
    vis[cur.v] = 1;
    for(auto& nxt : adj[cur.v]) {
      if(dis[nxt.v] > dis[nxt.u] + nxt.w) {
        dis[nxt.v] = dis[nxt.u] + nxt.w;
        pq.emplace(nxt.u, nxt.v, dis[nxt.v]);
      }
    }
  }
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);

  cin >> n >> m >> k >> r;
  iota(id, id + n + 1, 0);
  for(int t, i = 0; i < k; ++i) {
    cin >> t;
    id[t] = 0;
  }
  for(int u, v, w, i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    u = id[u];
    v = id[v];
    if(u == v) continue;
    adj[u].emplace_back(u, v, w);
    adj[v].emplace_back(v, u, w);
  }
  dijsktra();
  sort(dis, dis + n + 1, greater<int>());
  cout << dis[r] << '\n';
}