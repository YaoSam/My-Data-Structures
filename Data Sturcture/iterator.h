#pragma once
#include "btree.cpp"

template <class T>
class tree_iterator//抽象基类
{
protected:
	Tree<T>* Pcurrent;
	Tree<T>* root;
	friend class Tree < T > ;
	friend class PreOrder_iterator < T > ;
	friend class InOrder_iterator < T > ;
public:
	tree_iterator(Tree<T>* r, Tree<T>* p = NULL) :
		root(r),
		Pcurrent(p ? p : r)
	{}
	tree_iterator(const tree_iterator & other) :
		Pcurrent(other.Pcurrent),
		root(other.root)
	{}
	~tree_iterator(){}
	virtual T operator*()const;
	virtual Tree<T>* operator()()const;
	virtual void gotoFirst()
	{
		Pcurrent = root;
	}
	virtual bool isEnd(){ return Pcurrent == NULL; }
	virtual tree_iterator<T>& operator++() = 0;
};
TEMP
class PreOrder_iterator :public tree_iterator < T >
{
	stack<Tree<T>*> Stack;
public:
	PreOrder_iterator(Tree<T> *Pone) :tree_iterator<T>(Pone){}
	PreOrder_iterator(const tree_iterator<T>& other) :
		tree_iterator<T>(other.root, other.Pcurrent),
		Stack(other.Stack)
	{}
	virtual tree_iterator<T>&  operator++();
};

TEMP
class InOrder_iterator :public tree_iterator < T >
{
	stack<Tree<T>*> Stack;
public:
	InOrder_iterator(Tree<T>* P);//在最左边开始。
	InOrder_iterator(const tree_iterator< T >& other) :
		tree_iterator<T>(other.root, other.Pcurrent),
		Stack(other.Stack){}
	virtual T operator*()const;
	virtual Tree<T>* operator()()const;
	virtual void gotoFirst();
	virtual bool isEnd(){ return Stack.isEmpty(); }
	virtual tree_iterator<T>&operator++();
};