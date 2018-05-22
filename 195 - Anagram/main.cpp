#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

bool compare(char, char);
bool isUpperCase(char);

bool compare(char a, char b) {
  bool smallA = true, smallB = true;

  if (isUpperCase(a)) {
    smallA = false;
  }
  if (isUpperCase(b)) {
    smallB = false;
  }

  if ((smallA && smallB) || (!smallA && !smallB)) {
    return a < b;
  }

  if (smallA) {
    a -= ('a' - 'A');
    return a < b;
  } else {
    b -= ('a' - 'A');
    return a <= b;
  }
}

bool isUpperCase(char a) {
  return a >= 'A' && a <= 'Z';
}

int main() {
  int N;
  scanf("%d", &N);

  while (N--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end(), compare);
    do {
      cout << s << endl;  
    } while (next_permutation(s.begin(), s.end(), compare));
  }

  return 0;
}
