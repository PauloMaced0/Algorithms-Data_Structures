#include<stdio.h>

int binary_search(int *data, int data_size, int value)
{// returns the greatest index to the searched value
  int i_low = 0;
  int i_high = data_size - 1;
  int greatestIndex = -1;
  int i_middle;

  while(i_low <= i_high)
  {
    i_middle = (i_low + i_high) / 2;
    if(value == data[i_middle]){
      greatestIndex = i_middle; 
      i_low = i_middle + 1;       //In case of wanting the first occurrance and not the last, i_high = i_middle - 1
    }
    else if(value > data[i_middle]){
      i_low = i_middle + 1;
    }
    else if(value < data[i_middle]){
      i_high = i_middle - 1;
    }
  }
  return greatestIndex;
}

int main(){
    int data[] = {1, 2, 5, 7, 7, 8, 9, 10, 13, 15, 19};
    int size_data = sizeof(data)/sizeof(data[0]);
    int search = 7;
    int index = binary_search(data,size_data, search);
    printf("Last occurance of %d in index: %d\n", search, index);

    return 0;
}