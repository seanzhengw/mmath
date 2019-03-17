#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mmath/Transform.h>

using mmath::TransformD;

class TransformTest : public ::testing::Test
{
protected:
    TransformTest() {}
    virtual ~TransformTest() {}
    virtual void SetUp() override
    {
        tran[0] = 12;
        tran[1] = 123;
        tran[2] = 1234;
        tran[3] = 4321;
        tran[4] = 321;
        tran[5] = 21;
    }
    virtual void TearDown() override
    {
    }

    TransformD tran;
};

TEST_F(TransformTest, SubscriptOperatorTest)
{
    ASSERT_EQ(tran.pos.x, tran[0]);
    ASSERT_EQ(tran.pos.y, tran[1]);
    ASSERT_EQ(tran.pos.z, tran[2]);
    ASSERT_EQ(tran.rot.x, tran[3]);
    ASSERT_EQ(tran.rot.y, tran[4]);
    ASSERT_EQ(tran.rot.z, tran[5]);
}
