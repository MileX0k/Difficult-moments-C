#include <iostream>
#include <vector>
#include <random>

using namespace std;

//===========================TASK 1=============================================

vector<float> Average(vector<float> *v1) {

	float aver = 0, count = 0;
	vector<float> tmp;
	for (auto& n : *v1) {
		tmp.push_back(n);
		aver += n;
		++count;
	}
	aver = aver / count;
	tmp.push_back(aver);

	return tmp;
}

//===========================TASK 2=============================================

int Rdm(int n) {
	for (int i = 0; i < n; i++)
	{
		return rand() % 99;
	};
}


//template <typename T>
class Matrix {
private:
	vector<vector<int>> matrix;
	int size;
public:
	Matrix():size(1) {
		matrix.push_back(vector<int> (1, Rdm(size))); 
	}

	Matrix(int n) :size(n) {
		for (int i = 0; i < size; i++) {
			matrix.push_back(vector<int>(size, Rdm(size))); // Не могу придумать как заполнить разными числами((
		}
	}

	void PrintMatrix() {
		cout << " " << size << " matrix: " << endl;
		for(int i = 0; i < matrix.size(); i++){
			for (int j = 0; j < size; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	int Determinant() {
		if (size == 1)
			return matrix[0][0];
		else if (size == 2) {
			int res = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
			return res;
		}
		else if (size == 3) {
			int res = matrix[0][0] * matrix[1][1] * matrix[2][2]
					- matrix[0][0] * matrix[2][1] * matrix[1][2]
					- matrix[1][0] * matrix[0][1] * matrix[2][2]
					+ matrix[1][0] * matrix[2][1] * matrix[0][2]
					+ matrix[2][0] * matrix[0][1] * matrix[1][2]
					- matrix[2][0] * matrix[1][1] * matrix[0][2];
			return res;
		}
		else return false;
	}
};

int main()
{
//===========================TASK 1=============================================

	cout << "------TASK 1------" << endl;

    vector<float> numbers{ 14, 2, 3, 8, 123, 65 };

	cout << "Before func():" << endl;
	for (const auto& x : numbers)
		cout << x << " ";
	cout << endl;

	auto newnumbers = Average(&numbers);

	cout << "After func():" << endl;
	for (const auto& x : newnumbers)
		cout << x << " ";

	cout << endl;

//===========================TASK 2=============================================
	
	cout << "------TASK 2------" << endl;

	Matrix m1{};
	m1.PrintMatrix();
	Matrix m2{ 2 };
	m2.PrintMatrix();
	Matrix m3{ 3 };
	m3.PrintMatrix();

	cout << "Determinant of a single matrix: " << m1.Determinant() << endl;
	cout << "The determinant of a double matrix: " << m2.Determinant() << endl;
	cout << "The determinant of the triple matrix: " << m3.Determinant() << endl;

	cout << endl;

}
