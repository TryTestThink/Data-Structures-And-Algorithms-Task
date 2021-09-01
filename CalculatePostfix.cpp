#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
float scanNum(char ch) {
   int value;
   value = ch;
   return float(value-'0');   
}
int value(char ch) {
    
	if(ch=='+' || ch=='-'){
		return 1;
	}

	else if(ch=='*' || ch=='/' ){
		return 2;
	}

	else if(ch=='^'){
		return 3;
	}

	else{
		return -1;
	}
}
int isOperand(char ch) {
   if(ch >= '0' && ch <= '9')
      return 1;   
   return -1;   
  
}
double 	Math(double op1, double op2, char op) {
	
   if(op == '+'){
      return op2+op1;
   }
  
   else if(op == '-'){
      return op2-op1;
   }
   
   else if(op == '*'){
      return op2*op1;
   }
   
   else if(op == '/'){
      return op2/op1;
   }
   
   else if(op == '^'){
      return pow(op2,op1);
   }
  
}
double postfixEval(string postfix) {
   int i, j;
   stack<float> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++) {
      if(value(*it) != -1) {
         i = stk.top();
         stk.pop();
         j = stk.top();
         stk.pop();
         stk.push(Math(i, j, *it));
      }else if(isOperand(*it) > 0) {
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}
main() {
   string expression = "32 * 56 *+";
   cout << "Result: "<<postfixEval(expression);
}
