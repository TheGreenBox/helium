/* ========================================================
 * Organization: The Green Box
 *
 * Project name: Helium
 * File name:  heliumScreenConsole.h
 * Description: heliumMultilineText Class
 * Author:
 * ========================================================
 */

#ifndef HELIUM_MULTILINE_TEXT_INCLUDED
#define HELIUM_MULTILINE_TEXT_INCLUDED

#include <list>
#include <Polycode.h>

#include "heliumScreenObjects.h"
#include "pathGlobal.h"

class heliumMultilineText : public PackagedScreenObject {
public:

    /**
    * Create heliumMultilineText
    * @param _textSize
    * @param _maxVisibleLines
    * @param _stackSize
    * @param _lineSpacing
    * @param _defaultColor
    */
    heliumMultilineText( int _textSize,
             int _maxVisibleLines,
             int _stackSize,
             double _lineSpacing = 0.0,
             Polycode::Vector3 _defaultColor = Polycode::Vector3(0,0,0) );

    virtual ~heliumMultilineText();

    /**
    *
    */
    // void setPosition( Polycode::Vector3 _defaultColor = Polycode::Vector3(0,0,0) ){};

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
    *        if no arguements   - remove all history
    */
    int clear(int linesToRemove);
    int clear();

    /**
    * Add new line to the heliumMultilineText
    */
    void newLine();

    /**
    *
    */
    // void scroll(int n);

private:
    std::list< Polycode::ScreenLabel* > lines;
    Polycode::ScreenShape* shape;

    double lineSpacing;
    int    textSize;
    int    maxVisibleLines;
    int    maxLines;
    Polycode::Vector3 defaultColor;

    int lines_count;
    int visible_lines;
};

#endif // HELIUM_MULTILINE_TEXT_INCLUDED

