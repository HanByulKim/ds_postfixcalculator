#pragma once
template <typename T>
class stack{
public:
	stack(){
		data = new T[5];
		arrsize = 5;
	}
	~stack(){
		delete[] data;
	}

	void array_doubling(){
		T* newdata = new T[arrsize*2];
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
	T top(){ return data[tail]; }
	T pop(){ size--; return data[tail--]; }
	int sizeis(){ return size; }

private:
	T* data;
	int arrsize=0;
	int size = 0;
	int tail = -1;
};