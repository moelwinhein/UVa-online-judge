#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int countSquares(string big[], string small[], int N, int n) {
  int count = 0;
  for (int j = 0; j <= N-n; j++) {
    string str = big[j];
    string cmp = small[0];
    size_t pos = str.find(cmp);
    bool match = pos != string::npos;
    while (pos != string::npos) {
      for (int k = 1; k < n; k++) {
        if (big[j + k].compare(pos, n, small[k]) != 0) {
          match = false;
          break;
        }
      }
      if (match) {
        count++;
      }
      match = true;
      pos = str.find(cmp, pos + 1);
    }
  }
  return count;
}

void rotate90(string arr[], int size) {
  for (int r = 0; r < size; r++) {
    for (int c = r; c < size; c++) {
      swap(arr[r][c], arr[c][r]);
    }
  }
  for(int r = 0; r < size; r++) {
    for(int c =0; c < size/2; c++) {
      swap(arr[r][c], arr[r][size-c-1]);
    }
  }
}

int main() {
  while (true) {
    int N, n, c0, c90, c180, c270;
    scanf("%d %d", &N, &n);
    if (N == 0 && n == 0) {
      break;
    }
  
    string big[N];
    string small[n];

    for (int i = 0; i < N; i++) {
      cin >> big[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> small[i];
    }

    c0 = countSquares(big, small, N, n);
    rotate90(small, n);
    c90 = countSquares(big, small, N, n);
    rotate90(small, n);
    c180 = countSquares(big, small, N, n);
    rotate90(small, n);
    c270 = countSquares(big, small, N, n);

    printf("%d %d %d %d\n",c0, c90, c180, c270);
  }

  return 0;
}
