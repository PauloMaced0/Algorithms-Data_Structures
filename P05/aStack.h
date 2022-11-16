//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic stack (First In Last Out) implementation based on an array
//

#ifndef _AED_aStack_
#define _AED_aStack_

#include <cassert>
#include <cstring>
#include "../P02/elapsed_time.h"

template <typename T>
class aStack
{
  private:
    int max_size; // maximum stack size
    int cur_size; // current stack size
    T *data;      // the stack data (stored in an array)

    void resize(void)
    {
      int new_max_size = (int)max_size * sizeof(T) * 1.5;
      T *new_data = new T[max_size];
      memcpy(new_data, data, max_size * sizeof(T));

      assert(max_size <= 1000000);
      max_size = new_max_size;
      delete[] data;
      data = new_data;
    }

  public:
    aStack(int n = 10)
    {
      assert(n >= 10 && n <= 1000000);
      max_size = n;
      cur_size = 0;
      data = new T[n];
    }
    ~aStack(void)
    {
      delete[] data;
      max_size = 0;
      cur_size = 0;
      data = nullptr;
    }
    void clear(void)
    {
      cur_size = 0;
    }
    int size(void) const
    {
      return cur_size;
    }
    int is_full(void) const
    {
      return (cur_size == max_size) ? 1 : 0;
    }
    int is_empty(void) const
    {
      return (cur_size == 0) ? 1 : 0;
    }
    T top(void) const
    {
      assert(cur_size > 0);
      return data[cur_size - 1];
    }
    void push(T &v)
    {
      if(cur_size < max_size){
        data[cur_size++] = v;
      } else {
        resize();
        data[cur_size++] = v;
      }
    }
    T pop(void)
    {
      assert(cur_size > 0);
      return data[--cur_size];
    }
};

#endif
