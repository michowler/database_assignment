//char *strtok(char *str, const char *delim)

#include <string.h>
#include <stdio.h>
//create a function to read and then store lines (each line has 4 variables) into seperate variables inside he array
char stringify(char string[]);

int main () {
   stringify("this:is:bad");
   return 0;
}

char stringify(char string[]){
  
  const char s[2] = ":";
  char *token;
  
  /* get the first token */
  token = strtok(string, s);
  
  /* walk through other tokens */
  while( token != NULL ) {
     printf( " %s\n", token );
   
     token = strtok(NULL, s);
  }

  return printf( "" );
}

// char c[] = "abcd";
//      OR,
// char c[50] = "abcd";
//      OR,
// char c[] = {'a', 'b', 'c', 'd', '\0'};
//      OR,
// char c[5] = {'a', 'b', 'c', 'd', '\0'};