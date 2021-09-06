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
			std::cout << "현재 스택에 저장된 데이터는 없습니다." << std::endl;

		else
		{
		    Node* temp = p_head_node;

			while (true)
			{
				//가장 마지막에 추가된 요소
				if(!temp->p_next_node)
				{ 
					std::cout << temp->data << std::endl;
					break;
				}

				std::cout << temp->data << ", ";
				temp = temp->p_next_node;
			}

			std::cout << "현재 스택에는 총 " << i_size << "개의 데이터가 존재합니다." << std::endl;
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

				//가장 마지막에 추가된 노드일 경우
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
	//가장 첫 번째에 연결되어 있는 노드를 가리키는 포인터
	Node* p_head_node = nullptr;

    //가장 마지막에 연결되어 있는 노드를 가리키는 포인터
	Node* p_tail_node = nullptr;

	int i_size = 0;
};

template<typename T>
inline void Stack_Base_LinkedList<T>::PushData(const T & data)
{
	//최초 등록
	if (!i_size || !p_head_node || !p_tail_node)
	{
		p_head_node = new Node;
		p_tail_node = p_head_node;
		p_tail_node->p_pre_node = nullptr;
	}

	//데이터가 1개 이상 존재할 때
	else
	{
		//가장 마지막에 연결된 노드의 주소를 
		//이전에 가장 마지막으로 연결된 노드 포인터에 저장
		Node* p_tail_pre_node = p_tail_node;

		//가장 마지막에 새로운 노드 생성
		p_tail_node = new Node;
		//새로운 노드 생성의 이전에 연결된 노드의 주소를 저장
		p_tail_node->p_pre_node = p_tail_pre_node;

		//p_pre_node가 가리키는 노드의 p_next_node에 새로 생성한 노드의 주소를 저장
		p_tail_pre_node->p_next_node = p_tail_node;
	}

	//새로 생성한 노드에 데이터 값 저장
	p_tail_node->data = data;
	p_tail_node->p_next_node = nullptr;

	++i_size;

	//스택 요소 출력
	ShowStack();
}

template<typename T>
inline T Stack_Base_LinkedList<T>::PopData()
{
	//데이터가 없는 경우
	if (!i_size || !p_head_node || !p_tail_node)
	{
		//스택 요소 출력
		ShowStack();

		return NULL;
	}

	//데이터가 있는 경우
	else
	{
		Node* p_tail_pre_node = p_tail_node->p_pre_node;

		delete p_tail_node;

		p_tail_node = p_tail_pre_node;

		p_tail_node->p_next_node = nullptr;

		--i_size;
	}

	//스택 요소 출력
	ShowStack();
}
