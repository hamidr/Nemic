#include "GlobalDef.h"

#include "derived1.h"
#include "derived2.h"
#include "derived3.h"
#include "derived4.h"
#include "derived5.h"

#define NumberOfProcess 5

int main()
{
	pid_t pid;
	pid_t process[NumberOfProcess] = {0};

	int i;
	base *b = NULL;

	for(i=0; i < NumberOfProcess; ++i )
	{
		pid = fork();

		if ( pid != 0 )
			continue;

		process[i] = pid;

		switch(i)
		{
		case 0:
			b = new derived1;
			break;

		case 1:
			b = new derived2;
			break;

		case 2:
			b = new derived3;
			break;

		case 3:
			b = new derived4;
			break;

		case 4:
			b = new derived5;
			break;
		}

		//each process do its own job
		b->sleepWell(1);
		
		//release the allocated space
		release(b);
		
		// and end the process
		return i;
	}

	for(i=0; i < NumberOfProcess; ++i)
		waitpid(process[i], NULL, 0);

	return 0;
}

