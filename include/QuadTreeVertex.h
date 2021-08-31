#include "Cube.h"
#include "vertex.h"
#include "ObjectFactory.h"
#include <vector>
#include <chrono>
#include <random>

class QuadTreeVertex {
    private:
        std :: vector<Object*> objects;

    public:
        ObjectFactory* factory;
        QuadTreeVertex* bottomLeft, *bottomRight, *topLeft, *topRight;
        vertex posBottomLeft, posUpperRight;
        bool horiznotalRoad, verticalRoad;

        QuadTreeVertex();
        QuadTreeVertex(vertex posBottomLeft, vertex posUpperRight);

        void draw();

        void addObject(Object* object);

        void allocateChildren(double roadWidth);

        void distributeRoads(int &numRoads);

        void distributePavements();

        void distributeBuildings(int &numMainBuildings, int &numBuildings, objectType type1, objectType type2);

        void distributeTrees(int &numTrees);

        void distributeLamps(int& numLamps);

        void distributeCars(int& numCars);
};