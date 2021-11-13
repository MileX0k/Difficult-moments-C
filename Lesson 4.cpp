#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


//===========================TASK 1=============================================

template <typename T>
void PrintVector(vector<T> v1) {
	for (auto& n : v1)
		cout << n << " ";
	cout << endl;
}

template <typename T>
vector<T> Sorted(vector<T> &v1) {
	sort(v1.begin(), v1.end());
	return v1;
}



template <typename T>
vector<T> Insert_Sorted(vector<T> &v1, T n) {
	
	if (n > *(v1.end() - 1))
		v1.push_back(n);
	else if (n < *(v1.begin()))
		v1.insert(v1.begin(), n);
	else {
		auto up = upper_bound(v1.begin(), v1.end(), n);
		v1.insert(up, n);
	}

	return v1;
}


int main()
{
//===========================TASK 1=============================================

	cout << "------TASK 1------" << endl;

	vector<int> vint(20);
	generate(vint.begin(), vint.end(), []() {return rand() % 29; });
	
	Sorted(vint);
	cout << "Sorted vector: " << endl;
	PrintVector(vint);
	Insert_Sorted(vint, 16);
	cout << "Insert value in vector: " << endl;
	PrintVector(vint);

	cout << endl;
	//=======================CHAR========================
	vector<char> vchar(20);
	generate(vchar.begin(), vchar.end(), [&]() { return 97 + rand() % 26; });
	
	cout << "Sorted vector: " << endl;
	Sorted(vchar);
	PrintVector(vchar);
	cout << "Insert value in vector: " << endl;
	Insert_Sorted(vchar, 'b');
	PrintVector(vchar);

	cout << endl;
	//=======================STRING========================
	vector<string>vstring {"Hello", "world", "I" , "was", "born", "today"};
	cout << "Sorted vector: " << endl;
	Sorted(vstring);
	PrintVector(vstring);
	cout << "Insert value in vector: " << endl;
	string po = "teacher";
	Insert_Sorted(vstring, po);
	PrintVector(vstring);

	cout << endl;

//===========================TASK 2=============================================

	cout << "------TASK 2------" << endl;

	vector<double> db(100);
	vector<int> in;
	generate(db.begin(), db.end(), []() {double i = 1+rand()/ (double)100; return i; });
	//cout << "Analog: " << endl;
	//PrintVector(db);                   //Выводит 100 значений с запятой

	transform(db.begin(), db.end(), back_inserter(in), [](double i)->int {return i; });
	//cout << "Digital: " << endl;
	//PrintVector(in);                  //Выводит 100 значений без запятой

	vector<double> result;
	transform(db.begin(), db.end(), in.begin(), back_inserter(result), minus<double>());
	//cout << "Minus: " << endl;
	//PrintVector(result);             //Выводит поэлементное вычитание двух векторов

	transform(result.begin(), result.end(), result.begin(), [](double i) { return i * i; });
	//cout << "i*i: " << endl;
	//PrintVector(result);             //Выводит квадраты каждого элемента

	double sum = accumulate(result.begin(), result.end(), 0.0);
	cout << "Result = " << sum << endl; //Выводит конечную суммы всех элементов

	cout << endl;

}
