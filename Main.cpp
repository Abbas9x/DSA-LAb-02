#include<iostream>
#include<string>
using namespace std;
template<class Type>
class Stack{
private:
int top;
int max;
Type* stack;
public:
Stack(int max){
this->max = max;
this->top = -1;
this->stack = new Type[max];
}
bool isFull(){
return (top == this->max - 1);
}
bool isEmpty(){
return (top == -1);
}
void Push(Type item){
if(isFull()){
cout << "\nStack Overflow!\n";
return;
}else{
top++;
stack[top] = item;
}
}
void Pop(Type &item){
if(isEmpty()){
cout << "\nStack Underflow!\n";
return;
}else{
item = stack[top];
top--;
}
}
~Stack(){
delete [] stack;
}
};
int main(){
int max;
string inputString, outputString;
cout << "\nEnter the Size of the Stack: ";
cin >> max;
cin.ignore();
Stack<char>* st1 = new Stack<char>(max);
cout << "\nWelcome to the Palindrome Checker!\n";
cout << "\nEnter a String: ";
getline(cin, inputString);
for(int i = 0; i < inputString.length(); i++){
char c = inputString[i];
st1->Push(c);
}
while(!st1->isEmpty()){
char c;
st1->Pop(c);
outputString += c;
}
if(outputString == inputString){
cout << "\nString is a Palindrome\n";
}else{
cout << "\nString is not a Plaindrome\n";
}
delete st1;
cout << endl << endl;
return 0;
}
