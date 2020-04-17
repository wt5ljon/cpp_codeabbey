// Problem 12: Modulo and Time Difference
#include <iostream>
#include <sstream>

class Time {
private:
    int m_day{};
    int m_hour{};
    int m_minute{};
    int m_second{};
    int m_totalSeconds{};
public:
    Time(int day, int hour, int minute, int second)
        :m_day{ day }, m_hour{ hour }, m_minute{ minute },
         m_second{ second } {
        m_totalSeconds = m_day * 24 * 3600 + m_hour * 3600 +
                         m_minute * 60 + m_second;
    }

    Time calcDifference(const Time& other) {
        int difference{ m_totalSeconds - other.m_totalSeconds };
        int day{ difference / (24 * 3600) };
        difference = difference % (24 * 3600);
        int hour{ difference / 3600 };
        difference = difference % 3600;
        int minute{ difference / 60 }; 
        int second{ difference % 60 };
        return Time(day, hour, minute, second);
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& time);
};

std::ostream& operator<<(std::ostream& out, const Time& time) {
    out << '(' << time.m_day << ' ' << time.m_hour << ' ' <<
           time.m_minute << ' ' << time.m_second << ')';
    return out;
}

int main() {
    int cases{};
    std::cin >> cases;

    std::ostringstream out{};
    for (int i{ 0 }; i < cases; ++i) {
        int d1, h1, m1, s1, d2, h2, m2, s2;
        std::cin >> d1 >> h1 >> m1 >> s1 >> 
                    d2 >> h2 >> m2 >> s2;
        Time t1(d1, h1, m1, s1);
        Time t2(d2, h2, m2, s2);
        Time tDiff{ t2.calcDifference(t1) };
        out << tDiff << ' '; 
    }      

    std::cout << '\n' << out.str() << '\n';

    return 0;
}