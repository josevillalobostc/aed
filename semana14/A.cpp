#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;

const long long N = 100000 + 5;
const long long INF = numeric_limits<long long>::max();

vector<long long> dist(N, INF);
vector<vector<pair<int, int>>> nodes(N);
int n, m, r;

void dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      Q;
  dist[r] = 0;
  Q.push({0, r});
  while (!Q.empty()) {
    auto [d, u] = Q.top();
    Q.pop();
    if (d > dist[u])
      continue;
    for (auto [v, w] : nodes[u]) {
      if (d + w < dist[v]) {
        dist[v] = d + w;
        Q.push({d + w, v});
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m >> r;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    nodes[u].push_back({v, w});
  }
  dijkstra();
  for (int i = 0; i < n; ++i) {
    if (dist[i] == INF) {
      cout << "INF" << '\n';
      continue;
    }
    cout << dist[i] << '\n';
  }
  return 0;
}
