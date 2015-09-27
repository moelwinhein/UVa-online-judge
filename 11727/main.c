#include <stdio.h>

int findMin(int a, int b, int c) 
{
	int min;
	min = a;
	if (min > b) min = b;
	if (min > c) min = c;
	return min;
}

int findMax(int a, int b, int c) 
{
	int max;
	max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return max;
}


int main() 
{
	int tc, a, b, c, min, max;
	int num = 1;

	scanf("%d", &tc);
	while(tc)
	{
		scanf("%d %d %d", &a, &b, &c);
		min = findMin(a, b, c);
		max = findMax(a, b, c);
		printf("Case %d: %d\n", num, (a+b+c)-min-max);
		num++;
		tc--;
	}

	return (0);
}