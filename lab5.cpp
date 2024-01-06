//============================================================================
// Name         : lab5.cpp
// Author       : 
// Version      : 1.0
// Date Created : 
// Date Modified: 
// Copyright    : All rights are reserved
// Description  : Convert Infix expression to PostFix and then evaluate it
//============================================================================
#include<iostream>
#include<string>
#include<exception>
#include<math.h>
#include<ctype.h>

using namespace std;

bool isOperator(char); //Function which checks if the input char is an operator
int convertOpToInt (char); //Function which converts operators into int so their precdence can be compared
bool isleq(char, char); //Function which compare two operators  and return True if first operator has less or equal predence than the right operator
string infix2postfix(string);   //Function which converts an infix notaiton into a postfix notation (lab4)
float evaluate(string postfix);	 //Function which will evaluate a PostfixExpression and return the result
bool isBalanced(string expression); // Funciton which will check for balanced parentheses 

//==============CStack Class===============
//declare the Cstack class here




template <typename E>
class CStack{

	private:
		E * arr;
		int ptr;
	public:
		CStack(){
			arr = new E[1]; 
			ptr = 0;
		}

		void push(E a){
			arr[ptr] = a;
			refresharray(arr,ptr);
			//display();
		}

		void display(){
			for(int i = 0; i < ptr; i++){
				cout << ">> " <<  arr[i] << endl;
			} 
		}

		void refresharray(E * arr, int& ptr){
			E * a = NULL;
			a = new E[ptr+1];
			for(int i = 0; i < ptr; i++){
				a[i] = arr[i];
			}
			ptr += 1; 
			arr =  a;
		}

		void pop(){
			//remember doing the exception shit
			try
			{

				if(empty())
					throw string("the stack is empty");	
				ptr--;
			}

			catch(string e)
			{
				cout<<e;
			}
			//arr[ptr] = NULL;
		}

		E top(){
			///if (empty()) throw exception("Top of empty stack");
			try
			{

				if(empty())
					throw string("the stack is empty");	
				return (arr[ptr-1]); 
			}

			catch(string e)
			{
				cout<<e;
			}

		return 0;
			
		}

		int size(){
			return ptr;
		}

		bool empty(){
			return (ptr == 0)? true:false;
		}

};

//=============Main funciton ==============
int main()
{
	CStack <string> u;
	u.push("p");
	//u.display();
	u.pop();

	while(true)
	{
		string infix;  						//Infix expression
		cout<<"Enter an Infix Expression: ";
		cin>>infix;
		try
		{
			if(infix=="exit") 
				break;
			
			else if(!isBalanced(infix)) 
			{
				cout<<"Expression is not Balanced "<<endl;
				continue;
			}

			string postfix = infix2postfix(infix);	//Postfix Expression
			cout<<"The postfix form is: "<<postfix<<endl;
			float ans=evaluate(postfix);			//evaluate the postfix Expresion
			cout<<infix<<"="<<ans<<endl;		//print the final answer
		}
		catch(exception &e)
		{
			cout<<"Exception: "<<e.what()<<endl;
		}
	}

	return EXIT_SUCCESS;
}
//=====================================================================
bool isOperator(char ch)
{
	if( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		return true;
	else
		return false;

}
//Function which converts operators into int so their precdence can be compared
int convertOpToInt (char ch)
{
    if (ch=='+' || ch=='-') return 1;
    if (ch=='*' || ch=='/') return 2;
    if (ch=='^') return 3;
    return 0;
}
//Helper Function which compare two operators and return True if first operator
//has less or equal predence than the right operator
bool isleq(char opA, char opB)
{
	return (convertOpToInt(opA)<=convertOpToInt(opB));
}

//Funciton which will check for balanced parentheses 
bool isBalanced(string expression)
{	
	int count(0), counterCount(0);
	for(int i = 0; i < expression.size() ; i++){
		if(expression[i] == '('){
			count++;
		}
		if(expression[i] == ')'){
			counterCount++;
		}
	}
	return (count == counterCount)? true:false;
}

// Function which converts an Infix Notaiton to a Postfix notation
string infix2postfix(string infix)
{

	//0.    Create a stack of type char to store operators/parenthesis
	CStack <char> j;
	string POSTFIX = "";

	//1.	Push “(“onto Stack, and add “)” to the end of INFIX.
	//j.push('('); infix = infix + ')';
	//2.	Scan INFIX from left to right and repeat Step 3 to 6 for each element of X 
	//until the Stack is empty.3.	
	
	for(int counter = 0; counter < infix.size(); counter++){
		if( !isOperator(infix[counter]) && infix[counter] != '(' && infix[counter] != ')'){
			POSTFIX += infix[counter];

		}else if(infix[counter] == '('){
			j.push('(');

		}else if(infix[counter] == ')'){
			while(j.top() != '('){
				POSTFIX += j.top();
				j.pop();
			}
			j.pop();
		
		}else if(isOperator(infix[counter])){
			while( !j.empty() && isleq(infix[counter],j.top())){
				POSTFIX += j.top();
				j.pop();
			}
			j.push(infix[counter]);
		
		}	
	}


	while(!j.empty()){
		POSTFIX += j.top();
		j.pop();
	}


	return POSTFIX;
	// a+b*c
	// 

	//3.	If an operand is found, add it to POSTFIX.
	//4.	If a left parenthesis is found, push it onto Stack.
	//5.	If an operator is found, then: 
			//a.	Repeatedly pop from Stack and add to POSTFIX each operator (on the top of Stack) 
				//which has the same precedence as or higher precedence than operator.
			//b.	Push the operator onto Stack.
	//.6.	If a ")" is found, then: 
			//a.	Repeatedly pop from Stack and add to POSTFIX each operator 
			//(on the top of Stack) until a "(" found.
			//b.	Remove(pop) the "(" from the stack
}
// //Function which will evaluate a PostfixExpression and return the result


float calc(float a, float b, char o){
	float ans;
	if(o == '+')
	{
		ans = a + b;
	}
	else if(o == '-')
	{
		ans = b - a;
	}
	else if(o == '*')
	{
		ans = a * b;
	}
	else if(o == '/')
	{
		ans = a / b;
	}
	else if(o == '^')
	{
		ans = pow(b,a);
	}
	return ans;
}



float evaluate(string postfix)		
{	
	//1. Create a stack of type float to store the operands
	CStack <float>j; float result;
	//2. Scan the postfix expression from left to right for every element
	
	//cout << "---" << j.top() << endl;;
	
	for(int counter = 0; counter < postfix.size(); counter++){
		if(!isOperator(postfix[counter])){
			//cout << ">>>" << postfix[counter] << endl;
			float aa =  postfix[counter] - '0';
			//cout << "--" << aa << endl;
			j.push(aa);
			//cout << j.top() << endl;
		}else if(isOperator(postfix[counter])){
			float a = j.top();
			j.pop();
			float b = j.top();
			j.pop();
			result = calc(a,b,postfix[counter]);
			//cout << a << " "<< b << " " << result << endl;
			j.push(result);
		}

	}
	//	 a. if an operand is found push it to the stack
	//   b. if an operator is found pop 2 elements from the stack,
	//      apply the operator on it and push the result back to the stack
	//3. return the value from the top of the stack (i.e. the final answer)
	return j.top();
}