#include "Shape.h"

template<typename VertexType>
bebr::shape::Shape<VertexType>::Shape() : m_texture( nullptr ) {}

#include "Shape2Vertex.h"

template class bebr::shape::Shape<bebr::shape::Shape2Vertex>;
