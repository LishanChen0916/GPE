#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <stdlib.h>

using namespace std;

void eval(char op, stack<int>& operands) {
	int tmp1, tmp2, res = 0;
	tmp1 = operands.top();
	operands.pop();
	tmp2 = operands.top();
	operands.pop();
	switch (op) {
	case '+': res = tmp1 + tmp2;
		break;
	case '-': res = tmp1 - tmp2;
		break;
	case '*': res = tmp1 * tmp2;
		break;
	case '/': res = tmp1 / tmp2;
		break;
	case '%': res = tmp1 % tmp2;
		break;
	}
	operands.push(res);
}

int main() {
	while (true) {
		char inputs[1024];
		stack<int> operands;
		
		cin.getline(inputs, 1024);
		if (inputs[0] == '.') { break; }

		bool illegal = false;
		for (int i = strlen(inputs) - 1; i >= 0; i--) {
			if (illegal == true) { break; }
			switch (inputs[i]) {
			case ' ': continue;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
				if (operands.size() <= 1) { 
					illegal = true;
					cout << "illegal" << endl; 
				}
				else { eval(inputs[i], operands); }
				break;
			default:
				int pow = 1;
				int operand = 0;
				while (inputs[i] <= '9' && inputs[i] >= '0') {
					operand += (inputs[i] - '0') * pow;
					pow *= 10;
					i--;
				}
				operands.push(operand);
				break;
			}
		}

		if (!illegal) { cout << operands.top() << endl; }
	}

	return 0;
}