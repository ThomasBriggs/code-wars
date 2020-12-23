#include <string>
#include <iostream>

std::string to_camel_case(std::string text) {
  for (size_t i = 0; i < text.length(); i++)
  {
      if (text[i] == '-' || text[i] == '_') {
          text.erase(i, 1);
          text[i] = toupper(text[i]);
      }
  }
  return text;
}

int main(int argc, char const *argv[])
{
    std::cout << to_camel_case("this-is-a-test") << std::endl;
    return 0;
}
