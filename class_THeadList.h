#pragma once
#include"class TList.h"
//��������� ������ � ������� ����� (����� 0, ����� -1) - pHead
// �����������, ��������� (==,!=), *�� ���������, ��������, ���������, �������������, ���������� �������� �� 1 �����, ��������� ���������(���)
//����� ����������� ���������
//����� ��� ���������
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