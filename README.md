# Rotating ASCII Cube

![Cube Animation](rotation_video/screen_cube.gif)  

This project renders a rotating 3D cube using ASCII characters in the terminal. The rotation is implemented using 3D rotation matrices and trigonometric calculations.

## How It Works
The cube is projected onto a 2D plane using the depth buffer method. The rotation is achieved using the following 3D rotation matrix formulas:

### Rotation around X-axis
\[
\begin{bmatrix}
1 & 0 & 0 \\
0 & \cos(A) & -\sin(A) \\
0 & \sin(A) & \cos(A)
\end{bmatrix}
\]

### Rotation around Y-axis
\[
\begin{bmatrix}
\cos(B) & 0 & \sin(B) \\
0 & 1 & 0 \\
-\sin(B) & 0 & \cos(B)
\end{bmatrix}
\]

### Rotation around Z-axis
\[
\begin{bmatrix}
\cos(C) & -\sin(C) & 0 \\
\sin(C) & \cos(C) & 0 \\
0 & 0 & 1
\end{bmatrix}
\]

Using these rotation matrices, the transformed coordinates \( (x', y', z') \) of the cube are calculated as follows:

\[
\begin{aligned}
X' &= j \sin(A) \sin(B) \cos(C) - k \cos(A) \sin(B) \cos(C) + j \cos(A) \sin(C) + k \sin(A) \sin(C) + i \cos(B) \cos(C) \\
Y' &= j \cos(A) \cos(C) + k \sin(A) \cos(C) - j \sin(A) \sin(B) \sin(C) + k \cos(A) \sin(B) \sin(C) - i \cos(B) \sin(C) \\
Z' &= k \cos(A) \cos(B) - j \sin(A) \cos(B) + i \sin(B)
\end{aligned}
\]

where \( i, j, k \) are the original cube coordinates before rotation.

## Features
- Real-time ASCII rendering of a rotating cube
- Depth buffering to ensure correct surface visibility
- Adjustable rotation speed and cube size
- Customizable ASCII characters for different cube faces

## Installation & Usage
Clone the repository and compile the program:
```sh
$ git clone https://github.com/yourusername/rotating-ascii-cube.git
$ cd rotating-ascii-cube
$ gcc cube.c -o cube -lm
$ ./cube
```

## Customization
- Modify the `cubeWidth` variable to change the cube size.
- Adjust `incrementSpeed` for finer rendering quality.
- Change the ASCII characters used for different faces in the `calcualteForSurface` function.

## Dependencies
- GCC Compiler
- Unix-based terminal (Linux/Mac recommended)

## References
- [Rotation Matrix - Wikipedia](https://en.wikipedia.org/wiki/Rotation_matrix)
- [Trigonometry and 3D transformations](https://en.wikipedia.org/wiki/Rotation_matrix)

## License
This project is licensed under the MIT License.

