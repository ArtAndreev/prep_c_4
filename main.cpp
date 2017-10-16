#include <iostream>

#include "Person.h"

#define BUFFER_SIZE 100
#define CURRENT_YEAR 2017

void set_persons(Person*& users, size_t& count);
void input_personal_info(Person& person);
void show_persons_with_bigger_age(const Person* users, size_t count);
void show_persons_with_higher_education(const Person* users, size_t count);
void show_male_persons(const Person* users, size_t count);

enum {
    SECONDARY_EDUCATION = 0,
    SECONDARY_VOCATIONAL_EDUCATION,
    HIGHER_EDUCATION
};

int main() {
    Person* users = nullptr;
    size_t count = 0;

    set_persons(users, count);

    show_persons_with_bigger_age(users, count);
    show_persons_with_higher_education(users, count);
    show_male_persons(users, count);

    delete[] users;
    return 0;
}

void set_persons(Person*& users, size_t& count) {
    std::cout << "Input number of persons you want to add." << std::endl;
    std::cin >> count;
    users = new Person[count];
    for (size_t i = 0; i < count; i++) {
        input_personal_info(users[i]);
    }
}

void input_personal_info(Person& person) {
    char buffer[BUFFER_SIZE];
    int buffer_num = 0;
    getchar();
    std::cout << "Enter information about the person line by line." << std::endl
              << "Input surname:" << std::endl;
    std::cin.getline(buffer, BUFFER_SIZE);
    person.set_surname(buffer);
    std::cout << "Input name:" << std::endl;
    std::cin.getline(buffer, BUFFER_SIZE);
    person.set_name(buffer);
    std::cout << "Input patronymic:" << std::endl;
    std::cin.getline(buffer, BUFFER_SIZE);
    person.set_patronymic(buffer);
    std::cout << "Input address:" << std::endl;
    std::cin.getline(buffer, BUFFER_SIZE);
    person.set_address(buffer);
    std::cout << "Input sex ('f' or 'm'):" << std::endl;
    std::cin >> buffer[0];
    person.set_sex(buffer[0]);
    std::cout << "Input education:" << std::endl
              << "0 - SECONDARY EDUCATION;" << std::endl
              << "1 - SECONDARY VOCATIONAL EDUCATION;" << std::endl
              << "2 - HIGHER EDUCATION." << std::endl;
    std::cin >> buffer_num;
    person.set_education(buffer_num);
    std::cout << "Input birth year:" << std::endl;
    std::cin >> buffer_num;
    person.set_birth_year(buffer_num);
}

void show_persons_with_bigger_age(const Person* users, size_t count) {
    int age = 0;
    std::cout << "Input age for searching:" << std::endl;
    std::cin >> age;
    if (age < 0) {
        std::cerr << "Age must be 0 or bigger." << std::endl;
        return;
    }
    std::cout << "Persons with age bigger than " << age << ":" << std::endl;
    for (size_t i = 0; i < count; i++) {
        if ((CURRENT_YEAR - users[i].get_birth_year()) > age) {
            users[i].show_info();
        }
    }
}

void show_persons_with_higher_education(const Person* users, size_t count) {
    std::cout << "Persons with higher education:" << std::endl;
    for (size_t i = 0; i < count; i++) {
        if (users[i].get_education() == HIGHER_EDUCATION) {
            users[i].show_info();
        }
    }
}

void show_male_persons(const Person* users, size_t count) {
    std::cout << "Male persons" << std::endl;
    for (size_t i = 0; i < count; i++) {
        if (users[i].get_sex() == 'm') {
            users[i].show_info();
        }
    }
}