#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return head == tail; // dummy return
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return tail == N; // dummy return
}

template <typename T> void DynamicQueue<T> :: grow() {
  unsigned int newN = nextSize();
  T* newA = new T[newN];
  unsigned int count = size();
  for (unsigned int i = 0; i < count; ++i) newA[i] = A[head + i];
  delete[] A;
  A = newA;
  N = newN;
  tail = count;
  head = 0;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return tail - head;
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if (isFull()) grow();
  A[tail++] = x;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if (isEmpty()) return false;
  *x = A[head++];
  return true;
}
