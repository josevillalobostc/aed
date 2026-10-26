#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, x, y;
  cin >> A >> B >> x >> y;
  int aristas = 0;
  int grado = 0;
  for (int i = 0; i < A + 1; i++) {
    for (int j = 0; j < B + 1; j++) {
      if (i > 0) {
        int new_i = 0;
        int new_j = j;
        if (x == new_i && y == new_j)
          grado++;
        aristas++;
      }
      if (j > 0) {
        int new_i = i;
        int new_j = 0;
        if (x == new_i && y == new_j)
          grado++;
        aristas++;
      }
      if (i < A) {
        int new_i = A;
        int new_j = j;
        if (x == new_i && y == new_j)
          grado++;
        aristas++;
      }
      if (j < B) {
        int new_i = i;
        int new_j = B;
        if (x == new_i && y == new_j) {
          grado++;
        }
        aristas++;
      }
      if (i < A) {
        int new_i = min(A, i + j);
        int new_j = min(0, j - (A - i));
        if (x == new_i && y == new_j) {
          grado++;
        }
        aristas++;
      }
      if (j < B) {
        int new_j = min(B, i + j);
        int new_i = min(0, i - (B - j));
        if (x == new_i && y == new_j) {
          grado++;
        }
        aristas++;
      }
    }
  }
  cout << aristas << " " << grado;
}
