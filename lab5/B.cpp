#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<int>> nodos(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    nodos[u].push_back(v);
    nodos[v].push_back(u);
  }
  queue<int> Q;
  vector<int> distancias(n + 1, -1);
  Q.push(1);
  distancias[1] = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v : nodos[u]) {
      if (distancias[v] == -1) {
        distancias[v] = distancias[u] + 1;
        Q.push(v);
      }
    }
  }

  for (int i = 0; i <= n; ++i) {
    if (i != x)
      distancias[i] = -1;
  }

  if (distancias[x] != -1) {
    Q.push(x);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (int v : nodos[u]) {
        if (distancias[v] == -1) {
          distancias[v] = distancias[u] + 1;
          Q.push(v);
        }
      }
    }
  }
  cout << distancias[n];
}
