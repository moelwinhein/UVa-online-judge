#include <stdio.h>

int main() 
{
	int q, x_ref, y_ref, x, y;

	while(1)
	{
		scanf("%d", &q);
		if(!q) break;
		scanf("%d %d", &x_ref, &y_ref);
		while(q)
		{
			scanf("%d %d", &x, &y);
			if(x==x_ref || y==y_ref) printf("divisa\n");
			else if(x>x_ref && y>y_ref) printf("NE\n");
			else if(x>x_ref && y<y_ref) printf("SE\n");
			else if(x<x_ref && y<y_ref) printf("SO\n");
			else printf("NO\n");
			q--;
		}
	}
	return (0);
}