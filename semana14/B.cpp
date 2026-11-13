#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 5;
const long long INF = numeric_limits<long long>::max();
vector<pair<long long, long long>> dist(N, {INF, INF});
int r = 1;
long long n, P, Q, M;

int weight(int i, int j) {
  long long res = (i + j) * P + i * j * Q;
  return res % M + 1;
}

void dijkstra() {
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>,
                 greater<tuple<long long, int, int>>>
      Q;
  dist[r] = {0, 0};
  Q.push({0, 0, r});
  while (!Q.empty()) {
    auto [d, e, u] = Q.top();
    Q.pop();
    if (d > dist[u].first)
      continue;
    for (int v = 1; v <= n; ++v) {
      int w = weight(v, u);
      if (d + w < dist[v].first ||
          (d + w == dist[v].first && e + 1 < dist[v].second)) {
        dist[v].first = d + w;
        dist[v].second = e + 1;
        Q.push({d + w, e + 1, v});
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> P >> Q >> M;
  dijkstra();
  cout << dist[n].first << " " << dist[n].second << '\n';
  return 0;
}
