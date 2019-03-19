#include "TestClasses.h"

#include <memory>
#include <iostream>

using namespace ObjectsTest;
using namespace std;

namespace
{
    void TEST_CREATE( const std::string& name )
    {
        cout << "\nTEST_CREATE:\n\n";

        const auto object = Classification::CreateObject( name );

        if ( object )
        {
            cout << name.c_str() << " - created\n";

            if ( object->IsA<Object>() )
                cout << name.c_str() << " is a Object\n";

            return;
        }

        cout << "Test failed\n";
    }

    void TEST_ISA()
    {
        cout << "\nTEST_ISA:\n\n";

        const auto a1 = std::make_unique<Test1>();
        const auto a3 = std::make_unique<Test3>();

        if ( a1->IsA<Object>() )
            cout << "a1 is a Object\n";

        if ( a1->IsA<Test1>() )
            cout << "a1 is a Test1\n";

        if ( !a1->IsA<Test2>() )
            cout << "a1 is not a Test2\n";

        if ( a3->IsA<Object>() )
            cout << "a3 is a Object\n";

        if ( a3->IsA<Test1>() )
            cout << "a3 is a Test1\n";
    }
}

int main()
{
    TEST_CREATE( "Test1" );
    TEST_ISA();

    system( "pause" );

    return 0;
}
