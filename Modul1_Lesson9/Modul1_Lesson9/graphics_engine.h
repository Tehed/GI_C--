#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

/*
 * this will be an interface, i.e. 
 * it only consists of pure virtual functions
 */ 
class Object3D
{
public:
    virtual void draw() = 0;

};

class GraphicsEngine
{
    void draw(Object3D* object);
};

#endif