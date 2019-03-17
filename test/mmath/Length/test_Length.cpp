#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <mmath/Length.h>
#include <mmath/Vector3.h>

using mmath::Length;
using mmath::Vector;

class LengthTest : public ::testing::Test
{
protected:
    LengthTest() {}
    virtual ~LengthTest() {}
    virtual void SetUp() override
    {
    }
    virtual void TearDown() override
    {
    }
};

TEST_F(LengthTest, Vector3FloatTest)
{
    ASSERT_EQ(Length<float>(Vector<3, float>(1.0, 0.0, 0.0)), 1.0f);
    ASSERT_EQ(Length<float>(Vector<3, float>(0.0, 0.8, 0.6)), 1.0f);
    ASSERT_EQ(Length<float>(Vector<3, float>(1.0, 1.0, 0.0)), 1.41421356237309504880f);
    ASSERT_EQ(Length<float>(Vector<3, float>(1.0, 0.8, 0.6)), 1.41421356237309504880f);
    ASSERT_EQ(Length<float>(Vector<3, float>(1.0, 1.0, 1.0)), 1.73205080756887729352f);
    ASSERT_EQ(Length<float>(Vector<3, float>(2.0, 0.0, 0.0)), 2.0f);
    ASSERT_EQ(Length<float>(Vector<3, float>(0.0, 1.6, 1.2)), 2.0f);
    ASSERT_EQ(Length<float>(Vector<3, float>(10.0, 10.0, 10.0)), 17.3205080756887729352f);

    ASSERT_EQ(Length<float>(Vector<3, float>(-1.0, 0.0, 0.0)), 1.0f);
    ASSERT_EQ(Length<float>(Vector<3, float>(0.0, 0.8, -0.6)), 1.0f);
    ASSERT_EQ(Length<float>(Vector<3, float>(1.0, -1.0, 0.0)), 1.41421356237309504880f);
    ASSERT_EQ(Length<float>(Vector<3, float>(-1.0, 0.8, -0.6)), 1.41421356237309504880f);
    ASSERT_EQ(Length<float>(Vector<3, float>(1.0, -1.0, 1.0)), 1.73205080756887729352f);
    ASSERT_EQ(Length<float>(Vector<3, float>(-2.0, 0.0, 0.0)), 2.0f);
    ASSERT_EQ(Length<float>(Vector<3, float>(0.0, -1.6, -1.2)), 2.0f);
    ASSERT_EQ(Length<float>(Vector<3, float>(-10.0, -10.0, 10.0)), 17.3205080756887729352f);
}

TEST_F(LengthTest, Vector3DoubleTest)
{
    ASSERT_EQ(Length<double>(Vector<3, double>(1.0, 0.0, 0.0)), 1.0);
    ASSERT_EQ(Length<double>(Vector<3, double>(0.0, 0.8, 0.6)), 1.0);
    ASSERT_EQ(Length<double>(Vector<3, double>(1.0, 1.0, 0.0)), 1.41421356237309504880);
    ASSERT_EQ(Length<double>(Vector<3, double>(1.0, 0.8, 0.6)), 1.41421356237309504880);
    ASSERT_EQ(Length<double>(Vector<3, double>(1.0, 1.0, 1.0)), 1.73205080756887729352);
    ASSERT_EQ(Length<double>(Vector<3, double>(2.0, 0.0, 0.0)), 2.0);
    ASSERT_EQ(Length<double>(Vector<3, double>(0.0, 1.6, 1.2)), 2.0);
    ASSERT_EQ(Length<double>(Vector<3, double>(10.0, 10.0, 10.0)), 17.3205080756887729352);

    ASSERT_EQ(Length<double>(Vector<3, double>(-1.0, 0.0, 0.0)), 1.0);
    ASSERT_EQ(Length<double>(Vector<3, double>(0.0, 0.8, -0.6)), 1.0);
    ASSERT_EQ(Length<double>(Vector<3, double>(1.0, -1.0, 0.0)), 1.41421356237309504880);
    ASSERT_EQ(Length<double>(Vector<3, double>(-1.0, 0.8, -0.6)), 1.41421356237309504880);
    ASSERT_EQ(Length<double>(Vector<3, double>(1.0, -1.0, 1.0)), 1.73205080756887729352);
    ASSERT_EQ(Length<double>(Vector<3, double>(-2.0, 0.0, 0.0)), 2.0);
    ASSERT_EQ(Length<double>(Vector<3, double>(0.0, -1.6, -1.2)), 2.0);
    ASSERT_EQ(Length<double>(Vector<3, double>(-10.0, -10.0, 10.0)), 17.3205080756887729352);
}