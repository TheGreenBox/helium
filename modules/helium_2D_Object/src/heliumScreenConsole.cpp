/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumScreenConsole.cpp 
 * Description: ScreenConsole Class
 * Author:  AKindyakov 
 * ========================================================
 */

#include <iostream>
#include <list>

#include "heliumScreenConsole.h"

namespace P = Polycode;

ScreenConsole::ScreenConsole(int _textSize, int _maxVisibleLines, int _stackSize, double _lineSpacing, P::Vector3 _defaultColor) 
    : screen(new P::Screen()),
        lines_count(0),
        visible_lines(0),
        lineSpacing(_lineSpacing),
        textSize(_textSize),
        maxVisibleLines(_maxVisibleLines),
        maxLines(_stackSize),
        defaultColor(_defaultColor) {
    this->newLine();
    this->add("Helium ScreenConsole :");
    this->newLine();
}

ScreenConsole::~ScreenConsole() {
    this->clean();
}

void ScreenConsole::add(const char* str) {
    lines.back()->setText(lines.back()->getText() + str);
}

void ScreenConsole::add(const Polycode::String& str) {
    lines.back()->setText(lines.back()->getText() + str);
}

void ScreenConsole::clean(int num) {
    if ( num == 0 ) {
        for ( std::list< P::ScreenLabel* >::iterator it = lines.end(); it != lines.begin(); --it ) {
            screen->removeChild(*it);
            delete *it;
        }
        lines.resize(0);
    }
    else {
        if ( num > 0 ) {
            for ( ; num != 0; --num ) {
                screen->removeChild(lines.front());
                delete lines.front();
                lines.pop_front();
            }
        }
        else {
            for ( ; num != 0; ++num ) {
                screen->removeChild(lines.back());
                delete lines.back();
                lines.pop_back();
            }
        }
    }
}

void ScreenConsole::newLine() {
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
        this->clean(1);
    }
    
}

void ScreenConsole::scroll(int n) {
    double offset = static_cast<double>((lines_count-visible_lines+n)*textSize) * (lineSpacing+1);
    screen->setScreenOffset(0, -offset);
    visible_lines += n;
}
