#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	string str;
	string chars   ("ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789");
	string mirrors ("A---3--HIL-JM-O---2TUVWXY51SE-Z--8-");
	map<char, char> mmap;
	for (int i = 0; i < chars.length(); i++) {
		mmap.insert(pair<char, char> (chars.at(i), mirrors.at(i)));
	}
	while (getline(cin, str)) {
		bool ispalindrome = true, ismirror = true;
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		int l = str.length();
		for (int i = 0; i < l/2; i++) {
			if (str.at(i) != str.at(l - i - 1)) ispalindrome = false; 
			char ch = mmap.find(str.at(i))->second;
			if (ch == '-' || ch != str.at(l - i - 1)) ismirror = false;
		}
		if (l % 2) {
			char ch = mmap.find(str.at(l/2))->second;
			if (ch != str.at(l/2)) ismirror = false;
		}

		if (ispalindrome && ismirror) cout << str << " -- is a mirrored palindrome." << endl;
		else if (ispalindrome) cout << str << " -- is a regular palindrome." << endl;
		else if (ismirror) cout << str << " -- is a mirrored string." << endl;
		else cout << str << " -- is not a palindrome." << endl;
		cout << endl;
	}
	return 0;
}