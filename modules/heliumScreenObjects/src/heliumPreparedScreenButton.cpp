/* ========================================================
 * Organization: The Green Box
 *
 * Project name: Helium
 * File name:    heliumPreparedScreenButton.cpp
 * Description:
 * Author:       AKindyakov
 * ========================================================
 */

#include <Polycode.h>
#include "Polycode2DPhysics.h"

#include "heliumPreparedScreenButton.h"
#include "keyboardHandler.h"
#include "pathGlobal.h"

namespace P = Polycode;

HeliumPauseScreenButton::HeliumPauseScreenButton (HeliumGameCore* gm) {
    const int b_size = 50;
    P::ScreenShape* shape = new P::ScreenShape( P::ScreenShape::SHAPE_RECT,
                                                 b_size, b_size);
    shape->setPosition( gm->getEngineCorePt()->getXRes()/2,
                         gm->getEngineCorePt()->getYRes()/2);

    shape->loadTexture( g_helium_resource_path + "/pause_button.png" );
    this->heliumAlife = new ScreenButton( shape, new PauseGame(), NULL );

    this->entityType = PackagedScreenObject::ENTITY_COLLISION_ONLY;
    this->entityShapeType = P::PhysicsScreenEntity::ENTITY_RECT;
    this->alife = 1;
}

HeliumPauseScreenButton::~HeliumPauseScreenButton () {}

HeliumExitScreenButton::HeliumExitScreenButton(HeliumGameCore* gm) {
    const int b_size = 50;
    P::ScreenShape* shape = new P::ScreenShape( P::ScreenShape::SHAPE_RECT,
                                                b_size, b_size);
    shape->setPosition( gm->getEngineCorePt()->getXRes()-b_size/2,
                        gm->getEngineCorePt()->getYRes()-b_size/2 );

    shape->loadTexture( g_helium_resource_path + "/exit_button.png" );
    this->heliumAlife = new ScreenButton( shape, new EscapeGame(), NULL );

    this->entityType = PackagedScreenObject::ENTITY_COLLISION_ONLY;
    this->entityShapeType = P::PhysicsScreenEntity::ENTITY_RECT;
    this->alife = 1;
}

HeliumExitScreenButton::~HeliumExitScreenButton() {}

HeliumTextScreenButton::HeliumTextScreenButton(HeliumGameCore* gm, P::String textLabel, int t_size, P::String font, int b_x_size, int b_y_size, int x_pos, int y_pos) {
    // const int b_size = 50;
    int xRes = gm->getEngineCorePt()->getXRes();
    int yRes = gm->getEngineCorePt()->getYRes();

    if (x_pos > xRes - b_x_size / 2) {
        x_pos = xRes / 2;
    }
    if (y_pos > yRes - b_y_size / 2) {
        y_pos = yRes / 2;
    }

    P::ScreenShape* shape = new P::ScreenShape( P::ScreenShape::SHAPE_RECT,
                                                b_x_size, b_y_size);
    P::ScreenLabel* buttonText = new ScreenLabel(textLabel, t_size, font, 0, false);

    shape->addChild(buttonText);
    shape->setPosition(x_pos, y_pos);
    shape->loadTexture( g_helium_resource_path + "/dark_wood.jpg" );

    heliumAlife = new ScreenButton( shape, new EscapeGame(), NULL );

    entityType = PackagedScreenObject::ENTITY_COLLISION_ONLY;
    entityShapeType = P::PhysicsScreenEntity::ENTITY_RECT;
    alife = 1;
}

HeliumTextScreenButton::~HeliumTextScreenButton() {}
