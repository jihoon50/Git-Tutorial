#include<iostream>
using namespace std;

const int MAX_NUM = 100;
typedef int element;
typedef int element2;

class Stack{
public:
	element data[MAX_NUM];
	int top;
	
	Stack(){
		top=-1;
	} 
	bool is_empty(){
		return(top==-1);
	}
	bool is_full(){
		return(top==MAX_NUM-1);
	}
	void push(element value){
		if(is_full()){
			cout<<"STACK OVERFLOW!!!"<<endl;
			exit(-1);
		}
		else{
			data[++top] = value;
		}
	}
	element pop(){
		if(is_empty()){
			cout<<"STACK UNDERFLOW!!!"<<endl;
			exit(-1);
		}
		else{
			return(data[top]);
		}
	}
	void printStack(){
		cout<<"##STACK 상태 ###"<<endl;
		for(int i = top; i>=0; i--)
		cout<< data[i] <<endl;
	}
};
class IntStack{
public:
	element2 data[MAX_NUM];
	int top;
	
	IntStack(){
		top=-1;
	}
	bool is_empty(){
		return(top==-1);
	}
	bool is_full(){
		return(top == MAX_NUM-1);
	}
	void push(element2 value){
		if(is_full()){
			cout<<"STACK OVERFLOW!!!"<<endl;
			exit(-1);
		}
		else{
			data[++top] = value;
		}
	} 
	element2 pop(){
		if(is_empty()){
			cout<<"STACK UNDERDFLOW!!!"<<endl;
			exit(-1);
		}
		else{
			return(data[top--]);
		}
	}
	element2 peek(){
		if(is_empty()){
			cout<<"STACK UNDERFLOW!!!"<<endl;
			exit(-1);
		}
		else{
			return(data[top]);
		}
	}
	void printIntStack(){
		cout<<"##STACK상태 ###"<<endl;
		for(int i=top; i>=0; i--)
			cout<< data[i]<<endl;
	}
};

void convert_postfix(char *infix, char *postfix){
	Stack PStack;
	int j = 0;
	
	for(int i=0; i<strlen(infix); i++){
		char ch = infix[i];
		if(ch=='(') continue;
		else if (ch =='+'|| ch == '-'|| ch == '*' || ch == '/')
			PStack.push(ch);
		else if(ch ==')'){
			postfix[j++] = PStack.pop();
		}
		else
			postfix[j++] = ch;
	}
	while (!PStack.is_empt()){
		postfix[j++] = PStack.pop();
	}
	postfix[j] = '|0';
}
int caculate_postfix(char *postfix){
	IntStack CStack;
	
	for(int i =0; i<strlen(postfix); i++){
		char ch = postfix[i];
		int opr1 ,opr2;
		
		if(ch=='+'){
			opr2 = CStack.pop();
			opr1 = CStack.pop();
			CStatck.push(opr1+opr2);
		}else if(ch=='*'){
			opr2 = CStack.pop();
			opr1 = CStack.pop();
			CStack.push(opr1*opr2);
		}else if(ch == '-'){
			opr2 = CStack.pop();
			opr1 = CStack.pop();
			CStack.push(opr1-opr2);
		}else if(ch == '/'){
			opr2 = CStack.pop();
			opr1 = CStack.pop();
			CStack.push(opr1/opr2);
	}
	else{
		CStack.push(ch -'0');
	}
}
return CStack.pop();
}

int main(){
	char infix[100];
	char postfix[100];
	
	cout<<"중위 수식을 입력하세요:";
	cin.getline(infix,100);
	
	convert_postfix(infix,postfix);
	cout<<"변환된 후위 표기식은:"<<postfix<<endl;
	
	int result = calculate_postfix(postfix);
	cout < infix << "=" <<result <<endl;
}



