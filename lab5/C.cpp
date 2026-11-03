#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> saltar(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> saltar[i];
  }
  vector<int> distancias(n + 1, -1);
  queue<int> Q;
  distancias[1] = 0;
  Q.push(1);
  while (!Q.empty()) {
    int p = Q.front();
    Q.pop();
    int der = p + saltar[p];
    int izq = p - saltar[p];
    if (der <= n && distancias[der] == -1) {
      distancias[der] = distancias[p] + 1;
      Q.push(der);
    }
    if (izq > 0 && distancias[izq] == -1) {
      distancias[izq] = distancias[p] + 1;
      Q.push(izq);
    }
  }
  cout << distancias[n];
}
