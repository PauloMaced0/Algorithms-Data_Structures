//test doubly linked impemetation(dList.h)#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "dList.h"

using std::rand;
using std::cout;
using std::endl;
using std::setw;

int main(void)
{
  dList<int> D;
  D.test_invariants();
  int i = 0;
  while(i < 1000000)
  {
    int j = 0;
    switch(rand() % 3)
    {
      case 0: // move (probability 1/3)
        j = 1;
        assert(D.move(-1 + rand() % (D.size() + 2)) == 0);
        break;
      case 1: // insert (probability: 1/3)
        if(D.size() < 10)
          switch(rand() % 8)
          {
            case 0: // insert after (probability: 1/3*3/8)
            case 1:
            case 2:
            // insert after
              if(D.position() < D.size())
              {
                j = 1;
                D.insert_after(i);
              }
              break;
            case 3: // insert before (probability: 1/3*3/8)
            case 4:
            case 5:
              if(D.position() >= 0)
              {
                j = 1;
                D.insert_before(i);
              }
              break;
            case 6: // insert before head (probability: 1/3*1/8)
              j = 1;
              D.insert_before_head(i);
              break;
            case 7: // insert after tail (probability: 1/3*1/8)
              j = 1;
              D.insert_after_tail(i);
              break;
          }
        break;
      case 2: // remove (probability: 1/3)
        if(D.size() > 0)
          switch(rand() % 6)
          {
            case 0: // current (probability: 1/3*2/6)
            case 1:
              if(D.position() >= 0 && D.position() < D.size())
              {
                j = 1;
                D.remove();
              }
              break;
            case 2: // next (probability: 1/3*2/6)
            case 3:
              if(D.position() >= -1 && D.position() < D.size() - 1)
              {
                j = 1;
                D.remove_next();
              }
              break;
            case 4: // head (probability: 1/3*1/6)
              j = 1;
              D.remove_head();
              break;
            case 5: // tail (probability: 1/3*1/6)
              j = 1;
              D.remove_tail();
              break;
          }
        break;
    }
    i += j;
    if(j != 0)
      D.test_invariants();
  }
  cout << "Final contents of the list:" << endl;
  D.move_to_head();
  D.test_invariants();
  for(int i = 0;i < D.size();i++)
  {
    cout << "  " << setw(2) << i << " " << setw(6) << D.value() << endl;
    D.move_to_next();
    D.test_invariants();
  }
  cout << "All went well!" << endl;
  return 0;
}
