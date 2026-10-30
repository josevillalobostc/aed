#include <bits/stdc++.h>
using namespace std;

int foo(int &n, int &m) {
  int limite = max(n, 2 * m);
  vector<int> pesos(limite + 1, -1);
  queue<int> Q;
  Q.push(n);
  pesos[n] = 0;
  int c;
  while (!Q.empty()) {
    c = Q.front();
    Q.pop();
    if (c == m) {
      return pesos[c];
    }
    if (c < m && pesos[2 * c] == -1) {
      pesos[c * 2] = pesos[c] + 1;
      Q.push(c * 2);
    }
    if (c > 0 && pesos[c - 1] == -1) {
      pesos[c - 1] = pesos[c] + 1;
      Q.push(c - 1);
    }
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  cout << foo(n, m);
}
