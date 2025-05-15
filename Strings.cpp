//Topic 7. Strings.

#include <iostream>

// //Task 1.
// //2)Replace each digit in the string with a letter of the Latin alphabet. 0 on a, 1 on b, 2 on c, etc.

// //Function for replacing numbers with letters
void task1()
{
    // Creating an array for the input string
    char input[100];
    
    // Getting a string from the user
    std::cout << "Enter a string of numbers: ";
    std::cin.getline(input, 100);
    
    //go through each character of the string
    for(int i = 0; input[i] != '\0'; i++) {
        
        //Checking whether the character is a digit
        if(input[i] >= '0' && input[i] <= '9') {
            
            //Converting a digit to a letter
             // '0' in ASCII = 48, 'a' = 97
             // Difference between '0' and 'a' = 49
            input[i] = input[i] + 49;
        }
    }
    
    //Displaying the result
    std::cout << "The string after replacing symbols: " << input << std::endl;
}

// //Task 2. This assignment involves implementing a memory reallocating function to resize the source string for compression and to get rid of unnecessary memory during passing and processing.
// //2) Find out if there are two adjacent identical characters in the string. If available, delete all these pairs.

// Function for reallocating memory
char* reallocString(char* str, size_t newSize) 
{
    char* newStr = (char*)realloc(str, newSize + 1);
    if (newStr == NULL) 
    {
        std::cerr << "Memory allocation error!";
        exit(1);
    } 
    return newStr;
}

// Function for deleting pairs of identical characters
char* removeAdjacentDuplicates(char* str) {
    size_t len = 0;
    // Calculating the string length
    while (str[len] != '\0') len++;
    
    size_t newLen = len;
    size_t i = 0;
    
    // going through the string and look for pairs of identical characters
    while (i < newLen - 1) {
        if (str[i] == str[i + 1]) {
            //Finding the end of a sequence of identical characters
            size_t j = i + 1;
            while (j < newLen && str[j] == str[i]) j++;
            
            // Move the remaining characters to the left
            for (size_t k = i; k < newLen; k++) {
                str[k] = str[k + (j - i)];
            }
            
            // Updating the string length
            newLen -= (j - i);
            
            // Reallocating memory
            str = reallocString(str, newLen);
            
            // Go back a step to check
            if (i > 0) i--;
        } else {
            i++;
        }
    }
    
    // Adding a terminal character
    str[newLen] = '\0';
    return str;
}

void task2() {
    // Usage example
    char* input = (char*)malloc(100 * sizeof(char));
    std::cout << "Enter the string: ";
    fgets(input, 100, stdin);
    
    // Removing the newline character
    size_t len = 0;
    while (input[len] != '\0' && input[len] != '\n') len++;
    input[len] = '\0';
    
    // Deleting pairs of identical characters
    input = removeAdjacentDuplicates(input);
    
    std::cout << "The string after deleting pairs of identical characters: " << input;
    free(input);
}

int main()
{ 
    task1();
    task2();
    
    return 0;
}
