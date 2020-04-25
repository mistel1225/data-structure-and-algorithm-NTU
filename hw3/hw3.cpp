#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;


bool compare(string &ope1, string &ope2){
	int Pope1, Pope2;
	if(ope1=="("&&ope1=="(")
		return 1;
	else if(ope1 == ope2 && (ope1!="!"&&ope1!="~"&&ope1!="(unary)+"&&ope1!="(unary)-"))
		return 0;
	else if(ope1=="(")
		Pope1 = 999;
	else if(ope1=="!"||ope1=="~"||ope1=="(unary)+"||ope1=="(unary)-")
		Pope1 = 14;
	else if(ope1=="*"||ope1=="/"||ope1=="%")
		Pope1 = 13;
	else if(ope1=="(binary)+"||ope1=="(binary)-")
		Pope1 = 12;
	else if(ope1=="<<"||ope1==">>")
		Pope1 = 11;
	else if(ope1=="=="||ope1=="!=")
		Pope1 = 10;
	else if(ope1=="&")
		Pope1 = 9;
	else if(ope1=="^")
		Pope1 = 8;
	else if(ope1=="|")
		Pope1 = 7;
	else if(ope1=="&&")
		Pope1 = 6;
	else if(ope1=="||")
		Pope1 = 5;
	
	if(ope2=="(")
		Pope2 = 0;
	else if(ope2=="!"||ope2=="~"||ope2=="(unary)+"||ope2=="(unary)-")
		Pope2 = 14;
	else if(ope2=="*"||ope2=="/"||ope2=="%")
		Pope2 = 13;
	else if(ope2=="(binary)+"||ope2=="(binary)-")
		Pope2 = 12;
	else if(ope2=="<<"||ope2==">>")
		Pope2 = 11;
	else if(ope2=="=="||ope2=="!=")
		Pope2 = 10;
	else if(ope2=="&")
		Pope2 = 9;
	else if(ope2=="^")
		Pope2 = 8;
	else if(ope2=="|")
		Pope2 = 7;
	else if(ope2=="&&")
		Pope2 = 6;
	else if(ope2=="||")
		Pope2 = 5;
	//right associativity
	if(Pope1==14&&Pope2==14)
		return 1;

	if(Pope1>Pope2)
		return 1;
	else 
		return 0;
}


string inf_toPostf(string infix){
	string postfix;
	stack<string> infix_stack;
	string x, y;
	for(int i=0; i<infix.size(); i++){
		x.clear();y.clear();
		x=infix[i];
		if(x=="&" && infix[i+1]=='&')
			x+=infix[++i];
		else if(x=="<" && infix[i+1]=='<')
			x+=infix[++i];
		else if(x==">" && infix[i+1]=='>')
			x+=infix[++i];
		else if(x=="!" && infix[i+1]=='=')
			x+=infix[++i];
		else if(x=="=" && infix[i+1]=='=')
			x+=infix[++i];
		else if(x=="|" && infix[i+1]=='|')
			x+=infix[++i];
		if(x>="0"&&x<="9"){
			while(infix[i+1]>='0'&&infix[i+1]<='9'&&i+1!=infix.size()){
				x+=infix[++i];
			}
		}
		
		if(x=="+"||x=="-"){
			if((infix[i-1]>='0'&&infix[i-1]<='9')){
				if(x=="+")
					x = "(binary)+";
				else
					x = "(binary)-";
			}
			else{
				if(x=="+")
					x = "(unary)+";
				else
					x = "(unary)-";
			}
		}

		if(x==" ");
		else if(x==")"){
			while(1){
				y = infix_stack.top();
				infix_stack.pop();
				if(y=="(")
					break;
				postfix += y;
				postfix += " ";
			}
		}
		else if(x=="("||x=="*"||x=="/"||x=="%"||x=="(binary)+"||x=="(binary)-"||x=="(unary)-"
				||x=="(unary)+"||x=="&"||x=="^"||x=="|"||x=="<<"||x==">>"||x=="~"||x=="!"
				||x=="=="||x=="!="||x=="||"||x=="&&"){
			//x>top()
			if(infix_stack.empty()){
				infix_stack.push(x);
			}
			else if(compare(x, infix_stack.top()))
				infix_stack.push(x);
			//x<=top()
			else{
				while(!infix_stack.empty()){
					if(!compare(x, infix_stack.top())){
						y = infix_stack.top();
						infix_stack.pop();
						postfix += y;
						postfix += " ";
					}
					else
						break;
				}
				infix_stack.push(x);
			}
		}
		else{
			postfix += x;
			postfix += " ";
		}
	}
	while(!infix_stack.empty()){
		y = infix_stack.top();
		infix_stack.pop();
		postfix += y;
		postfix += " ";
	}

	return postfix;
}

int postfix_cal(const string &postfix){
	string x;
	stack<int> operand;
	for(int i=0; i<postfix.size(); i++){
		x.clear();
		while(postfix[i]!=' '){
			x+=postfix[i++];
		}
/*x=="*"||x=="/"||x=="%"||x=="+"||x=="-"||x=="&"||x=="^"||x=="|"||
  x=="<<"||x==">>"||x=="~"||x=="!"||x=="=="||x=="!="||x=="||"||x=="&&"*/
		if(x=="*"||x=="/"||x=="%"||x=="(binary)+"||x=="(binary)-"||x=="&"||x=="^"
				||x=="|"||x=="<<"||x==">>"||x=="=="||x=="!="||x=="||"||x=="&&"){
				int b = operand.top();
				operand.pop();
				int a = operand.top();
				operand.pop();
				
				int c;
				if(x=="*")
					c = a*b;
				else if(x=="/")
					c = a/b;
				else if(x=="%")
					c = a%b;
				else if(x=="(binary)+")
					c = a+b;
				else if(x=="(binary)-")
					c = a-b;
				else if(x=="&")
					c = a&b;
				else if(x=="^")
					c = a^b;
				else if(x=="|")
					c = a|b;
				else if(x=="<<")
					c = a<<b;
				else if(x==">>")
					c = a>>b;
				else if(x=="==")
					c = a==b;
				else if(x=="!=")
					c = a!=b;
				else if(x=="||")
					c = a||b;
				else if(x=="&&")
					c = a&&b;
				operand.push(c);
		}
		else if(x=="!"||x=="~"||x=="(unary)+"||x=="(unary)-"){
			int a = operand.top();
			operand.pop();
			
			int c;
			if(x=="!")
				c = !a;
			else if(x=="~")
				c = ~a;
			else if(x=="(unary)+")
				c = +a;
			else if(x=="(unary)-")
				c = -a;
			operand.push(c);
		}
		else{
			operand.push(stoi(x));	
		}		
	}
	return operand.top();
}



int main(){
	string receiver;
	cin>>receiver;
	string postfix = inf_toPostf(receiver);
	cout<<postfix<<endl;
	cout<<postfix_cal(postfix)<<endl;
}

