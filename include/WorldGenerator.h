#include "QuadTreeVertex.h"
#include "Resources.h"

class WorldGenerator {
    private:
        int size, numBuildings, numMainBuildings, numRoads, numTrees, numCars, numLamps;
        QuadTreeVertex* root;

    public:
        QuadTreeVertex* generate();
};