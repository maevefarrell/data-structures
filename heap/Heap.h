#ifndef heap_mp
#define heap_mp
#include <vector>
#include <iostream>

template <class T>
class Heap{
	private:
		unsigned long heapsize;
		std::vector<T> data;
		static int parent(int i){return(i-1)/2;}
		void swap(T &a, T &b);
	public:
		Heap();
		Heap(std::vector<T> &obj);
		static int left(int i) {return 2*i +1;}
		static int right(int i){return 2*i +2;}
		void addElement(T element);
		T getPriority();
		bool empty();
		unsigned long size();
		std::vector<T> getArray();
		void siftdown(int);
		void heapify();
		bool isLeaf(int i);
};
template <class T>
Heap<T>::Heap(){
	heapsize = 0;
}	
template <class T>
Heap<T>::Heap(std::vector<T> &obj){
	heapsize = obj.size();
	for(int i = 0; i < this->size(); i++) {
		data.push_back(obj.at(i));
	}
	heapify();
}
template <class T>
void Heap<T>::heapify(){
	for(int i = (heapsize-2)/2; i >= 0; i--){
		siftdown(i);
	}
}
template <class T>
void Heap<T>::siftdown(int i){
//credit to Dr. David Sullivan at the Harvard Extension School (https://sites.fas.harvard.edu/~cscie119/lectures/heaps.pdf)
	if(i >= 0) {
		T toSift = data.at(i);

		int parent = i;
		int child = 2*parent + 1;

		while(child < heapsize) {
			if((child < heapsize-1) && (data.at(child) < data.at(child+1))) child = child+1;
			if(toSift >= data.at(child)) break;

			data.at(parent) = data.at(child);
			parent = child;
			child = 2*parent + 1;
		}

		data.at(parent) = toSift;
	}
}
template <class T>
T Heap<T>::getPriority(){
	if(!(heapsize == 0)) {
		T ret = data.at(0);
		swap(data.at(0),data.at(heapsize-1));
		heapsize--;
		heapify();
		data.pop_back();
		return ret;
	}
}
template <class T>
bool Heap<T>::isLeaf(int i) {
	int n = left(i);
	if(i >= n && i < 2*n+1) return true;
	else return false;
}

template <class T>
void Heap<T>::addElement(T element){
	data.push_back(element);
	heapsize++;
	heapify();
}
template <class T>
bool Heap<T>::empty(){
	if(data.empty()){
		return true;
	}
	return false;
}
template <class T>
unsigned long Heap<T>::size(){
	return heapsize;
}
template <class T>
std::vector<T> Heap<T>::getArray(){
	return data;
}
template <class T>
void Heap<T>::swap(T &a, T &b) {
  T temp(a);
  a = b;
  b = temp;
}
#endif
