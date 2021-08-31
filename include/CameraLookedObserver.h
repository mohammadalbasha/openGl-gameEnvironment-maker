#ifndef CAMERA_LOOKED_OBSERVER_H
#define CAMERA_LOOKED_OBSERVER_H

#include "vertex.h"

class CameraLookedObserver {
    public:
        virtual void notify(vertex dir) = 0;
};

#endif