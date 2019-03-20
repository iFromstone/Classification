#include "TestClasses.h"

#include <memory>
#include <gtest/gtest.h>

using namespace ObjectsTest;

TEST( ClassificationTestSuite, TestCreateObject )
{
    const auto object = Classification::CreateObject( "Test1" );

    EXPECT_NE( object, nullptr );
    EXPECT_TRUE( object->IsA<Object>() );
}

class ClassificationTestSuiteFixture : public ::testing::Test
{
protected:
    void SetUp() override
    {        
        ot1 = std::make_unique<Test1>();
        ot3 = std::make_unique<Test3>();
    }

    std::unique_ptr<Test1> ot1;
    std::unique_ptr<Test3> ot3;
};

TEST_F( ClassificationTestSuiteFixture, TestIsAObject )
{
    EXPECT_TRUE( ot1->IsA<Object>() );
    EXPECT_TRUE( ot3->IsA<Object>() );
}

TEST_F( ClassificationTestSuiteFixture, TestIsADerived )
{
    EXPECT_TRUE( ot1->IsA<Test1>() );
    EXPECT_TRUE( ot3->IsA<Test1>() );
}

TEST_F( ClassificationTestSuiteFixture, TestIsNotADerived )
{
    EXPECT_FALSE( ot1->IsA<Test2>() );
}
