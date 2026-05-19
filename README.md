# Cub3D
*This project has been created as part of the 42 curriculum by kevlim, gchalmel.*

## Description
**Cub3D** is a 3D graphical game engine inspired by the world-famous 1992 classic *Wolfenstein 3D*. Built entirely in C using the **miniLibX** graphical library, the goal of this project is to explore the concepts of Raycasting. 

## Instructions

### Compilation
To compile the project run:
```bash
make
```
To compile with the bonus:
```bash
make bonus
```

### Execution

```bash
./cub3d maps/good/cheese_maze.cub
```

### Controls

* `W` / `S` : Move forward / backward
* `A` / `D` : Strafe left / right
* `Left` / `Right` Arrows : Rotate camera left / right
* `ESC` or clicking the window's red cross : Quit

## Resources

### Documentation & Tutorials

* [Tutorial - Raycasting](https://www.google.com/search?q=https://lodev.org/cgtutor/raycast.html): main reference guide for understanding DDA and raycasting mathematics.
* [Permadi's Raycasting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/): Fundamental breakdown of pseudo-3D matrices and field-of-view geometry.
* [MiniLibX Manual](https://github.com/42Paris/minilibx-linux): Official documentation for hooks, loops, and image manipulation.

### Use of AI

* **Memory Management**
* **Norminette**
* **Explanation mathematical concepts**

---

## Raycasting Mathematics

### Ray Direction Formula

$$\vec{rayDir} = \vec{dir} + \vec{plane} \times \text{cameraX}$$

Generates all rays across the Field of View ($FOV$) using 2D vector algebra

### Delta Distance (`deltaDist`)

$$\text{deltaDistX} = \left| \frac{1}{\text{rayDirX}} \right|, \quad \text{deltaDistY} = \left| \frac{1}{\text{rayDirY}} \right|$$

Computes the exact distance a ray needs to travel to cross one full grid line on the map.

### DDA (Digital Differential Analysis)

```c
if (sideDistX < sideDistY) {
    sideDistX += deltaDistX;
    mapX += stepX;
} else {
    sideDistY += deltaDistY;
    mapY += stepY;
}
```

Increments the ray grid square by grid square rather than millimeter by millimeter, ensuring high performance by stopping immediately upon hitting a wall (`1`).

### Perpendicular Wall Distance (`perpWallDist`)

$$\text{perpWallDist} = \text{sideDistX} - \text{deltaDistX}$$

Calculates the shortest straight distance to the camera plane line rather than the player's single point. This mathematically eliminates the **Fish-Eye effect** (lens distortion), keeping the walls perfectly straight on screen.
