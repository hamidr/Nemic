#include <unistd.h>
#include <cstdio>
#include <sys/wait.h>
#include "base.h"

template <typename T>
void release(T *x)
{
	if(x)
		delete x;

	x = NULL;
}


