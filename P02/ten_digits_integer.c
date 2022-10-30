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
    if ((number % 10 == 0) ) // se implementar forma iterativa adicionar && allDiferentdigits(number) no if
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
void arrayTostring(int arr[]){
    char str[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\0'};
    for (int j = 0; j < 10; j++)
    {
        str[j] = arr[j] + '0';
    }
    char *p;
    long int number = strtol(str, &p, 10);
    printf("%ld",number);
}

void veryNicefunction(long n, int nd, int arr[]){
    if(nd == 10 && validate(n)){
        printf("%ld\n",n);
    }
    nd++;
    for(int d = 0; d < 10; d++){
        if((arr[d] == 0) ){
            arr[d] = 1;
            veryNicefunction(n * 10 + d,nd,arr);
            arr[d] = 0;
        }
    }
}
int main()
{
    // for(long int i = 1234567890; i <= 9876543210; i++){ // 26 seconds algorithm using brute force
    //     if(validate(i)){
    //         printf("%ld\n",i);
    //     }     
    // }
    int arr[10] = {0};
    int n = 0;
    int nd = 0;
    veryNicefunction(n, nd, arr);
    return 0;
   //the number we are looking for... 3816547290 
}
