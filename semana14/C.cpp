#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 10000 + 5;
vector<vector<pair<int, int>>> nodes(N);
const long long INF = numeric_limits<long long>::max();
vector<long long> dist1(N, INF);
vector<long long> dist2(N, INF);
int n, m;

void dijkstra1() {
  int r = 1;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      Q;
  dist1[r] = 0;
  Q.push({0, r});
  while (!Q.empty()) {
    auto [d, u] = Q.top();
    Q.pop();
    if (d > dist1[u])
      continue;
    for (auto [v, w] : nodes[u]) {
      if (d + w < dist1[v]) {
        dist1[v] = d + w;
        Q.push({d + w, v});
      }
    }
  }
}

void dijkstra2() {
  int r = n;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      Q;
  dist2[r] = 0;
  Q.push({0, r});
  while (!Q.empty()) {
    auto [d, u] = Q.top();
    Q.pop();
    if (d > dist2[u])
      continue;
    for (auto [v, w] : nodes[u]) {
      if (d + w < dist2[v]) {
        dist2[v] = d + w;
        Q.push({d + w, v});
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    nodes[u].push_back({v, w});
    nodes[v].push_back({u, w});
  }
  vector<long long> tiempos(n + 1, INF);
  for (int i = 1; i <= n; ++i) {
    tiempos[i] = max(dist1[i], dist2[i]);
  }
  sort(tiempos.begin(), tiempos.end());
  long long minimin = tiempos[0];
  long long cant = upper_bound(tiempos.begin(), tiempos.end(), minimin) -
                   lower_bound(tiempos.begin(), tiempos.end(), minimin);
  if (minimin == INF) {
    cout << -1 << '\n';
    return 0;
  }
  cout << minimin << " " << cant << '\n';
  return 0;
}
