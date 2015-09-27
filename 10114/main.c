#include <stdio.h>
#include <string.h>

int main() 
{
	int months, num, cnt, ptr, i; 
	float down, loan, car_price, inst;
	int end_month[150];
	float percent[150];

	while(1)
	{
		scanf("%d %f %f %d", &months, &down, &loan, &num);
		if (months < 0) break;
		car_price = down + loan;
		inst = loan/months;
		cnt = num;
		ptr = 0;
		i = 0;
		memset(end_month, 0, sizeof(end_month));
		memset(percent, 0, sizeof(percent));
		while(num)
		{
			scanf("%d %f", &end_month[cnt-num], &percent[cnt-num]);
			num--;
		}
		while(1)
		{
			if (i >= end_month[ptr+1] && ptr < cnt-1) ptr++;
			car_price = car_price - (car_price * percent[ptr]);
			if (car_price > (loan - inst * i)) break;
			i++;
		}
		if (i == 1) printf("%d month\n", i);
		else printf("%d months\n", i);
	}
	return (0);
}