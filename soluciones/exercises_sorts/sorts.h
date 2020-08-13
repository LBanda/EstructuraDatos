/*
 * sorts.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef SORTS_H_
#define SORTS_H_

#include "exception.h"
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> bubbleSort(const std::vector<T>&);
	std::vector<T> selectionSort(const std::vector<T>&);
	std::vector<T> insertionSort(const std::vector<T>&);
	std::vector<T> shellSort(const std::vector<T>&);
	std::vector<T> mergeSort(const std::vector<T>&);

	std::vector<T> bucketSort(const std::vector<T>&);
	std::list<T>   mergeList(const std::list<T>&, const std::list<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::bubbleSort(const std::vector<T> &source) {
	std::vector<T> v(source);

	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::selectionSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	int pos;

	for (int i = v.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (v[j] > v[pos]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(v, i, pos);
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::insertionSort(const std::vector<T> &source) {
	std::vector<T> v(source);

	for (int i = 1; i < v.size(); i++) {
		for (int j = i; j > 0 && v[j] < v[j - 1]; j--) {
			swap(v, j, j - 1);
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::shellSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	int gap = v.size() / 2;

	while (gap > 0) {
		for (int i = gap; i < v.size(); i++) {
			for (int j = i; j >= gap && v[j] < v[j - gap]; j -= gap) {
				swap(v, j, j - gap);
			}
		}
		gap /= 2;
	}
	return v;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
std::vector<T> Sorts<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1);
	return v;
}

template <class T>
std::vector<T> Sorts<T>::bucketSort(const std::vector<T> &source) {
    /*
	* Esta solucion es mas general ya que calcula 'max'
    * index = source[i]*source.size()/max;
    */

	std::list<T> arrList[source.size()];
	std::vector<T> v(source.size());
	int index, max = -99999;

	//obtener max
    for(int i = 0; i < source.size(); i++){
        if(max < source[i])
            max = source[i]+1;
    }

	//nuevos indices
    for (int i=0; i < source.size(); i++){
        index = source[i]*(source.size())/max;
        arrList[index].push_back(source[i]);
    }

	//sort a cada subconjunto
    for(int i =0; i < source.size(); i++){
        arrList[i].sort();
    }
    int k = 0;

	//vaciamos los subconjuntos en un solo arreglo
    for(int i = 0; i < source.size(); i++){
        while(!arrList[i].empty()){
            v[k] = arrList[i].front();
            arrList[i].pop_front();
            k++;
        }
    }

	return v;
}

template <class T>
std::list<T> Sorts<T>::mergeList(const std::list<T> &lst1, const std::list<T> &lst2) {
	typename std::list<T>::const_iterator itr1, itr2;
	std::list<T> result;

	itr1 = lst1.begin();
	itr2 = lst2.begin();
	while (itr1 != lst1.end() && itr2 != lst2.end()) {
		if (*itr1 < *itr2) {
			result.push_back(*itr1);
			itr1++;
		} else {
			result.push_back(*itr2);
			itr2++;
		}
	}
	if (itr1 == lst1.end()) {
		for (; itr2 != lst2.end(); itr2++) {
			result.push_back(*itr2);
		}
	} else if (itr2 == lst2.end()) {
		for (; itr1 != lst1.end(); itr1++) {
			result.push_back(*itr1);
		}
	}
	return result;
}

#endif /* SORTS_H_ */
