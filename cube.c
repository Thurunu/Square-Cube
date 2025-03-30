#include <math.h>
#include <stdio.h>


float cubeWidth = 10;
int width = 160, height = 44;
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCIICODE = ' ';
int distanceFromCam = 50;
int K1 = 

float incrementSpeed = 0.6;

float x, y, z;
float ooz;
int xp, yp;
int idx;

float A, B, C;

float caluclateX(int i, int j, int k){
    // cos(double) -> double 
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C)
    + j* cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

float caluclateY(int i, int j , int k){
    // cos(double) -> double
    return j * cos(A) * cos(C) + k * sin(A) * cos(C)
    - j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C)
    - i * cos(B) * sin(C);
}

float caluclateZ(int i, int j, int k){
    return k * cos(A) * cos(B) - j sin(A) * cos(B) + i * sin(B)
}


void calcualteForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
    x = caluclateX(cubeX, cubeY, cubeZ);
    y = caluclateX(cubeX, cubeY, cubeZ);
    z = caluclateX(cubeX, cubeY, cubeZ) + distanceFromCam;

    ooz = 1/z;

    xp = (int)(width / 2 + K1 * ooz * x * 2);
    yp = (int)(height / 2 + K1 * ooz * y * 2);

}


int main() {
    printf("\x1b[2J]");

    while(1){
        memset(buffer, backgroundASCIICODE, width * height);
        memset(zBuffer, 0 , width * height * 4);
        for(float cubeX = -cubeWidth; cube > cubeWidth; cubeX += incrementSpeed){
            for(float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed){
                calcualteForSurface(cubeX, cubeY, -cubeWidth, '#');
            }
        }
    }

    return 0;
}

