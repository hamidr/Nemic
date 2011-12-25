#include <unistd.h>
#include <cstdio>
#include <sys/wait.h>
#include "base.h"

#define RELEASE(x) if(x) delete x; x = NULL;

