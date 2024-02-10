#pragma once
/*

*/
template <class T>
struct TNode {
	T val;
	TNode<T>* pNext;
};

template <class T>
class TList {
public:
	TList() {
		pFirst = nullptr;
		pLast = nullptr;
		pStop = nullptr;
		pCurrent = nullptr;
		pPrevious = nullptr;
		pos = -1;
		length = 0;
	}
	void deleteList() {
		TNode<T>* tmp = pFirst;
		while (pFirst != pStop)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
		length = 0; pos = -1; 
		pFirst = nullptr;
		pLast = nullptr;
		pStop = nullptr;
		pCurrent = nullptr;
		pPrevious = nullptr;
	}
	TList(const TList<T>& list) {
		TNode<T>* tmp = list.pFirst;
		while (tmp!=list.pStop) {
			insertLast(tmp->val);
			tmp = tmp->pNext;
		}
		length = list.length;
		pos = -1;
		pStop = nullptr;
		pCurrent = nullptr;
		pPrevious = nullptr;
	}
	~TList(){
		deleteList();
	}

	//insert first, insert last, insCurr (btw curr and previous)
	void insertFirst(T el) {
		TNode<T>* newEl = new TNode<T>;
		newEl->val = el;
		if (length != 0) {
			newEl->pNext = pFirst;
		}
		else {
			newEl->pNext = pStop;
			pPrevious = pStop;
			pLast = newEl;
			pCurrent = newEl;
		}
		pFirst = newEl;
		pos = 0;
		length++;
	}
	void insertCurrent(T el) {
		if (pCurrent == pFirst||length==0) {
			insertFirst(el);
		}
		else if(pCurrent==pLast){
			insertLast(el);
		}
		else {
			TNode<T>* newEl = new TNode<T>;
			newEl->pNext = pCurrent;
			newEl->val = el;
			pPrevious->pNext = newEl;
			pPrevious = newEl;
			length++; pos++;
		}
	}
	void insertLast(T el){
		if (length == 0) {
			insertFirst(el);
		}
		TNode<T>* newEl = new TNode<T>;
		newEl->val = el;
		newEl->pNext = pStop;
		pLast->pNext = newEl;
		length++;
	}

	//del first, del del current
	void deleteCurrent() {
		if (pCurrent == pStop) {
			throw - 1;
		}
		if (pCurrent != pFirst) {
			TNode<T>* tmpCurr = pCurrent;
			pCurrent = pCurrent->pNext;
			pPrevious->pNext = pCurrent;
			delete tmpCurr;
			length--;
		}
		else {
			deleteFirst();
		}
	}
	void deleteFirst() {
		if (length == 0) {
			throw - 1;
		}
		TNode<T>* tmpCurr = pFirst;
		pFirst = pFirst->pNext;
		delete tmpCurr;
		length--;
		pos--;
	}

	// getCurrentValue or ptr, set pos
	T getCurrent() {
		if (pCurrent == pStop || length == 0) { throw - 1; }
		return pCurrent -> value;
	}
	void setPosition(int position) {
		if (position >= length) {
			throw - 1;
		}
		reset(); 
		for (int i = 0; i < position; i++) {
			goNext();
		}
	}

	//3 methods for passthrough:
	//void reset(); (pcurrent to the beginning)
	//void goNext(); 
	//bool checkIsEnd(); (is all list looked through)
	//for(l.reset();!checkIsEnd(); l.GoNext()){}
	void reset() {
		pCurrent = pFirst;
		pPrevious = pStop;
		pos = 0;
	}
	void goNext() {
		if (pCurrent == pStop) {
			throw - 1;
		}
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
		pos++;
	}
	bool checkIsEnd() {
		return pCurrent == pStop;
	}

protected: //planning to 
	TNode<T>* pFirst; //compulsary
	TNode<T>* pLast; //for simplicity
	TNode<T>* pStop; //ptr of last element (usually nullptr)
	TNode<T>* pCurrent; //for 
	TNode<T>* pPrevious; //
	int pos, length;
};