//
// Tomás Oliveira e Silva, AED, October 2021
//
// list all command line arguments
//
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[argc])
{
  long String_value;
  char *ptr;
  // int String_value;
  for(int i = 0;i < argc;i++){
    //String_value = atoi(*argv); 
    //printf("argv[%2d] = \"%s\" String Value: %d\n",i,*argv,String_value);
    //argv++;
    String_value = strtol(*argv, &ptr, 10);
    printf("argv[%2d] = \"%s\" String Value: %ld\n",i,*argv,String_value);
    argv++;
  }

  return 0;
}
