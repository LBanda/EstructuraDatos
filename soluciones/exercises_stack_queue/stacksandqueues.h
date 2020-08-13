/*
 * saq.h
 *
 *  Created on: 10/08/2015
 *      Author: pperezm
 */

#ifndef STACKSANDQUEUES_H_
#define STACKSANDQUEUES_H_

#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <stack>

using namespace std;

class StacksAndQueues {
private:
	queue<string> tokenize(string);
	bool hasHigherPrecedence(const string&, const string&);

public:
	bool balancedBrackets(const string&);
	queue<int> merge(const queue<int>&, const queue<int>&);
	string convertInfixToPostfix(const string&);
};

queue<string> StacksAndQueues::tokenize(string str) {
	int i = 0;
	int length = str.size();
	string aux;
	queue<string> result;

	while (i < length) {
		if (isdigit(str[i])) {
			aux.clear();
			do {
				aux += str[i];
				i++;
			} while(isdigit(str[i]));
			result.push(aux);
		} else if (isspace(str[i])) {
			i++;
		} else {
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}

bool StacksAndQueues::hasHigherPrecedence(const string &stackTop, const string &op) {
	return !((stackTop == string("+") || stackTop == string("-")) &&
			 (op == string("*")       || op == string("/")));
}

bool StacksAndQueues::balancedBrackets(const string &expr) {
	stack<char> s;
	char c;

	for (int i = 0; i < (int) expr.size(); i++) {
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
			s.push(expr[i]);
		} else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
			if (s.empty()) {
				return false;
			}
			c = s.top();
			s.pop();
			switch(expr[i]) {
			case ')' : if (c != '(') return false; break;
			case ']' : if (c != '[') return false; break;
			case '}' : if (c != '{') return false; break;
			}
		} else {
			// do nothing
		}
	}
	return (s.empty());
}

queue<int> StacksAndQueues::merge(const queue<int> &queue1, const queue<int> &queue2) {
	queue<int> q1(queue1);
	queue<int> q2(queue2);
	queue<int> result;
	int val1, val2;

	while (!q1.empty() && !q2.empty()) {
		val1 = q1.front();
		val2 = q2.front();
		if (val1 < val2) {
			result.push(val1);
			q1.pop();
		} else {
			result.push(val2);
			q2.pop();
		}
	}
	if (q1.empty()) {
		while (!q2.empty()) {
			result.push(q2.front());
			q2.pop();
		}
	} else if (q2.empty()) {
		while (!q1.empty()) {
			result.push(q1.front());
			q1.pop();
		}
	}
	return result;
}

string StacksAndQueues::convertInfixToPostfix(const string &expr) {
	queue<string> tokens = tokenize(expr);
	stack<string> s;
	queue<string> q;
	string aux;

	while(!tokens.empty()) {
		aux = tokens.front();
		tokens.pop();

		if (aux == "(") {
			s.push(aux);
		} else if (aux == "+" || aux == "-" || aux == "*" || aux == "/") {
			while (!s.empty() && s.top() != "(") {
				string c = s.top();
				if (!hasHigherPrecedence(c, aux)) {
					break;
				}
				s.pop();
				q.push(c);
			}
			s.push(aux);
		} else if (aux == ")") {
			while (!s.empty() && s.top() != "(") {
				q.push(s.top());
				s.pop();
			}
			if (!s.empty()) {
				s.pop();
			}
		} else {
			q.push(aux);
		}
	}

	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	aux = "";
	while (!q.empty()) {
		aux += q.front();
		q.pop();
		if (!q.empty()) {
			aux += " ";
		}
	}
	return aux;
}

#endif /* STACKSANDQUEUES_H_ */
