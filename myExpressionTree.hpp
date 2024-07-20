#ifndef MYEXPRESSIONTREE_H_
#define MYEXPRESSIONTREE_H_

#include<iostream>
#include<stack>
#include<cstdlib>
#include<cctype>
#include "ExpressionNode.hpp"

using namespace std;

//used to determine operator precedence
enum operatorType {SUB = 0, ADD = 0, DIV = 1, MULT = 1};

//class that simulates an expression tree data structure
class myExpressionTree
{
	private:
	
	//keeps track of the number of levels of the tree	
	int levels;	
	
	string input;	//assume the string will only contain positive integers and
					//the math operations +,-,*,/ and the string
					//will be in infix notation, for example 2+3*5=, 
					//also assume each expression ends with the = symbol
	
	//Node that points to the root of the expression tree
	ExpressionNode *root;
	
	//stack used to build expression tree
	stack<ExpressionNode *> theNodes;	
	
	
	//deallocates the memory space occupied by the binary tree
	void destroyTree() {destroy(root);}
	
	//Recursive helper function that deallocates the memory space occupied by the 
	//expression tree given the root node
	void destroy(ExpressionNode* start){
		if(start != nullptr){
			delete start;
		}

	};
	
	
	
	public:
		//create any other constructors or methods you feel are needed to implement
		//the class accordingly
		
		//destructor for memory management
		~myExpressionTree() { destroyTree(); }
		
		//default constructor
		myExpressionTree() {root = NULL, levels = 0, input = "";}
		
		//assignment constructor that sets input
		myExpressionTree(string &str) {root = NULL, levels = 0, input = str;}
		
		//returns the input string that stores the infix expression
		string getInput() {return input;}
		
		//resets the input string that stores the infix expression
		void resetInput(const string &str) {input = str;}
		
		//creates the expression tree from the infix expression stored in input
		void build(){

				string left = "Left child";
				ConstantNode* leftNode = new ConstantNode(left);

				string right = "Right child";
				ConstantNode* rightNode = new ConstantNode(right);

				string s = "the root";
				OperatorNode* newNode = new OperatorNode(s, leftNode, rightNode);
				root = newNode;
		};
		
		//prints the tree using pre-order traversal
		void printPre(ExpressionNode * start);
		
		//prints the tree using in-order traversal
		void printIn(ExpressionNode *start);
		
		//prints the tree using post-order traversal
		void printPost(ExpressionNode * start);
		
		//evaluates the actual value of the input string
		//Postcondition: Assuming the input string is a valid infix expression,
		//the actual value of the math expression is returned
		int evaluate();
		
		//For 10% extra credit on this project write a prettyPrint function
		//that prints the binary tree how it would look on paper
};

#endif /* MYEXPRESSIONTREE_H_ */



	