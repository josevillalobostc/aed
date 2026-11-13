#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;

vector<vector<int>> nodes(N);
vector<int> visitados(N, 0);

void bfs(int u) {
  visitados[u] = 1;
  for (auto &v : nodes[u]) {
    bfs(v);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  if (m != n - 1) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    nodes[u].push_back(v);
    nodes[v].push_back(u);
  }
  bfs(1);

  for (int i = 1; i <= n; ++i) {
    if (visitados[i] == 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
