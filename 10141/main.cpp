#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int want, num_company, give, i, cnt=0, index=0; 
	float price, min_price, compliance, max_compliance;
	string company, chosen_company, dummy;

	while(scanf("%d %d", &want, &num_company), (want||num_company)) {
		index++;
		if(index>1) printf("\n");
		for(i=0;i<=want;i++) getline(cin, dummy);
		while(num_company--) {
			cnt++;
			getline(cin, company);
			scanf("%f %d", &price, &give);
			compliance = (float)give/want;
			if(cnt>1) {
				if(max_compliance<compliance) {
					max_compliance = compliance;
					chosen_company = company;
					min_price = price;
				}
				else if(max_compliance==compliance) {
					if(min_price>price) {
						max_compliance = compliance;
						chosen_company = company;
						min_price = price;
					}
				}
			}
			else {
				max_compliance = compliance;
				chosen_company = company;
				min_price = price;
			}
			for(i=0;i<=give;i++) getline(cin, dummy);
		}
		printf("RFP #%d\n", index);
		printf("%s\n", chosen_company.c_str());
		cnt=0;
	}
	return 0;
}