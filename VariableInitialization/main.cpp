#include <iostream>
#include <string>

[[maybe_unused]] constexpr int DEFAULT_NUM = 42;

struct CustomDataType {
    int num = DEFAULT_NUM;
    std::string str = "Hello World!";
};

auto main() -> int {
    // no init - compile error because of -Werror
    // int x;
    // std::cout << x << '\n';

    // copy with equal
    int const var = DEFAULT_NUM;
    std::cout << var << '\n';

    // direct with parenthesis
    CustomDataType const first(DEFAULT_NUM*2, "GGs");
    std::cout << first.num << " w/ " << first.str << '\n';

    // Direct with Brances
    CustomDataType const second{DEFAULT_NUM*3, "Hello World!"};
    std::cout << second.num << " w/ " << second.str << '\n';

    // default with braces
    CustomDataType const third;
    std::cout << third.num << " w/ " << third.str << '\n';

    // illegal narrow conversion - compile error
    // int const wax{4.5};
    return 0;
}