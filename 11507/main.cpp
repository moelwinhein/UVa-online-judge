#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string prev="+x", curr;
	int tc;

	while(scanf("%d", &tc), tc) {
		cin.ignore();
		tc--;
		while(tc--) {
			cin >> curr;
			if(prev.compare("+x")==0) {
				if(curr.compare("No")!=0) prev = curr;
			}
			else if(prev.compare("-x")==0) {
				if(curr.compare("+y")==0) prev = "-y"; 
				else if(curr.compare("-y")==0) prev = "+y";
				else if(curr.compare("+z")==0) prev = "-z";
				else if(curr.compare("-z")==0) prev = "+z";
			}
			else if(prev.compare("+y")==0) {
				if(curr.compare("+y")==0) prev = "-x"; 
				else if(curr.compare("-y")==0) prev = "+x";
				else if(curr.compare("+z")==0) prev = "+y";
				else if(curr.compare("-z")==0) prev = "+y";
			}
			else if(prev.compare("-y")==0) {
				if(curr.compare("+y")==0) prev = "+x"; 
				else if(curr.compare("-y")==0) prev = "-x";
				else if(curr.compare("+z")==0) prev = "-y";
				else if(curr.compare("-z")==0) prev = "-y";
			}
			else if(prev.compare("+z")==0) {
				if(curr.compare("+y")==0) prev = "+z"; 
				else if(curr.compare("-y")==0) prev = "+z";
				else if(curr.compare("+z")==0) prev = "-x";
				else if(curr.compare("-z")==0) prev = "+x";
			}
			else if(prev.compare("-z")==0) {
				if(curr.compare("+y")==0) prev = "-z"; 
				else if(curr.compare("-y")==0) prev = "-z";
				else if(curr.compare("+z")==0) prev = "+x";
				else if(curr.compare("-z")==0) prev = "-x";
			}
		}
		printf("%s\n", prev.c_str());
		prev = "+x";
	}

	return 0;
}