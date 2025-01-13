//
// Created by CagesThrottleUs on 14-01-2025.
//

#include <cstring>
#include <fstream>
#include <iostream>

#include "Person.h"

void Person::setName(const char *newName) {
    std::strncpy(this->name.data(), newName, this->name.size() - 1);
    this->name[this->name.size() - 1] = '\0'; // NOLINT - Important to ensure that there is null termination
}

void Person::display() const {
    std::cout << "ID: " << this->id << '\n';
    std::cout << "Name: " << this->name.data() << '\n';
    std::cout << "Salary: " << this->salary << '\n';
}

void Person::serialize(std::ostream &oss) const {
    // reinterpret_cast is used to convert the memory representation of a type to binary data
    oss.write(reinterpret_cast<const char *>(&this->id), sizeof(this->id)); // NOLINT
    oss.write(this->name.data(), static_cast<std::streamsize>(this->name.size()));

    // Why use const char* ? To prevent changing of underlying data
    oss.write(reinterpret_cast<const char *>(&this->salary), sizeof(this->salary)); // NOLINT
}

void Person::deserialize(std::istream &iss) {
    // Here we use char* to tell that it is okay to modify underlying data
    iss.read(reinterpret_cast<char *>(&this->id), sizeof(this->id)); // NOLINT
    iss.read(this->name.data(), static_cast<std::streamsize>(this->name.size()));

    iss.read(reinterpret_cast<char *>(&this->salary), sizeof(this->salary)); // NOLINT
}

