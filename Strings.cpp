//Topic 7. Strings.

#include <iostream>

// //Task 1.
// //2)Replace each digit in the string with a letter of the Latin alphabet. 0 on a, 1 on b, 2 on c, etc.

// //Function for replacing numbers with letters
void task1()
{
    // Создаем массив для входной строки
    char input[100];
    
    // Получаем строку от пользователя
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

// //Task 2.
// //2) Find out if there are two adjacent identical characters in the string. If available, delete all these pairs.

//Function for calculating the string length
int strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

//Function for deleting pairs of identical characters
void removeAdjacentPairs(char* str) {
    int length = strlen(str);
    
    //If the string is empty or contains only one character
    if (length <= 1) {
        return;
    }
    
    int writeIndex = 0;  //Index for writing new characters
    
    //Go through the line
    for (int readIndex = 0; readIndex < length; readIndex++) {
        //If the current character is not equal to the next or it is the last character
        if (readIndex == length - 1 || str[readIndex] != str[readIndex + 1]) {
            str[writeIndex++] = str[readIndex];
        }
        //If you find a pair of identical characters, skip both of them
        else {
            readIndex++;  //Skip the second character from the pair
        }
    }
    
    //Ending the string with a null character
    str[writeIndex] = '\0';
}

void task2() {
    char input[100];
    
    std::cout << "Enter the string: ";
    std::cin.getline(input, 100);
    
    removeAdjacentPairs(input);
    
    std::cout << "The string after deleting symbols: " << input << std::endl;
}

int main()
{
    
    task1();
    task2();
    
    return 0;
    
}
