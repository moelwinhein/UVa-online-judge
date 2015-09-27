#include <stdio.h>

int main()
{
	int num_tc, max = -20000, num_mon, speed, cnt;
	scanf("%d", &num_tc);
	cnt = num_tc;
	while(num_tc)
	{
		scanf("%d", &num_mon);
		while(num_mon)
		{
			scanf("%d", &speed);
			if(speed > max) max = speed;
			num_mon--;
		}
		printf("Case %d: %d\n", cnt-num_tc+1, max);
		max = -20000;
		num_tc--;
	}
	return (0);
}