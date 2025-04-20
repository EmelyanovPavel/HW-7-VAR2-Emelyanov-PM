#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <unordered_map>

//Task 1.
//2) �������� ������ ����� � ������ �� ����� ���������� ��������. 0 �� a, 1 �� b, 2 �� c � �.�.

std::string replaceDigitsWithLetters(const std::string& input) {
    std::string result = input;

    // �������� �� ������� ������� � ������
    for (size_t i = 0; i < result.length(); ++i) {
        // ���������, �������� �� ������ ������
        if (isdigit(result[i])) {
            // ����������� ����� � �����:
            // '0' = 48 � ASCII, 'a' = 97 � ASCII
            // ������� ����� ���� 48, ������� �������� 48 � ���������� 97
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
//��������, ������� �� � ������ ��� ������������� ���������� �������. ���� �������, �� ������� ��� ������ ����.
// Find out if there are two adjacent identical characters in the string. If available, delete all these pairs.

void task2() {

    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::unordered_map<char, int> charCount;
    // ������� ������������� ��������
    for (char c : input) {
        if (charCount.find(c) != charCount.end()) {
            charCount[c]++;
        }
        else {
            charCount[c] = 1;
        }
    }
    // ������������ ������ ��� ������������� �������� 
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

