#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 128


int main( int argc, char **argv){
  FILE *fp = fopen(argv[1], "r");

  //count lines in file
  char c;

  int lineCount = 0;

  if (fp == NULL){
    printf("File not found %s", argv[1]);
    return 1;
  }

  for (c = getc(fp); c != EOF; c = getc(fp)){
    if (c == '\n'){ // Increment count if this character is newline
      lineCount = lineCount + 1;
    }
  }

  printf("line count: %d\n", lineCount);

  char lines[lineCount + 1][MAX_LINE_LENGTH];
 
  // write file lines to array

  fp = fopen(argv[1], "r");
  int i = 0;
  while(fgets(lines[i], MAX_LINE_LENGTH, fp)){
    printf("is running");
    lines[i][strlen(lines[i]) - 1] = '\0';
    i++;
  }
  
  return 0;
}
