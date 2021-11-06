#pragma once
#include <iostream>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <optional>
#include <vector>
#include <functional>
#include <string>

using namespace std;


struct Person {

    string name;
    string surname;
    optional <string> middlename;


    bool operator<(const Person& rhs) {
        return tie(surname, name, middlename) < tie(rhs.surname, rhs.name, rhs.middlename);
    }

    bool operator==(const Person& rhs) {
        return tie(surname, name, middlename) == tie(rhs.surname, rhs.name, rhs.middlename);
    }

    friend ostream& operator<<(ostream& out, const Person& person);
};


struct PhoneNumber {

    int country_code;
    int city_code;
    string phone_number;
    optional<int> add_code;

    bool operator<(const PhoneNumber& right) {
        return tie(country_code, city_code, phone_number, add_code) <
            tie(right.country_code, right.city_code, right.phone_number, right.add_code);
    }

    friend ostream& operator<<(ostream& out, const PhoneNumber& current);

};


class PhoneBook {
private:
    PhoneBook() {};
    vector<pair<Person, PhoneNumber>> m_book;
public:
    PhoneBook(ifstream& ifin);

    void SortByName();
    void SortByPhone();
    void ChangePhoneNumber(Person, PhoneNumber);
    tuple<string, PhoneNumber> GetPhoneNumber(string);

    friend ostream& operator<<(ostream& out, const PhoneBook& PBcurrent);
};


