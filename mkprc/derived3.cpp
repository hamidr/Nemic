#include "GlobalDef.h"
#include "derived3.h"

derived3::derived3()
	: base(3)
{
}
derived3::~derived3()
{
}

void derived3::create()
{
	printf("%d\n", mVar);
}

