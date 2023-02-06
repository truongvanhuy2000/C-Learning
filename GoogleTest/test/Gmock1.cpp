#include<iostream>
#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include <stdlib.h>
#include <cstdlib>
using :: testing :: AtLeast;
using :: testing ::_;
using :: testing :: InvokeWithoutArgs;
using :: testing :: Return;
using :: testing :: ReturnRoundRobin;
using :: testing :: NiceMock;
using :: testing :: Invoke;
class GumballMachineInterface
{
    public:
        virtual void insertQuarter() = 0;
        virtual int ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispenseGumball() = 0;
        virtual void dispensePrize() = 0;
        virtual bool isWin() = 0;
        virtual int getGumballs() = 0;
};
class MockGumball : public GumballMachineInterface
{
    public:
        MOCK_METHOD(void, insertQuarter, (), (override));
        MOCK_METHOD(int, ejectQuarter, (), (override));
        MOCK_METHOD(void, turnCrank, (), (override));
        MOCK_METHOD(void, dispenseGumball, (), (override));
        MOCK_METHOD(void, dispensePrize, (), (override));
        MOCK_METHOD(bool, isWin, (), (override));
        MOCK_METHOD(int, getGumballs, (), (override));
};

class TestUnit
{
    GumballMachineInterface* mGumballMachine;
    int mGumballAmount;
    public:
    TestUnit(GumballMachineInterface* gumballMachine, int amount)  : mGumballMachine(gumballMachine), mGumballAmount(amount){};
    ~TestUnit(){}
    bool beginTest()
    {
        mGumballMachine->insertQuarter();
        mGumballMachine->turnCrank();
        if(mGumballMachine->getGumballs() == 0)
        {
            mGumballMachine->ejectQuarter();
            return false;
        }
        if(mGumballMachine->isWin())
        {
            mGumballMachine->dispensePrize();
        }
        mGumballMachine->dispenseGumball();
        return true;
    }
    bool randomGenerator()
    {
        int mRandom;
        mRandom = rand() % 2 + 0;
        if(mRandom == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int decreasingOrder()
    {
        mGumballAmount--;
        return mGumballAmount;
    }
};

TEST(GumballTest, runGood)
{
    MockGumball mockGumball;
    TestUnit testUnit1(&mockGumball, 9);
    int count = 9;
    bool result;
    EXPECT_CALL(mockGumball, insertQuarter()).Times(AtLeast(10));
    EXPECT_CALL(mockGumball, turnCrank()).Times(AtLeast(10));
    EXPECT_CALL(mockGumball, dispenseGumball()).Times(AtLeast(10));
    EXPECT_CALL(mockGumball, getGumballs()).Times(AtLeast(10)).WillRepeatedly(Invoke(&testUnit1, &TestUnit::decreasingOrder));
    EXPECT_CALL(mockGumball, isWin()).Times(AtLeast(10)).WillRepeatedly(InvokeWithoutArgs(&testUnit1, &TestUnit::randomGenerator));
    EXPECT_CALL(mockGumball, dispensePrize()).Times(2);
    EXPECT_CALL(mockGumball, ejectQuarter()).Times(1);
    while(count > 0)
    {
        result = testUnit1.beginTest();
        count--;
        EXPECT_TRUE(result);
    }
    
}