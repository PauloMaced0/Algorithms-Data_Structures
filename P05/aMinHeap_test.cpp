
#include <iostream>
#include"min_heap.h"

using std::cout;
using std::cerr;
using std::endl;

int main(void){
    Min_heap<int> heap(100);
    for(int i= 0;i<100;i++){
        heap.insert(rand() % 100 + 1);
    }
    heap.check_minHeap();
    heap.dispaly();
    for(int j = 0;j < 100;j++){
        heap.remove(0);
        heap.remove(rand() % 100);
        heap.remove(6);
        heap.check_minHeap();
    }
    printf("All went well!!!\n");
    return 0;
}