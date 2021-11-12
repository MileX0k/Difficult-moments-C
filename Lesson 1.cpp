#include "PhoneBook.h"

using namespace std;

//===========================TASK 1=============================================

ostream& operator<<(ostream& out, const Person& person) {
    out << person.surname << " " << person.name << " ";
    
    if (person.middlename) 
        out << *person.middlename << " ";
    return out;
};

//===========================TASK 2=============================================

ostream& operator<<(ostream& out, const PhoneNumber& current) {
    out << "+" << current.country_code;
    out << "(" << current.city_code << ")";
    out << current.phone_number << " ";

    if (current.add_code)
        out << *current.add_code << " ";
    return out;
};

//===========================TASK 3=============================================

ostream& operator<<(ostream& out, const PhoneBook& PBcurrent) {
    for (auto it : PBcurrent.m_book)
        out << it.first << it.second << endl;
    return out;
};


PhoneBook::PhoneBook(ifstream& ifin) {
    while (!ifin.eof())
    {
        string tempName, tempSur, tempPhone, garb;
        optional<string> tempMiddle = nullopt;
        optional<int> tempAdd = nullopt;
        int tempCountry, tempCity, temp;
        char check;

        getline(ifin, tempSur, ' ');
        getline(ifin, tempName, ' ');

        check = ifin.peek();

        if (check != '-') {
            getline(ifin, garb, ' ');
            tempMiddle = garb;
        }
        else ifin.ignore(2);

        ifin >> tempCountry;
        ifin >> tempCity;
        ifin.ignore(1);

        getline(ifin, tempPhone, ' ');

        check = ifin.peek();

        if (check != '-')
        {
            ifin >> temp;
            tempAdd = temp;
        }

        getline(ifin, garb, '\n');

        pair<Person, PhoneNumber> pNew;
        pNew.first = Person{ tempName, tempSur, tempMiddle };
        pNew.second = PhoneNumber{ tempCountry, tempCity, tempPhone, tempAdd };
        m_book.insert(m_book.end(), pNew);


    };
}

void PhoneBook::SortByName() {

    sort(m_book.begin(), m_book.end(), [](auto& left, auto& right) { return left.first < right.first; });
}

void PhoneBook::SortByPhone() {

    sort(m_book.begin(), m_book.end(), [](auto& left, auto& right) { return left.second < right.second; });
};

void PhoneBook::ChangePhoneNumber(Person currentPerson, PhoneNumber changePhone) {

    for (auto it : m_book)
        if (it.first == currentPerson)
            it.second = changePhone;
};

tuple<string, PhoneNumber> PhoneBook::GetPhoneNumber(string surName) {

    tuple<string, PhoneNumber> toReturn;

    for (auto it : m_book) {
        if ((it.first.surname == surName) && (get<0>(toReturn).empty())) {

            if (get<1>(toReturn).phone_number.empty())
                get<1>(toReturn) = it.second;
            else
                get<0>(toReturn) = "Found more than 1\n";
        }
    }

    if (get<1>(toReturn).phone_number.empty())
        get<0>(toReturn) = "Not found\n";
    return toReturn;
};

int main()
{
    ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    cout << book;

    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;

    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;

    cout << "-----GetPhoneNumber-----" << endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона этого    	человека, либо строку с ошибкой
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;

    };
    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;

}
