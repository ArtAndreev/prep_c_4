#include <cstring>
#include <iostream>

#include "Person.h"

Person::Person(const char* surname, const char* name, const char* patronymic,
               const char* address, char sex, int education, int birth_year) :
        surname(nullptr), name(nullptr), patronymic(nullptr),
        address(nullptr), sex('m'), education(0), birth_year(0)
{
    set_string_field(this->surname, surname);
    set_string_field(this->name, name);
    set_string_field(this->patronymic, patronymic);
    set_string_field(this->address, address);
    this->sex = sex;
    this->education = education;
    this->birth_year = birth_year;
}

Person::Person(const Person& person) {
    if (this == &person) {
        return;
    }
    set_string_field(this->surname, surname);
    set_string_field(this->name, name);
    set_string_field(this->patronymic, patronymic);
    set_string_field(this->address, address);
    sex = person.sex;
    education = person.education;
    birth_year = person.birth_year;
}

Person::~Person() {
    delete[] surname;
    surname = nullptr;
    delete[] name;
    name = nullptr;
    delete[] patronymic;
    patronymic = nullptr;
    delete[] address;
    address = nullptr;
}

void Person::set_string_field(char*& field, const char* string) {
    if (field == nullptr && string == nullptr)
        return;
    if (string == nullptr) {
        std::cerr << "Empty string given." << std::endl;
        return;
    }

    if (field && !strcmp(field, string))
        return;

    auto temp_field = new char[strlen(string) + 1];

    delete[] field;
    memcpy(temp_field, string, strlen(string) + 1);
    field = temp_field;
}

void Person::set_surname(const char* surname) {
    set_string_field(this->surname, surname);
}

const char* Person::get_surname() const {
    return surname;
}

void Person::set_name(const char* name) {
    set_string_field(this->name, name);
}

const char* Person::get_name() const {
    return name;
}

void Person::set_patronymic(const char* patronymic) {
    set_string_field(this->patronymic, patronymic);
}

const char* Person::get_patronymic() const {
    return patronymic;
}

void Person::set_address(const char* address) {
    set_string_field(this->address, address);
}

const char* Person::get_address() const {
    return address;
}

void Person::set_sex(char sex) {
    if (isupper(sex)) {
        sex -= 'A' + 'a';
    }
    if (sex != 'm' && sex != 'f') {
        std::cerr << "Wrong type of sex given." << std::endl;
        return;
    }

    this->sex = sex;
}

char Person::get_sex() const {
    return sex;
}

void Person::set_education(int education) {
    this->education = education;
}

int Person::get_education() const {
    return education;
}

void Person::set_birth_year(int birth_year) {
    this->birth_year = birth_year;
}

int Person::get_birth_year() const {
    return birth_year;
}

void Person::show_info() const {
    std::cout << "Surname: " << surname << std::endl
              << "Name: " << name << std::endl
              << "Patronymic: " << patronymic << std::endl
              << "  Address: " << address << std::endl
              << "  Sex: " << sex << std::endl
              << "  Education: " << education << std::endl
              << "  Birth year: " << birth_year << std::endl;
}