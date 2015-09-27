#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> ps, p, bk;
	int a, b, c, d, e, win=0, value, erase=-1;

	while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&e) && a && b && c && d && e) {
		if(!ps.empty()) ps.clear();
		if(!p.empty()) p.clear();
		if(!bk.empty()) bk.clear();
		ps.push_back(a); ps.push_back(b); ps.push_back(c);
		bk.push_back(a); bk.push_back(b); bk.push_back(c);
		p.push_back(d); p.push_back(e);
		bk.push_back(d); bk.push_back(e);
		sort(ps.begin(), ps.end());
		sort(p.begin(), p.end());
		sort(bk.begin(), bk.end());
		if(p.at(1)>ps.at(2) && p.at(0)>ps.at(2)) {
			value = 1;
			if(value==bk.at(0)) value++; 
			if(value==bk.at(1)) value++;
			if(value==bk.at(2)) value++; 
			if(value==bk.at(3)) value++;
			if(value==bk.at(4)) value++;
			if(value > 52) value = -1;
		}
		else {
			for(int i=0;i<ps.size();i++) {
				if(ps.at(i)>p.at(1)) { erase=i; break; }
			}
			if(erase==-1) {
				win++;
				ps.erase(ps.begin());
			}
			else {
				ps.erase(ps.begin()+erase);
				erase=-1;
			}
			for(int i=0;i<ps.size();i++) {
				if(ps.at(i)>p.at(0)) { erase=i; break; }
			}
			if(erase==-1) {
				win++;
				ps.erase(ps.begin());
			}
			else {
				ps.erase(ps.begin()+erase);
				erase=-1;
			}

			if(win>=1) {
				value = ps.at(0)+1;
				if(value==bk.at(0)) value++; 
				if(value==bk.at(1)) value++;
				if(value==bk.at(2)) value++; 
				if(value==bk.at(3)) value++;
				if(value==bk.at(4)) value++;
				if(value > 52) value = -1;
			}
			else value=-1;
		}
		printf("%d\n", value);
		win=0;
	}
	return 0;
}