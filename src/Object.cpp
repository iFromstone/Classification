#include "Object.h"

using namespace ObjectsTest;

const Classification Object::classObject( "Object", nullptr, nullptr );

Object::Object() = default;
Object::~Object() = default;

Classification* Object::GetClass() const
{
    return CLASSIFICATION( Object );
}

Classification* Object::GetClassStatic()
{
    return CLASSIFICATION( Object );
}
