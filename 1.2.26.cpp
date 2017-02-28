#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for (int i = 1; i <= 1000; i++)
    {
    	int n = i;
    	int k = 0;
    	while (n != 0)
		{
        	k++;
       		n /= 10;
		}
		int square = pow(i, 2);
		int zeroes = pow(10, k);
		if (square % zeroes  == i)
		printf("%d ^ 2 = %d\n", i, square);
    }
    return 0;
}