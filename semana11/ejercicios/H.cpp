#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<bitset<3001>> adj(n + 1);
  vector<pair<int, int>> e;
  while (m--) {
    int a, b;
    cin >> a >> b;
    e.push_back({a, b});
    adj[a][b] = 1;
    adj[b][a] = 1;
  }
  int suma = 0;
  for (auto [a, b] : e) {
    suma += (adj[a] & adj[b]).count();
  }
  cout << suma / 3;
}
