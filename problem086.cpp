// Problem 86: BrainFuck Interpreter
#include <iostream>
#include <sstream>

class BrainF {
private:
    int* m_memory { nullptr };
    int m_memoryCounter{ 0 };
    const char* m_program{ nullptr };
    int m_programCounter{ 0 };
    int* m_dstack{ nullptr };
    int m_dstackCounter{ 0 };
    int* m_pstack{ nullptr };
    int m_pstackCounter{ 0 };
    const static int MAX_MEMORY{ 100 };
    const static int MAX_STACK{ 20 };
public:
    BrainF();
    BrainF(const char* code);
    void run();
    void setInput(const std::string& in) const;
    ~BrainF();
private:
    bool push();
    bool pop();
    bool ppush(int pc);
    int  ppop();
    void jumpForward(int pc);
};

BrainF::BrainF() :m_memoryCounter{ 0 }, m_programCounter{ 0 },
                  m_dstackCounter{ 0 }, m_pstackCounter{ 0 } {
    m_memory = new int[MAX_MEMORY]{ 0 };   // 99 locations available
    m_dstack = new int[MAX_STACK]{ 0 };    // 19 locations available
    m_pstack = new int[MAX_STACK]{ 0 };    // 19 locations available
    m_program = nullptr;
}

BrainF::BrainF(const char* code) :BrainF() {
    m_program = code;
}

// data stack push operation
bool BrainF::push() {
    if (m_dstackCounter < MAX_STACK - 1) {
       m_dstack[++m_dstackCounter] = m_memory[m_memoryCounter]; 
       return true;
    }
    return false;
}

// data stack pop operation
bool BrainF::pop() {
    if (m_dstackCounter != 0) {
        m_memory[m_memoryCounter] = m_dstack[m_dstackCounter--];
        return true;
    }
    return false;
}

// program stack push operation
bool BrainF::ppush(int pc) {
    if (m_pstackCounter < MAX_STACK - 1) {
       m_pstack[++m_pstackCounter] = pc; 
       return true;
    }
    return false;
}

// program stack pop operation
int BrainF::ppop() {
    if (m_pstackCounter != 0)
        return m_pstack[m_pstackCounter--];
    return -1;
}

void BrainF::jumpForward(int pc) {
    int level{ m_pstackCounter };
    ++pc;
    while (m_program[pc++] != '\0') {
        if (m_program[pc] == '[')
            ppush(pc);
        else if (m_program[pc] == ']' && level != m_pstackCounter)
            ppop();
        else if (m_program[pc] == ']' && level == m_pstackCounter) {
            m_programCounter = pc;
            return;
        }
    }
}

void BrainF::run() {
    while(*(m_program + m_programCounter) != '\0') {
        switch(m_program[m_programCounter]) {
            case '>':
                ++m_memoryCounter;
                break;
            case '<':
                --m_memoryCounter;
                break;
            case '+':
                ++m_memory[m_memoryCounter];
                break;
            case '-':
                --m_memory[m_memoryCounter];
                break;
            case '.':
                std::cout << static_cast<char>(m_memory[m_memoryCounter]);
                break;
            case ',':
                char ch;
                std::cin >> ch;
                m_memory[m_memoryCounter] = static_cast<int>(ch);
                break;
            case ':':
                std::cout << m_memory[m_memoryCounter] << ' ';
                break;
            case ';':
                int val;
                std::cin >> val;
                m_memory[m_memoryCounter] = val;
                break;
            case '[':
                if (m_memory[m_memoryCounter] == 0)
                    jumpForward(m_programCounter);
                else
                    ppush(m_programCounter);
                break;
            case ']':
                m_programCounter = ppop();
                continue;
            case '#':
                push();
                break;
            case '$':
                pop();
                break;
            default:
                ;
        }
        ++m_programCounter;
    }
}

BrainF::~BrainF() {
    delete[] m_memory;
    delete[] m_dstack;
}

int main() {
    std::string program{};
    getline(std::cin, program);
    BrainF b(program.c_str());

    b.run();
    std::cout << '\n';

    return 0;
}