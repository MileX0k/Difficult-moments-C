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

//===========================TASK 3=============================================

bool find_vowel(char vow) {            //   find
	char res = tolower(vow);
	string letters = "aeyuio";
	return find(letters.begin(), letters.end(), res) != letters.end();
}

bool for_vowel(char vow) {            //   for
	char res = tolower(vow);
	string letters = "aeyuio";
	int found = letters.find(res);
	bool out;
	found == string::npos ? out = false : out = true;
	return out;
}

int count_if_and_find(ifstream& file) {

	Timer time;
	time.start("Count_if and Find: ");
	int summ = 0;
	while (!file.eof()) {
		string raw_string = "";
		getline(file, raw_string);
		summ += count_if(raw_string.begin(), raw_string.end(), find_vowel);
	}
	time.print();
	cout << "Vowel letters found: " << summ << endl;
	file.close();
	return 0;
}

int count_if_and_for(ifstream& file) {
	
	Timer time;
	time.start("Count_if and For: ");
	int summ = 0;
	while (!file.eof()) {
		string raw_string = "";
		getline(file, raw_string);
		summ += count_if(raw_string.begin(), raw_string.end(), for_vowel);
	}
	time.print();
	cout << "Vowel letters found: " << summ << endl;
	file.close();
	return 0;
}

int for_and_find(ifstream& file){
	
	Timer time;
	time.start("For and Find: ");
	int summ = 0;
	while (!file.eof()) {
		string raw_string = "";
		getline(file, raw_string);
		for (auto i = raw_string.begin(); i < raw_string.end(); ++i)
			if (find_vowel(*i)) ++summ;
	}
	time.print();
	cout << "Vowel letters found: " << summ << endl;
	file.close();
	return 0;

}

int for_and_for(ifstream& file) {

	Timer time;
	time.start("For and For: ");
	int summ = 0;
	while (!file.eof()) {
		string raw_string = "";
		getline(file, raw_string);
		for (auto i = raw_string.begin(); i < raw_string.end(); ++i)
			if (for_vowel(*i)) ++summ;
	}
	time.print();
	cout << "Vowel letters found: " << summ << endl;
	file.close();
	return 0;

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

//===========================TASK 3=============================================

	cout << "------TASK 3------" << endl;

	ifstream text1("War and peace.txt");
	if (!text1.is_open()) return 0;
	count_if_and_find(text1);
	cout << endl;

	ifstream text2("War and peace.txt");
	if (!text2.is_open()) return 0;
	count_if_and_for(text2);
	cout << endl;

	ifstream text3("War and peace.txt");
	if (!text3.is_open()) return 0;
	for_and_find(text3);
	cout << endl;

	ifstream text4("War and peace.txt");
	if (!text4.is_open()) return 0;
	for_and_for(text4);
	cout << endl;


}


