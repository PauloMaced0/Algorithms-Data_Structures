//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic queue (First In First Out) implementation based on an linked list
//

#ifndef _AED_lQueue_
#define _AED_lQueue_

#include <cassert>

template <typename T>
class lQueue
{
  private:
    class qNode
    {
      public:
        T value; // data stored in the node 
        qNode *next; // pointer to the next node
    };
  private:
    qNode *tail; // tail of the queue
    qNode *head; // head of the queue
    int n_nodes; // number of nodes on the queue
    int queue_size; // number of nodes queue can hold
    
  public:
    lQueue(void)
    {
      n_nodes = 0;
      queue_size = 100;
      head = nullptr;
      tail = nullptr;
    }
    ~lQueue(void)
    {
      qNode *qn,*qn1;

      for(qn = head; qn != nullptr;qn = qn1){
        qn1 = qn->next;
        delete qn;
      }
      head = nullptr;
      tail = nullptr;
      n_nodes = 0;
      queue_size = 0;
    }
    void clear(void)
    {
      qNode *qn,*qn1;
      
      for(qn = tail;qn != nullptr;qn = qn1){
        qn1 = qn->next;
        dequeue();
      }
      assert(n_nodes == 0);
    }
    int size(void) const
    {
      return n_nodes;
    }
    int is_full(void) const
    {
      return (n_nodes == queue_size) ? 1 : 0;
    }
    int is_empty(void) const
    {
      return (n_nodes = 0) ? 1 : 0;
    }
    void enqueue(T &v)
    {
      if (n_nodes < queue_size)
      {
        qNode *qn = new qNode;
        qn->value = v;
        if (n_nodes == 0)
        {
          qn->next = nullptr;
          head = tail = qn;
        }
        else
        {
          qn->next = tail;
          tail = qn;
        }
        n_nodes++;
      }
    }
    T dequeue(void)
    {
      T data;
      if(n_nodes == 1){
        data = head->value;
        delete head;
        head = nullptr;
        tail = nullptr;
        n_nodes = 0;
      }
      else
      {
        qNode *qn = tail;
        while(qn->next != head){
          qn = qn->next;
        }
        qn->next = nullptr;
        data = head->value;
        delete head;
        head = qn;
        n_nodes--;
      }
      return data;
    }
    // Gets the element at the front of the queue without removing it
    T peek(void)
    {
      return head->value;
    }
};

#endif
