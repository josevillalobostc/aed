#include <bits/stdc++.h>
using namespace std;

int n, m;

int bfs(int u, vector<vector<int>> &vec) {
  int m = 0;
  queue<int> Q;
  vector<int> pesos(n + 1, -1);
  pesos[u] = 0;
  Q.push(u);
  int cant = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (pesos[u] == 2) {
      cant++;
      continue;
    }
    for (int v : vec[u]) {
      if (pesos[v] == -1) {
        pesos[v] = pesos[u] + 1;
        Q.push(v);
      }
    }
  }
  return cant;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  cin >> n >> m;
  vector<vector<int>> nodes(n + 1);
  vector<int> amigos(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    nodes[u].push_back(v);
    nodes[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    cout << bfs(i, nodes) << " ";
  }
}
