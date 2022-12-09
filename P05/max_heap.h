#ifndef max_heap
#define max_heap

#include<cassert>

template <typename T>
class Max_heap
{
    private:
        T *heap;
        int max_size; 
        int current_size;
    public:
        Max_heap(int size = 100)
        {
            current_size = 0;
            max_size = size;
            heap = new int[max_size];
        }
        ~Max_heap(void) 
        {
            current_size = 0;
            max_size = 0;
            delete heap;
        }
        void insert(const T &v)
        {
            assert(current_size < max_size);
            int i;
            for(i = ++current_size;i > 1 && heap[i / 2] < v;i /= 2){
                heap[i] = heap[i / 2];
            }
            heap[i] = v;
        }
        void remove(int pos)
        {
            int i,j;
            if(pos < 1) return;
            for(i = pos;2 * i <= current_size;heap[i] = heap[j],i = j){
                j = (2 * i + 1 <= current_size && heap[2 * i + 1] > heap[2 * i]) ? 2*i+1 : 2*i;
            }
            for(;i>1 && heap[i / 2] < heap[current_size];i /= 2){
                heap[i] = heap[i / 2];
            }
            heap[i] = heap[current_size--];
            assert(current_size >= 0);
        }
        void check_maxHeap(void)
        {
            for (int i = 2; i <= current_size; i++)
                assert(heap[i / 2] >= heap[i]);
        }
        void dispaly(void){
            if(current_size < 0) return;
            for(int i = 1;i<=current_size;i++){
                printf("Max_heap[%d]=%d\n",i,heap[i]);
            }
        }
};
#endif