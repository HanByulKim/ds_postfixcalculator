#pragma once
#include <stdio.h>
template <typename T>
class queue{
public:
	queue(){
		data = new T[5];
		arrsize = 5;
	}
	~queue(){
		delete[] data;
	}

	void array_doubling(){
		T* newdata = new T[arrsize * 2];
		for (int i = 0; i < arrsize; i++)
			newdata[i] = data[i];
		delete[] data;
		data = newdata;
		arrsize *= 2;
	}
	void push(T n){
		if (tail >= arrsize - 1)
			array_doubling();
		data[++tail] = n;
		size++;
	}
	//T top(){ return data[tail]; }
	//T pop(){ size--; return data[tail--]; }
	void print(){
		for (int i = 0; i < size; i++)
			printf("%c ", data[i]);
			//std::cout << data[i] << " ";
		std::cout<<std::endl;
	}
	int sizeis(){ return size; }
	T* data;

private:
	int arrsize = 0;
	int size = 0;
	int tail = -1;
};