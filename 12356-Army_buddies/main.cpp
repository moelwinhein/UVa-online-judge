#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int S, B;
  while (true) {
    scanf("%d %d", &S, &B);
    if (S == 0 && B == 0) {
      break;
    }
    int left[S+2];
    int right[S+2];

    fill_n(left, S+2, -1);
    fill_n(right, S+2, -1);

    for (int i = 0; i < S + 2; i++) {
      if (i > 1) {
        left[i] = i - 1;
      }
      if (i < S) {
        right[i] = i + 1;
      }
    }
    
    while (B--) {
      int L, R;
      string ll, rr, result;
      scanf("%d %d", &L, &R);
      ll = left[L] == -1 ? "*" : to_string(left[L]);
      rr = right[R] == -1 ? "*" : to_string(right[R]);
      right[left[L]] = right[R];
      left[right[R]] = left[L];
      result = ll + " " + rr;
      cout << result << endl;
    }

    cout << "-" << endl;
  }

  return 0;
}
