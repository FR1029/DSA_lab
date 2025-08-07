#include "bits/stdc++.h"
using namespace std;

template <typename T>
class Deque
{
  friend ostream& operator<<(ostream& out, const Deque& dq)
  { 
    int i = dq.front_index;
    for(int count = 0; count < dq.size; count++){
      out << dq.arr[i] << " ";
      i = (i + 1) % dq.capacity;
    }
    return out;
  }
protected:
  T* arr;
  int capacity;
  int size;
  bool auto_resize;
  int resize_factor;
  int front_index;
  int rear_index;
  void resize(){
      int new_capacity = capacity * resize_factor;
      T* new_arr = new T[new_capacity];
      for(int i = 0; i < capacity; i++) new_arr[i] = arr[(front_index+i) % capacity];
      delete[] arr;
      arr = new_arr;
      capacity = new_capacity;
      front_index = 0;
      rear_index = size - 1;
  }

public:
  Deque(int cap, bool resize = true, int resizefactor = 2)
    : capacity(cap), size(0), auto_resize(resize), resize_factor(resizefactor)
  {                                           
    arr = new T[capacity];
    front_index = 0;
    rear_index = -1;
  }

    Deque(bool resize = true, int resizefactor = 2)
      : Deque(5, resize, resizefactor)
    {
    }

    Deque(const Deque& dq)
      : capacity(dq.capacity), size(dq.size), auto_resize(dq.auto_resize), resize_factor(dq.resize_factor), front_index(dq.front_index), rear_index(dq.rear_index)
    {
      arr = new T[capacity];
      for(int i = 0; i < capacity; i++) arr[i] = dq.arr[i];
    }

    ~Deque()
    {
      delete[] arr;
    }

    int get_capacity()
    {
      return capacity;
    }

    int get_size()
    {
      return size;
    }

    bool is_empty()
    {
      return size == 0;
    }  
protected:
    bool push_back(T data)
    {
      if (size == capacity) {
          if (!auto_resize) return false;
          resize();
      }
      rear_index = (rear_index + 1) % capacity;
      arr[rear_index] = data;
      size++;
      return true;
    }

    T pop_front()
    {
      if (is_empty()) throw runtime_error("Deque is empty");
      T value = arr[front_index];
      front_index = (front_index + 1) % capacity;
      size--;
      return value;
    }

    bool push_front(T data)
    {
      if (size == capacity) {
        if (!auto_resize) return false;
        resize();
      }
      front_index = (front_index - 1 + capacity) % capacity;
      arr[front_index] = data;
      size++;
      return true;
    }

    T pop_back()
    {
      if (is_empty()) throw runtime_error("Deque is empty");
      T value = arr[rear_index];
      rear_index = (rear_index - 1 + capacity) % capacity;
      size--;
      return value;
    }

    T peek_front()
    {
      if (is_empty()) throw runtime_error("Deque is empty");
      return arr[front_index];
    }

    T peek_back()
    {
      if (is_empty()) throw runtime_error("Deque is empty");
      return arr[rear_index];
    }
};

template<typename T>
class Queue : public Deque<T>
{
  friend ostream& operator<<(ostream& out, const Queue& q) {
    out << static_cast<const Deque<T>&>(q);
    return out;
  }
public:
  Queue(int cap, bool resize = true, int resize_factor = 2) 
    : Deque<T>(cap, resize, resize_factor)
  {}

  Queue(bool resize = true, int resize_factor = 2)
    : Deque<T>(resize, resize_factor)
  {}
  Queue(const Queue& q) : Deque<T>(q) {}
  using Deque<T>::push_back;
  using Deque<T>::pop_front;
  using Deque<T>::peek_front;
  using Deque<T>::get_size;
  using Deque<T>::get_capacity;
  using Deque<T>::is_empty;
};


template<typename T>
class Stack : public Deque<T>
{
  friend ostream& operator<<(ostream& out, const Stack& s) {
    out << static_cast<const Deque<T>&>(s);
    return out;
  }
    
public:
  Stack(int cap, bool resize = true, int resize_factor = 2) 
    : Deque<T>(cap, resize, resize_factor)
  {}

  Stack(bool resize = true, int resize_factor = 2)
    : Deque<T>(resize, resize_factor)
  {}

  Stack(const Stack& s) : Deque<T>(s) {}
  using Deque<T>::push_back;
  using Deque<T>::pop_back;
  using Deque<T>::peek_back;
  using Deque<T>::get_size;
  using Deque<T>::get_capacity;
  using Deque<T>::is_empty;
};
