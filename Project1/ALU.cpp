#pragma once

#include <string>
#include "Output.cpp"

class ALU {
public:
    void enableSignal(Output* r) {
        if (isInvalidOPCODE()) {
            r->setOutput(INVALID_STATUS_OPCODE, INVALID_NO_RESULT);
            return;
        }

        if (isInvalidOperand1()) {
            r->setOutput(INVALID_STATUS_OPERAND1, INVALID_NO_RESULT);
            return;
        }

        if (isInvalidOperand2()) {
            r->setOutput(INVALID_STATUS_OPERAND2, INVALID_NO_RESULT);
            return;
        }

        int result = calOperand();
        r->setOutput(SUCCESS_STATUS, result);
    }

    void setOperand1(int operand1) {
        this->Operand1 = operand1;
    }

    void setOperand2(int operand2) {
        this->Operand2 = operand2;
    }

    void setOPCODE(std::string OPCODE) {
        this->OPCODE = OPCODE;
    }

    bool isInvalidOperand1()
    {
        return Operand1 == INVALID_STATUS_NO_INPUT;
    }

    bool isInvalidOperand2()
    {
        return Operand2 == INVALID_STATUS_NO_INPUT;
    }

    bool isInvalidOPCODE()
    {
        return OPCODE != "ADD" && OPCODE != "MUL" && OPCODE != "SUB";
    }

    int calOperand() {
        if (OPCODE == "ADD") return Operand1 + Operand2;
        if (OPCODE == "MUL") return Operand1 * Operand2;
        if (OPCODE == "SUB") return Operand1 - Operand2;
    }

private:
    int Operand1 = INVALID_STATUS_NO_INPUT;
    int Operand2 = INVALID_STATUS_NO_INPUT;
    std::string OPCODE = "";
};