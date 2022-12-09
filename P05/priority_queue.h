// Implementing a priority_queue using a min_heap, assuming that lower values have higher priorities.

#ifndef priority_queue
#define priority_queue

#include<cassert>

template <typename T>
class Priority_queue
{
    private:
        T *prio_queue;
        int max_size; 
        int current_size;
    public:
        Priority_queue(int size = 100)
        {
            current_size = 0;
            max_size = size;
            prio_queue = new int[max_size];
        }
        ~Priority_queue(void) 
        {
            current_size = 0;
            max_size = 0;
            delete prio_queue;
        }
        int size(void) const
        {
            return current_size;
        }
        int is_full(void) const
        {
            return (current_size == max_size - 1) ? 1 : 0;
        }
        int is_empty(void) const
        {
            return (current_size = 0) ? 1 : 0;
        }
        void enqueue(const T &v)
        {
            assert(current_size < max_size);
            int i;
            for(i = ++current_size;i > 1 && prio_queue[i / 2] > v;i /= 2){
                prio_queue[i] = prio_queue[i / 2];
            }
            prio_queue[i] = v;
        }
        T dequeue(void)
        {
            int i,j;
            int min = prio_queue[1];
            for(i = 1;2 * i <= current_size;prio_queue[i] = prio_queue[j],i = j){
                j = (2 * i + 1 <= current_size && prio_queue[2 * i + 1] < prio_queue[2 * i]) ? 2*i+1 : 2*i; // select the smallest child
            }
            for(;i>1 && prio_queue[i / 2] > prio_queue[current_size];i /= 2){
                prio_queue[i] = prio_queue[i / 2];
            }
            prio_queue[i] = prio_queue[current_size--];
            assert(current_size >= 0);
            return min;
        }
        T peek(void)
        {
            return prio_queue[1];
        }
        void check_priority_queue(void)
        {
            // for (int i = 2; i <= current_size; i++)
            //     assert(prio_queue[i / 2] <= prio_queue[i]);
        }
        void display(void){
            assert(current_size >= 0);
            for(int i = 1;i<=current_size;i++){
                printf("Priority_queue[%d]=%d\n",i,prio_queue[i]);
            }
        }
};
#endif