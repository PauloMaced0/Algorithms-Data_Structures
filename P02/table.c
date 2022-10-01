//
// Tomás Oliveira e Silva, AED, October 2021
//
// program to print a table of the squares and square roots of some integers
//
// on GNU/Linux, run the command
//   man 3 printf
// to see the manual page of the printf function
//

#include <math.h>
#include <stdio.h>

void do_it(int N)
{
  int i;

  printf(" n n*n      sqrt(n)\n");
  printf("-- --- -----------------\n");
  for(i = 1;i <= N;i++)
    printf("%2d %3d %17.15f\n",i,i * i,sqrt((double)i));
}
void cos_sen(){
  FILE *fp;
  fp = fopen("table.txt","w");
  fprintf(fp,"ang  cos  sen\n");
  for(int i = 0; i<= 90; i++){
    fprintf(fp,"%2d %6.3f %6.3f\n",i,cos(i) * (180/M_PI),sin(i) * (180/M_PI));
  }
  fclose(fp);
}

int main(void)
{
  do_it(10);
  cos_sen();
  return 0;
}
