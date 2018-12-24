#ifndef __FILEINFO_H__
#define __FILEINFO_H__
#include <sys/stat.h>
struct stat * readFileInfo(char * str);
void printFileInfo(struct stat * s, char * str);
#endif
