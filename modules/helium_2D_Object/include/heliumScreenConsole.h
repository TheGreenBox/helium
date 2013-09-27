/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumScreenConsole.h 
 * Description: ScreenConsole Class
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_SCREEN_CONSOLE_INCLUDED
#define HELIUM_SCREEN_CONSOLE_INCLUDED

#include <list>
#include <Polycode.h>

#include "heliumScreenObjects.h"

class ScreenConsole {
public:

    /**
    * Create ScreenConsole
    * @param _textSize
    * @param _maxVisibleLines
    * @param _stackSize
    * @param _lineSpacing 
    * @param _defaultColor
    */ 
    ScreenConsole( int _textSize,
             int _maxVisibleLines,
             int _stackSize,
             double _lineSpacing = 0.0,
             Polycode::Vector3 _defaultColor = Polycode::Vector3(0,0,0) );
    
    virtual ~ScreenConsole();
   
    /**
    *
    */ 
    void setPosition( Polycode::Vector3 _defaultColor = Polycode::Vector3(0,0,0) ){};
   
    /**
    *
    */ 
    void add(const char*);
    void add(const Polycode::String&);
    
    /**
    * Remove elements from the top
    * @param numToRemove number of removed elements, 
    *        if numToRemove > 0 - remove from the top of history 
    *        if numToRemove < 0 - remove from the bottom of history 
    *        if numToRemove = 0 - remove all history 
    */
    void clean(int numToRemove=0);
    
    /**
    * Add new line to the ScreenConsole
    */
    void newLine();
    
    /**
    *
    */ 
    void scroll(int);
    
private:
    std::list< Polycode::ScreenLabel* > lines;
    Polycode::Screen* screen;
    
    double lineSpacing;
    int    textSize;
    int    maxVisibleLines;
    int    maxLines;
    Polycode::Vector3 defaultColor;

    int lines_count;
    int visible_lines;
};

#endif // HELIUM_SCREEN_CONSOLE_INCLUDED

