#include <iostream>
#include <string>
using namespace std;

int top = 0;
string stack[32];
string str;

bool chkDigit(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}

	return true;
}

int retDigit(string s) {
	int num = s[0] - '0';

	for (int i = 1; i < s.size(); i++) {
		num = num * 10 + s[i] - '0';
	}

	return num;
}

int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		stack[top] = str[i];

		if (top != 0) {
			if (!stack[top].compare(")") && !stack[top - 1].compare("(")) {
				stack[--top] = "2";
			} 
			else if (!stack[top].compare("]") && !stack[top - 1].compare("[")) {
				stack[--top] = "3";
			}
			else if (!stack[top].compare(")") && chkDigit(stack[top - 1]) && !stack[top - 2].compare("(")) {
				stack[top - 2] = to_string(retDigit(stack[top - 1]) * 2);
				top -= 2;
			}
			else if (!stack[top].compare("]") && chkDigit(stack[top - 1]) && !stack[top - 2].compare("[")) {
				stack[top - 2] = to_string(retDigit(stack[top - 1]) * 3);
				top -= 2;
			}

			if (chkDigit(stack[top - 1]) && chkDigit(stack[top])) {
				stack[top - 1] = to_string(retDigit(stack[top - 1]) + retDigit(stack[top]));
				top--;
			}
		}
		top++;
	}

	if (top == 1 && chkDigit(stack[0])) {
		cout << stack[0] << endl;
	}
	else {
		cout << "0\n";
	}

	return 0;
}