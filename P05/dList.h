//doubly linked list implemetation

#ifndef _AED_sList_
#define _AED_sList_

#include <cassert>

template <typename T>
class dList
{
  private:
    class dNode
    {
      public:
        T value;     // the data stored in the node
        dNode *prev; // pointer to the previous node 
        dNode *next; // pointer to the next node
    };
  private:
    int n_nodes;     // number of nodes
    dNode *head;     // head of the linked list
    dNode *tail;     // tail of the linked list
    dNode *current;  // current node
    int pos;         // current node index
  public:
    //
    // constructor
    //
    dList(void)
    {
      n_nodes = 0;
      head = nullptr;
      tail = nullptr;
      current = nullptr;
      pos = -1; // default position is before the head of the list
    }
    //
    // destructor
    //
    ~dList(void)
    {
      dNode *sn1,*sn2;

      for(sn1 = head;sn1 != nullptr;sn1 = sn2)
      {
        sn2 = sn1->next;
        delete sn1;
      }
      n_nodes = 0;
      head = nullptr;
      tail = nullptr;
      current = nullptr;
      pos = -1;
    }
    //
    // list size
    //
    int size(void) const
    {
      return n_nodes;
    }
    //
    // value of the current node
    //
    T value(void) const
    {
      assert(current != nullptr);
      return current->value;
    }
    //
    // modify the value of the current node
    //
    void modify_value(const T &v) const
    {
      assert(current != nullptr);
      current->value = v;
    }
    //
    // number of the current node
    //
    int position(void) const
    {
      return pos;
    }
    //
    // move to the node at position new_pos
    //
    int move(int new_pos)
    {
      if(new_pos < -1 || new_pos > n_nodes)
        return -1; // failure
      if(new_pos == -1 || new_pos == n_nodes)
        current = nullptr;
      else if(new_pos == 0)
        current = head;
      else if(new_pos == n_nodes - 1)
        current = tail;
      else
      {
        if(pos < 0 || pos >= n_nodes || new_pos < pos)
        {
          current = head;
          pos = 0;
        }
        for(int i = pos;i < new_pos;i++)
          current = current->next;
      }
      pos = new_pos;
      return 0; // success
    }
    //
    // move to the next node
    //
    int move_to_next(void)
    {
      return move(pos + 1);
    }
    //
    // move to the previous node
    //
    int move_to_previous(void)
    {
      return move(pos - 1);
    }
    //
    // move to the head of the list
    //
    int move_to_head(void)
    {
      return move(0);
    }
    //
    // move to the tail of the list
    //
    int move_to_tail(void)
    {
      return move(n_nodes - 1);
    }
    //
    // insert a node before the head and make it the new head
    // the current node is not changed
    //
    void insert_before_head(const T &v)
    {
      dNode *new_node = new dNode;
      new_node->value = v;
      if(n_nodes == 0)
      {
        new_node->next = nullptr;
        new_node->prev = nullptr;
        head = tail = new_node;
      }
      else
      {
        new_node->next = head;
        new_node->prev = nullptr;
        head = new_node;
      }
      if(pos >= 0)
        pos++;
      n_nodes++;
    }
    //
    // insert a node after the tail and make it the new tail
    // the current node is not changed
    //
    void insert_after_tail(const T &v)
    {
      dNode *new_node = new dNode;
      new_node->value = v;
      if(n_nodes == 0)
      {
        new_node->next = nullptr;
        new_node->prev = nullptr;
        head = tail = new_node;
      }
      else
      {
        new_node->next = nullptr;
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
      }
      if(pos == n_nodes)
        pos++;
      n_nodes++;
    }
    //
    // insert a node after the current node and make it the current node
    //
    void insert_after(const T &v)
    {
      assert(-1 <= pos && pos < n_nodes);
      if(pos == -1)
      {
        insert_before_head(v);
        current = head;
        pos = 0;
      }
      else if(pos == n_nodes - 1)
      {
        insert_after_tail(v);
        current = tail;
        pos = n_nodes - 1;
      }
      else
      {
        dNode *new_node= new dNode;
        new_node->value = v;
        new_node->next = current->next;
        new_node->prev = current;
        current->next = new_node; // define next node of the current one to new_node
        current = new_node; // new_node is the new current node
        pos++;
        n_nodes++;
      }
    }
    //
    // insert a node before the current node and make it the current node
    //
    void insert_before(const T &v)
    {
      assert(move_to_previous() == 0);
      insert_after(v);
    }
    //
    // remove the head of the list and make its next node the new head
    // if the current node is the head, it is replaced by its next node
    //
    void remove_head(void)
    {
      assert(n_nodes > 0);
      if(current == head)
      {
        current = head->next;
        pos++;
      }
      if(n_nodes == 1)
      {
        delete head;
        head = nullptr;
        tail = nullptr;
        n_nodes = 0;
        if(pos > 0)
          pos = 0;
      }
      else
      {
        dNode *sn = head->next;
        sn->prev = nullptr;
        delete head;
        head = sn;
        if(pos > 0)
          pos--;
        n_nodes--;
      }
    }
    //
    // remove the tail of the list and make its previous node the new tail
    // if the current node is the tail, it is replaced by it by its next node
    //
    void remove_tail(void)
    {
      assert(n_nodes > 0);
      if(current == tail)
      {
        current = nullptr;
        pos++;
      }
      if(n_nodes == 1)
      {
        delete head;
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        if(pos > 0)
          pos = 0;
        n_nodes = 0;
      }
      else
      {
        dNode *new_tail= head;
        while(new_tail->next != tail)
          new_tail = new_tail->next;
        new_tail->next = nullptr;
        delete tail;
        tail = new_tail;
        if(pos == n_nodes)
          pos--;
        n_nodes--;
      }
    }
    //
    // remove the current node and make its next node the current node
    //
    void remove(void)
    {
      assert(pos >= 0 && pos < n_nodes);
      if(pos == 0)
        remove_head();
      else if(pos == n_nodes - 1)
        remove_tail();
      else
      {
        dNode *sn = head;
        while(sn->next != current)
          sn = sn->next;
        sn->next = current->next; 
        sn->prev = current->prev;
        delete current;
        current = sn->next; // define the next node as current
        n_nodes--;
      }
    }
    //
    // remove the next node
    //
    void remove_next(void)
    {
      assert(-1 <= pos && pos < n_nodes - 1);
      if(n_nodes == 1)
      { // pos can only be -1
        delete head;
        head = nullptr;
        tail = nullptr;
        n_nodes = 0;
      }
      else if(pos == -1)
      {
        dNode *sn = head->next;
        sn->prev = nullptr;
        delete head;
        head = sn;
        n_nodes--;
      }
      else
      {
        dNode *sn = current->next; // node to be deleted
        if (sn != tail)
        {
          current->next = sn->next;  // define new next
          dNode *next_node = current->next;
          next_node->prev = current;
        } else {
          current->next = sn->next;  // define new next
          tail = current;
        }
        delete sn;
        n_nodes--;
      }
    }
    //
    // starting at the current node, search for the first node with a value of v
    // on failure the current node is not changed
    //
    int search(const T &v)
    {
      int i = (pos < 0) ? 0 : pos;
      dNode *sn = (pos < 0) ? head : current;
      while(i < n_nodes && v != sn->value)
      {
        i++;
        sn = sn->next;
      }
      if(i == n_nodes)
        return -1; // failure
      current = sn;
      pos = i;
      return 0; // success
    }
    //
    // test the consistency of the list (used only during code development)
    //
    void test_invariants(void)
    {
      assert(n_nodes >= 0);
      if(n_nodes == 0)
        assert(head == nullptr && tail == nullptr);
      else
        assert(head != nullptr && tail != nullptr);
      if(n_nodes == 1)
        assert(head == tail);
      assert(-1 <= pos && pos <= n_nodes);
      if(pos == -1 || pos == n_nodes)
        assert(current == nullptr);
      dNode *sn = head;
      for(int i = 0;i < n_nodes;i++)
      {
        if(i == n_nodes - 1)
          assert(sn == tail && sn->next == nullptr);
        else
          assert(sn->next != nullptr);
        if(i == pos)
          assert(sn == current);
        sn = sn->next;
      }
    }
};

#endif