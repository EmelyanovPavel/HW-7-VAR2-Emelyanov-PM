//Topic 7. Strings.

#include <iostream>
#include <cstdio>
#include <cstring>

//Task 1.
//2)Replace each digit in the string with a letter of the Latin alphabet. 0 on a, 1 on b, 2 on c, etc.

//Function for replacing numbers with letters
void replaceDigits(char* str) 
{
    
    //Go through each character of the string
    for (int i = 0; str[i] != '\0'; i++) 
    {
        
        //Checking whether the character is a digit
        if (str[i] >= '0' && str[i] <= '9') 
        {
            
            // Calculating the offset from ' 0 ' to 'a'
            // and replace the number with the corresponding letter
            str[i] = str[i] - '0' + 'a';
            
        }
    }
}

void task1() 
{
    
    //Usage example
    char input[100];
    std::cin.getline(input, 100);
    
    //Output the original string
    std::cout << "Source string: " << input;
    
    // Replacing numbers with letters
    replaceDigits(input);
    
    //Displaying the result
    std::cout << "\nString after replacing symbols: " << input << std::endl;
    
}

//Task 2.
//2) Find out if there are two adjacent identical characters in the string. If available, delete all these pairs.

void removeAdjacentDuplicates(char* str) 
{
    //If the string is empty or consists of a single character
    if (strlen(str) <= 1)
        return;

    //Creating two pointers: one for reading and one for writing
    char* read = str;
    char* write = str;
    
    //Go through the line
    while (*read) 
    {
        // If the current character is not equal to the next one
        if (*read != *(read + 1)) 
        {
            *write = *read;
            write++;
        }
        read++;
    }
    
    //Ending a new line with a null character
    *write = '\0';
}

void task2() 
{
    
    char str[100];
    
    std::cout << "Enter a string: ";
    std::cin.getline(str, 100);
    
    removeAdjacentDuplicates(str);
    
    std::cout << "\nString after deleting symbols pairs: " << str << std::endl;
    
}

int main()
{
    
    task1();
    task2();
    
    return 0;
    
}
