#include <cstdio>
#include <cstring>
using namespace std;

int ctoi(char c) {
    if(c == 'X' || c == '/') return 10;
    return c - '0';
}

int main() {
    char ch, c_arr[100];
    int score = 0, i = 0;
    while(scanf("%c", &ch) && ch != 'G') {
        if(ch == ' ') continue;
        if(ch == '\n') {
            int j = 0;
            int k = 0;
            while(i--) {
                if(c_arr[k] == 'X') j += 2;
                else j += 1;
                if(j < 20) {
                    if(c_arr[k] == 'X') {
                        if(c_arr[k+2] == '/') score += ctoi(c_arr[k]) + 10;
                        else score += ctoi(c_arr[k]) + ctoi(c_arr[k+1]) + ctoi(c_arr[k+2]); 
                    }
                    else if(c_arr[k] == '/') score += ctoi(c_arr[k]) + ctoi(c_arr[k+1]) - ctoi(c_arr[k-1]);
                    else score += ctoi(c_arr[k]);
                }
                else {
                    if(c_arr[k] == '/') score += 10 - ctoi(c_arr[k-1]);
                    else score += ctoi(c_arr[k]);
                }
                k++;
            }
            printf("%d\n", score);

            memset(c_arr, 0, sizeof(c_arr));
            i = 0; score = 0;
            continue;
        }
        c_arr[i++] = ch;
    }
    return 0;
}
