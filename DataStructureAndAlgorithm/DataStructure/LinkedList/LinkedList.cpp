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
	//����Ʈ ���� �����Ͱ� 0��
	if (linked_list.i_count == 0)
	{
		linked_list.p_head_node = CreateNode(data);
	}

	//����Ʈ ���� �����Ͱ� 1�� �̻�
	else
	{
		//����Ʈ�� ��ȸ�� ��� ������
		Node* p_iterator_node = linked_list.p_head_node;

		//���� ���� �Ѿ��
		while (p_iterator_node->p_next_node) //���� ������ ����� ��� = ���� ��尡 ���� ���
		{
			p_iterator_node = p_iterator_node->p_next_node;
		}

		//���� p_iterator_node�� ������ ����� �ּ� ���� ������ ����
		p_iterator_node->p_next_node = CreateNode(data);
	}

	++linked_list.i_count;
}

void InsertFrontNode(LinkedList & linked_list, const int & data)
{
	//����Ʈ ���� �����Ͱ� 0��
	if (linked_list.i_count == 0)
	{
		linked_list.p_head_node = CreateNode(data);
	}

	//����Ʈ ���� �����Ͱ� 1�� �̻�
	else
	{
		//���� ���Ե� ����� ���� ���
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
	//����Ʈ ���� �����Ͱ� 0��
	if (linked_list.i_count == 0)
	{
		return;
	}

	//����Ʈ ���� �����Ͱ� 1�� �̻�
	//������ ��带 ����Ű�� ������
	//������ ��带 ���� ���� ����Ű�� ����� ������
	//������ ����� ���� ��带 ����Ű�� ����� ������
	else
	{
		//����Ʈ�� ��ȸ�� ��� ������
		Node* p_iterator_node = linked_list.p_head_node;

		//������ ��带 ����Ű�� ������
		Node* p_delete_node = nullptr;
		//������ ��带 ���� ���� ����Ű�� ����� ������
		Node* p_pre_node = nullptr;

		//������ ����� ���� ��带 ����Ű�� ����� ������
		Node* p_next_node = nullptr;

		//���� ���� �Ѿ��
		while (p_iterator_node)
		{
			if (p_iterator_node->i_data == find_data)
			{
				p_delete_node = p_iterator_node;
				p_next_node = p_delete_node->p_next_node;
				break;
			}

			//���� ��� ����
			p_pre_node = p_iterator_node;
			//���� ���� ��ȸ
			p_iterator_node = p_iterator_node->p_next_node;
		}

		//������ ��带 ã�Ҵٸ�
		if (p_delete_node)
		{
			p_pre_node->p_next_node = p_next_node;

			DeleteNode(p_delete_node);

			--linked_list.i_count;
		}

		else
		{
			std::cout << "�ش� �����͸� ������ ���� �����ϴ�." << std::endl;
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
