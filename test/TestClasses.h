#pragma once
#include "Object.h"

namespace ObjectsTest
{
    class Test1 : public Object
    {
    public:
        DECLARE_CLASS( Test1 )
        Test1() {}

    protected:
        std::string name = "Test1";
    };

    class Test2 : public Object
    {
    public:
        DECLARE_CLASS( Test2 )
        Test2() {}

    private:
        std::string name = "Test2";
    };

    class Test3 : public Test1
    {
    public:
        DECLARE_CLASS( Test3 )
        Test3();
    };
}
