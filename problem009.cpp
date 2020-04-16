// Problem 9: Triangles
#include <iostream>
#include <sstream>
#include <vector>

struct Triangle {
    int side_a{};
    int side_b{};
    int side_c{};
};

int main() {
    int cases{};
    std::cin >> cases;
    std::vector<Triangle> shapes{};

    for (int i{ 0 }; i < cases; ++i) {
        Triangle tri;
        std::cin >> tri.side_a >> tri.side_b >> tri.side_c;
        shapes.push_back(tri);
    }

    std::ostringstream out{};
    for (auto shape: shapes) {
        bool isTriangle{ true };
        if (shape.side_a + shape.side_b <= shape.side_c ||
            shape.side_b + shape.side_c <= shape.side_a ||
            shape.side_a + shape.side_c <= shape.side_b)
            isTriangle = false;
        out << isTriangle << ' ';
    }

    std::cout << '\n';
    std::cout << out.str() << '\n';

    return 0;    
}