#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;

const long long N = 2 * 100000 + 5;
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
  cin >> n;
  vector<int> grados(n + 1, 0);
  m = n - 1;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    grados[u]++;
    grados[v]++;
    nodes[u].push_back({v, w});
    nodes[v].push_back({u, w});
  }

  r = *max_element(grados.begin() + 1, grados.end());

  dijkstra();
  cout << *max_element(dist.begin() + 1, dist.begin() + n + 1) << '\n';
  return 0;
}
