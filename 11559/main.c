#include <stdio.h>

int main() 
{
	int p_num, h_num, weeks, i, flag=0, beds;
	float budg, per_night, min_budg=1000000, cost;

	while(scanf("%d %f %d %d", &p_num, &budg, &h_num, &weeks)==4)
	{
		while(h_num)
		{
			scanf("%f", &per_night);
			for(i=0;i<weeks;i++)
			{
				scanf("%d", &beds);
				if(beds>=p_num)
				{
					flag = 1;
				}
			}
			if(flag)
			{
				cost = per_night*p_num;
				if(budg>=cost && cost < min_budg)
				{
					min_budg = cost;
				}
			}
			flag=0;
			h_num--;
		}
		if(min_budg<1000000) printf("%d\n", (int)min_budg);
		else printf("stay home\n");
		min_budg = 1000000;
	}
	return (0);
}