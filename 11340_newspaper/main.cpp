#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int k, p;
    string val, para = "", para_seg;
    map<char, double> dict;
    cin >> k;
    getline(cin, val);
    while (k--) {
      char c;
      double d;
      cin >> c;
      cin >> d;
      dict[c] = d;
      getline(cin, val);
    }

    cin >> p;
    getline(cin, para_seg);
    while (p--) {
      getline(cin, para_seg);
      para += para_seg;
    }

    double sum = 0;

    for (int i = 0; i < para.size(); i++) {
      sum += dict[para.at(i)];
    }

    cout << fixed;
    cout << setprecision(2);
    cout << (sum / 100.0) << "$" << endl;
  }

    return 0;
}