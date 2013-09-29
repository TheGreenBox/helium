/* ========================================================
 * Organization: The Green Box
 *
 * Project name: Helium
 * File name:  heliumScreenConsole.cpp
 * Description: heliumMultilineText Class
 * Author:
 * ========================================================
 */

#include <iostream>
#include <list>

#include "Polycode2DPhysics.h"

#include "heliumPreparedScreenButton.h"
#include "heliumMultilineText.h"

namespace P = Polycode;

heliumMultilineText::heliumMultilineText(int _textSize, int _maxVisibleLines, int _stackSize, double _lineSpacing, P::Vector3 _defaultColor)
    :   shape(new P::ScreenShape(P::ScreenShape::SHAPE_RECT, 300, 100) ),
        lines_count(0),
        visible_lines(0),
        lineSpacing(_lineSpacing),
        textSize(_textSize),
        maxVisibleLines(_maxVisibleLines),
        maxLines(_stackSize),
        defaultColor(_defaultColor) {

    shape->loadTexture(g_helium_resource_path + "window_background.png");
    shape->setPosition(100, 100);

    this->heliumAlife = new ScreenButton( shape, new EscapeGame(), NULL );
    this->entityType = PackagedScreenObject::ENTITY_COLLISION_ONLY;
    this->entityShapeType = P::PhysicsScreenEntity::ENTITY_RECT;
    this->alife = 1;

    this->newLine();
    this->add("I am heliumMultilineText! Now love me!");
    this->newLine();
}

heliumMultilineText::~heliumMultilineText() {
    this->clear();
}

void heliumMultilineText::add(const char* str) {
    lines.back()->setText(lines.back()->getText() + str);
}

void heliumMultilineText::add(const Polycode::String& str) {
    lines.back()->setText(lines.back()->getText() + str);
}

int heliumMultilineText::clear(int linesToRemove) {
    if (linesToRemove > 0) {
        for ( ; linesToRemove != 0; --linesToRemove ) {
            shape->removeChild(lines.front());
            delete lines.front();
            lines.pop_front();
        }
    }
    else {
        for ( ; linesToRemove != 0; ++linesToRemove) {
            shape->removeChild(lines.back());
            delete lines.back();
            lines.pop_back();
        }
    }
    return 0;
}

int heliumMultilineText::clear() {
    while (! lines.empty() ) {
        shape->removeChild(lines.back());
        delete lines.back();
        lines.pop_back();
    }
    // lines.clear();
    return 0;
}

void heliumMultilineText::newLine() {
    //P::String lineBegin = P::String::IntToString(lines_count);
    //lineBegin += " : ";
    //P::ScreenLabel* label = new P::ScreenLabel(lineBegin, textSize, "mono");

    P::ScreenLabel* label = new P::ScreenLabel("", textSize, "mono");

    label->setColor( defaultColor.x,
                     defaultColor.y,
                     defaultColor.z, 1 );

    label->setPosition(4, static_cast<double>(lines_count*textSize)*(lineSpacing+1) );
    shape->addChild(label);

    lines.push_back(label);
    ++lines_count;
    // if ( visible_lines >= maxVisibleLines ) {
    //     scroll(-1);
    // }
    // else {
    //     ++visible_lines;
    // }
    if ( lines_count > maxLines ) {
        this->clear(1);
    }

}

// void heliumMultilineText::scroll(int n) {
//     double offset = static_cast<double>((lines_count-visible_lines+n)*textSize) * (lineSpacing+1);
//     shape->setScreenOffset(0, -offset);
//     visible_lines += n;
// }
