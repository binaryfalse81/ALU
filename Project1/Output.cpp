#pragma once

enum ErrorCode {
    INVALID_STATUS_NO_INPUT = -1,
    SUCCESS_STATUS = 0,
    INVALID_STATUS_OPERAND1 = 1,
    INVALID_STATUS_OPERAND2 = 2,
    INVALID_STATUS_OPCODE = 3,
    INVALID_NO_RESULT = 65535
};

class Output
{
public:
    void setOutput(int status, int result) {
        this->Status = status;
        this->Result = result;
    }

    int getStatus() {
        return Status;
    }

    int getResult() {
        return Result;
    }

private:

    int Status = INVALID_STATUS_NO_INPUT;
    int Result = INVALID_NO_RESULT;

};