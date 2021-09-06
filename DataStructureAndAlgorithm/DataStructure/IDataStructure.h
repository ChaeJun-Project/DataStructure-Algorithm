#pragma once

#include "stdafx.h"

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

protected:
	std::string dataStructure_title;
};