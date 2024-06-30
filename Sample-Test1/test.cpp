#include "pch.h"
#include "../Project1/ALU.cpp";
#include "../Project1/Output.cpp";

#include <string>
using namespace std;

class ALUFixture :public testing::Test {
public:

    ALU alu;
    Output ret;

    void commonFunc(int op1, int op2, string oper) {

        int expResult = 0;
        int expStatus = 0;

        alu.setOperand1(op1);
        alu.setOperand2(op2);
        alu.setOPCODE(oper);

        alu.enableSignal(&ret);

        if (!(oper == "ADD" || oper == "SUB" || oper == "MUL"))
        {
            expResult = 65535;
            expStatus = 3;
        }
        else
        {
            if (op1 == -1) {
                expResult = 65535;
                expStatus = 1;
            }
            else if (op2 == -1) {
                expResult = 65535;
                expStatus = 2;
            }
            else
            {
                if (oper == "ADD")
                {
                    expResult = op1 + op2;
                }
                else if (oper == "SUB")
                {
                    expResult = op1 - op2;
                }
                else if (oper == "MUL")
                {
                    expResult = op1 * op2;
                }
            }
        }

        EXPECT_EQ(expResult, ret.getResult());
        EXPECT_EQ(expStatus, ret.getStatus());
    }

protected:
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST_F(ALUFixture, ADDTest) {
    commonFunc(10, 20, "ADD");
}

TEST_F(ALUFixture, ADDTest2) {
    commonFunc(-1, 20, "ADD");
}

TEST_F(ALUFixture, ADDTest3) {
    commonFunc(10, -1, "ADD");
}

TEST_F(ALUFixture, MULTest) {
    commonFunc(10, 20, "MUL");
}

TEST_F(ALUFixture, MULTest2) {
    commonFunc(-1, 20, "MUL");
}

TEST_F(ALUFixture, MULTest3) {
    commonFunc(10, -1, "MUL");
}

TEST_F(ALUFixture, SUBTest) {
    commonFunc(10, 20, "SUB");
}

TEST_F(ALUFixture, SUBTest2) {
    commonFunc(-1, 20, "SUB");
}

TEST_F(ALUFixture, SUBTest3) {
    commonFunc(10, -1, "SUB");
}

TEST_F(ALUFixture, ETCTest) {
    commonFunc(10, 20, "ETC");
}