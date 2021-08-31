#include "WorldGenerator.h"
#include "Cube.h"
#include <iostream>

QuadTreeVertex* WorldGenerator :: generate() {
    puts("Enter map size: "); scanf("%d", &size);
    puts("Enter number of roads: "); scanf("%d", &numRoads);
    puts("Enter number of main buildings: "); scanf("%d", &numMainBuildings);
    puts("Enter number of buildings: "); scanf("%d", &numBuildings);
    puts("Enter number of trees: "); scanf("%d", &numTrees);
    puts("Enter number of cars: "); scanf("%d", &numCars);
    puts("Enter number of tree lamps: "); scanf("%d", &numLamps);
    root = new QuadTreeVertex(vertex(-size / 2, 0, size / 2), vertex(size / 2, 0, -size / 2));

    Cube* skybox = new Cube(root -> posBottomLeft + vertex(0, -size / 2, 0), size, size, size, 0);
    Cube* collisionLeft = new Cube(root -> posBottomLeft, size, size / 2, 5, 90);
    Cube* collisionRight = new Cube(root -> posBottomLeft + vertex(size + 5, 0, 0), size, size / 2, 5, 90);
    Cube* collisionFront = new Cube(root -> posBottomLeft + vertex(-5, 0, 5), size + 10, size / 2, 5, 0);
    Cube* collisionBack = new Cube(root -> posBottomLeft + vertex(-5, 0, -size), size + 10, size / 2, 5, 0);
    camera.addMovementObserver(collisionLeft);
    camera.addMovementObserver(collisionRight);
    camera.addMovementObserver(collisionFront);
    camera.addMovementObserver(collisionBack);
    skybox -> setTextures({skyFront, skyBack, skyLeft, skyRight, skyUp, skyDown}, {1}, {1});
    root -> addObject(skybox);

    Cube* ground = new Cube(root -> posBottomLeft, size, 1e-3, size, 0);
    ground -> setTextures({grass}, {size}, {size});
    root -> addObject(ground);
    
    root -> factory = new ObjectFactory();

    root -> distributeRoads(numRoads);
    root -> distributePavements();
    root -> distributeBuildings(numMainBuildings, numBuildings, objectType :: MAIN_BUILDING1, objectType :: BUILDING1);
    root -> distributeTrees(numTrees);
    root->distributeLamps(numLamps);
    root->distributeCars(numCars);
    if(numRoads > 0 || numBuildings > 0 || numMainBuildings > 0 || numTrees > 0 || numLamps > 0 || numCars > 0) {
        puts("Couldn't fit everything in map!!");
        exit(0);
    }

    return root;
}