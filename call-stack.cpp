#include <iostream>
using namespace std;

struct Struct {
	string s;
	int a;
} S;

void fun2(int b);
void fun3(int c);

void fun1(int a) 
{
	try {
	int x = a + 1;
	fun2(x);
	}
	catch (Struct S)
	{
		cout << S.s << " " << S.a << "\n";
		S.s = "fun1";
		S.a = a;
		throw S;
	}
}

void fun2(int b) 
{
	try {
		int y = b + 2;
		fun3(y);
	}
	catch (Struct S) 
	{
		cout << S.s << " " << S.a <<"\n";
		S.s = "fun2";
		S.a = b;
		throw S;
	}
}

void fun3(int c)
{
	int z = c + 3;
	S.s = "fun3";
	S.a = c;
	throw S;
}

int main()
{

	try 
	{
		fun1(0);
	}
	catch (Struct S)
	{
		cout << S.s << " " << S.a << "\n";
	}


}

