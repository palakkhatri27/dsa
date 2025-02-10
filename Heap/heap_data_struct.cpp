#include<vector>
#include<iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;


class minHeap {
	int *heapArray;
	int capacity;
	int heap_size;
	public:
		minHeap(int capacity);
		
		int parent(int i) {return (i-1)/2;}

		int left(int i) {return (2*i)+1;}

		int right(int i) {return (2*i)+2;}

		int extractMin();

		void decreaseKey(int i, int new_val);

		int getMin() {return heapArray[0];}

		void deleteKey(int i);

		void insertKey(int k);

		void minHeapify(int i);

		void printHeap() { for(int i=0;i<heap_size;i++) {cout<<heapArray[i]<<' ';} cout<<endl;}
};

void swap(int *x, int *y);

minHeap::minHeap(int capacity) {
	heap_size = 0;
	capacity = capacity;
	heapArray = new int[capacity];
}

void minHeap::insertKey(int k) {
	if(heap_size==capacity) {
		cout<<"Heap Overflow"<<endl;
		return;
	}

	int i = heap_size++;
	heapArray[i] = k;

	while(i!=0 && heapArray[parent(i)]>heapArray[i]) {
		swap(&heapArray[parent(i)],&heapArray[i]);
		i = parent(i);
	}
}

void minHeap::decreaseKey(int i, int newVal) {
	heapArray[i] = newVal;

	while(i!=0 && heapArray[parent(i)]>heapArray[i]) {
		swap(&heapArray[parent(i)],&heapArray[i]);
		i = parent(i);
	}
}

int minHeap::extractMin() {
	if(heap_size<=0) {
		return INT_MAX;
	}
	if(heap_size==1) {
		heap_size--;
		return heapArray[0];
	}

	int root = heapArray[0];
	heapArray[0] = heapArray[heap_size-1];
	heap_size--;
	minHeapify(0);
	
	return root;
}

void minHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void minHeap::minHeapify(int i) {
	int leftChildIndex = left(i);
	int rigthChildIndex = right(i);
	int smallestIndex = i;

	if(leftChildIndex < heap_size && heapArray[leftChildIndex] < heapArray[smallestIndex]) {
		smallestIndex = leftChildIndex;
	}
	if(rigthChildIndex < heap_size && heapArray[rigthChildIndex] < heapArray[smallestIndex]) {
		smallestIndex = rigthChildIndex;
	}
	if(smallestIndex!=i) {
		swap(&heapArray[i],&heapArray[smallestIndex]);
		minHeapify(smallestIndex);
	}
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
	minHeap h(11);
    h.insertKey(3);
	h.printHeap();
    h.insertKey(2);
	h.printHeap();
	cout << "Delete index 1 "<<endl;
    h.deleteKey(1);
	h.printHeap();
    h.insertKey(15);
	h.printHeap();
    h.insertKey(5);
	h.printHeap();
    h.insertKey(4);
	h.printHeap();
    h.insertKey(45);
	h.printHeap();
    cout << "Extract min "<<h.extractMin() << " "<<endl;
	h.printHeap();
    cout << "Get min "<<h.getMin() << " "<<endl;
    h.decreaseKey(2, 1);
	cout << "Decrease index 2 key to 1 "<<endl;
	h.printHeap();
	cout << "Get min "<<h.getMin() << " "<<endl;
    return 0;
}
	