#pragma once
#include "btree.cpp"

TEMP
class BSTree : public BTree < T >
{
protected:
	Tree<T>* FindRightNext()const;
	Tree<T>* FindLeftNext()const;
	void deleteNode();//�Ͻ�����ʹ�ð�����������ɾ���ڵ��ָ��ſ����ð���
public:
	void insert(T const &x);
	BSTree(T const a[]=NULL,unsigned int n=0);
	virtual ~BSTree(){}
	Tree<T>* find(T const &x);
	void DelNode(T const &x);
};
