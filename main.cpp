#include <iostream>
#include <sstream>

uint64_t fibonacci(uint64_t i) {
  uint64_t a[2] = {1, 1};
  while (i-- > 2)
    a[i & 1] = a[0] + a[1];
  return a[0];
}

uint64_t string2ulong(const std::string& ref) {
  uint64_t result;
  std::string s(ref);
  s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);
  std::stringstream ss(s);
  ss >> result;
  if (!ss.eof())
    throw std::runtime_error("Argument is not of type uint64_t.");
  return result;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Wrong number of arguments." << std::endl;
    return 1;
  }
  try {
    uint64_t firstArg = string2ulong(argv[1]);
    std::cout << fibonacci(firstArg) << std::endl;
  } catch(std::runtime_error& error) {
    std::cerr << error.what() << std::endl;
    return 1;
  }
  return 0;
}
