#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
	while (cin >> n) {
		int k, prev, curr;
    bool skip = false;

		if (n == 1) {
			cout << "Jolly" << endl;
			cin >> prev;
			continue;
		}

		k = n;
		cin >> prev;
		n--;

		char str[k];
		char *begin = &str[0];
		char *end = begin + sizeof(str);
		fill(begin, end, 0);

		while (n--) {
			cin >> curr;
      if (!skip) {
        if (abs(prev - curr) >= k) {
          skip = true;
        } else {
          str[abs(prev - curr) - 1] = '1';
        }
      }
      prev = curr;
		}

    string strstr = str;

    if (skip) cout << "Not jolly" << endl;
    else if (strstr.size() == (k - 1)) cout << "Jolly" << endl;
    else cout << "Not jolly" << endl;
	}

	return 0;
}
