#ifndef BRAINF_H
#define BRAINF_H

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

#endif // BRAINF_H