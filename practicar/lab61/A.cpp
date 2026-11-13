#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100000 + 5;
int n, m;
vector<vector<int>> nodos(N);
vector<int> orden;
vector<int> visitados(N, -1);
int cant = 0;

void dfs(int u) {
  orden.push_back(u);
  cant++;
  for (auto &v : nodos[u]) {
    if (visitados[v] == -1) {
      visitados[v] = 1;
      dfs(v);
    }
  }
}

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    nodos[u].push_back(v);
    nodos[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    sort(nodos[i].begin(), nodos[i].end());
  }
  visitados[1] = 1;
  dfs(1);
  cout << cant << '\n';
  for (auto u : orden) {
    cout << u << " ";
  }
  cout << '\n';
}
