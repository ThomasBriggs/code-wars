#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#if defined(TAPE_SIZE)
#define DEFAULT_TAPE_SIZE TAPE_SIZE
#else
#define DEFAULT_TAPE_SIZE 5000
#endif // TAPE_SIZE

#if defined(TAPE_GROW_SIZE)
#define DEFAULT_TAPE_GROW_SIZE TAPE_GROW_SIZE
#else
#define DEFAULT_TAPE_GROW_SIZE 5000
#endif // TAPE_GROW_SIZE

bool findCloseBracket(const std::string& code, unsigned int& iTapeIndex)
{
    unsigned int count = 0;
    char c;
    while (iTapeIndex < code.size()) {
        iTapeIndex++;
        c = code.at(iTapeIndex);
        switch (c) {
        case '[':
            count++;
            break;
        case ']':
            if (count == 0) {
                iTapeIndex++;
                return true;
            }
            count--;
            break;
        }
    }
    return false;
}

bool findOpenBracket(const std::string& code, unsigned int& iTapeIndex)
{
    unsigned int count = 0;
    char c;
    while (iTapeIndex > 0) {
        iTapeIndex--;
        c = code.at(iTapeIndex);
        switch (c) {
        case ']':
            count++;
            break;
        case '[':
            if (count == 0) {
                iTapeIndex++;
                return true;
            }
            count--;
            break;
        }
    }
    return false;
}

std::string brainLuck(const std::string& code, const std::string& input)
{
    std::vector<uint8_t> memoryTape(DEFAULT_TAPE_SIZE, (uint8_t)0);

    unsigned int iTapeIndex = 0;
    unsigned int mTapeIndex = 0;
    unsigned int inputIndex = 0;
    std::stringstream output;
    bool setITape;

    while (iTapeIndex < code.size()) {
        setITape = false;
        char instruction = code.at(iTapeIndex);
        switch (instruction) {
        case '>':
            mTapeIndex++;
            if (mTapeIndex > memoryTape.size() - 1)
                memoryTape.insert(memoryTape.end(), DEFAULT_TAPE_GROW_SIZE, (uint8_t)0);
            break;
        case '<':
            mTapeIndex--;
            break;
        case '+':
            memoryTape[mTapeIndex]++;
            break;
        case '-':
            memoryTape[mTapeIndex]--;
            break;
        case '.':
            output << memoryTape[mTapeIndex];
            break;
        case ',':
            memoryTape[mTapeIndex] = input.at(inputIndex);
            inputIndex++;
            break;
        case '[':
            if (memoryTape[mTapeIndex] == 0) {
                findCloseBracket(code, iTapeIndex);
                setITape = true;
            }
            break;
        case ']':
            if (memoryTape[mTapeIndex] != 0) {
                findOpenBracket(code, iTapeIndex);
                setITape = true;
            }
            break;
        }
        if (!setITape)
            iTapeIndex++;
    }

    return output.str();
}

int main()
{

    std::string code;
    code.append(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.");

    std::string input;
    input.append(1, (char)17);
    input.append(1, (char)3);

    std::string output = brainLuck(code, input);

    std::cout.operator<<((char)output.at(0)) << '\n';
}
