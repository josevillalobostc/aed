#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  cin >> n >> m;
  vector<int> deg(n, 0);
  while (m--) {
    int u, v;
    cin >> u >> v;
    ++deg[u - 1];
    ++deg[v - 1];
  }
  int odds = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[i] % 2 == 1) {
      odds++;
    }
  }
  if (odds == 0) {
    cout << "CIRCUITO";
  } else if (odds == 2) {
    cout << "CAMINO";
  } else {
    cout << "IMPOSIBLE";
  }
}
