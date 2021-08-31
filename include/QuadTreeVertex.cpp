#include "QuadTreeVertex.h"
#include <queue>

QuadTreeVertex :: QuadTreeVertex() {
    horiznotalRoad = false;
    verticalRoad = false;
    bottomLeft = bottomRight = topLeft = topRight = nullptr;
}

QuadTreeVertex :: QuadTreeVertex(vertex posBottomLeft, vertex posUpperRight) : posBottomLeft(posBottomLeft), posUpperRight(posUpperRight) {
    horiznotalRoad = false;
    verticalRoad = false;
    bottomLeft = bottomRight = topLeft = topRight = nullptr;
}

void QuadTreeVertex :: draw() {
    for(auto obj : objects)
        obj -> draw();

    if(verticalRoad) { 
        bottomLeft -> draw();
        bottomRight -> draw();
        topRight -> draw();
        topLeft -> draw();
    }
}

void QuadTreeVertex :: addObject(Object* obj) {
    objects.push_back(obj);
}

void QuadTreeVertex :: allocateChildren(double roadWidth) {
    double size = posUpperRight.x - posBottomLeft.x;
    bottomLeft = new QuadTreeVertex(posBottomLeft, posBottomLeft + vertex((size - roadWidth) / 2, 0, (-size + roadWidth) / 2));
    bottomLeft -> factory = factory;
    bottomRight = new QuadTreeVertex(posBottomLeft + vertex((size + roadWidth) / 2, 0, 0), posUpperRight + vertex(0, 0, (size + roadWidth) / 2));
    bottomRight -> factory = factory;
    topRight = new QuadTreeVertex(posUpperRight + vertex((-size + roadWidth) / 2, 0, (size - roadWidth) / 2), posUpperRight);
    topRight -> factory = factory;
    topLeft = new QuadTreeVertex(posBottomLeft + vertex(0, 0, (-size - roadWidth) / 2), posUpperRight + vertex((-size - roadWidth) / 2, 0, 0));
    topLeft -> factory = factory;
}

void QuadTreeVertex :: distributeRoads(int &numRoads) {
    double width = 20;      // Street width

    std :: queue<QuadTreeVertex*> queue;
    queue.push(this);
    
    while(!queue.empty()) {
        QuadTreeVertex* cur = queue.front();
        queue.pop();
        double size = cur -> posUpperRight.x - cur -> posBottomLeft.x;

        if(size < width || numRoads <= 0)
            continue;

        numRoads--;
        Object* roadX = cur -> factory -> createObject(objectType :: STREET, vertex(cur -> posBottomLeft.x, cur -> posBottomLeft.y, cur -> posBottomLeft.z + (-size + width) / 2),
                                                size, 1e-2, width, 1, 0);
        cur -> addObject(roadX);
        cur -> horiznotalRoad = true;

        if(numRoads <= 0) continue;

        numRoads--;
        Object* roadZ = cur -> factory -> createObject(objectType :: STREET, vertex(cur -> posBottomLeft.x + (size + width) / 2, cur -> posBottomLeft.y, cur -> posBottomLeft.z),
                                                size, 1e-2, width, 1, 90);
        cur -> addObject(roadZ);
        cur -> verticalRoad = true;
        
        cur -> allocateChildren(width);
        queue.push(cur -> bottomLeft);
        queue.push(cur -> bottomRight);
        queue.push(cur -> topRight);
        queue.push(cur -> topLeft);
    }

}

void QuadTreeVertex :: distributePavements() {
    double width = 20;      // Street width

    std :: queue<QuadTreeVertex*> queue;
    queue.push(this);
    
    while(!queue.empty()) {
        QuadTreeVertex* cur = queue.front();
        queue.pop();
        double size = cur -> posUpperRight.x - cur -> posBottomLeft.x;

        if(cur -> verticalRoad) {
            queue.push(cur -> bottomLeft);
            queue.push(cur -> bottomRight);
            queue.push(cur -> topRight);
            queue.push(cur -> topLeft);
        }
        else if(cur -> horiznotalRoad) {
            Object* pavement = cur -> factory -> createObject(objectType :: PAVEMENT, vertex(cur -> posBottomLeft.x, cur -> posBottomLeft.y, -width + cur -> posBottomLeft.z + (-size + width) / 2),
                                                    size, 1, 5, 1, 0); 
            cur -> addObject(pavement);
            
            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, vertex(cur -> posBottomLeft.x, cur -> posBottomLeft.y, 5 + cur -> posBottomLeft.z + (-size + width) / 2),
                                                size, 1, 5, 1, 0); 
            cur -> addObject(pavement);

            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft, size, 1, 5, 1, 0);
            cur -> addObject(pavement);
            
            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft + vertex(0, 0, -size + 5), size, 1, 5, 1, 0);
            cur -> addObject(pavement);

            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft + vertex(5, 0, -5), -5 + (size - width) / 2, 1, 5, 1, 90);
            cur -> addObject(pavement);
            
            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft + vertex(size, 0, -5), -5 + (size - width) / 2, 1, 5, 1, 90);
            cur -> addObject(pavement);
            
            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft + vertex(size, 0, (-size - width) / 2), -5 + (size - width) / 2, 1, 5, 1, 90);
            cur -> addObject(pavement);
            
            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft + vertex(5, 0, (-size - width) / 2), -5 + (size - width) / 2, 1, 5, 1, 90);
            cur -> addObject(pavement);
        }
        else {
            Object* pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft, size, 1, 5, 1, 0);
            cur -> addObject(pavement);

            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft + vertex(0, 0, -size + 5), size, 1, 5, 1, 0);
            cur -> addObject(pavement);

            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft + vertex(5, 0, -5), size - 10, 1, 5, 1, 90);
            cur -> addObject(pavement);
            
            pavement = cur -> factory -> createObject(objectType :: PAVEMENT, cur -> posBottomLeft + vertex(size, 0, -5), size - 10, 1, 5, 1, 90);
            cur -> addObject(pavement);
        }

    }

}

void QuadTreeVertex :: distributeBuildings(int &numMainBuildings, int &numBuildings, objectType type1, objectType type2) {
    double width = 20;      // Street width
    double min = 20;        // Minimum building side length

    std :: queue<QuadTreeVertex*> queue;
    queue.push(this);
    
    while(!queue.empty()) {
        QuadTreeVertex* cur = queue.front();
        queue.pop();
        double size = cur -> posUpperRight.x - cur -> posBottomLeft.x;
        Object* building;

        if(size - 40 < min)
            continue;

        if(cur -> verticalRoad) {
            queue.push(cur -> bottomLeft);
            queue.push(cur -> bottomRight);
            queue.push(cur -> topRight);
            queue.push(cur -> topLeft);
        }
        else if(cur -> horiznotalRoad) {
            if((size / 2) - 40 >= min) {
                if(numMainBuildings > 0) {
                    numMainBuildings--;
                    building = cur -> factory -> createObject(type1, cur -> posBottomLeft + vertex(20, 0, -20),
                                                size - 40, 70, -40 + (size - width) / 2, 1, 0);
                    cur -> addObject(building);
                }
                else if(numBuildings > 0) {
                    numBuildings--;
                    building = cur -> factory -> createObject(type2, cur -> posBottomLeft + vertex(20, 0, -20),
                                                size - 40, 70, -40 + (size - width) / 2, 1, 0);
                    cur -> addObject(building);
                }

                if(numMainBuildings > 0) {
                    numMainBuildings--;
                    building = cur -> factory -> createObject(type1, cur -> posBottomLeft + vertex(20, 0, -20 + (-size - width) / 2),
                                                size - 40, 70, -40 + (size - width) / 2, 1, 0);
                    cur -> addObject(building);
                }
                else if(numBuildings > 0) {
                    numBuildings--;
                    building = cur -> factory -> createObject(type2, cur -> posBottomLeft + vertex(20, 0, -20 + (-size - width) / 2),
                                                size - 40, 70, -40 + (size - width) / 2, 1, 0);
                    cur -> addObject(building);
                }
            
            }
        }
        else {
            if(numMainBuildings > 0) {
                numMainBuildings--;
                building = cur -> factory -> createObject(type1, cur -> posBottomLeft + vertex(20, 0, -20),
                                            size - 40, 70, size - 40, 1, 0);
                cur -> addObject(building);
            }
            
            else if(numBuildings > 0) {
                numBuildings--;
                building = cur -> factory -> createObject(type2, cur -> posBottomLeft + vertex(20, 0, -20),
                                            size - 40, 70, size - 40, 1, 0);
                cur -> addObject(building);
            }
        }

    }
}

void QuadTreeVertex :: distributeTrees(int &numTrees) {
    std :: queue<QuadTreeVertex*> queue;
    queue.push(this);
    
    while(!queue.empty()) {
        QuadTreeVertex* cur = queue.front();
        queue.pop();
        double size = cur -> posUpperRight.x - cur -> posBottomLeft.x;

        if(numTrees <= 0)
            continue;
        
        if(cur->verticalRoad) {
            queue.push(cur -> bottomLeft);
            queue.push(cur -> bottomRight);
            queue.push(cur -> topRight);
            queue.push(cur -> topLeft);
        }
        else if(cur->horiznotalRoad) {
            double z1 = 10 + cur -> posBottomLeft.z + (-size + 20) / 2;
            for(double x = cur -> posBottomLeft.x + 10; x <= cur -> posUpperRight.x - 10 && numTrees; x += 20, numTrees--) {
                Object* tree = cur -> factory -> createObject(objectType :: TREE, vertex(x, 0, z1));
                cur -> addObject(tree);
            }

            double z2 = -10 + cur -> posBottomLeft.z + (-size - 20) / 2;
            for(double x = cur -> posBottomLeft.x + 10; x <= cur -> posUpperRight.x - 10 && numTrees; x += 20, numTrees--) {
                Object* tree = cur -> factory -> createObject(objectType :: TREE, vertex(x, 0, z2));
                cur -> addObject(tree);
            }
        }
        else {
            double z = cur -> posBottomLeft.z - 10;
            for(double x = cur -> posBottomLeft.x + 10; x <= cur -> posUpperRight.x - 10 && numTrees; x += 20, numTrees--) {
                Object* tree = cur -> factory -> createObject(objectType :: TREE, vertex(x, 0, z));
                cur -> addObject(tree);
            }

            z = cur -> posUpperRight.z + 10;
            for(double x = cur -> posBottomLeft.x + 10; x <= cur -> posUpperRight.x - 10 && numTrees; x += 20, numTrees--) {
                Object* tree = cur -> factory -> createObject(objectType :: TREE, vertex(x, 0, z));
                cur -> addObject(tree);
            }

            double x = cur->posBottomLeft.x + 10;
            for(double z = cur -> posBottomLeft.z - 10; z >= cur -> posUpperRight.z + 10 && numTrees; z -= 20, numTrees--) {
                Object* tree = cur -> factory -> createObject(objectType :: TREE, vertex(x, 0, z));
                cur -> addObject(tree);
            }
            
            x = cur -> posUpperRight.x - 10;
            for(double z = cur -> posBottomLeft.z - 10; z >= cur -> posUpperRight.z + 10 && numTrees; z -= 20, numTrees--) {
                Object* tree = cur -> factory -> createObject(objectType :: TREE, vertex(x, 0, z));
                cur -> addObject(tree);
            }
        }

    }

}

void QuadTreeVertex::distributeLamps(int& numLamps) {
    std::queue<QuadTreeVertex*> queue;
    queue.push(this);

    while (!queue.empty()) {
        QuadTreeVertex* cur = queue.front();
        queue.pop();
        double size = cur->posUpperRight.x - cur->posBottomLeft.x;

        if (numLamps <= 0)
            continue;

        if (cur->verticalRoad) {
            queue.push(cur->bottomLeft);
            queue.push(cur->bottomRight);
            queue.push(cur->topRight);
            queue.push(cur->topLeft);
        }
        else if (cur->horiznotalRoad) {
            double z1 = 4 + cur->posBottomLeft.z + (-size + 20) / 2;
            for (double x = cur->posBottomLeft.x + 4; x <= cur->posUpperRight.x - 4 && numLamps; x += 20, numLamps--) {
                Object* tree = cur->factory->createObject(objectType::LAMP_POST, vertex(x, 0, z1), 0, 0, 0, 1 , -90);
                cur->addObject(tree);
            }

            double z2 = -4 + cur->posBottomLeft.z + (-size - 20) / 2;
            for (double x = cur->posBottomLeft.x + 4; x <= cur->posUpperRight.x - 4 && numLamps; x += 20, numLamps--) {
                Object* tree = cur->factory->createObject(objectType::LAMP_POST, vertex(x, 0, z2), 0, 0, 0, 1, 90);
                cur->addObject(tree);
            }
        }
        else {
            double z = cur->posBottomLeft.z - 4;
            for (double x = cur->posBottomLeft.x + 4; x <= cur->posUpperRight.x - 4 && numLamps; x += 20, numLamps--) {
                Object* tree = cur->factory->createObject(objectType::LAMP_POST, vertex(x, 0, z), 0, 0, 0, 1, 90);
                cur->addObject(tree);
            }

            z = cur->posUpperRight.z + 4;
            for (double x = cur->posBottomLeft.x + 4; x <= cur->posUpperRight.x - 4 && numLamps; x += 20, numLamps--) {
                Object* tree = cur->factory->createObject(objectType::LAMP_POST, vertex(x, 0, z), 0, 0, 0, 1, -90);
                cur->addObject(tree);
            }

            double x = cur->posBottomLeft.x + 4;
            for (double z = cur->posBottomLeft.z - 4; z >= cur->posUpperRight.z + 4 && numLamps; z -= 20, numLamps--) {
                Object* tree = cur->factory->createObject(objectType::LAMP_POST, vertex(x, 0, z));
                cur->addObject(tree);
            }

            x = cur->posUpperRight.x - 4;
            for (double z = cur->posBottomLeft.z - 4; z >= cur->posUpperRight.z + 4 && numLamps; z -= 20, numLamps--) {
                Object* tree = cur->factory->createObject(objectType::LAMP_POST, vertex(x, 0, z), 0, 0, 0, 1, 180);
                cur->addObject(tree);
            }
        }

    }

}

void QuadTreeVertex::distributeCars(int& numCars) {
    std::queue<QuadTreeVertex*> queue;
    queue.push(this);

    while (!queue.empty()) {
        QuadTreeVertex* cur = queue.front();
        queue.pop();
        double size = cur->posUpperRight.x - cur->posBottomLeft.x;

        if (cur -> verticalRoad) {
            queue.push(cur->bottomLeft);
            queue.push(cur->bottomRight);
            queue.push(cur->topRight);
            queue.push(cur->topLeft);

            for (double x = 5 + cur->posBottomLeft.x; x <= cur->posUpperRight.x - 5 && numCars > 0; x += 20) {
                if (x >= cur->posBottomLeft.x + (size / 2) - 10
                    && x <= cur->posUpperRight.x - (size / 2) + 10) continue;

                numCars--;
                Object* car = cur->factory->createObject(objectType::CAR1, vertex(x, 0, cur -> posBottomLeft.z -size / 2), 0, 0, 0, 1, 90);
                cur->addObject(car);
            }
        
            for (double z = cur->posBottomLeft.z - 5; z >= cur->posUpperRight.z + 5; z -= 20) {
                if (z <= cur->posBottomLeft.z - (size / 2) + 10
                    && z >= cur->posUpperRight.z + (size / 2) - 10) continue;

                numCars--;
                Object* car = cur->factory->createObject(objectType::CAR1, vertex(cur->posBottomLeft.x + (size / 2), 0, z));
                cur->addObject(car);
            }
        }

        else if (cur->horiznotalRoad) {
            for (double x = 5 + cur->posBottomLeft.x; x <= cur->posUpperRight.x - 5 && numCars > 0; x += 20) {
                if (x >= cur->posBottomLeft.x + (size / 2) - 10
                    && x <= cur->posUpperRight.x - (size / 2) + 10) continue;

                numCars--;
                Object* car = cur->factory->createObject(objectType::CAR1, vertex(x, 0, cur->posBottomLeft.z - size / 2), 0, 0, 0, 1, 90);
                cur->addObject(car);
            }
        }

    }

}