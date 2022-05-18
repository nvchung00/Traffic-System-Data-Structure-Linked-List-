/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}

	~L1List() {
		clean();
	}

	void    clean() {
		while (_pHead)
		{
			L1Item<T>* p = _pHead;
			_pHead = _pHead->pNext;
			delete p;		
		}
		_pHead = NULL;
	}

    bool    isEmpty() {
        return _pHead == NULL;
    }

    size_t  getSize() {
        return _size;
    }
	T& at(int i) {
		if ( i >= _size || i < 0 ) return NULL;
		L1Item<T>* p = _pHead;
		while (i) {
			p = p->pNext;
			i--;
		}
		return p->data;
		
	}

	T& operator[](int i) {
		if ( i >= _size ||  i < 0) throw DSAException(-2, "Out of range");
		L1Item<T>* p = _pHead;
		while (i) {
			p = p->pNext;
			i--;
		}
		return p->data;
	}
	bool    find(T& a, int& idx) {
		L1Item<T>* p = _pHead;
		idx = 0;
		while (p) {
			if (p->data == a) {
				return true;
			}
			p = p->pNext;
			idx++;
		}
		return false;
	}
	int     insert(int i, T& a) {
		if (i == 0) return insertHead(a);
			L1Item<T>* pPre = _pHead;
			L1Item<T>* pCur = pPre->pNext;
			while (i>1) {
				pPre = pCur;
				pCur = pCur->pNext;
				i--;
			}
			L1Item<T>* pNew = new L1Item<T>(a);
			pPre->pNext = pNew;
			pNew->pNext = pCur;
			_size++;
			return 0;
	}
	int     remove(int i) {
		if (i == 0) return removeHead();
		L1Item<T>* pPre = _pHead;
		L1Item<T>* pCur = pPre->pNext;
		while (i > 1) {
			pPre = pCur;
			pCur = pCur->pNext;
			i--;	
		}
		pPre->pNext = pCur->pNext;
		delete pCur;
		pCur = NULL;
		_size--;
		return 0;
	}

    int     push_back(T& a);
    int     insertHead(T& a);

    int     removeHead();
    int     removeLast();

	void    reverse() {
		L1Item<T>* pPre = NULL;
		L1Item<T>* pCur = _pHead;
		L1Item<T>* pNex = NULL;
		while (pCur) {
			pNex = pCur->pNext;
			pCur->pNext = pPre;
			pPre = pCur;
			pCur = pNex;
		}
		_pHead = pPre;
	}

    void    traverse(void (*op)(T&)) {
		L1Item<T>*p = _pHead;
		while (p) {
			op(p->data);
			p = p->pNext;
		}
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
		L1Item<T>*p = _pHead;
		while (p) {
			op(p->data, pParam);
			p = p->pNext;
		}
    }
};

template <class T>
int L1List<T>::push_back(T &a) {
	if (_pHead == NULL) {
		L1Item<T>* p = new L1Item<T>(a);
		_pHead = p;
	}
	else {
		L1Item<T>* p = _pHead;
		while (p->pNext) p = p->pNext;
		p->pNext = new L1Item<T>(a);
		p = p->pNext;
		p->pNext = NULL;
	}
	_size++;
	return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
	L1Item<T>* p = new L1Item<T>(a);
	p->pNext = _pHead;
	_pHead=p;
    _size++;
    return 0;
}
template <class T>
int L1List<T>::removeHead() {
	if (_pHead == NULL) return -1;
	else{
		L1Item<T>* p = _pHead;
		_pHead = p->pNext;
		delete p;
		_size--;
		return 0;
	}
}
template <class T>
int L1List<T>::removeLast() {
	if (_pHead == NULL) return -1;
	else {
		L1Item<T>* pPre = _pHead;
		L1Item<T>* pCur = pPre->pNext;
		while (pCur->pNext) {
			pPre = pCur;
			pCur = pCur->pNext;
		}
		delete pCur;
		pPre->pNext = NULL;
		_size --;
		return 0;
	}
}


#endif //DSA191_A1_DSALIB_H
