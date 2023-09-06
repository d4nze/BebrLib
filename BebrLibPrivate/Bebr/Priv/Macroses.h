#pragma once

#define TEMPLATE_SOMETHING( Something )\
template Something<int>;\
template Something<unsigned int>;\
template Something<short>;\
template Something<unsigned short>;\
template Something<long>;\
template Something<unsigned long>;\
template Something<long long>;\
template Something<unsigned long long>;\
template Something<float>;\
template Something<double>;\
template Something<long double>;\
template Something<char>;\
template Something<unsigned char>;\
template Something<bool>;\
template Something<wchar_t>
#define TEMPLATE_STRUCT( Struct ) TEMPLATE_SOMETHING( struct Struct )
#define TEMPLATE_CLASS( Class ) TEMPLATE_SOMETHING( class Class )

#define TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, type ) template void method<type>(const std::vector<type>&) const
#define TEMPLATE_VERTEX_BUFFER_METHOD( method )\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, int );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, unsigned int );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, short );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, unsigned short );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, long );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, unsigned long );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, long long );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, unsigned long long );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, float );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, double );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, long double );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, char );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, unsigned char );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, bool );\
TEMPLATE_VERTEX_BUFFER_METHOD_TYPE( method, wchar_t )
