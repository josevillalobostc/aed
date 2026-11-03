#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> deg(n + 1, 0);
  vector<vector<int>> nodos(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
    nodos[u].push_back(v);
    nodos[v].push_back(u);
  }
  queue<int> Q;
  vector<int> distancias(n + 1, -1);
  distancias[1] = 0;
  Q.push(1);
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
  int max1 = -1;
  int ind;
  for (int i = 1; i <= n; ++i) {
    if (distancias[i] > max1) {
      max1 = distancias[i];
      ind = i;
    }
  }
  distancias[ind] = 0;
  int max2 = -1;
  for (int i = 1; i <= n; ++i) {
    if (distancias[i] > max2) {
      max2 = distancias[i];
      ind = i;
    }
  }
  distancias[ind] = 0;

  if (max1 + max2 == n - 1) {
    cout << "SI";
  } else {
    cout << "NO";
  }
  return 0;
}
