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

class WorldObjects;
class CommonWorldObjects;

class ObjectBehavior {
public:
    ObjectBehavior(){};
    virtual ~ObjectBehavior(){};
    void thinkAndDo();
private:
    
};

class ImmaterialObject {
public:    
    ImmaterialObject(){};
    virtual ~ImmaterialObject(){};

private:
};

class ImmaterialIntellectualObject {
public:
    ImmaterialIntellectualObject(){};
    virtual ~ImmaterialIntellectualObject(){};

private:
    ObjectBehavior behavior;
};


class StaticIntellectualObject {
public:    
    StaticIntellectualObject(){};
    virtual ~StaticIntellectualObject(){};

private:
    long int damage;
};

class DynamicObject {
public:    
    DynamicObject(){};
    virtual ~DynamicObject(){};

private:
    long int damage;
};

class DynamicIntellectualObject {
public:    
    DynamicIntellectualObject(){};
    virtual ~DynamicIntellectualObject(){};

private:
    long int damage;
};

class WorldObjects {
public:    
    WorldObjects(){};
    virtual ~WorldObjects(){};
};

class CommonWorldObjects : public WorldObjects {
public:    
    CommonWorldObjects(){};
    virtual ~CommonWorldObjects(){};

private:
};

#endif // _HELIUM_SCENE_OBJECTS_INCLUDED_

