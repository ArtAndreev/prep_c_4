#include <iostream>

#include "Person.h"

#define BUFFER_SIZE 100
#define CURRENT_YEAR 2017

void set_persons(Person*& users, size_t& count);
void input_personal_info(Person& person);
bool input_string_field(char* destination, const char* message);
bool input_int_field(int& destination, const char* message);
void check_sex(char* sex);
void check_education_id(int& id);
void check_birth_year(int& birth_year);
void show_persons_with_bigger_age(const Person* users, size_t count);
void show_persons_with_higher_education(const Person* users, size_t count);
void show_male_persons(const Person* users, size_t count);

enum EDUCATION {
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
    std::cout << "Enter information about the person line by line." << std::endl;

    bool input_result = true;

    if ((input_result = input_string_field(buffer, "surname")))
        person.set_surname(buffer);
    if (input_result && (input_result = input_string_field(buffer, "name")))
        person.set_name(buffer);
    if (input_result && (input_result = input_string_field(buffer, "patronymic")))
        person.set_patronymic(buffer);
    if (input_result && (input_string_field(buffer, "address")))
        person.set_address(buffer);
    if (input_result && (input_string_field(buffer, "sex ('f' or 'm')")))
        person.set_sex(buffer[0]);
    if (input_result && (input_int_field(buffer_num, "education")))
        person.set_education(buffer_num);
    if (input_result && (input_int_field(buffer_num, "birth year")))
        person.set_birth_year(buffer_num);
}

bool input_string_field(char* destination, const char* message) {
    if (!destination || !message)
        return false;

    std::cout << "Input " << message << "." << std::endl;
    std::cout << "Max length: " << BUFFER_SIZE << std::endl;
    if (std::cin.getline(destination, BUFFER_SIZE)) {
        if (message == "sex ('f' or 'm')")
            check_sex(destination);
        return true;
    }
    return false;
}

bool input_int_field(int& destination, const char* message) {
    if (!message)
        return false;

    std::cout << "Input " << message << "." << std::endl;
    if (message == "education") {
        std::cout << SECONDARY_EDUCATION
                  << " - SECONDARY EDUCATION ID;" << std::endl
                  << SECONDARY_VOCATIONAL_EDUCATION
                  << " - SECONDARY VOCATIONAL EDUCATION ID;" << std::endl
                  << HIGHER_EDUCATION
                  << " - HIGHER EDUCATION ID." << std::endl;
        std::cin >> destination;
        check_education_id(destination);
        return true;
    }
    std::cin >> destination;
    if (message == "birth year")
        check_birth_year(destination);
    return true;
}

void check_sex(char* sex) {
    while (sex[0] != 'f' && sex[0] != 'm') {
        std::cout << "Incorrect sex inputted. Try again." << std::endl;
        std::cin.getline(sex, BUFFER_SIZE);
    }
}

void check_education_id(int& id) {
    while (id != SECONDARY_EDUCATION && id != SECONDARY_VOCATIONAL_EDUCATION
           && id != HIGHER_EDUCATION) {
        std::cout << "Incorrect education ID inputted. Try again." << std::endl;
        std::cin >> id;
    }
}

void check_birth_year(int& birth_year) {
    while (birth_year > CURRENT_YEAR) {
        std::cout << "Incorrect birth year inputted. Try again." << std::endl;
        std::cin >> birth_year;
    }
}

void show_persons_with_bigger_age(const Person* users, size_t count) {
    int age = 0;
    bool found = false;
    do {
        std::cout << "Input age for searching:" << std::endl;
        std::cin >> age;
        if (age < 0) {
            std::cerr << "Age must be 0 or bigger." << std::endl;
        }
    }
    while (age < 0);
    std::cout << "Persons with age bigger than " << age << ":" << std::endl;
    for (size_t i = 0; i < count; i++) {
        if ((CURRENT_YEAR - users[i].get_birth_year()) > age) {
            users[i].show_info();
            found = true;
        }
    }
    if (!found)
        std::cout << "No persons found with age bigger than " << age << "." << std::endl;
}

void show_persons_with_higher_education(const Person* users, size_t count) {
    bool found = false;
    std::cout << "Persons with higher education:" << std::endl;
    for (size_t i = 0; i < count; i++) {
        if (users[i].get_education() == HIGHER_EDUCATION) {
            users[i].show_info();
            found = true;
        }
    }
    if (!found)
        std::cout << "No persons found with higher education." << std::endl;
}

void show_male_persons(const Person* users, size_t count) {
    bool found = false;
    std::cout << "Male persons:" << std::endl;
    for (size_t i = 0; i < count; i++) {
        if (users[i].get_sex() == 'm') {
            users[i].show_info();
            found = true;
        }
    }
    if (!found)
        std::cout << "No male persons found." << std::endl;
}