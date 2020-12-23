#include <string>
#include <iostream>

std::string spinWords(const std::string &str)
{
    std::string string = str;
    std::string word;
    for (size_t i = 0; i < str.length() + 1; i++)
    {
        if (str[i] != ' ') word.insert(0, 1, str[i]);
        if ( i == str.length() || str[i + 1] == ' ') {
            if (word.length() > 4) string.replace(i - word.length(), word.length(), word);
            word = "";
        }
    }
    return string;
}

int main(int argc, char const *argv[])
{
    std::cout << spinWords("Welcome") << std::endl;
    return 0;
}
