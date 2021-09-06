#include "stdafx.h"
#include "LinkedList.h"

Node * CreateNode(const int & data)
{
	Node* p_new_node = new Node;

	p_new_node->i_data = data;
	p_new_node->p_next_node = nullptr;

	return p_new_node;
}

void DeleteNode(Node* node)
{
	delete node;
	node = nullptr;
}

void InitList(LinkedList & linked_list)
{
	linked_list.p_head_node = nullptr;
	linked_list.i_count = 0;
}

void InsertBackNode(LinkedList& linked_list, const int& data)
{
	//리스트 내에 데이터가 0개
	if (linked_list.i_count == 0)
	{
		linked_list.p_head_node = CreateNode(data);
	}

	//리스트 내에 데이터가 1개 이상
	else
	{
		//리스트를 순회할 노드 포인터
		Node* p_iterator_node = linked_list.p_head_node;

		//다음 노드로 넘어가기
		while (p_iterator_node->p_next_node) //가장 마지막 노드인 경우 = 다음 노드가 없는 경우
		{
			p_iterator_node = p_iterator_node->p_next_node;
		}

		//현재 p_iterator_node는 마지막 노드의 주소 값을 가지고 있음
		p_iterator_node->p_next_node = CreateNode(data);
	}

	++linked_list.i_count;
}

void InsertFrontNode(LinkedList & linked_list, const int & data)
{
	//리스트 내에 데이터가 0개
	if (linked_list.i_count == 0)
	{
		linked_list.p_head_node = CreateNode(data);
	}

	//리스트 내에 데이터가 1개 이상
	else
	{
		//새로 삽입될 노드의 다음 노드
		Node* p_next_node = linked_list.p_head_node;

		linked_list.p_head_node = CreateNode(data);
	
	    auto new_node = linked_list.p_head_node;
		new_node->p_next_node = p_next_node;
		new_node->i_data = data;
	}

	++linked_list.i_count;
}

void ReleaseNode(LinkedList& linked_list, const int& find_data)
{
	//리스트 내에 데이터가 0개
	if (linked_list.i_count == 0)
	{
		return;
	}

	//리스트 내에 데이터가 1개 이상
	//삭제할 노드를 가리키는 포인터
	//삭제할 노드를 다음 노드로 가리키는 노드의 포인터
	//삭제할 노드의 다음 노드를 가리키는 노드의 포인터
	else
	{
		//리스트를 순회할 노드 포인터
		Node* p_iterator_node = linked_list.p_head_node;

		//삭제할 노드를 가리키는 포인터
		Node* p_delete_node = nullptr;
		//삭제할 노드를 다음 노드로 가리키는 노드의 포인터
		Node* p_pre_node = nullptr;

		//삭제할 노드의 다음 노드를 가리키는 노드의 포인터
		Node* p_next_node = nullptr;

		//다음 노드로 넘어가기
		while (p_iterator_node)
		{
			if (p_iterator_node->i_data == find_data)
			{
				p_delete_node = p_iterator_node;
				p_next_node = p_delete_node->p_next_node;
				break;
			}

			//이전 노드 저장
			p_pre_node = p_iterator_node;
			//다음 노드로 순회
			p_iterator_node = p_iterator_node->p_next_node;
		}

		//삭제할 노드를 찾았다면
		if (p_delete_node)
		{
			p_pre_node->p_next_node = p_next_node;

			DeleteNode(p_delete_node);

			--linked_list.i_count;
		}

		else
		{
			std::cout << "해당 데이터를 저장한 노드는 없습니다." << std::endl;
		}
	}
}


void ReleaseList(LinkedList& linked_list)
{
	Node* p_iterator_node = linked_list.p_head_node;

	for (int i = 0; i < linked_list.i_count; ++i)
	{
		Node* p_delete_node = p_iterator_node;

		p_iterator_node = p_iterator_node->p_next_node;

		DeleteNode(p_delete_node);
	}

	InitList(linked_list);
}
