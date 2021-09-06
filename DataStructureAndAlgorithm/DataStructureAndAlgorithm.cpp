#include "stdafx.h"

int main()
{
	Stack_Base_LinkedList<int> stack("이중 연결 리스트기반 스택");

	for (int i = 0; i < 4; ++i)
		stack.PushData(i);

	stack.ReleaseDataStructure();

	_CrtDumpMemoryLeaks();
	return 0;
}
