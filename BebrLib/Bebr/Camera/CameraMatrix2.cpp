#include "CameraMatrix2.h"

bebr::camera::CameraMatrix2::CameraMatrix2() : 
    transform::AngleMatrix2(), transform::PositionMatrix2(), transform::ScaleMatrix2() {}

bebr::camera::CameraMatrix2::CameraMatrix2( core::Rect rectangle ) :
    transform::AngleMatrix2(), transform::PositionMatrix2(), transform::ScaleMatrix2()
{
    setView( rectangle );
}

bebr::camera::CameraMatrix2::CameraMatrix2( float x, float y, float width, float height ) :
    transform::AngleMatrix2(), transform::PositionMatrix2(), transform::ScaleMatrix2()
{
    setView( x, y, width, height );
}

bebr::camera::CameraMatrix2::CameraMatrix2( math::Vector2f position, math::Vector2f size ) :
    transform::AngleMatrix2(), transform::PositionMatrix2(), transform::ScaleMatrix2()
{
    setView( position, size );
}

void bebr::camera::CameraMatrix2::setView( core::Rect rectangle )
{
    setCenter( rectangle.position + rectangle.size / 2.f );
    setSize( rectangle.size );
}

void bebr::camera::CameraMatrix2::setView( float x, float y, float width, float height )
{
    setCenter( x - width / 2.f, y - height / 2.f );
    setSize( width, height );
}

void bebr::camera::CameraMatrix2::setView( math::Vector2f position, math::Vector2f size )
{
    setCenter( position + size / 2.f );
    setSize( size );
}

bebr::core::Rect bebr::camera::CameraMatrix2::getView() const
{
    math::Vector2f size = getSize();
    return { getCenter() - size, size };
}

void bebr::camera::CameraMatrix2::setCenter( float x, float y )
{
    setPosition( -x, -y );
}

void bebr::camera::CameraMatrix2::setCenter( math::Vector2f center )
{
    setPosition( center * -1.f );
}

bebr::math::Vector2f bebr::camera::CameraMatrix2::getCenter() const
{
    return getPosition() * -1.f;
}

bebr::math::Vector2f bebr::camera::CameraMatrix2::getMousePos( math::Vector2i mousePos, math::Vector2i windowSize ) const
{
    math::Vector2f localPos = math::Vector2f( mousePos );
    localPos.x /= static_cast<float>(windowSize.x);
    localPos.y /= static_cast<float>(windowSize.y);
    math::Vector2f size = getSize();
    localPos.x *= size.x;
    localPos.y *= size.y;
    size /= 2.f;
    localPos.x -= size.x;
    localPos.y += size.y;
    localPos += getCenter();
    return localPos;
}

void bebr::camera::CameraMatrix2::move( float x, float y )
{
    PositionMatrix2::move( -x, -y );
}

void bebr::camera::CameraMatrix2::move( math::Vector2f velocity )
{
    PositionMatrix2::move( velocity * -1.f );
}

void bebr::camera::CameraMatrix2::setSize( float width, float height )
{
    setScale( 2.f / width, 2.f / height );
}

void bebr::camera::CameraMatrix2::setSize( math::Vector2f size )
{
    setScale( 2.f / size.x, 2.f / size.y );
}

bebr::math::Vector2f bebr::camera::CameraMatrix2::getSize() const
{
    math::Vector2f size = getScale();
    return { 2.f / size.x, 2.f / size.y };
}

void bebr::camera::CameraMatrix2::setAngle( float angle )
{
    AngleMatrix2::setAngle( angle );
}

float bebr::camera::CameraMatrix2::getAngle() const
{
    return AngleMatrix2::getAngle();
}

bebr::math::Mat4& bebr::camera::CameraMatrix2::getMatrix() const
{
    static math::Mat4 s_matrix;
    s_matrix = ScaleMatrix2::getMatrix() * PositionMatrix2::getMatrix();
    return s_matrix;
}
