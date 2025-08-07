#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return tail == head;
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return (tail + 1) % N == head;
}

template <typename T> void DynamicQueue<T> :: grow() {
  unsigned int newN = nextSize();
  T* newA = new T[newN];
  unsigned int count = size();
  for (unsigned int i = 0; i < count; ++i) {
      newA[i] = A[(head + i) % N];
  }
  delete[] A;
  A = newA;
  N = newN;
  head = 0;
  tail = count;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  if(tail >= head) return tail - head;
  return N - head + tail;
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if (isFull()) grow();
  A[tail] = x;
  tail = (tail + 1) % N;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if (isEmpty()) return false;
  *x = A[head];
  head = (head + 1) % N;
  return true;
}
