#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> segs(n + 1);
  set<pair<int, int>> aristas;
  while (m--) {
    int a, b;
    cin >> a >> b;
    segs[b]++;
    aristas.insert({a, b});
  }
  int cant = 0;
  for (auto it = aristas.begin(); it != aristas.end(); ++it) {
    int x = it->first;
    int y = it->second;
    if (aristas.find({y, x}) != aristas.end()) {
      cant++;
    }
  }
  cant /= 2;
  int best = max_element(segs.begin() + 1, segs.end()) - segs.begin();
  cout << cant << " " << best << " " << segs[best];
}
