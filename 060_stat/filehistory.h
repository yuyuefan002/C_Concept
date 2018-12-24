#ifndef __FILEHISTORY_H__
#define __FILEHISTORY_H__
#include <sys/stat.h>
//char * time2str(const time_t * when, long ns);
void printHistory(struct stat * s);
#endif
