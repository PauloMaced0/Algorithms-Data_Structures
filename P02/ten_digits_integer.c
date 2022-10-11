#include <stdio.h>
#include <stdlib.h>

long int power(int base, int power){
    for(int p = 0; p < power - 1; p++){
        base *= 10;
    }
    return base;
}

int allDifferentdigits(long int number){
    int seen[10] = {0};
    while (number)
    {
        int digit = number % 10;
        seen[digit] += 1;
        number /= 10;
    }

    for(int i = 0; i<sizeof(seen)/sizeof(int);i++){
        if(seen[i] != 1){
            return 0;
        }
    }
    
    return 1;
}

int validate(long int number){
    if ((number % 10 == 0) && allDifferentdigits(number))
    {
        for (int k = 2; k <= 9; k++)
        {
            long int checkNumber = (long int) number / power(10,10-k) ;
            if(checkNumber % k != 0){
                return 0;
            }
        }
    } else {
        return 0;
    }
    return 1;
}
void veryNicefunction(int i, int arr[]){
    char str[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\0'};
    for (int j = 0; j < 10; j++)
        {
            str[j] = arr[j] + '0';
        }
    char *p;
    long int number = strtol(str, &p, 10);
    printf("%ld",number);
    if(number == 3816547290){
        printf("%ld",number);
    }

    for(int k = i + 1; k<10; k++){
        arr[i] = k;
        veryNicefunction(i+1,arr);
       

    }

}
int main()
{
    // for(long int i = 1234567890; i <= 9876543210; i++){ // 26 seconds algorithm 
    //     if(validate(i)){
    //         printf("%ld\n",i);
    //     }     
    // }
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int i = 0;
    veryNicefunction(i,arr);
}
