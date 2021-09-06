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
			std::cout << "���� ���ÿ� ����� �����ʹ� �����ϴ�." << std::endl;

		else
		{
			for (int i = 0; i < i_size; ++i)
			{
				if (i != (i_size - 1))
					std::cout << data_stack[i] << ", ";

				else
					std::cout << data_stack[i] << std::endl;
			}

			std::cout << "���� ���ÿ��� �� " << i_size << "���� �����Ͱ� �����մϴ�." << std::endl;
		}
	}

	void ReleaseDataStructure()
	{
		if (i_size && data_stack)
		{
			//���� �迭 �޸� ����
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
	//���� ���
	if (!i_size || !data_stack)
		//�ִ� �����ŭ �޸� �Ҵ�
		data_stack = new T[max_size];

	//���� ���� ����� ������ �ִ� ������� ���� ���
	//���� �ִ� �������� 2�踸ŭ ���� �迭 ���Ҵ� �� ���� ������ ����
	if (i_size == max_size)
	{
		//�ִ� ������ 2��
		max_size *= 2;

		//������ �����͸� �ӽ� ������ �迭
		//�ִ� �����ŭ �޸� �Ҵ�
		T* temp_data_stack = new T[max_size];

		//���� ������ ����
		std::copy(data_stack, data_stack + i_size, temp_data_stack);

		//���� �迭 �޸� ����
		SAFE_DELETE_ARRAY(data_stack);

		//���� �Ҵ��� �迭�� ���� �ּҸ� ����
		data_stack = temp_data_stack;
	}

	//���� ������ +1
	++i_size;

	//������ �߰�
	data_stack[i_size - 1] = data;

	//���� ��� ���
	ShowStack();
}

template<typename T>
inline T Stack_Base_Array<T>::PopData()
{
	//�����Ͱ� ���� ���
	if (!i_size || !data_stack)
	{
		//���� ��� ���
		ShowStack();

		return NULL;
	}

	//�����Ͱ� �ִ� ���
	else
	{
		//������ ����
		data_stack[i_size - 1] = 0;

		--i_size;
	}

	//���� ��� ���
	ShowStack();
}
