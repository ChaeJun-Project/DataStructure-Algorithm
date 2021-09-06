#pragma once

#include "stdafx.h"

//Macro function
#define SAFE_RELEASE(p)         { if (p) { (p)->Release(); (p) = nullptr; } }
#define SAFE_DELETE(p)          { if (p) { delete (p); (p) = nullptr; } }
#define SAFE_DELETE_ARRAY(p)    { if (p) { delete[] (p); (p) = nullptr; } }

class IDataStructure
{
public:
	IDataStructure() = default;
	IDataStructure(std::string dataStructure_title)
		:dataStructure_title(dataStructure_title)
	{

	}

	virtual ~IDataStructure()
	{

	}

	virtual void ReleaseDataStructure() = 0;

protected:
	std::string dataStructure_title;
};