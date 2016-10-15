#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

void main(){
	stack<std::string> eq;
	std::string input;
	std::cout << "postfix eq : ";
	std::cin >> input;
	double sum = 0;

	for (int i = 0; i < input.length(); i++){
		switch (input.at(i)){
		case '+':
			sum = std::stod(eq.pop()) + std::stod(eq.pop());
			eq.push(std::to_string(sum));
			break;
		case '-':
			sum = std::stod(eq.pop()) - std::stod(eq.pop());
			eq.push(std::to_string(sum));
			break;
		case '*':
			sum = std::stod(eq.pop()) * std::stod(eq.pop());
			eq.push(std::to_string(sum));
			break;
		case '/':
			sum = std::stod(eq.pop()) / std::stod(eq.pop());
			eq.push(std::to_string(sum));
			break;
		case '^':
			sum = pow(std::stod(eq.pop()), std::stod(eq.pop()));
			eq.push(std::to_string(sum));
			break;
		default:
			std::string temp = "";
			temp += input.at(i);
			eq.push(temp);
			break;
		}
	}

	std::cout << "result : " << eq.pop() << std::endl;
	system("pause");
}