#include "DrawCube.h"

void DrawCube::drawQuad(vertex bottomLeft, vertex bottomRight, vertex topRight, vertex topLeft,
    bool textured, int tex, int hRepeation, int vRepeation) {

    if (textured) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        if (hRepeation == 1 && vRepeation == 1) {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
        }
    }

    glBegin(GL_QUADS);

    glTexCoord2d(0, 0);
    glVertex3d(bottomLeft.x, bottomLeft.y, bottomLeft.z);

    glTexCoord2d(hRepeation, 0);
    glVertex3d(bottomRight.x, bottomRight.y, bottomRight.z);

    glTexCoord2d(hRepeation, vRepeation);
    glVertex3d(topRight.x, topRight.y, topRight.z);

    glTexCoord2d(0, vRepeation);
    glVertex3d(topLeft.x, topLeft.y, topLeft.z);

    glEnd();

    if (textured)
        glDisable(GL_TEXTURE_2D);
}

void DrawCube::draw(vertex pos, double width, double height, double length,
    bool textured, std :: vector<int> tex, std :: vector<int> hRepeation, std :: vector<int> vRepeation) {

    if(textured && (tex.size() < 6 || hRepeation.size() < 6 || vRepeation.size() < 6)) {
        tex.resize(6, tex[0]);
        hRepeation.resize(6, hRepeation[0]);
        vRepeation.resize(6, vRepeation[0]);
    }
    glPushMatrix();
    glTranslated(pos.x, pos.y, pos.z);
    glScaled(width, height, length);

    vertex v[6][4] = {
        {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}},                // Front Face 
        {{1, 0, -1}, {0, 0, -1}, {0, 1, -1}, {1, 1, -1}},                    // Back  Face
        {{0, 0, -1}, {0, 0, 0}, {0, 1, 0}, {0, 1, -1}},                // Left  Face
        {{1, 0, 0}, {1, 0, -1}, {1, 1, -1}, {1, 1, 0}},                    // Right Face
        {{0, 1, 0}, {1, 1, 0}, {1, 1, -1}, {0, 1, -1}},                    // Top   Face
        {{0, 0, -1}, {1, 0, -1}, {1, 0, 0}, {0, 0, 0}},                // Bottom  Face
    };

    for (int i = 0; i < 6; i++) {
        if (textured)
            drawQuad(v[i][0], v[i][1], v[i][2], v[i][3], textured, tex[i], hRepeation[i], vRepeation[i]);
        else
            drawQuad(v[i][0], v[i][1], v[i][2], v[i][3], textured);
    }

    glPopMatrix();
}


     