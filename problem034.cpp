// Problem 34: Savings Calculagtor
#include <iostream>
#include <sstream>

class Savings {
private:
    int m_principal{};
    double m_apr{};
    int m_target{};
public:
    Savings(int principal, int target, int apr)
        :m_principal{ principal*100 }, m_apr{ apr / 100.0 },
         m_target{ target * 100 } {}
    double getPrincipal() const { return m_principal / 100.0; }
    double getTarget() const { return m_target / 100.0; }
    void advanceOneYear() { m_principal = static_cast<int>(m_principal * (1 + m_apr)); }
    bool isTarget() { return m_principal > m_target; }
};

int main() {
    int testcases{};
    std::cin >> testcases;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ostringstream out{};
    for (int i{ 0 }; i < testcases; ++i) {
        int start, required, rate;

        std::cin >> start >> required >> rate;
        Savings s(start, required, rate );
        int year{ 0 };
        while (!s.isTarget()) {
            s.advanceOneYear();
            ++year;
        }

        out << year << ' ';
    }

    std::cout << '\n' << out.str() << '\n';
    return 0;
}