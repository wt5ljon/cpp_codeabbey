// Problem 167: Line Copy
#include <iostream>
#include <sstream>
#include "brainf.h"

int main() {
    std::string program{ "+++++ +++++ >+[<#>>$ >, #>$ <<[->-<] >#<<$ >>[>. >#<<$]<<]" };
    BrainF b(program.c_str());

    std::string in{ "Invent some test cases yourself!\nThis line should not be copied!" };
    b.run(in);
    std::cout << '\n';

    return 0;
}