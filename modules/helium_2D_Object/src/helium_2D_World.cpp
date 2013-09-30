/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_2D_World.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#include "helium_2D_World.h"

namespace P = Polycode;

Helium_2D_World::Helium_2D_World ()
    : engineScreen(new Polycode::PhysicsScreen()) {
}

Helium_2D_World::~Helium_2D_World () {
    engineScreen->Shutdown();
    delete engineScreen;
    
//    for ( ObjectIterator it = objects.begin();
//            it != objects.end(); ++it ) {
//        delete reinterpret_cast<P::ScreenEntity*>(*it);
//    }
//    for ( AlifeIterator itl = alifeObjects.begin();
//            itl != alifeObjects.end(); ++itl ) {
//        delete reinterpret_cast<P::ScreenEntity*>(itl->first);
//        delete itl->second;
//    }
}

void Helium_2D_World::lifeStep() {
//    for ( AlifeIterator it = alifeObjects.begin();
//            it != alifeObjects.end(); ++it ) {
//        it->second->lifeStep();
//    }
#warning fix me //FIXME
}

bool Helium_2D_World::mouseClick( int button, bool upDown, P::Vector2 mouse ) {
//	P::ScreenEntity* entity = engineScreen->getEntityAtPosition(mouse.x, mouse.y);
//    
//    // TODO !! wrap it to inline function!
//    IHeliumObjectsWorld::ObjectsIdType id = 
//        reinterpret_cast< IHeliumObjectsWorld::ObjectsIdType >(entity);
//
//   AlifeIterator ait = alifeObjects.find(id);
//    if (ait != alifeObjects.end() ) {
//        ait->second->mouseClick(upDown);
//        return true;
//    }
#warning fix me //FIXME
    return false;
}
    
void Helium_2D_World::setPause(bool set) {
    engineScreen->enabled = set;
}

bool Helium_2D_World::getPause() {
    return engineScreen->enabled;
}

Helium_2D_World::ObjectId Helium_2D_World::addObject( Packaged_2D_Object* obj ) {
    switch( obj->getEntityType() ) {
        case IHeliumPackaging::ENTITY_IMMATERIAL:
            engineScreen->addChild( obj->getModel() );
        break;
        case IHeliumPackaging::ENTITY_COLLISION_ONLY:
            engineScreen->addCollisionChild( obj->getModel(), obj->getShapeType() );
        break;
        case IHeliumPackaging::ENTITY_PHYSICAL:
            engineScreen->addPhysicsChild( obj->getModel(), obj->getShapeType(), false );
        break;
        default:
            throw "Create correct exeption class!";
        break;
    }
    return obj->getModel();
}

void Helium_2D_World::signOutObject( ObjectId id ) {
/*    ObjectIterator it = objects.find(id);
    if ( it != objects.end() ) {
        P::ScreenEntity* pObj = reinterpret_cast<P::ScreenEntity*>(id);
            
        engineScreen->removeChild( pObj );
        delete pObj;
        objects.erase(it);
    }
    else {
        AlifeIterator ait = alifeObjects.find(id);
        if (ait != alifeObjects.end() ) {
            P::ScreenEntity* pObj = reinterpret_cast<P::ScreenEntity*>(id);
                
            engineScreen->removeChild( pObj );
            delete pObj;
            delete ait->second;
            alifeObjects.erase(ait);
        }
    }
*/
#warning fix me //FIXME
}

