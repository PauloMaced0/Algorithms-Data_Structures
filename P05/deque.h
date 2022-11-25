//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic deque implementation based on a circular buffer
//

#ifndef _AED_deque_
#define _AED_deque_

#include <cassert>

template <typename T>
class deque
{
  private:
    class dNode
    {
      public:
        T value;     // value of the node
        dNode *next; // pointer to the next node
    };

  private:
    int deque_size; // :)
    int n_nodes; // current size of the dique
    dNode *head; // head of the deque
    dNode *tail; // tail of the deque

  public:
    deque(int max_size = 100)
    {
      n_nodes = 0;
      deque_size = max_size;
      head = nullptr;
      tail = nullptr;
    }
    ~deque(void)
    {
      dNode *dn1,*dn2;
      for(dn1 = head;dn1 != nullptr; dn1 = dn2){
        dn2 = dn1->next;
      }
      n_nodes = 0;
      head = nullptr;
      tail = nullptr;
      deque_size = 0;
    }
    void clear(void)
    {
      dNode *dn1,*dn2;

      for(dn1 = tail;dn1 != nullptr;dn1 = dn2){
        dn2 = dn1->next;
        remove_head();
      }
    }
    int size(void) const
    {
      return n_nodes;
    }
    int is_full(void) const
    {
      return (n_nodes == deque_size) ? 1 : 0;
    }
    int is_empty(void) const
    {
      return (n_nodes == 0) ? 1 : 0;
    }
    void insert_at_head(T &v)
    {
      assert(n_nodes >= 0 && n_nodes <= deque_size);
      printf("Insert at head: %d\n",v);
      dNode *dn = new dNode;
      dn->value = v;
      if (n_nodes == 0)
      {
        dn->next = nullptr;
        head = tail = dn;
      }
      else
      {
        dn->next = head;
        head = dn;
      }
      n_nodes++;
    }
    T remove_head(void)
    {
      assert(n_nodes > 0);
      T data;
      if(n_nodes == 1){
        data = head->value;  
        delete head;
        head = nullptr;
        tail = nullptr;
        n_nodes = 0;
      } else {
        dNode *dn = head->next;
        data = head->value;
        delete head;
        head = dn;
        n_nodes--;
      }
      printf("Remove head: %d\n",data);
      return data;
    }
    T peek_head(void)
    {
      printf("Peek head: %d\n",head->value);
      return head->value;
    }
    void insert_at_tail(T &v)
    {
      assert(n_nodes >= 0 && n_nodes <= deque_size);
      printf("Insert at tail: %d\n",v);
      dNode *dn = new dNode;
      dn->value = v;
      if(n_nodes == 0){
        dn->next = nullptr;
        tail = head = dn;
      } else {
        dn->next = nullptr;
        tail->next = dn;
        tail = dn;
      }
      n_nodes++;
    }
    T remove_tail(void)
    {
      assert(n_nodes > 0);
      T data;
      if(n_nodes == 1){
        data = tail->value;
        delete tail;
        head = nullptr;
        tail = nullptr;
        n_nodes = 0;
      } else {
        dNode *dn = head;
        while(dn->next != tail){
          dn = dn->next;
        }
        data = tail->value,
        dn->next = nullptr;
        delete tail;
        tail = dn;
        n_nodes--;
      }
      printf("Remove tail: %d\n",data);
      return data;
    }
    T peek_tail(void)
    {
      printf("Peek tail: %d\n",tail->value);
      return tail->value;
    }
};

#endif
