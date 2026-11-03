#include <algorithm>
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
  int ind = 1;
  int min = 2 * m;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] < min) {
      ind = i;
      min = deg[i];
    }
  }
  queue<int> Q;
  vector<int> distancias(n + 1, -1);
  distancias[ind] = 0;
  Q.push(ind);
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
  int val = *max_element(distancias.begin(), distancias.end());
  if (val == n - 1) {
    cout << "SI";
  } else {
    cout << "NO";
  }
  return 0;
}
