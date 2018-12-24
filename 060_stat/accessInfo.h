#ifndef __ACCESSINFO_H__
#define __ACCESSINFO_H__
#include <sys/stat.h>
#define USR 1
#define GRP 2
#define OTHER 3
typedef int user_t;
//char parseType(struct stat * s);
//char parseReadable(struct stat * s, user_t user);
//char parseWritable(struct stat * s, user_t user);
//char parseExecutable(struct stat * s, user_t user);
void printAccess(struct stat * s);
#endif
