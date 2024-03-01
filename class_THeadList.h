#pragma once
#include"class TList.h"
//кольцевой список с нулевым полем (коэфф 0, номер -1) - pHead
// копирование, сравнение (==,!=), *на константу, сложение, вычитание, приравнивание, домножение полинома на 1 моном, умножение полиномов(доп)
//можно графический интерфейс
//тесты для полиномов
template<class T>
class THeadList : public TList<T> {
public:
	THeadList() {
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pStop = pFirst = pLast = pCurrent = pPrevious = pHead;
		length = 0; pos = -1;
	}
	THeadList(const THeadList& hlist){
			pHead = new TNode<T>;
			pHead->pNext = pHead;
			pStop = pFirst = pLast = pCurrent = pPrevious = pHead;
			length = 0; pos = -1;
		if (hlist.length != 0) {
			TNode<T>* tmp = hlist.pFirst;
			while (tmp != hlist.pStop) {
				insertLast(tmp->val);
				tmp = tmp->pNext;
			}
		}
	}
	~THeadList() {
		TList<T>::deleteList();
		delete pHead;
	}
	void insertFirst(T el) {
		TList<T>::insertFirst(el);
		pHead->pNext = pFirst;
	}
	void deleteFirst() {
		TList<T>::deleteFirst();
		pHead->pNext = pFirst;
	}
protected:
	TNode<T>* pHead;
};