#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"
#include "queue.h"

void postfix(std::string& input, queue<std::string>& postf);
int weight_dec(char& val);

void main(){
	stack<std::string> eq;
	queue<std::string> postf;
	std::string input;
	std::cout << "postfix eq : ";
	std::cin >> input;
	double sum = 0;

	postfix(input, postf);
	postf.print();
	/*
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

	std::cout << "result : " << eq.pop() << std::endl;*/
	system("pause");
}

void postfix(std::string& input, queue<std::string>& postf){
	stack<std::string> temp;
	for (int i = 0; i < input.length(); i++){
		if (input.at(i) == ')'){	// pop until a left parenthesis exits the stack
			for (int j = 0; j < temp.sizeis(); j++){
				postf.push(temp.pop());
			}
		}
		else if (weight_dec(input.at(i)) <= 0) // operand immediately goes to output
			postf.push(std::to_string(input.at(i)));
		else if (temp.sizeis()>0 && weight_dec(input.at(i)) < weight_dec(temp.top().at(0)) && temp.top().at(0) != '('){ // pop all stack symbols until met symbol of lower precedence
			int s = temp.sizeis();
			for (int j = 0; j < s; j++){
				postf.push(temp.pop());
			}
			temp.push(std::to_string(input.at(i)));
		}
		else if (temp.sizeis()>0 && weight_dec(input.at(i)) == weight_dec(temp.top().at(0)) && temp.top().at(0) != '('){ // equal precedence
			if (weight_dec(input.at(i)) < 5){ // left associative equal precedence pop once
				postf.push(temp.pop());
			}
			temp.push(std::to_string(input.at(i))); // push current operator(for left and right)
		}
		else if (weight_dec(input.at(i))>0) // EoI : pop all remaining operators
			temp.push(std::to_string(input.at(i)));
	}
	int s = temp.sizeis();
	for (int j = 0; j < s; j++){
		postf.push(temp.pop());
	}

}

int weight_dec(char& val){
	switch (val){
	case'+':case'-': return 1;
	case'*':case'/': return 3;
	case'^': return 6;
	case')': return 0;
	case'(': return 100;
	default: return 0;
	}
}