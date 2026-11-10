#include <iostream>
#include <string>

using namespace std;

// تعريف أنواع بسيطة (Type Aliases) لتوضيح المعنى
typedef unsigned short Word; // 16-bit word
typedef unsigned char Byte;  // 8-bit byte

class Instruction {
private:
    Word rawWord;
    char opcode;
    int regR;
    int regS;
    int regT;
    Byte operand;

public:
    // Constructor لتهيئة التعليمة
    Instruction(Word raw, char op, int r, int s, int t, Byte opnd) {
        rawWord = raw;
        opcode = op;
        regR = r;
        regS = s;
        regT = t;
        operand = opnd;
    }

    // Getters لاسترجاع القيم بسهولة
    char getOpcode() const { return opcode; }
    int getR() const { return regR; }
    int getS() const { return regS; }
    int getT() const { return regT; }
    Byte getOperand() const { return operand; }
    Word getRawWord() const { return rawWord; }
};