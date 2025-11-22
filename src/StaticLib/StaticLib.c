#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	if (!l || !p) return;

	p->pPrev = NULL;
	p->pNext = l->header;
	if (l->header)
	{
		l->header->pPrev = p;
	}
	else
	{
		l->footer = p;
	}
	l->header = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (!l || !p) return;

	if (l->footer)
	{
		p->pPrev = l->footer;
		l->footer->pNext = p;
	}
	else
	{
		p->pPrev = NULL;
		l->header = p;
	}
	p->pNext = NULL;
	l->footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (!l || !p) return;
	if (p->pPrev)
	{
		p->pPrev->pNext = p->pNext;
	}
	else
	{
		l->header = p->pNext;
	}

	if (p->pNext)
	{
		p->pNext->pPrev = p->pPrev;
	}
	else
	{
		l->footer = p->pPrev;
	}
	
	p->pNext = NULL;
	p->pPrev = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (!l || !p || !p->pNext) return;
	node* target = p->pNext;

	p->pNext = target->pNext;

	if (target->pNext)
	{
		target->pNext->pPrev = p;
	}
	else
	{
		l->footer = p;
	}

	target->pNext = NULL;
	target->pPrev = NULL;
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (!l || !p || !p->pPrev) return;
	node* target = p->pPrev;

	if (target->pPrev)
	{
		target->pPrev->pNext = p;
	}
	else
	{
		l->header = p;
	}

	p->pPrev = target->pPrev;

	target->pNext = NULL;
	target->pPrev = NULL;
}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
