// The goal of the program is to highlight the idea of anon objects that are used withing C++.
// Basic concept here is that: All the data that we access are done via an abstraction of the memory box present called
// as Objects. An Object with a names becomes variable.

#include <cmath>
#include <iostream>

// We use using for modern C++ as typedef is an old keyword
using Coordinate_x = int;
using Coordinate_y = int;

// More readable with function name first, then parameters and what it returns
auto main() -> int {
    constexpr unsigned int NUM_10 = 10;
    constexpr unsigned int NUM_20 = 20;
    std::cout << "Sum of 10 and 20 is " << NUM_10 + NUM_20 << '\n'; // Where is the sum being stored? Anon Objects

    class Point {
        Coordinate_x x_;
        Coordinate_y y_;

    public:
        Point(Coordinate_x x, Coordinate_y y) : x_(x), y_(y) { // NOLINT
        }

        // Don't discard the result from distance() and it also does not change the given members
        [[nodiscard]] auto distance(const Point &other) const -> double {
            return std::hypot(x_ - other.x_, y_ - other.y_);
        }
    };

    Point const first{NUM_10, NUM_20};

    // We will create a new object there itself and then we will find the distance here - anon objects
    std::cout << "Anon Distance of (10,20) with (5,10): " <<  first.distance(Point{NUM_10/2, NUM_20/2}) << '\n';
    return 0;
}