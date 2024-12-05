#include "iter.hpp"
#include <iostream>
#include <string>

void doubleValue(int& x) {
    x *= 2;
}

void printValue(const int& x) {
    std::cout << x << " ";
}

void capitalizeChar(char& c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
}


void printString(const std::string& str) {
    std::cout << str << " ";
}

int main() {

    int numbers[] = {1, 2, 3, 4, 5};
    std::size_t numbersLength = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original numbers: ";
    iter(numbers, numbersLength, printValue);
    std::cout << "\n";

    iter(numbers, numbersLength, doubleValue);

    std::cout << "Doubled numbers: ";
    iter(numbers, numbersLength, printValue);
    std::cout << "\n\n";

    char chars[] = {'h', 'e', 'l', 'l', 'o'};
    std::size_t charsLength = sizeof(chars) / sizeof(chars[0]);

    std::cout << "Original characters: ";
    iter(chars, charsLength, [](const char& c) { std::cout << c; });
    std::cout << "\n";

    iter(chars, charsLength, capitalizeChar);

    std::cout << "Capitalized characters: ";
    iter(chars, charsLength, [](const char& c) { std::cout << c; });
    std::cout << "\n\n";

    std::string strings[] = {"hello", "world", "cpp"};
    std::size_t stringsLength = sizeof(strings) / sizeof(strings[0]);

    std::cout << "Strings: ";
    iter(strings, stringsLength, printString);
    std::cout << "\n";

    return 0;
}
