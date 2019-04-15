#include <iostream>
#include "heap.hpp"
using namespace std;




Heap::Heap(int heapSize){
  heapSize = heapSize;
  heap = new float[heapSize];
  currentSize = 0;
}

Heap::~Heap(){
  delete [] heap;
}

void Heap::printHeap(){

  for (int i = 0; i < currentSize; i++) {
    cout << heap[i] << endl;
  }
}

void Heap::addToHeap (float value){
      if(currentSize != heapSize){
      heap[currentSize] = value;
      repairUpward(currentSize);
      currentSize++;

    }
    else{
        cout << "Heap full, cannot enqueue" << endl;
    }
}

float Heap::removeFromHeap(){
  if (currentSize==0) {
     cout << "Heap empty, cannot dequeue" << endl;
     return peekValue();
   }
   else{

   heap[0] = heap[currentSize-1];
   currentSize--;
   repairDownward(0);
   return peekValue();
       }
}

float Heap::peekValue(){
  if (currentSize != 0) {
        return heap[0];
      }
      else{
        cout << "Queue empty, cannot peek" << endl;
        return heap[0];
      }
}

bool Heap::isFull(){
  if (currentSize == heapSize) {
      return true;
    }
    else{
      return false;
        }
}

bool Heap::isEmpty(){
  if (currentSize != 0) {
        return false;
      }
      else{
        return true;
      }
}

int Heap::parent(int i)
 { return (i-1)/2; }

int left(int i)
{ return (2*i+1); }

int right(int i)
 { return (2*i + 2); }

void swap(float *x, float *y)
  {
      float temp = *x;
      *x = *y;
      *y = temp;
  }

void Heap::repairUpward(int nodeIndex){
  if (nodeIndex==0) {
    return;
  }
  int Parent = parent(nodeIndex);
    if(heap[nodeIndex] < heap[Parent] ){
        swap(&heap[Parent], &heap[nodeIndex]);
        repairUpward(Parent);
        }
}

bool checkpriority(int x, int y){
    if(x < y){
       return false;
    }
    else{
      return true;
    }

}

void Heap::repairDownward(int nodeIndex)
{
  int l = left(nodeIndex);
  int r = right(nodeIndex);
  int smallest = nodeIndex;

  if (l < currentSize && heap[l] < heap[nodeIndex]) {
      smallest = l;
    }
    if (r < currentSize and heap[r] < heap[smallest]) {
      smallest = r;
    }
    if (smallest != nodeIndex) {
      swap(&heap[nodeIndex], &heap[smallest]);
      repairDownward(smallest);
    }


}

int main(int argc, char const *argv[]) {
  Heap h(10);
  h.addToHeap(1);
  h.addToHeap(10);
  h.addToHeap(5);
  h.addToHeap(8);
  h.addToHeap(7);
  h.addToHeap(0);
//  h.removeFromHeap();
  h.printHeap();
  return 0;
}
