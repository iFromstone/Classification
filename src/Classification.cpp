#include "Classification.h"
#include <atomic>

using namespace ObjectsTest;

namespace
{
    std::atomic<unsigned int> lastClassIndex;
}

Classification::Classification( const char* className,
    const Classification* baseClass,
    Object* ( *pCreateFunc )( ) )
    : myBase( baseClass )
    , index( ++lastClassIndex )
    , createFunc( pCreateFunc )
{
    GetClasses().insert( std::make_pair( className, this ) );
}

Object* Classification::CreateObject() const
{
    if ( createFunc() )
        return createFunc();

    return nullptr;
}

Object* Classification::CreateObject( const std::string& name )
{
    const auto& classes = GetClasses();
    const auto  it = classes.find( name );

    return it != classes.end() ? it->second->CreateObject() : nullptr;
}

const Classification* Classification::FromName( const std::string& name )
{
    const auto& classes = GetClasses();
    const auto  it = classes.find( name );

    return it != classes.end() ? it->second : nullptr;
}

bool Classification::IsDerivedFrom( const Classification* base ) const
{
    if ( myBase == nullptr )
        return false;

    if ( myBase == base )
        return true;

    return myBase->IsDerivedFrom( base );
}

bool Classification::operator==( const Classification& other ) const
{
    return index == other.index;
}

Classification::Classes& Classification::GetClasses()
{
    static Classes map;
    return map;
}
