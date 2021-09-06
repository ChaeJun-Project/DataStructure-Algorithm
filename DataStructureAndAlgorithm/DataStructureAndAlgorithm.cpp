#include "stdafx.h"

int main()
{
	LinkedList list;

	InitList(list);

	for (int i = 0; i < 10; ++i)
		InsertFrontNode(list, 10 + i);

	ReleaseList(list);

	return 0;
}
