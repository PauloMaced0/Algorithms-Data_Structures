// Generic prirotity queue(smallest values have higher priority) demo

#include <cstdlib>
#include <iostream>

using std::rand;
using std::cout;
using std::endl;

#include "priority_queue.h"

int main(void)
{
  Priority_queue<int> P;
  int i = 0;
  int o = 0;
  for(int n = 0;n < 1000000;n++)
  {
    if(P.size() == 0 || (P.size() < 20 && (rand() & 0x01000000) == 0))
    {
      P.enqueue(i);
      i++;
    }
    else
    {
      P.dequeue();
      o++;
    }
    if(P.size() > 0)
      P.peek();

    P.check_priority_queue();
    P.display();
  }
  while(P.size() > 0)
    cout << P.dequeue() << endl;
  cout << "All is well [i=" << i << ",o=" << o << "]" << endl;
  return 0;
}