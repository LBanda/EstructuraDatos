/*
 * evaltree.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef EVALTREE_H_
#define EVALTREE_H_

#include <cctype>
#include <string>

#include <sstream>
#include <queue>
#include <stack>
#include "exception.h"

class EvalTree;

class TreeNode {
private:
	char value;
	TreeNode *left, *right;

	bool isOperator() const;
	bool isVariable() const;
	bool isOperand() const;

public:
	TreeNode(char);
	TreeNode(char, TreeNode*, TreeNode*);
	int depth() const;
	void inorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void levelOrder(std::stringstream&) const;
	int howManyLeaves() const;
	char minValue() const;
	bool find(char) const;
	double eval(double x) const;
	TreeNode* derive() const;
	void removeChilds();
	TreeNode* copy() const;
	friend class EvalTree;
};

TreeNode::TreeNode(char c) {
  value = c; 
  left = 0; 
  right =0;
}

TreeNode::TreeNode(char c, TreeNode* le, TreeNode* ri) {
  value = c; 
  left = le; 
  right =ri;
}

bool TreeNode::isOperator() const {
	return ( value == '+' || value == '-'  || value == '*'  ||value == '/');
}

bool TreeNode::isVariable() const {
	return (value == 'x');
}

bool TreeNode::isOperand() const {
	return (value > '0' && value < '9');
}

int TreeNode::depth() const {
	int right_count = -1;
    int left_count = -1;
    int higher_count = -1;

	  if(left != 0){
        left_count = left->depth();
    }
	
    if(right != 0){
        right_count = right->depth();
    }
  

	higher_count = (left_count > right_count) ?  left_count:right_count;
	return (higher_count +1);
}

void TreeNode::inorder(std::stringstream &aux) const {
	if(left != 0){
        left->inorder(aux);
	}

	aux << value << " ";

	if(right != 0){
        right->inorder(aux);
	}
}

void TreeNode::postorder(std::stringstream &aux) const {
	if(left != 0){
        left->postorder(aux);
	}

	if(right != 0){
        right->postorder(aux);
	}

	aux << value << " ";
}

void TreeNode::preorder(std::stringstream &aux) const {
	aux << value << " ";

    if(left != 0){
        left->preorder(aux);
	}

	if(right != 0){
        right->preorder(aux);
	}
}

int TreeNode::howManyLeaves() const {
	int left_count = 0;
    int right_count = 0;
    int total_count = 0;

    if(left!=0){
       left_count = left->howManyLeaves();
    }


    if(right!=0){
       right_count = right->howManyLeaves();
    }


    total_count = left_count + right_count;


	return (total_count == 0)? 1 : total_count;
}

char TreeNode::minValue() const {
	char left_value = '9';
    char right_value = '9';
    char min_value = '9';

    if (isOperand()){
        min_value = value;
    } else if(isOperator()){
        if(left != 0){
          left_value = left->minValue();
        }
        if(right != 0){
          right_value = right->minValue();
        }
		min_value = (left_value < right_value)? left_value : right_value;
    }

	return min_value;
}

bool TreeNode::find(char val) const {
	bool found = false;

	if(value == val){
        return true;
	}

    if(left != 0){
        found = (found || left->find(val))? true : false;
    }

    if(right != 0){
        found = (found || right->find(val))? true : false;
    }

    return found;
}

double TreeNode::eval(double x) const {
	double left_value, right_value;
    if (isVariable()){
        return x;
    }

    if(isOperand()){
       return value - '0';
    }

    if(isOperator()){
        if(left != 0){
                left_value = left->eval(x);
        }

        if(right !=0){
                right_value = right->eval(x);
        }

        if (value == '*') return left_value * right_value;
        if (value == '+') return left_value + right_value;
        if (value == '-') return left_value - right_value;
        if (value == '/'){
                if(right_value == 0) throw IllegalAction();
                return left_value / right_value;}
    }
	return 0;
}

void TreeNode::removeChilds() {
  if(left != NULL){
         left->removeChilds();
            delete left;
            left =0;
        }

        if(right != NULL){
            right->removeChilds();
            delete right;
            right = 0;
        }
}

TreeNode* TreeNode::derive() const {
	return 0;
}

TreeNode* TreeNode::copy() const {
	return 0;
}

class EvalTree {
private:
	TreeNode *root;

	std::queue<std::string> tokenize(std::string);

public:
	EvalTree();
	EvalTree(std::string) throw (IllegalAction);
	~EvalTree();
	bool empty() const;
	int height() const;
	std::string inorder() const;
	std::string postorder() const;
	std::string preorder() const;
	std::string levelOrder() const;
	int howManyLeaves() const;
	char minValue() const throw (IllegalAction);
	bool find(char) const;
	double eval(double) const throw (IllegalAction) ;
	EvalTree* derive() const;
	void removeAll();
	bool isFull() const;
	int internalNodes() const;
	bool isPerfect() const;
	bool isDegenerate() const;
};

EvalTree::EvalTree() {
}

std::queue<std::string> EvalTree::tokenize(std::string str) {
	int i = 0;
	int length = str.size();
	std::string aux;
	std::queue<std::string> result;

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

EvalTree::EvalTree(std::string str) throw (IllegalAction) {
	root = 0;
	std::stack<TreeNode*> s;
	std::queue<std::string> tokens = tokenize(str);
	std::string aux;
	TreeNode *left, *right, *newNode;

	while (!tokens.empty()) {
		aux = tokens.front(); tokens.pop();
		if (aux == "+" || aux == "-" || aux == "*" || aux == "/") {
			if (s.empty()) {
				throw IllegalAction();
			}
			left = s.top(); s.pop();
			if (s.empty()) {
				throw IllegalAction();
			}
			right = s.top(); s.pop();
			newNode = new TreeNode(aux[0], left, right);
			s.push(newNode);
		} else if (aux[0] == 'x' || isdigit(aux[0])) {
			newNode = new TreeNode(aux[0]);
			s.push(newNode);
		}
	}
	newNode = s.top(); s.pop();
	if (!s.empty()) {
		throw IllegalAction();
	}
	root = newNode;
}

EvalTree::~EvalTree() {
}

bool EvalTree::empty() const {
}

int EvalTree::height() const {
	return 0;
}

std::string EvalTree::inorder() const {
	std::stringstream aux;

	return aux.str();
}

std::string EvalTree::preorder() const {
	std::stringstream aux;

	return aux.str();
}

std::string EvalTree::postorder() const {
	std::stringstream aux;

	return aux.str();
}

std::string EvalTree::levelOrder() const {
	std::stringstream aux;

	return aux.str();
}

int EvalTree::howManyLeaves() const {
	return 0;
}

char EvalTree::minValue() const throw (IllegalAction) {
	return '9';
}

bool EvalTree::find(char c) const {
	return false;
}

double EvalTree::eval(double x) const throw (IllegalAction) {
	return 0.0;
}

EvalTree* EvalTree::derive() const {
	return 0;
}

void EvalTree::removeAll() {
}
#endif /* EVALTREE_H_ */
