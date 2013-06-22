/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumSceneObjects.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef _HELIUM_SCENE_OBJECTS_INCLUDED_
#define _HELIUM_SCENE_OBJECTS_INCLUDED_

#include <list>

class Object;
class DynamicObject;
class StaticObjec;
class DeadDynamycObject;
class DeadStaticObject;
class Sentient;
class SentientDynamicObject;
class SentientStaticObject;

class IWorldObjects;
class CommonWorldObjects;

// ------
class Object
{
public:
    Object(){};
    virtual ~Object(){};

private:
    // shape
    // color
    // face etc
};

class NonPhysicalObject : public Object
{
public:
    NonPhysicalObject(){};
    virtual ~NonPhysicalObject(){};

private:
};

class DynamicObject : public Object
{
public:    
    DynamicObject(){};
    virtual ~DynamicObject(){};

private:
    int mass;
    // damage ?
};

class StaticObject : public Object
{
public:    
    StaticObject(){};
    virtual ~StaticObject(){};

private:
    // damage ?
};

class DeadDynamicObject : public DynamicObject 
{
public:    
    DeadDynamicObject(){};
    virtual ~DeadDynamicObject(){};

private:
};

class DeadStaticObject : public StaticObject 
{
public:
    
    DeadStaticObject(){};
    virtual ~DeadStaticObject(){};

private:
};

class Sentient
{
public:
    Sentient(){};
    virtual ~Sentient(){};
private:
};

class SentientDynamicObject 
                : public DynamicObject, 
                  public Sentient
{
public:    
    SentientDynamicObject(){};
    virtual ~SentientDynamicObject(){};

private:
};

class SentientStaticObject
                : public StaticObject,
                  public Sentient 
{
public:    
    SentientStaticObject(){};
    virtual ~SentientStaticObject(){};

private:
};

class IWorldObjects
{
public:    
    IWorldObjects(){};
    virtual ~IWorldObjects(){};
};

class CommonWorldObjects : public IWorldObjects
{
public:    
    CommonWorldObjects(){};
    virtual ~CommonWorldObjects(){};

private:
    
    std::list< Object* >            pAllObjects;
    
    std::list< DynamicObject* >     pDynamic; 
    //std::list< TempObject* >        pTempObjects;
    // for iterate by behavior
    std::list< Sentient* >          pSentient;
};

#endif // _HELIUM_SCENE_OBJECTS_INCLUDED_
