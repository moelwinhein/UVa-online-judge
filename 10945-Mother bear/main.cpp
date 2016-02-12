#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	char ch[] = {'.', ',', '!', '?', ' '};
	while(getline(cin, str)) {
		for (int i = 0; i < 5; i++) 
			str.erase(remove(str.begin(), str.end(), ch[i]), str.end()); 
		if (str.compare("DONE") == 0) break;
		bool ispalindrome = true;
		int len = str.length();
		for (int i = 0; i < len/2; i++) {
			if (toupper(str.at(i)) != toupper(str.at(len - i - 1))) {
				ispalindrome = false;
				break;
			}
		}

		if (ispalindrome) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
	return 0;
}