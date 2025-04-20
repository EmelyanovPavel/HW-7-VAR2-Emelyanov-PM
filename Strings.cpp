//Topic 7. Strings.

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <unordered_map>

//Task 1.
//2)Replace each digit in the string with a letter of the Latin alphabet. 0 on a, 1 on b, 2 on c, etc.

std::string replaceDigitsWithLetters(const std::string& input) {
    std::string result = input;

    //go through each character in the string
    for (size_t i = 0; i < result.length(); ++i) {
        //Checking whether the character is a digit
        if (isdigit(result[i])) {
            // Converting a digit to a letter: '0' = 48 in ASCII, 'a' = 97 in ASCII
            // The difference between them is 48, so we subtract 48 and add 97
            result[i] = 'a' + (result[i] - '0');
        }
    }

    return result;
}

void task1() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string result = replaceDigitsWithLetters(input);

    std::cout << "Result: " << result << std::endl;
}

//Task 2.
// Find out if there are two adjacent identical characters in the string. If available, delete all these pairs.

void task2() {

    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::unordered_map<char, int> charCount;
    
    //Counting duplicate characters
    for (char c : input) {
        if (charCount.find(c) != charCount.end()) {
            charCount[c]++;
        }
        else {
            charCount[c] = 1;
        }
    }
    //Forming a string without repeating characters
    std::string result;
    for (char c : input) {
        if (charCount[c] == 1) {
            result += c;
        }
    }
    std::cout << "New string: " << result << std::endl;
}

int main()
{
    task1();
    task2();
    return 0;
}
