#include <stdio.h>
#include <stdlib.h>

#include "accessInfo.h"
#include "filehistory.h"
#include "fileinfo.h"
//print stat of the file
//the parameter is the path of the file
void fileStat(char * str) {
  struct stat * s = readFileInfo(str);  //make system call to read file info
  printFileInfo(s, str);                //print first three lines
  printAccess(s);                       //print forth line
  printHistory(s);                      //print last three lines
  free(s);
}
int main(int argc, char ** argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  for (int i = 1; i < argc; i++) {
    fileStat(argv[i]);  //print the stat of current path
  }
  return EXIT_SUCCESS;
}
