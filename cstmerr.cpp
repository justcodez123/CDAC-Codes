#include <iostream>
#include <string>
#include <stdexcept>

// 1. We create a new struct that inherits from a standard exception.
struct MathError : public std::runtime_error {
    // 2. Its constructor just passes the error message up to the parent.
    MathError(const std::string& message)
        : std::runtime_error(message) {}
};

// 3. Now our function can throw our custom, descriptive error.
double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw MathError("Division by zero occurred.");
    }
    return static_cast<double>(numerator) / denominator;
}

int main() {
    try {
        double result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    }
    // 4. And we can catch our specific error type!
    catch (const MathError& e) {
        std::cerr << "Caught a Math Error: " << e.what() << std::endl;
    }

    return 0;
}