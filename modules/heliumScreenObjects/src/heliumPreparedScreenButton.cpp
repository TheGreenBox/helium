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

    /**
    * Creates a button with a text in the center of it.
    * @param gm Standart Helium Game Core.
    * @param textValue A text string to be displayed on the button.
    * @param b_x_size Button width (in pixels).
    * @param b_y_size Button height (in pixels).
    * @param x_pos Position of button's center point on x-Axis.
    * @param y_pos Position of button's center point on y-Axis.
    * @param font String name of a wanted font (handled by Polycode FontManager).
    * @param f_size Font height (in pixels).
    */
HeliumTextScreenButton::HeliumTextScreenButton(HeliumGameCore* gm, P::String textValue,
                                               KeyHandler* buttonHandler,
                                               int b_x_size = 50, int b_y_size = 100,
                                               int x_pos = 0, int y_pos = 0,
                                               P::String font = "sans", int f_size = 10) {

    const int defaultAntiAliasMode      = P::Label::ANTIALIAS_FULL;
    const bool defaultPremultiplyAlpha  = false;

    int xRes = gm->getEngineCorePt()->getXRes();
    int yRes = gm->getEngineCorePt()->getYRes();

    if ( (x_pos > xRes - b_x_size / 2) || (x_pos == 0) ) {
        x_pos = xRes / 2;
    }
    if ( (y_pos > yRes - b_y_size / 2) || (y_pos == 0) ) {
        y_pos = yRes / 2;
    }

    P::ScreenShape* shape = new P::ScreenShape( P::ScreenShape::SHAPE_RECT,
                                                b_y_size, b_x_size);
    P::ScreenLabel* textObject = new P::ScreenLabel(textValue, f_size, font,
                                                    defaultAntiAliasMode, defaultPremultiplyAlpha);

    textObject->setPositionMode(P::ScreenLabel::POSITION_CENTER);

    shape->addChild(textObject);
    shape->setPosition(x_pos, y_pos);
    shape->loadTexture( g_helium_resource_path + "/dark_gray_button.png" );

    heliumAlife = new ScreenButton( shape, buttonHandler, NULL );

    entityType = PackagedScreenObject::ENTITY_COLLISION_ONLY;
    entityShapeType = P::PhysicsScreenEntity::ENTITY_RECT;
    alife = 1;
}

HeliumTextScreenButton::~HeliumTextScreenButton() {}
