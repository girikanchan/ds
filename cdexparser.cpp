#include <iostream>
#include <string>
#include <cctype>

class RecursiveDescentParser {
public:
    RecursiveDescentParser(const std::string& input) : input_(input), pos_(0) {}

    int parseExpression() {
        int result = parseTerm();
        while (pos_ < input_.length() && (input_[pos_] == '+' || input_[pos_] == '-')) {
            char op = input_[pos_++];
            int right = parseTerm();
            if (op == '+') {
                result += right;
            } else {
                result -= right;
            }
        }
        return result;
    }

    int parseTerm() {
        int result = parseFactor();
        while (pos_ < input_.length() && (input_[pos_] == '*' || input_[pos_] == '/')) {
            char op = input_[pos_++];
            int right = parseFactor();
            if (op == '*') {
                result *= right;
            } else {
                if (right != 0) {
                    result /= right;
                } else {
                    throw std::runtime_error("Division by zero.");
                }
            }
        }
        return result;
    }

    int parseFactor() {
        if (pos_ >= input_.length()) {
            throw std::runtime_error("Unexpected end of input.");
        }
        if (isdigit(input_[pos_])) {
            int number = 0;
            while (pos_ < input_.length() && isdigit(input_[pos_])) {
                number = number * 10 + (input_[pos_] - '0');
                pos_++;
            }
            return number;
        } else if (input_[pos_] == '(') {
            pos_++;
            int result = parseExpression();
            if (pos_ >= input_.length() || input_[pos_] != ')') {
                throw std::runtime_error("Mismatched parentheses.");
            }
            pos_++;
            return result;
        } else {
            throw std::runtime_error("Unexpected character: " + std::string(1, input_[pos_]));

        }
    }

private:
    const std::string& input_;
    size_t pos_;
};

int main() {
    std::string input;
    std::cout << "Enter an arithmetic expression: ";
    std::cin >> input;

    RecursiveDescentParser parser(input);
    try {
        int result = parser.parseExpression();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
