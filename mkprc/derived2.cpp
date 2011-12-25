#include "GlobalDef.h"
#include "derived2.h"

derived2::derived2()
	: base(2)
{
}
derived2::~derived2()
{
}

void derived2::create()
{
	printf("%d\n", mVar);
}

