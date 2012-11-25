#include <stdio.h>
#include <stdlib.h>

#define BIT_NUMBERS(x) sizeof(x) * 8 

void getBits(int n)
{
	int i = 1;
	_Bool bit = 0;
	char c = 1;
	do {
		bit = n & i;
		printf("%d = %d\n", i,  bit);
		i <<= 1;
	} while ( ++c < BIT_NUMBERS(n) ) ;

}

void debugBits(int n)
{
	int i = 1;
	_Bool bit = 0;
	char c = 1;
	do {
		bit = n & 1;
		n >>= 1;
		printf("%d = %d\n", i,  bit);
		i <<= 1;
	} while ( ++c < BIT_NUMBERS(n) ) ;
}

int main()
{

	int input = 0;
	scanf("%d", &input);

	debugBits(input);

	return 0;
	int n = 1;
	char i = 0;
	printf("sizeof signed int = \"%ld\"\n", sizeof(n) );

	_Bool val = 0;

	do	{
		printf(" %d = %d \n", i, n );
		n <<= 1 ;
		++i;

		val = n & i;
		if ( val )
			printf("true");


	} while ( i <=32 ) ;


	return 0;
}
