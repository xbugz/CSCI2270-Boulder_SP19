#ifndef HEAP_HPP
#define HEAP_HPP

class Heap
{
	public:

	Heap(int heapSize);
	~Heap();
	void printHeap();
	void addToHeap (float value);
	float removeFromHeap();
	float peekValue();
	bool isFull();
	bool isEmpty();
	float getMax();
	private:

	int parent(int nodeIndex);
	int leftChild(int nodeIndex);
	int rightChild(int nodeIndex);
	void repairUpward(int nodeIndex);
	void repairDownward(int nodeIndex);

	float* heap; //pointer to the array
	int currentSize; //current number of students in heap
	int heapSize; //maximum capacity of the heap
};
#endif
