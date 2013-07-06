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

class DynamicObject;
class StaticObjec;
class DeadDynamycObject;
class DeadStaticObject;
class Sentient;
class SentientDynamicObject;
class SentientStaticObject;

class WorldObjects;
class CommonWorldObjects;

// ------
class NonPhysicalObject
{
public:
    NonPhysicalObject(){};
    virtual ~NonPhysicalObject(){};

private:
};

class DynamicObject
{
public:    
    DynamicObject(){};
    virtual ~DynamicObject(){};

private:
    int mass;
    // damage ?
};

class StaticObject
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

class WorldObjects
{
public:    
    WorldObjects(){};
    virtual ~WorldObjects(){};
};

class CommonWorldObjects : public WorldObjects
{
public:    
    CommonWorldObjects(){};
    virtual ~CommonWorldObjects(){};

private:
    
    std::list< DynamicObject* >     pDynamic; 
    // for iterate by behavior
    std::list< Sentient* >          pSentient;
};

#endif // _HELIUM_SCENE_OBJECTS_INCLUDED_


