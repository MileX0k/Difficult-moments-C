#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>
#include <unordered_set>
#include <map>
#include <fstream>
#include <string>

using namespace std;

//===========================TASK 1=============================================

template <typename T>
void UnicSet(typename vector<T>::iterator begin, typename vector<T>::iterator end) {

	set<T> r;
	for (auto i = begin; i != end; ++i)
		r.insert(*i);

	cout << "-----After:----- " << endl;

	for (auto& i : r)
		cout << i << " ";
	cout << endl;
}


int main()
{
//===========================TASK 1=============================================
	
		cout << "------TASK 1------" << endl;
		//-------STRING--------
		vector<string> test1{ "Hello", "world" , "war", "peace", "terror", "egg", "coconut", "radio","Hello", "world" };

		cout << "-----Before:-----" << endl;
		for (auto& i : test1)	cout << i << " ";
		cout << endl;

		UnicSet<string>(test1.begin(), test1.end());
		//-------INTEGER--------
		vector<int> test2{ 2,4,5,2,87,123,2,4,5 };

		cout << "-----Before:-----" << endl;
		for (auto& i : test2)	cout << i << " ";
		cout << endl;

		UnicSet<int>(test2.begin(), test2.end());

		cout << endl;
	
//===========================TASK 2=============================================

	cout << "------TASK 2------" << endl;

	multimap<int, string> m1;
	ifstream file("Rick and Morty.txt");
	string text;

	while (getline(file, text, '.')) {
		while (text[0] == ' ') text.erase(text.begin());
		m1.insert({ text.size(), text });
	}

	for (const auto& [key,val] : m1)
		cout << "---Size " << key << " : " << val << endl;

	cout << endl;
}

