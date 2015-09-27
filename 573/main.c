#include <stdio.h>

int main()
{
	int H, U, D, F, day=0, success=0;
	float reach=0, distance;

	while(scanf("%d %d %d %d", &H, &U, &D, &F) && H > 0)
	{
		while(1)
		{
			day++;
			if(day==1)
			{
				distance = U;
			}
			else
			{
				distance -= (U * F/100.0);
			} 
			if(distance>=0) reach += distance;
			if(reach>H)
			{
				success = 1;
				break;
			}
			reach -= D;
			if(reach<0) break;
		}
		if(success) printf("success on day %d\n", day);
		else printf("failure on day %d\n", day);
		day=0; 
		success=0; 
		reach=0;
	}

	return (0);
}