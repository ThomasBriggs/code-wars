#include <string>
#include <iostream>

std::string encrypt(std::string text, int n)
{
    if (n <= 0) return text;
    std::string left;
    std::string right;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < text.size(); j++)
        {
            if (j % 2 != 0) left += text.at(j);
            else right += text.at(j);
        }
        text = left + right;
        left = "", right = "";
    }
    return text;
}

std::string decrypt(std::string encryptedText, int n)
{
    if (n <= 0) return encryptedText;
    std::string left;
    std::string right;
    for (size_t i = 0; i < n; i++)
    {
        left = encryptedText.substr(0, encryptedText.size()/2);
        right = encryptedText.substr(encryptedText.size()/2, encryptedText.back());
        int size = encryptedText.size();
        encryptedText = "";
        for (size_t j = 0; j < size; j++)
        {
            if (j % 2 != 0) {
                encryptedText += left.at(0);
                left.erase(0, 1);
            } else {
                encryptedText += right.at(0);
                right.erase(0, 1);
            }
        }

    }
    return encryptedText;
}

int main(int argc, char const *argv[])
{
    std::cout << encrypt("", -1) << std::endl;
    std::cout << decrypt("hskt svr neetn!Ti aai eyitrsig", 1) << std::endl;
    return 0;
}

