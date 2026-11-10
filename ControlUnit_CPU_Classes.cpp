#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class CPU {
private:
    int pc;
    string ir;
    bool halted;

public:
    CPU() {
        reset(0);
    }

    void reset(int startAddress = 0) {
        pc = startAddress;
        ir = "0000";
        halted = false;
    }

    int getPC() const {
        return pc;
    }

    void setPC(int newPC) {
        pc = newPC;
    }

    string getIR() const {
        return ir;
    }

    void setIR(string newIR) {
        ir = newIR;
    }

    bool isHalted() const {
        return halted;
    }

    void setHalted(bool status) {
        halted = status;
    }
};

class ControlUnit {
public:
    Status execute(const Instruction& inst, Memory& mem, RegisterFile& regs, ALU& alu, OutputDevice& screen, CPU& cpu) {
        char op = inst.getOpcode();
        int r = inst.getR();
        int s = inst.getS();
        int t = inst.getT();
        int addr = inst.getAddress();
        unsigned char val = inst.getOperand();

        switch (op) {
        case '1':
            regs.write(r, mem.read(addr));
            break;

        case '2':
            regs.write(r, val);
            break;

        case '3':
            mem.write(addr, regs.read(r));
            if (addr == 0xFF) {
                screen.write(regs.read(r));
            }
            break;

        case '4':
            regs.write(t, regs.read(s));
            break;

        case '5':
            regs.write(r, alu.addSigned(regs.read(s), regs.read(t)));
            break;

        case '7':
            regs.write(r, alu.bitwiseOR(regs.read(s), regs.read(t)));
            break;

        case '8':
            regs.write(r, alu.bitwiseAND(regs.read(s), regs.read(t)));
            break;

        case '9':
            regs.write(r, alu.bitwiseXOR(regs.read(s), regs.read(t)));
            break;

        case 'A':
            regs.write(r, alu.rotateRight(regs.read(r), t));
            break;

        case 'B':
            if (regs.read(r) == regs.read(0)) {
                cpu.setPC(addr);
            }
            break;

        case 'C':
            if (inst.getRaw() == "C000") {
                cpu.setHalted(true);
                return Status::HALTED;
            }
            return Status::INVALID_INSTRUCTION;

        default:
            return Status::INVALID_INSTRUCTION;
        }
        return Status::CONTINUE;
    }
};