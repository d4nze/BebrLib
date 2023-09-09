#include "Shape.h"

template<typename VertexType>
bebr::shapes::Shape<VertexType>::Shape() : m_texture( nullptr ) {}

#include "Shape2Vertex.h"

template class bebr::shapes::Shape<bebr::shapes::Shape2Vertex>;
