#pragma once

typedef struct Node
{
    int i_data;
	Node* p_next_node;
};

typedef struct LinkedList
{
	Node* p_head_node; //첫 번째 노드의 주소
	int i_count;
};

//연결형 리스트의 노드를 생성
Node* CreateNode(const int& data);

//연결형 리스트의 노드 삭제
void DeleteNode(Node* node);

//연결형 리스트 초기화
void InitList(LinkedList& linked_list);

//연결형 리스트의 맨뒤에서 부터 데이터 추가
void InsertBackNode(LinkedList& linked_list, const int& data);

//연결형 리스트의 맨앞에서 부터 데이터 추가
void InsertFrontNode(LinkedList& linked_list, const int& data);

//특정 데이터를 가지고 있는 노드를 삭제
void ReleaseNode(LinkedList& linked_list, const int& find_data);

//연결형 리스트 내의 모든 노드 삭제
void ReleaseList(LinkedList& linked_list);