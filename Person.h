#ifndef C_TASK4_PERSON_H
#define C_TASK4_PERSON_H

class Person {
public:
    explicit Person(const char* surname = nullptr, const char* name = nullptr, const char* patronymic = nullptr,
                    const char* address = nullptr, char sex = 'm',
                    int education = 0, int birth_year = 0);
    Person(const Person& person);
    ~Person();

    void set_surname(const char* surname);
    const char* get_surname() const;

    void set_name(const char* name);
    const char* get_name() const;

    void set_patronymic(const char* patronymic);
    const char* get_patronymic() const;

    void set_address(const char* address);
    const char* get_address() const;

    void set_sex(char sex);
    char get_sex() const;

    void set_education(int education);
    int get_education() const;

    void set_birth_year(int birth_year);
    int get_birth_year() const;

    void show_info() const;

private:
    char* surname;
    char* name;
    char* patronymic;
    char* address;
    char sex;
    int education;
    int birth_year;

    void set_string_field(char*& field, const char* string);
};

#endif //C_TASK4_PERSON_H
