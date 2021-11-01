#include <iostream>
#include "Timer.h"
#include <vector>
#include <optional>
#include <algorithm>
#include <fstream>


using namespace std;

//===========================TASK 1=============================================

template <typename T>
void Swap(T*& a, T*& b)
{	
	cout << "Original: " << endl;
	cout << "a= " << *a << " | " << "&a= " << a << endl;
	cout << "b= " << *b << " | " << "&b= " << b << endl;

	T* boo = move(a);
	a = move(b);
	b = move(boo);

	cout << "Result: " << endl;
	cout << "a= " << *a << " | " << "&a= " << a << endl;
	cout << "b= " << *b << " | " << "&b= " << b << endl;
}

//===========================TASK 2=============================================
template <typename T>
void SortPointers(vector<T*> v1) {

	{
		for (const auto& i : v1)
			cout << *i << " ";
		cout << endl;
		for (const auto& i : v1)
			cout << i << " ";
		cout << endl;
	}

	for (auto i = v1.begin(); i < v1.end()-1; i++)
		for (auto j = v1.begin(); j < v1.end()-1; j++)
			if (**j > **(j+1))
				swap(*j, *(j+1));
		
	{
		for (const auto& i : v1)
			cout << *i << " ";
		cout << endl;
		for (const auto& i : v1)
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
//===========================TASK 1=============================================

	cout << "------TASK 1------" << endl;

	int a = 60, b = 90;
	int* pa = &a;
	int* pb = &b;

	Swap(pa, pb);

	char x = 'x', y = 'y';
	char* px = &x;
	char* py = &y;

	Swap(px, py);

	cout << endl;

//===========================TASK 2=============================================

	cout << "------TASK 2------" << endl;

	vector<int> vec{ 15, 3, 66, 35, 9};
	vector<int*> vptr;
	for (auto& i : vec) {
		int* po = &i;
		vptr.push_back(&i);
	}
	
	SortPointers<int>(vptr);
}


