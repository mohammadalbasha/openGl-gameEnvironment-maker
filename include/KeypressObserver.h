#ifndef KEY_PRESS_OBSERVER_h
#define KEY_PRESS_OBSERVER_h

#include <windows.h>

class KeypressObserver {
public:
    virtual void notify(USHORT key) = 0;
};

#endif 
