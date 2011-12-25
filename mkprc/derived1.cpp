#include "GlobalDef.h"
#include "derived1.h"

derived1::derived1()
	: base(1)
{
}
derived1::~derived1()
{
}

void derived1::create()
{
	printf("%d\n", mVar);
}

