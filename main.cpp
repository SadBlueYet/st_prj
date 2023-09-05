#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <stack>

using std::string;

std::pair<string, string> user_input();
bool check_numbers(const string& number);
string addition(std::pair<string, string> numbers);
int main(){
    char user_choise;
    while(user_choise != '0'){
        std::pair<string, string> numbers = user_input();
        if(numbers.second == "Error"){
            std::cout << "It's not a number!\n";
        }else{
            std::cout << "Perfect!\n"; 
            addition(numbers);
        }
    }
    
    
}

std::pair<string, string> user_input(){
    std::pair<string, string> uppper_and_lower_numbers;
    
    std::cout << "Enter the first number\n>>";
    std::cin >> uppper_and_lower_numbers.first;
    if (!check_numbers(uppper_and_lower_numbers.first)) return std::make_pair("1", "Error");
    
    
    std::cout << "Enter the second number\n>>";
    std::cin >> uppper_and_lower_numbers.second;
    
    if (!check_numbers(uppper_and_lower_numbers.second)) return std::make_pair("1", "Error");
    
    
    return uppper_and_lower_numbers;
}

bool check_numbers(const string& number){
    for (char const &c : number) {
        if (std::isdigit(c) == 0) return false;
    }

    return true;
}

string addition(std::pair<string, string> numbers){
    std::stack <int> result;
    int up_length;
    numbers.first.length() <= numbers.second.length() ? up_length = numbers.first.length() - 1: up_length = numbers.second.length() - 1;
    int number_in_mind = 0;
    for (int i = up_length; i >= 0; i--){
        int number = (numbers.first[i] - '0') + (numbers.second[i] - '0') + number_in_mind;
        if (number > 9) {
            int last_num = std::to_string(number)[1] - '0';
            number_in_mind = std::to_string(number)[0] - '0';
            result.push(last_num);
        }
    }
    
    result.push(number_in_mind);
    while (!result.empty()){
        std::cout << result.top();
        result.pop();
    }
    std::cout << '\n';
}

