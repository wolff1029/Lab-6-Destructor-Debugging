#include <iostream>
#include "myExpressionTree.hpp"
#include "ExpressionNode.hpp"

using namespace std;  //introduces namespace std

int main()
{	
	//string theInput1 = "2+3*5-6=";
	//string theInput1 = "2+3-5=";
	string theInput = "3+4*5/6=";
	//string theInput = "(3/2)*(4/2)";
	//string theInput2 = "11/3+92-4*6/12-16=";
	//string theInput3 = "234+34*65=";
	//string theInput4 = "(12+3)*(56/2)/(34-4)=";
	//string theInput5 = "25*2+30-5=";
	//string theInput6 = "100*2/25+5*4=";

	myExpressionTree t;
	
	myExpressionTree t2(theInput);
	
	cout << "t2 input string is " << t2.getInput() << endl;
	//cout << "t2 postfix input string is " << t2.getPostFixInput() << endl;
	
	// cout << "Before build the value of tree is " << t2.evaluate() << endl << endl;
	
	t2.build();

	// cout << "In-order traversal yields: ";
	// t2.printIn();
	// cout << endl << endl;
	
	// cout << "Post-order traversal yields: ";
	// t2.printPost();
	// cout << endl << endl;
	
	// cout << "Pre-order traversal yields: ";
	// t2.printPre();
	// cout << endl << endl;
	
	// cout << "After build the value of tree is " << t2.evaluate() << endl << endl;
	
	// cout << "Levels is: " << t2.getLevels() << endl;
	
	//t2.prettyPrint();
	//cout << endl;
	

}

	