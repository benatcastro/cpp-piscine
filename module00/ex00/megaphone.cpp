#include <iostream>
#include <string>

void upperPrint(const char *argv) {
  std::string str(argv);
  std::string::iterator it;

  for (auto & c: str) c = toupper(c);
  std::cout << str << std::endl;
}

int main (int argc, char *argv[]) {
  if (argc < 2)
    std::cout << "* LOUD AND UNVEREABLE NOISE *" << std::endl;
  else
  for(int i = 1; i < argc; i++)
      upperPrint(argv[i]);
}
