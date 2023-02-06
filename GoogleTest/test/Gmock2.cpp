#include<iostream>
#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include <stdlib.h>
#include <cstdlib>

class BankServer
{
    public:
    virtual bool Connect() = 0;
    virtual void Disconnect() = 0;
    virtual int GetBalance(int accountNumber) = 0;
    virtual void Debit(int accountNumber, int amount) = 0;
};
class MockBankServer : public BankServer
{
    public:
        MOCK_METHOD(bool, Connect, (), (override));
        MOCK_METHOD(void, Disconnect, (), (override));
        MOCK_METHOD(int, GetBalance, (int), (override));
        MOCK_METHOD(void, Debit, (int, int), (override));
};
class AtmMachine
{
    BankServer *mBank;
    public:
    AtmMachine(BankServer *bank)
    {
        mBank = bank;
    }
    bool Withdraw(int accountNumber, int amount)
    {
        bool result = false;
        mBank->Connect();
        if(amount <= mBank->GetBalance(accountNumber))
        {
            mBank ->Debit(accountNumber, amount);
            result = true;
        }
        mBank -> Disconnect();
        return result;
    }
};
using :: testing :: AtLeast;
using :: testing ::_;
using :: testing :: InvokeWithoutArgs;
using :: testing :: Return;
using :: testing :: Gt;
using :: testing :: Lt;
using ::testing :: NiceMock;
TEST(ATMTest, withDrawMoney)
{

    MockBankServer mockBank1;
    AtmMachine testUnit1(&mockBank1);
    EXPECT_CALL(mockBank1, Connect()).Times(1);
    EXPECT_CALL(mockBank1, Disconnect()).Times(1);
    EXPECT_CALL(mockBank1, GetBalance(Gt(0))).Times(1).WillOnce(Return(5000));
    EXPECT_CALL(mockBank1, Debit(Gt(0), Lt(10000))).Times(1);
    bool result1 = testUnit1.Withdraw(4511, 200);
    bool result2 = testUnit1.Withdraw(4511, 200);
    EXPECT_TRUE(result1);
    EXPECT_TRUE(result2);
}