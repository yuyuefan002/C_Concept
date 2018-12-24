#include <ftw.h>

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

/*
  initialize a hash table which stores the filename
  the reason why pick 196613, it is a good prime number
  according to https://planetmath.org/goodhashtableprimes
*/
size_t H_Size = 196613;
std::vector<std::list<std::string> > table(H_Size);

/*
  std::string readFile(std::string file)
  input: std::string (file path) 
  output: std::string (file content)
  Description: return the content of input file as a string
 */
std::string readFile(std::string file) {
  std::ifstream f(file);
  std::stringstream buffer;
  buffer << f.rdbuf();
  return buffer.str();
}

/*
  void addToHashTable(const char * fpath)
  input: const char* fpath
  output: None
  Description: add fpath into hashtable 
 */
void addToHashTable(const char * fpath) {
  std::string file = fpath;
  std::hash<std::string> hash;

  std::string content = readFile(file);

  size_t H_Value = hash(content);

  table[H_Value % H_Size].push_front(file);
}

/*
  void findIdentical(std::string file,std::list<std::string>& list)
  input: std::string file,std::list<std::string>& list
  output: True of false
  Description: find whether there is an identical file as the input file in the list
            if there is one,return true,else return false
 */
bool findIdentical(std::string file, std::list<std::string> & list) {
  std::string content = readFile(file);
  for (std::list<std::string>::iterator it = list.begin(); it != list.end(); ++it) {
    if (content == readFile(*it)) {
      std::cout << "#Removing " << file << " (duplicate of " << *it << ").\n";
      return true;
    }
  }
  return false;
}

/*
  void rmDup(std::list<std::string>&list)
  input: std::list<std::string>
  output: none
  Description: check the list to delete all identical files but one.
 */
void rmDup(std::list<std::string> & list) {
  size_t size = list.size();
  for (size_t i = 0; i < size; i++) {
    std::string file = list.front();
    list.pop_front();
    if (findIdentical(file, list)) {
      std::cout << "rm " << file << std::endl;
    }
  }
}

/*
  system call
  Description: each time found a new file, add it into hash table
 */
static int display_info(const char * fpath,
                        const struct stat * sb,
                        int tflag,
                        struct FTW * ftwbuf) {
  if (tflag == FTW_SL) {
    return 0;
  }
  else if (tflag == FTW_F) {
    addToHashTable(fpath);
  }
  return 0; /* To tell nftw() to continue */
}

int main(int argc, char ** argv) {
  if (argc == 1) {
    std::cerr << "Usage: ./" << argv[0] << " directories" << std::endl;
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) {
    int flags = 0;
    flags |= FTW_DEPTH;
    flags |= FTW_PHYS;
    if (nftw(argv[i], display_info, 20, flags) == -1) {
      perror("nftw");
      exit(EXIT_FAILURE);
    }
  }

  std::cout << "#!/bin/bash" << std::endl;

  for (size_t i = 0; i < H_Size; i++) {
    if (table[i].size() > 1) {
      rmDup(table[i]);
    }
  }
  return EXIT_SUCCESS;
}
