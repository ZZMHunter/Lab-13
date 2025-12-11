/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab 13

    Task A: Function that prints all numbers in range left ≤   x   ≤ right, separated by spaces.
    Task B: Function that computes the sum of all numbers in range left ≤  x  ≤ right.
    Task C: Function which receives an array (as a pointer to its first element) and the size of the array,
            and should return the sum of its elements.
    Task D: Function which returns true if all characters in the string are letters and digits, otherwise returns false.
    Task E: Function which returns true if the string is a sequence of nested parentheses:
*/

#include <iostream>
#include <string>
#include <cctype>

//A
void printRange(int left, int right){
    if (left == right){
        std::cout << left << " ";
        return;
    }else{
        std::cout << left << " ";
        printRange(left+1,right);
    }
}
//B 
int sumRange(int left, int right){
    if (left == right){
        return right;
    }else{
        return left + sumRange(left+1, right);
    }
}
//C
int sumArray(int *arr, int size){
    if (size-1 == 0){
        return arr[0];
    }else{
        return arr[size-1] + sumArray(arr,size-1);
    }
}
//D
bool isAlphanumeric(std::string s){
    if (s == ""){
        return true;
    }
    if (s.length() == 1){
        return isalnum(s[0]);
    }else{
        return isalnum(s[s.length()-1]) && isAlphanumeric(s.substr(0, s.length()-1));
    }
}
//E
bool nestedParens(std::string s){
    if (s == ""){
        return true;
    }else if (s[0]=='(' && s[s.length()-1]==')'){
        return nestedParens(s.substr(1,s.length()-2));
    }
    return false;
}
int main() {
    std::cout << nestedParens("((()))") << std::endl;      // true (1)
    std::cout << nestedParens("()") << std::endl;          // true (1)
    std::cout << nestedParens("") << std::endl;            // true (1)

    std::cout << nestedParens("(((") << std::endl;         // false (0)
    std::cout << nestedParens("(()") << std::endl;         // false (0)
    std::cout << nestedParens(")(") << std::endl;          // false (0)
    std::cout << nestedParens("a(b)c") << std::endl;       // false (0)
}