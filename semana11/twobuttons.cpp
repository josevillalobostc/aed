#include <bits/stdc++.h>
using namespace std;

int foo(int &n, int &m) {
  unordered_map<int, int> pesos;
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
    if (pesos.find(c * 2) == pesos.end() && c * 2 <= 2 * m) {
      pesos[c * 2] = pesos[c] + 1;
      Q.push(c * 2);
    }
    if (pesos.find(c - 1) == pesos.end() && c > 0) {
      pesos[c - 1] = pesos[c] + 1;
      Q.push(c - 1);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  cout << foo(n, m);
}
