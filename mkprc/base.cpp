#include "base.h"
#include "GlobalDef.h"

base::base(const int var)
	: mVar(var)
{
}

base::~base()
{
}

void base::sleepWell(const int i)
{
	sleep(i);
	printf("pid: %ld, ppid: %ld.\n",(long)getpid(), (long)getppid());
	create();
}
