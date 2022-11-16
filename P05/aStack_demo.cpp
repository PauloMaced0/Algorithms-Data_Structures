//
// Tomás Oliveira e Silva, AED, November 2021
//
// matched-parenthesis verification
//

#include <iostream>
#include "aStack.h"

using std::cout;
using std::cerr;
using std::endl;

// solving the problem using a iterative way, using the string given
int check_parentheses(const char *s)
{
  int left_parentheses= 0,right_parentheses = 0;
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (s[i] == '(')
    {
      int found = 0;
      int counter_left = 0, counter_right = 0;
      left_parentheses++;
      for (int k = i; s[k] != '\0'; k++)
      {
        if (s[k] == '(')
        {
          counter_left++;
        }
        if (s[k] == ')')
        {
          counter_right++;
        }
        if (s[k] == ')' && counter_left - counter_right == 0 && found == 0)
        {
          found = 1;
          printf("'(' at position %d and matching ')' at position %d\n", i, k);
        }
      }
      if(found == 0){
        printf("unmatched '(' at position %d\n", i);
        return 1;
      }
    }
    if (s[i] == ')')
    {
      right_parentheses++;
      if (left_parentheses < right_parentheses)
      {
        printf("unmatched ')' at position %d\n", i);
        return 1;
      }
    }
  }
  return 0;
}


//solving the problem using a stack
int check_parentheses_using_stack(const char *s){
  aStack<int> stack;
  for(int i = 0;s[i] != '\0';i++){
    if(s[i] == '(') stack.push(i);
    if(s[i] == ')'){
      if(!stack.is_empty()){
        if (stack.top() < i)
        {
          printf("'(' at position %d and matching ')' at position %d\n",stack.pop(),i);
        }
      } else {
        printf("unmatched ')' at position %d\n",i);
        return 1;
      }
    }
  } 
  if(!stack.is_empty()){
    printf("unmatched '(' at position %d\n", stack.pop());
    return 1;
  }
  return 0;
}
int main(int argc,char **argv)
{
  if(argc == 1)
  {
    cerr << "usage: " << argv[0] << " [arguments...]" << endl;
    cerr << "example: " << argv[0] << " 'abc(def)ghi' 'x)(y'" << endl;
    return 1;
  }
  for(int i = 1;i < argc;i++)
  {
    cout << argv[i] << endl;
    if(check_parentheses_using_stack(argv[i]) == 0){
      cout << "  good" << endl;
    }
    else {
      cout << "  bad" << endl;
    }
  }
  return 0;
}
