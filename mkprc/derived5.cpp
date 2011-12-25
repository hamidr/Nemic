#include "GlobalDef.h"
#include "derived5.h"

derived5::derived5()
	: base(5)
{
}
derived5::~derived5()
{
}

void derived5::create()
{
	printf("%d\n", mVar);
}

