#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
int main(int argc, char ** argv) {
  if (argc == 1) {
    std::vector<std::string> lines;
    std::string temp;
    while (getline(std::cin, temp)) {
      lines.push_back(temp);
    }
    std::sort(lines.begin(), lines.end());
    for (auto line : lines) {
      std::cout << line << std::endl;
    }
  }
  else {
    for (int i = 1; i < argc; i++) {
      std::vector<std::string> lines;
      std::ifstream ifs;
      ifs.open(argv[i], std::ifstream::in);
      if (ifs.is_open()) {
        std::string temp;
        while (getline(ifs, temp)) {
          lines.push_back(temp);
        }
        std::sort(lines.begin(), lines.end());
        for (auto line : lines) {
          std::cout << line << std::endl;
        }
        ifs.close();
      }

      else {
        std::cerr << "canot open file \"" << argv[i] << "\"" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
  }
  return EXIT_SUCCESS;
}
