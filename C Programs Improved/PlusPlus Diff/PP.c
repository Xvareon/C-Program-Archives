#include <stdio.h>

int main()
{
	int i, x,y,z;
	x=2;
	i=x++;
	y=2;
	z=++y;
	printf("%d %d", x, i);
	printf("\n");
	printf("%d %d", y ,z);
	return 0;
}
