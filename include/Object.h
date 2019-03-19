#pragma once

#include "Classification.h"

#define DISALLOW_COPY_AND_ASSIGN( TypeName ) \
    TypeName( const TypeName& ) = delete;    \
    void operator=( const TypeName& ) = delete;

namespace ObjectsTest
{
    class Object
    {
    public:
        DISALLOW_COPY_AND_ASSIGN( Object )

    public:
        virtual ~Object();

        template<class T> bool IsA() const;

        static const Classification classObject;
        virtual Classification*     GetClass() const;
        static  Classification*     GetClassStatic();

    protected:
        Object();
    };

    template<typename T> bool Object::IsA() const
    {
        const auto pThisClass = GetClass();

        if ( pThisClass == T::GetClassStatic() )
            return true;

        return pThisClass->IsDerivedFrom( T::GetClassStatic() );
    }

#define DECLARE_CLASS( class_name )                    \
    static const Classification class##class_name;     \
    static Classification*  GetClassStatic();          \
    virtual Classification* GetClass() const override; \
    static Object* CreateObject();

#define IMPLEMENT_CLASS( class_name, base_class_name )                                                 \
    const ObjectsTest::Classification class_name::class##class_name(                                   \
        #class_name, CLASSIFICATION( base_class_name ), class_name::CreateObject );                    \
    ObjectsTest::Classification* class_name::GetClassStatic() { return CLASSIFICATION( class_name ); } \
    ObjectsTest::Classification* class_name::GetClass() const { return CLASSIFICATION( class_name ); } \
    ObjectsTest::Object*         class_name::CreateObject() { return new class_name(); }
}
