#pragma once

#include "DataStructure/IDataStructure.h"

template<typename T>
class Stack_Base_Array : public IDataStructure
{
public:
	Stack_Base_Array(std::string dataStructure_title)
		: IDataStructure(dataStructure_title)
	{

	}

	~Stack_Base_Array()
	{
	   
	}

	void PushData(const T& data);

	T PopData();

	void ShowStack()
	{
		if (!i_size)
			std::cout << "현재 스택에 저장된 데이터는 없습니다." << std::endl;

		else
		{
			for (int i = 0; i < i_size; ++i)
			{
				if (i != (i_size - 1))
					std::cout << data_stack[i] << ", ";

				else
					std::cout << data_stack[i] << std::endl;
			}

			std::cout << "현재 스택에는 총 " << i_size << "개의 데이터가 존재합니다." << std::endl;
		}
	}

	void ReleaseDataStructure()
	{
		if (i_size && data_stack)
		{
			//기존 배열 메모리 해제
			SAFE_DELETE_ARRAY(data_stack);

			max_size = 10;

			i_size = 0;
		}

		ShowStack();
	}

	const unsigned int GetSize() { return i_size; }

private:
	T* data_stack = nullptr;

	int max_size = 10;

	int i_size = 0;
};

template<typename T>
inline void Stack_Base_Array<T>::PushData(const T & data)
{
	//최초 등록
	if (!i_size || !data_stack)
		//최대 사이즈만큼 메모리 할당
		data_stack = new T[max_size];

	//현재 스택 사이즈가 설정한 최대 사이즈와 같은 경우
	//현재 최대 사이즈의 2배만큼 스택 배열 재할당 후 기존 데이터 복사
	if (i_size == max_size)
	{
		//최대 사이즈 2배
		max_size *= 2;

		//기존의 데이터를 임시 저장할 배열
		//최대 사이즈만큼 메모리 할당
		T* temp_data_stack = new T[max_size];

		//기존 데이터 복사
		std::copy(data_stack, data_stack + i_size, temp_data_stack);

		//기존 배열 메모리 해제
		SAFE_DELETE_ARRAY(data_stack);

		//새로 할당한 배열의 시작 주소를 저장
		data_stack = temp_data_stack;
	}

	//스택 사이즈 +1
	++i_size;

	//데이터 추가
	data_stack[i_size - 1] = data;

	//스택 요소 출력
	ShowStack();
}

template<typename T>
inline T Stack_Base_Array<T>::PopData()
{
	//데이터가 없는 경우
	if (!i_size || !data_stack)
	{
		//스택 요소 출력
		ShowStack();

		return NULL;
	}

	//데이터가 있는 경우
	else
	{
		//데이터 삭제
		data_stack[i_size - 1] = 0;

		--i_size;
	}

	//스택 요소 출력
	ShowStack();
}
