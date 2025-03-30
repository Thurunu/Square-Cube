#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

float A, B, C;

float cubeWidth = 15;
int width = 160, height = 44;
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCIICODE = ' ';
int distanceFromCam = 150;
int K1 = 55;

float incrementSpeed = 0.4;

float x, y, z;
float ooz;
int xp, yp;
int idx;


float caluclateX(int i, int j, int k){
    // cos(double) -> double 
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C)
    + j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

float caluclateY(int i, int j , int k){
    // cos(double) -> double
    return j * cos(A) * cos(C) + k * sin(A) * cos(C)
    - j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C)
    - i * cos(B) * sin(C);
}

float caluclateZ(int i, int j, int k){
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}


void calcualteForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
    x = caluclateX(cubeX, cubeY, cubeZ);
    y = caluclateY(cubeX, cubeY, cubeZ);
    z = caluclateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

    ooz = 1 / z;

    xp = (int)(width / 2 + K1 * ooz * x * 3);
    yp = (int)(height / 2 + K1 * ooz * y * 2 + 5);

    idx  = xp + yp * width;
    if(idx >= 0 && idx < width * height){
        if(ooz > zBuffer[idx]){
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }

}


int main() {
    printf("\x1b[2J]");

    while(1){
        memset(buffer, backgroundASCIICODE, width * height);
        memset(zBuffer, 0 , width * height * 4);
        for(float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed){
            for(float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed){
                calcualteForSurface(cubeX, cubeY, -cubeWidth, '$'); // Front Face
                calcualteForSurface(cubeWidth, cubeY, cubeX, '#'); // Right Face
                calcualteForSurface(-cubeWidth, cubeY, -cubeX, '*'); // Left Face
                calcualteForSurface(-cubeX, cubeY, cubeWidth, '+'); // Back Face
                calcualteForSurface(cubeX, -cubeWidth, -cubeY, '.'); // Bottom Face
                calcualteForSurface(cubeX, cubeWidth, cubeY, '!'); // Top Face
            }
        }
        printf("\x1b[H");
        for(int k  =0; k < width * height; k++){
            putchar(k % width ? buffer[k] : 10);
        }

        A += 0.005;
        B += 0.005;
        usleep(1000);
    }

    return 0;
}

