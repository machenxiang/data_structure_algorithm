//函数模板和类模板
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<stdexcept>
using namespace std;

template<class T>
T abc(T a, T b, T c)
{
	return a * b*c;
}

template<class T>
class Stack
{
private:
	vector<T> elems;
public:
	Stack(){};
	~Stack(){};
	void push(T const& elem);//入栈
	void pop();//出栈
	T top() const;//返回栈顶元素
	bool empty() const{return elems.empty();}
};
template<class T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}
template<class T>
void Stack<T>::pop()
{
	if(elems.empty()){
		throw out_of_range("Stack<>::pop: empty stack");
	}
	elems.pop_back();
}
template<class T>
T Stack<T>::top() const
{
	if(elems.empty()){
		throw out_of_range("Stack<>::top: empty stack");
	}
	return elems.back();
}

int main()
{
	int a1 = 1, b1 = 2, c1 = 3;
	int output = abc(a1, b1, c1);
	cout << "abc=" << output << endl;
    try
	{
		Stack<int> intStack;
		intStack.push(7);
		cout<<intStack.top()<<endl;

		Stack<string> stringStack;
		stringStack.push("hello");
		cout<<stringStack.top()<<endl;
		stringStack.pop();
		stringStack.pop();

	}
	catch(exception const& e)
	{
		cerr << e.what() << '\n';
		return -1;
	}
	return 0;
}