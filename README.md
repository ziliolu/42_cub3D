# Cub3D

![Cub3D Banner](cub3d_banner.png)

Welcome to the Cub3D project! Dive into the exciting world of raycasting and maze exploration with our interactive game. Learn about the DDA algorithm and how raycasting works in this creative 3D environment.

### 🤝 Authorship - Collaborative Work
> We worked together to develop and enhance this project, sharing knowledge and experiences throughout the process :)

- [Ivo Marques](https://github.com/Pastilhex) - **riolivei**
- [Luiza Zilio](https://github.com/ziliolu) - **lpicoli-**
- 
## Table of Contents
- [Project Overview](#project-overview)
- [Usage](#usage)
- [What is DDA?](#what-is-dda)
- [How Raycasting Works](#how-raycasting-works)
- [Bonus Features](#bonus-features)

## Project Overview
Cub3D is more than just a game; it's a learning experience. Step into the shoes of a maze explorer and immerse yourself in the world of raycasting. Use your skills to navigate through a 3D maze, all while gaining an understanding of the DDA algorithm.

## Usage
Let's get started on your journey of raycasting and maze exploration. Here's how:

1. Clone the repository:
  ```bash
  git clone git@github.com:ziliolu/42_cub3d.git
  ```
2. Navigate to the project directory and compile it:
  ```bash
  cd 42_cub3d && make
  ```
3. Choose a map from maps folder or test with your own map
  ```bash
 ./cub3D maps/valid/subject_map.cub
  ```
  ```bash
  ./cub3D path_to_your_own_map**
  ```

## What is DDA?
DDA stands for Digital Differential Analyzer, a mathematical algorithm used for generating lines, as we do in raycasting. In our context, DDA is the magic behind the scenes, helping us draw rays to create a 3D view of the maze.

Imagine DDA as your artist's brush, painting the pixels that make up our 3D world. It's a step-by-step process, calculating the intersections between the rays and the walls. This allows us to simulate the play of light and shadows, making the maze come to life.

## How Raycasting Works
Raycasting is a fascinating technique used in video games to create a 3D perspective. It simulates how light rays travel through a scene. In our game, the player emits rays in all directions, just like a flashlight illuminating the path ahead.

As these rays hit walls, we calculate their lengths and angles, which ultimately create the illusion of depth. This is how you see the 3D maze, even though it's just a 2D grid. The rays cast the world around you, showing you what's near and far.

## Bonus Features
In addition to the core requirements, we've added extra excitement to the Cub3D experience:

### Wall Collision Detection
Our walls are solid! You can't walk through them. Try to pass through a wall, and you'll find yourself blocked.

### Minimap
Getting lost? Our minimap has got you covered. This handy feature provides an overhead view of the maze, helping you keep your bearings and navigate through the labyrinth.

[Start Your Adventure](#usage)

![Cub3D Screenshot](cub3d_screenshot.png)
