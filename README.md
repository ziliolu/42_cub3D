# Cub3D

<p align="center">
  <img src="https://img.shields.io/github/languages/top/ziliolu/42_cub3D?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/score-103%20%2F%20100-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/status-finished-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/ziliolu/42_cub3D?color=#FFFFFF&style=flat-square" />
</p>
<p align="center">
  <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExYnZqdWpvMm9rYXZhcjVjaWppODVnOW51YzByNzc1dmxkaWZyMmxuMCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/lFddL2AhlVY9QC2YLI/giphy-downsized-large.gif" width="500" />
</p>
  
![Cub3D Banner](https://github.com/ziliolu/42_cub3D/blob/main/cub3d_gif.mp4)

Welcome to the Cub3D project! Dive into the exciting world of raycasting and maze exploration with our interactive game. Learn about the DDA algorithm and how raycasting works in this creative 3D environment.

### 🤝 Authorship - Collaborative Work
> We worked together to develop and enhance this project, sharing knowledge and experiences throughout the process :)

- [Ricardo Melo](https://github.com/reomelo) - **riolivei**
- [Luiza Zilio](https://github.com/ziliolu) - **lpicoli-**

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
  git clone git@github.com:ziliolu/42_cub3D.git
  ```
2. Navigate to the project directory and compile it:
  ```bash
  cd 42_cub3D && make
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

[Start Your Adventure](#usage)

![Cub3D Screenshot](cub3d_screenshot.png)
