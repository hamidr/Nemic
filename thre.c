#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


struct state
{
	int ms;
	int arg;
};


void *echo(void *arg)
{
	(*((int*) arg))++;
	char i=0;

	for( i=0;i<20;i++)
		printf("%d ",(*((int*) arg)));

	putchar('\n');
	return 0;
}

int main()
{
	int a = 0;;
	pthread_t t;
	char i;

	for(i = 0; i < 32;i++)
		pthread_create(&t,NULL,echo, (void*)&a);

	pthread_join(t,NULL);

	
	return 0;
}
