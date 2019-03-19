#include "TestClasses.h"

using namespace ObjectsTest;

IMPLEMENT_CLASS( Test1, Object )
IMPLEMENT_CLASS( Test2, Object )
IMPLEMENT_CLASS( Test3, Test1 )

Test3::Test3()
{
    name = "Test3";
}
