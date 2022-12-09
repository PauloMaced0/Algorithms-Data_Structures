//
// Tomás Oliveira e Silva, AED, November 2021
//
// to compare strings use the function strcmp()
// to copy a string use the function strcpy()
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// complete the define T !!!
//

#define T int 

#include "hash_table.h"

//
// complete the register_word function (count this word)
//

void register_word(char word[64])
{
  hash_table_node *node = find_hash_table_node(word);
  if (node->key == NULL)
  {
    hash_table_node *newNode = allocate_hash_table_node();
    strcpy(newNode->key, word);
    newNode->value = 1;
    insert_hash_table_node(newNode);
  }
  else
  {
    node->value += 1;  
  }
 }

 void visit_all_nodes()
 {
  unsigned int i;
  hash_table_node *hd;

  for (i = 0u; i < hashSize(); i++)
    for(hd = hash_table[i]; hd != NULL; hd = hd->next){
      printf("%s : %d\n",hd->key,hd->value);
    }
 }
 hash_table_node *more_repetitions()
 {
  // See what's the word that appears more in SherlockHolmes.txt
  unsigned int i;
  hash_table_node *hd;
  hash_table_node *repeated = NULL;
  int repetitions = 0;

  for (i = 0u; i < hashSize(); i++)
    for(hd = hash_table[i]; hd != NULL; hd = hd->next){
      if(hd->value > repetitions){
        repetitions = hd->value;
        repeated = hd;  
      }
    }
  return repeated;
 }
 
//
// main program
//

int main(int argc,char **argv)
{
  char line[10000],word[64];
  // hash_table_node *n; // Use in case of defining visti_all_node() and more_repetitions() functions in main
  FILE *fp;
  int i,j;

  for(i = 1;i < argc;i++)
  {
    //
    // open file for reading
    //
    fp = fopen(argv[i],"r");
    if(fp == NULL)
    {
      fprintf(stderr,"Unable to open file %s\n",argv[i]);
      exit(1);
    }
    //
    // place your counter initialization code here (creation of the hash table ...)
    //
    init_hash_table(1000000); // hash table with size = 1 000 000 
    //
    // scan the entire file
    //
    while(fgets(line,sizeof(line),fp) != NULL)
    {
      // replace non-digits and non-letters by a space
      for(i = 0;line[i] != '\0';i++)
        if((line[i] < '0' || line[i] > '9') && (line[i] < 'A' || line[i] > 'Z') && (line[i] < 'a' || line[i] > 'z') && line[i] != '\'')
          line[i] = ' ';
      // go over the line and extract each word
      for(i = 0;line[i] != '\0';i += j)
        if(line[i] == ' ')
          j = 1;
        else
        {
          for(j = 0;line[i + j] != '\0' && line[i + j] != ' ';j++)
            if(j < 63)
              word[j] = line[i + j];
          word[(j < 63) ? j : 63] = '\0';
          register_word(word);
        }
    }
    //
    // close file
    //
    fclose(fp);
    //
    // place your code to print the words and respective number of occurrences here
    //
    visit_all_nodes();
    printf("Word \"%s\", repeats itself %d times\n",more_repetitions()->key,more_repetitions()->value);
  }
  return 0;
}
