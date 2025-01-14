//
// Created by CagesThrottleUs on 14-01-2025.
//

#ifndef PERSON_H
#define PERSON_H

#include <array>
#include <cstddef>
#include <fstream>
#include <string>

constexpr size_t MAX_NAME_LENGTH = 50;

class Person {

    int id;
    std::array<char, MAX_NAME_LENGTH> name;
    double salary;

public:
    explicit Person(const int id_val = 0, const char *name = "",
                    const double salary = 0.0): id(id_val), name({}), salary(salary) {
        setName(name);
    };

    [[nodiscard]] auto getId() const -> int {
        return id;
    }

    [[nodiscard]] auto getName() const -> std::string {
        return {name.data()};
    }

    [[nodiscard]] auto getSalary() const -> double {
        return salary;
    }

    void setId(const int newId) {
        this->id = newId;
    }

    void setSalary(const double newSalary) {
        this->salary = newSalary;
    }

    void setName(const char *newName);

    void serialize(std::ostream &oss) const;
    void deserialize(std::istream &iss);
    void display() const;
};


#endif //PERSON_H
