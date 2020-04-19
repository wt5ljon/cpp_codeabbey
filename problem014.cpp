// Problem 14: Modular Calculator
#include <iostream>
#include <vector>

struct Operation {
    char op_sign{};
    int  op_value{};
};

int main() {
    int modval{};
    std::vector<Operation> operation;

    int result{};
    std::cin >> result;

    while (true) {
        char op;
        int num;
        std::cin >> op >> num;
        
        operation.push_back({ op, num });

        if (op == '%') {
            modval = num;
            break;
        }
    }

    for (auto op: operation) {
        if (op.op_sign == '+') {
            result += op.op_value;
            result %= modval;
        }
        if (op.op_sign == '*') {
            result *= op.op_value;
            result %= modval;
        }
        if (op.op_sign == '%') {
            result %= modval;
        }
    }

    std::cout << '\n' << result << '\n';

    return 0;
}