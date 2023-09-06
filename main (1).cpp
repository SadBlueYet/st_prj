#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>

using std::string;

std::pair<string, string> user_input();
bool check_numbers(const string& number);
string addition(std::pair<string, string> numbers);
void subtraction(std::pair<string, string> numbers);

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
    std::stack <int> result, upper_number, lower_number;
    
    if (numbers.first.length() >= numbers.second.length()){
        for (int i = 0; i < numbers.first.length(); i++)
            upper_number.push(numbers.first[i] - '0');
            
        for (int i = 0; i < numbers.second.length(); i++)
            lower_number.push(numbers.second[i] - '0');
    }else{
        for (int i = 0; i < numbers.second.length(); i++)
            upper_number.push(numbers.second[i] - '0');
            
        for (int i = 0; i < numbers.first.length(); i++)
            lower_number.push(numbers.first[i] - '0');
    }
    
    int number_in_mind = 0;
    
    while (!lower_number.empty()){
        int result_number = upper_number.top() + lower_number.top() + number_in_mind;
        if (result_number > 9){
            result.push(result_number % 10);
            number_in_mind = result_number / 10;
        }else{
            result.push(result_number);
            number_in_mind = 0;
        }
        upper_number.pop();
        lower_number.pop();
    }
    while(!upper_number.empty()){
        int result_number = upper_number.top() + number_in_mind;
        if (result_number > 9){
            result.push(result_number % 10);
            number_in_mind = result_number / 10;
        }else{
            result.push(result_number);
            number_in_mind = 0;
        }
        upper_number.pop();
      
    }
    if (number_in_mind != 0) result.push(number_in_mind);
    
    while (!result.empty()){
        std::cout << result.top();
        result.pop();
    }
    std::cout << '\n';
}

void subtraction(std::pair<string, string> numbers){
    std::stack <int> result;
    int len;
    
    numbers.first.length() >= numbers.second.length() ? len = numbers.first.length() : len = numbers.second.length();

    for (i = len; i >= 0; i--){
        up_number = numbers.first[i] - '0';
        low_number = numbers.second[i] - '0';
        
        if (up_number < low_number)
            result.push(up_number - low_number);
            
        else{
            if (numbers.first[i-1] != 0){
                //НУЖНО ЗДЕСЬ ДОПИСАТЬ. БЕРЕМ 10 У СЛЕД. ЭЛЕМЕНТА
            }
        }
        
    }
}