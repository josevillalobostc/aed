#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, m, mat;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> mat;
    mat = mat << m;
  }
}
