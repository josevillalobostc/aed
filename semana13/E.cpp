#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> nodos;
vector<pair<int, int>> edges;
stack<int> current_path;
vector<int> path;
vector<int> s;

bool has_cycle(int u) {
  s[u] = 1;
  for (auto &e : nodos[u]) {
    if (s[e.first] == 1) {
      while (current_path.top() != u) {
      }
      return true;
    }
    current_path.push(e.second);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  nodos = vector<vector<pair<int, int>>>(n);
  edges = vector<pair<int, int>>(m);
  visit = vector<int>(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u, v};
    nodos[u].push_back({0, v});
    nodos[v].push_back({0, u});
  }
  dfs();
}
