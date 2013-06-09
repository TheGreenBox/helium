#include <Polycode.h>
#include "PolycodeView.h"

using namespace Polycode;

class First3DTest {
public:
    First3DTest(PolycodeView *view);
    ~First3DTest();
    
    void handleEvent(Event *e);
    bool Update();
    
private:
	Core *core;
	ScreenImage *cursor;
};
