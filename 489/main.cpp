#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int tc, w=0, wrong=0;
	int checker[26]={0};
	char word[200], guess[200];
	while(scanf("%d", &tc) && tc!=-1) {
		memset(checker, 0, sizeof(checker));
		memset(word, '0', sizeof(word));
		memset(guess, '0', sizeof(guess));
		w=0; wrong=0;
		scanf("%s", word);
		scanf("%s", guess);
		for(int i=0; word[i]; i++) {
			checker[(int)word[i] - 97] += 1;
			w++;
		}
		for(int i=0; guess[i]; i++) {
			if(checker[(int)guess[i]-97]==0) {
				checker[(int)guess[i]-97] = -1;
				wrong++;
				if(wrong>=7) break;
			}
			else if(checker[(int)guess[i]-97]>0) {
				w -= checker[(int)guess[i]-97];
				checker[(int)guess[i]-97] = -1;
				if(w==0) break;
			}
			else { }
		}
		if(wrong>=7) printf("Round %d\nYou lose.\n", tc);
		else if(w==0) printf("Round %d\nYou win.\n", tc);
		else printf("Round %d\nYou chickened out.\n", tc);
	}
	return 0;
}