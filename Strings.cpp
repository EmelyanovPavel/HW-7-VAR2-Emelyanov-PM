#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <unordered_map>

//Task 1.
//2) Заменить каждую цифру в строке на букву латинского алфавита. 0 на a, 1 на b, 2 на c и т.д.

std::string replaceDigitsWithLetters(const std::string& input) {
    std::string result = input;

    // Проходим по каждому символу в строке
    for (size_t i = 0; i < result.length(); ++i) {
        // Проверяем, является ли символ цифрой
        if (isdigit(result[i])) {
            // Преобразуем цифру в букву:
            // '0' = 48 в ASCII, 'a' = 97 в ASCII
            // Разница между ними 48, поэтому вычитаем 48 и прибавляем 97
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
//Выяснить, имеются ли в строке два соседствующих одинаковых символа. Если имеются, то удалить все данные пары.
// Find out if there are two adjacent identical characters in the string. If available, delete all these pairs.

void task2() {

    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::unordered_map<char, int> charCount;
    // Подсчёт повторяющихся символов
    for (char c : input) {
        if (charCount.find(c) != charCount.end()) {
            charCount[c]++;
        }
        else {
            charCount[c] = 1;
        }
    }
    // Формирование строки без повторяющихся символов 
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

