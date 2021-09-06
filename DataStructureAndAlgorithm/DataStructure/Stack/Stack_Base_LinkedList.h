#pragma once

#include "DataStructure/IDataStructure.h"

template<typename T>
class Stack_Base_LinkedList : public IDataStructure
{
private:
	struct Node
	{
		T data;
		Node* p_pre_node;
		Node* p_next_node;
	};

public:
	Stack_Base_LinkedList(std::string dataStructure_title)
		: IDataStructure(dataStructure_title)
	{

	}

	~Stack_Base_LinkedList()
	{

	}

	void PushData(const T& data);

	T PopData();

	void ShowStack()
	{
		if (!i_size || !p_head_node || !p_tail_node)
			std::cout << "���� ���ÿ� ����� �����ʹ� �����ϴ�." << std::endl;

		else
		{
		    Node* temp = p_head_node;

			while (true)
			{
				//���� �������� �߰��� ���
				if(!temp->p_next_node)
				{ 
					std::cout << temp->data << std::endl;
					break;
				}

				std::cout << temp->data << ", ";
				temp = temp->p_next_node;
			}

			std::cout << "���� ���ÿ��� �� " << i_size << "���� �����Ͱ� �����մϴ�." << std::endl;
		}
	}

	void ReleaseDataStructure()
	{
		if (i_size && p_head_node && p_tail_node)
		{
			Node* temp = nullptr;

			while (true)
			{
				temp = p_head_node;

				p_head_node = p_head_node->p_next_node;

				delete temp;

				//���� �������� �߰��� ����� ���
				//p_next_node == nullptr
				if (!p_head_node)
				{
					break;
				}
			}

		    p_head_node = nullptr;

			p_tail_node = nullptr;

			i_size = 0;
		}

		ShowStack();
	}

	const unsigned int GetSize() { return i_size; }

private:
	//���� ù ��°�� ����Ǿ� �ִ� ��带 ����Ű�� ������
	Node* p_head_node = nullptr;

    //���� �������� ����Ǿ� �ִ� ��带 ����Ű�� ������
	Node* p_tail_node = nullptr;

	int i_size = 0;
};

template<typename T>
inline void Stack_Base_LinkedList<T>::PushData(const T & data)
{
	//���� ���
	if (!i_size || !p_head_node || !p_tail_node)
	{
		p_head_node = new Node;
		p_tail_node = p_head_node;
		p_tail_node->p_pre_node = nullptr;
	}

	//�����Ͱ� 1�� �̻� ������ ��
	else
	{
		//���� �������� ����� ����� �ּҸ� 
		//������ ���� ���������� ����� ��� �����Ϳ� ����
		Node* p_tail_pre_node = p_tail_node;

		//���� �������� ���ο� ��� ����
		p_tail_node = new Node;
		//���ο� ��� ������ ������ ����� ����� �ּҸ� ����
		p_tail_node->p_pre_node = p_tail_pre_node;

		//p_pre_node�� ����Ű�� ����� p_next_node�� ���� ������ ����� �ּҸ� ����
		p_tail_pre_node->p_next_node = p_tail_node;
	}

	//���� ������ ��忡 ������ �� ����
	p_tail_node->data = data;
	p_tail_node->p_next_node = nullptr;

	++i_size;

	//���� ��� ���
	ShowStack();
}

template<typename T>
inline T Stack_Base_LinkedList<T>::PopData()
{
	//�����Ͱ� ���� ���
	if (!i_size || !p_head_node || !p_tail_node)
	{
		//���� ��� ���
		ShowStack();

		return NULL;
	}

	//�����Ͱ� �ִ� ���
	else
	{
		Node* p_tail_pre_node = p_tail_node->p_pre_node;

		delete p_tail_node;

		p_tail_node = p_tail_pre_node;

		p_tail_node->p_next_node = nullptr;

		--i_size;
	}

	//���� ��� ���
	ShowStack();
}
