//Topic 7. Strings.

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

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
//2) Find out if there are two adjacent identical characters in the string. If available, delete all these pairs.

std::string removeAdjacentDuplicates(std::string s) {
    // Creating a new line for the result
    std::string result;
    
    // Go through all the characters of the source string
    for (size_t i = 0; i < s.length(); ++i) {
        
        //If it is not the last character and it matches the next one
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            
            //Skip both characters
            i++;
        } else {
            
            //Adding a character to the result
            result += s[i];
        }
    }
    
    return result;
}

void task2() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    
    std::string result = removeAdjacentDuplicates(input);
    
    std::cout << "New string: " << result << std::endl; 
}

int main()
{
    task1();
    task2();
    return 0;
}
