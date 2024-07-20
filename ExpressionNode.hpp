#ifndef EXPRESSIONNODE_H_
#define EXPRESSIONNODE_H_

#include<iostream>
#include<cstdlib>
#include <iomanip>


using namespace std;
//P4 STUDENT FILE

//An "abstract" class that represents a math node of any type
//Every subclass of MathNode must define the function getValue()
//The keyword virtual means the function can change it's meaning in each subclass
//and the fact that it is set equal to zero implies that it has no definition
//in this class
//template <class type>
class ExpressionNode 
{
	protected:
		string parent;
		ExpressionNode *left;   // The left operand.
        ExpressionNode *right;  // The right operand.

	public: 
		// Returns the number value of this node.    
    	virtual int getValue() = 0; 
    	
    	//print with correct width spacing
    	virtual void printParent(int) = 0; 
    	
    	//destructor
		virtual ~ExpressionNode() {delete left; delete right;}
    
    	//returns parent node
    	string getParent() {return parent;};
    	
    	//returns left child
    	ExpressionNode* getLeft() { return left; }
    	
    	//returns right child
  		ExpressionNode* getRight() { return right; }
};
       

//A subclass of ExpressionNode that represents a math node that holds a number value  
class ConstantNode : public ExpressionNode
{     
    public:
    	// Constructor.  Create a node to hold number.
        ConstantNode(string theNumber) 
        { 
        	ExpressionNode::parent = theNumber;
        	ExpressionNode::left = NULL;
        	ExpressionNode::right = NULL;
        }
        
        //destructor
		~ConstantNode() {delete left; delete right;}
		
		//print with correct width spacing
    	void printParent(int n) { cout << setw(n) << getParent(); }
        
        //Returns the number value in the node
        int getValue(){
			return atoi( parent.c_str() );

		};       
}; 
        
//A subclass that represents a math node that holds a 
//binary operator +, -, *, / and pointers to expression nodes for the operands
class OperatorNode : public ExpressionNode 
{
	
    public:
    // Constructor.  Create a node to hold the operator.
    OperatorNode(string theOp, ExpressionNode *theLeft, ExpressionNode *theRight )
    {
    	ExpressionNode::parent = theOp;
    	ExpressionNode::left =theLeft;
    	ExpressionNode::right = theRight; 	
    }
    
     //destructor
	~OperatorNode() {delete left; delete right;}

	//print with correct width spacing
    void printParent(int n) { cout << setw(n) << getParent(); }

	// Returns the number value of this node if data is an integer   
        int getValue(){
			return atoi( parent.c_str() );

		};  
     	 
}; 


#endif /* EXPRESSIONNODE_H_ */



		
