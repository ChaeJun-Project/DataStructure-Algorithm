#pragma once

typedef struct Node
{
    int i_data;
	Node* p_next_node;
};

typedef struct LinkedList
{
	Node* p_head_node; //ù ��° ����� �ּ�
	int i_count;
};

//������ ����Ʈ�� ��带 ����
Node* CreateNode(const int& data);

//������ ����Ʈ�� ��� ����
void DeleteNode(Node* node);

//������ ����Ʈ �ʱ�ȭ
void InitList(LinkedList& linked_list);

//������ ����Ʈ�� �ǵڿ��� ���� ������ �߰�
void InsertBackNode(LinkedList& linked_list, const int& data);

//������ ����Ʈ�� �Ǿտ��� ���� ������ �߰�
void InsertFrontNode(LinkedList& linked_list, const int& data);

//Ư�� �����͸� ������ �ִ� ��带 ����
void ReleaseNode(LinkedList& linked_list, const int& find_data);

//������ ����Ʈ ���� ��� ��� ����
void ReleaseList(LinkedList& linked_list);