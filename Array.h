
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;
template <class T>

class Array {

	template <class V>
	friend ostream& operator<<(ostream&, Array<T>&);
	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T&);
		Array& operator+=(T&);
		Array& operator-=(T&);
		T& operator[](int) const;
		T& get(int index) const;
		T& get(int index);
		T* getElements() const;
		int getSize() const;
		bool isFull();
		void clear();
	
	private:
		int size;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	
}

template <class T>
void Array<T>::add(T& t){
	if (size >= MAX_ARRAY)   return;
  	elements[size++] = t;
}

template <class T>
Array<T>& Array<T>::operator+=(T& s){
	add(s);
	return *this;
}

template <class T>
T& Array<T>::operator[](int index) const{
	return get(index);
}

template <class T>
Array<T>& Array<T>::operator-=(T& s){
	for(int i=0; i < size; ++i){
		if(elements[i] == s){
			//remove s
			for(int j =i; j<size; ++j){
				elements[j] = elements[j+1];
			}
			--size;
			break;
		}
	}
	return *this;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull(){
	return size >= MAX_ARRAY;
}

template <class T>
T& Array<T>::get(int index) const{
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}


template <class T>
T& Array<T>::get(int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
T* Array<T>::getElements() const{
	return elements;
}



template <class T>
void Array<T>::clear(){
	delete elements;
	size =0;
}

template <class T>
ostream& operator<<(ostream& output, const Array<T>& c)
{
  
  for(int i=0; i<c.getSize(); ++i){
	output<<c.getElements()[i]<<endl;
  }

  return output;
}


#endif