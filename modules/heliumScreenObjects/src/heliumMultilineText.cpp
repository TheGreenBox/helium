/* ========================================================
 * Organization: The Green Box
 *
 * Project name: Helium
 * File name:  heliumScreenConsole.cpp
 * Description: MultilineText Class
 * Author:  AKindyakov
 * ========================================================
 */

#include <iostream>
#include <list>

#include "heliumMultilineTxt.h"

namespace P = Polycode;

MultilineText::MultilineText(int _textSize, int _maxVisibleLines, int _stackSize, double _lineSpacing, P::Vector3 _defaultColor)
    : screen(new P::Screen()),
        lines_count(0),
        visible_lines(0),
        lineSpacing(_lineSpacing),
        textSize(_textSize),
        maxVisibleLines(_maxVisibleLines),
        maxLines(_stackSize),
        defaultColor(_defaultColor) {
    this->newLine();
    this->add("Helium MultilineText :");
    this->newLine();
}

MultilineText::~MultilineText() {
    this->clear();
}

void MultilineText::add(const char* str) {
    lines.back()->setText(lines.back()->getText() + str);
}

void MultilineText::add(const Polycode::String& str) {
    lines.back()->setText(lines.back()->getText() + str);
}

void MultilineText::clear(int linesToRemove) {
    if (linesToRemove > 0) {
        for ( ; linesToRemove != 0; --linesToRemove ) {
            screen->removeChild(lines.front());
            // delete lines.front();
            lines.pop_front();
        }
    }
    else {
        for ( ; linesToRemove != 0; ++linesToRemove) {
            screen->removeChild(lines.back());
            // delete lines.back();
            lines.pop_back();
        }
    }
}

void MultilineText::clear() {
    lines.clear();
    return 0;
}

void MultilineText::newLine() {
    //P::String lineBegin = P::String::IntToString(lines_count);
    //lineBegin += " : ";
    //P::ScreenLabel* label = new P::ScreenLabel(lineBegin, textSize, "mono");

    P::ScreenLabel* label = new P::ScreenLabel("", textSize, "mono");

    label->setColor( defaultColor.x,
                     defaultColor.y,
                     defaultColor.z, 1 );

    label->setPosition(4, static_cast<double>(lines_count*textSize)*(lineSpacing+1) );
    screen->addChild(label);

    lines.push_back(label);
    ++lines_count;
    if ( visible_lines >= maxVisibleLines ) {
        scroll(-1);
    }
    else {
        ++visible_lines;
    }
    if ( lines_count > maxLines ) {
        this->clear(1);
    }

}

void MultilineText::scroll(int n) {
    double offset = static_cast<double>((lines_count-visible_lines+n)*textSize) * (lineSpacing+1);
    screen->setScreenOffset(0, -offset);
    visible_lines += n;
}
