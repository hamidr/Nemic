#include "GlobalDef.h"

#include "base.h"
#include "derived1.h"
#include "derived2.h"
#include "derived3.h"
#include "derived4.h"
#include "derived5.h"



#define NumberOfProcess 10

int main()
{
	pid_t pid = 1;
	pid_t process[NumberOfProcess] = {-1};

	int i=0;
	base *b = NULL;

	for(i=0; i < NumberOfProcess; i++ )
	{
		if ( pid <= 0 )
			return 0;

		pid = fork();

		if( pid > 0 ) {
			process[i]=pid;
			continue;
		}

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

		if ( pid <= 0 && b ) {
			//do the usual thing
			b->sleepWell(1);
			//release the allocated space
			RELEASE(b);
			//kill yourself my child!!
			return i;
		}
	}

	for(i=0; i<NumberOfProcess; i++)
		waitpid(process[i], NULL, 0);

	return 0;
}

