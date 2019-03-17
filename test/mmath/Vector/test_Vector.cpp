#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mmath/Vector3.h>

using mmath::Vector3D;

class VectorTest : public ::testing::Test
{
protected:
    VectorTest() {}
    virtual ~VectorTest() {}
    virtual void SetUp() override
    {
        vec.x = 0;
        vec.y = 0;
        vec.z = 0;
    }
    virtual void TearDown() override
    {
    }

    Vector3D vec;
};

TEST_F(VectorTest, SubscriptOperatorTest)
{
    ASSERT_EQ(vec.x, vec[0]);
    ASSERT_EQ(vec.y, vec[1]);
    ASSERT_EQ(vec.z, vec[2]);
}

TEST_F(VectorTest, RawDataTest)
{
    ASSERT_EQ(vec.data()[0], vec[0]);
    ASSERT_EQ(vec.data()[1], vec[1]);
    ASSERT_EQ(vec.data()[2], vec[2]);

    ASSERT_EQ(vec.data() + 0, &vec.x);
    ASSERT_EQ(vec.data() + 1, &vec.y);
    ASSERT_EQ(vec.data() + 2, &vec.z);
}
