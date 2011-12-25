#include "GlobalDef.h"
#include "derived4.h"

derived4::derived4()
	: base(4)
{
}
derived4::~derived4()
{
}

void derived4::create()
{
	printf("%d\n", mVar);
}

