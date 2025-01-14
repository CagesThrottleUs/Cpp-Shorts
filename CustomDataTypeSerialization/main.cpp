// This file combines different aspects of how can we serialize and de-serialize each of the object at binary level for
// various different fields of a custom C++ data type which shows how we are actually handling data in memory.

#include <fstream>
#include <iostream>

#include "Person.h"

auto main() -> int {
    constexpr double ALICE_SALARY = 75000.0;
    Person const personOut(1, "Alice Smith", ALICE_SALARY);

    std::ofstream outFile("person.dat", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening output file" << '\n';
        return 1;
    }

    personOut.serialize(outFile);
    outFile.close();

    std::cout << "Done Serializing!\n";

    Person personIN{};

    std::ifstream inFile("person.dat", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening input file" << '\n';
        return 1;
    }

    personIN.deserialize(inFile);
    inFile.close();

    std::cout << "Done Deserializing! Please find the displays\n";

    std::cout << "\nPerson Out:\n";
    personOut.display();

    std::cout << "\nPerson In:\n";
    personIN.display();
    return 0;
}