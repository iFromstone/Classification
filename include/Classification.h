#pragma once

#include <unordered_map>

namespace ObjectsTest
{
    class Object;

    class Classification final
    {
    public:
        explicit Classification( const char* className,
            const Classification* baseClass,
            Object* ( *pCreateFunc )( ) );

        Object*                      CreateObject() const;
        static Object*               CreateObject( const std::string& name );
        static const Classification* FromName( const std::string& name );


        bool IsDerivedFrom( const Classification* base ) const;
        bool operator==( const Classification& other ) const;

    private:
        using Classes = std::unordered_map<std::string, const Classification*>;

        static Classes& GetClasses();

        const Classification* myBase;
        unsigned int          index;
        Object* ( *createFunc )( );
    };

#define CLASSIFICATION( class_name ) ( (Classification*)( &class_name::class##class_name ) )
}
