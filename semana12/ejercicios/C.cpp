#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e7 + 9;

int conex = 1;

bool bipartite(vector<set<int>> &G, vector<int> &visitados, int n) {
  visitados[1] = 0;
  queue<int> Q;
  Q.push(1);
  bool todovisit = false;
  while (!todovisit) {
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      for (auto it = G[v].begin(); it != G[v].end(); ++it) {
        int u = *it;
        if (visitados[u] != -1) {
          if (visitados[u] == visitados[v]) {
            return false;
          } else {
            continue;
          }
        }
        visitados[u] = 1 - visitados[v];
        Q.push(u);
      }
    }
    todovisit = true;
    for (int i = 1; i <= n; ++i) {
      if (visitados[i] == -1) {
        conex++;
        Q.push(i);
        visitados[i] = 0;
        todovisit = false;
        break;
      }
    }
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<set<int>> G(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].insert(v);
    G[v].insert(u);
  }
  vector<int> visitados(n + 1, -1);

  bool rpta = bipartite(G, visitados, n);
  int val = 1;
  for (int i = 0; i < conex; ++i) {
    val = (val * 2) % MOD;
  }
  if (rpta) {
    cout << "SI " << val;
  } else {
    cout << "NO";
  }
}
