#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include "Timer.h"
#include <algorithm>

using namespace std;

//===========================TASK 1=============================================

mutex stop;
	int vol = 1;

void pcout(int i) {
	lock_guard lg(stop);
	cout << vol << ": " << i << endl;
	vol++;
}

//===========================TASK 2=============================================


void Find_simple(int n) {
	unsigned int ten = 10;
	unsigned int numbers = 0;
	unsigned int vec = 100;
	
	if (n <= 4) {
		if (n == 1) {
			numbers = 2;
			n--;
		}
		else if (n == 2){
			numbers = 3;
			n -= 2;
		}
		else if (n == 3){
			numbers = 5;
			n -= 3;
		}
		else { 
			numbers = 7;
			n -= 4;
		}
	} else n -= 4;
	while (n > 0) {
		//cout << "From " << ten << " " << "to " << vec << endl;   // Если нужен вывод промежутка из которого берутся числа
		for (unsigned int i = ten; i < vec; i++) {
			int summ_number_without_remaind = 0;
			if (i % 2 != 0) {
				for (int j = 1; j < i+1; j++) {
					if (i % j == 0 && summ_number_without_remaind < 3) {
						summ_number_without_remaind++;
					}
					j++;
				}
			}
			if (summ_number_without_remaind == 2) {
				numbers = i;
				//cout << numbers << ", ";    // Если нужен вывод всех чисел в консоль
				n--;
				if (n == 0) {
					//cout << endl; // Для красоты вывода)
					break;
				}
			}
		}
		ten = vec;
		vec *= ten;
	}
	cout << "a prime number is: " << numbers << endl;
}

//===========================TASK 3=============================================

vector<int> stuff{ 14, 23, 10, 43, 32, 18, 39, 30 };  // Иначе не придумал, кроме как вынести его в зону общей видимости

void Print_stuff() {
	cout << "Stuff in the house: ";
	for (auto i : stuff)
		cout << i << " ";
	cout << endl;
}

void House(int n) {
	while (!stuff.empty()) {

		if (n == 0) {
			this_thread::sleep_for(chrono::seconds(2));

			int box = 1 + rand() % 50;

			stop.lock();
			cout << "Push: ->" << box << endl;
			stop.unlock();

			stuff.push_back(box);
		}

		if (n == 1) {
			auto it = max_element(stuff.begin(), stuff.end());
			this_thread::sleep_for(chrono::seconds(1));

			stop.lock();
			cout << "Erease: <-" << *it << endl;
			stop.unlock();

			stuff.erase(it);
		}
	}
	cout << "House is empty(" << endl;

}


int main()
{
//===========================TASK 1=============================================

	cout << "------TASK 1------" << endl;

	vector<thread> threads;
	for (auto i = 0; i < 10; i++)
		threads.push_back(thread(pcout, i));

	for (auto& i : threads)
		i.join();

	thread th2(pcout, 4);

	th2.join();

	thread th3(pcout, 25);
	th3.join();

	cout << endl;

//===========================TASK 2=============================================

	cout << "------TASK 2------" << endl;
	
	int your_number = 0;
	cout << "Enter your number: ";
	cin >> your_number;

	Timer time("Time to search for a prime number");

	if (your_number > 0) {
		thread thsmpl(Find_simple, your_number);
		thsmpl.join();
	}
	else cout << "Wrong number!" << endl;

	time.print();

	cout << endl;

//===========================TASK 3=============================================

	cout << "------TASK 3------" << endl;

	Print_stuff();
	thread owner(House, 0);
	owner.detach();
	thread thief(House, 1);
	thief.join();

	cout << endl; 

}
