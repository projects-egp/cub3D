_This project has been created as part of the 42 curriculum by made-ped, enrgil-p_

<h2 id="top">Index</h2>
<ol type="1">
  <li><a href="#description">Description</a></li>
  <li><a href="#technologies">Technologies</a></li>
  <li><a href="#instructions">How to compile</a></li>
  <li><a href="#resources">Resources</a></li>
</ol>

<h1 id="description">Description</h1>

cub3D is a 42 school project inspired by the original Wolfenstein 3D game. The goal is to implement a first-person 3D renderer from scratch in C using the raycasting technique: a 2D map is projected into a 3D perspective by casting rays for each vertical column of the screen.

The renderer supports textured walls (one texture per cardinal direction), solid ceiling and floor colors, player movement and rotation, and reads scene configuration from a `.cub` file.

<h1 id="technologies">Technologies</h1>

<ul>
  <li><b>Language:</b> C (C99), following the 42 norm (max 25 lines per function, restricted constructs)</li>
  <li><b>Graphics:</b> MiniLibX — a lightweight graphics library provided by 42. Two independent builds are maintained: one for macOS (OpenGL + AppKit) and one for Linux (X11 + Xext)</li>
  <li><b>Raycasting algorithm:</b> DDA (Digital Differential Analysis) in its efficient lodev variant — distances are computed incrementally using only additions, avoiding expensive trigonometric operations in the hot loop</li>
  <li><b>Texture mapping:</b> textures are loaded as MiniLibX images; pixels are written directly to the framebuffer via pointer arithmetic for performance</li>
  <li><b>Build system:</b> GNU Make, two independent Makefiles (mac/ and linux/)</li>
</ul>

<h1 id="instructions">How to compile</h1>

The project is split into two independent directories. Use the one matching your OS.

**macOS**
```sh
cd mac
make
./cub3D maps/map.cub
```

**Linux**
```sh
cd linux
make
./cub3D maps/map.cub
```

To clean build artifacts:
```sh
make clean    # removes object files
make fclean   # removes object files and binary
make re       # full rebuild
```

<h1 id="resources">Resources</h1>

<ul>
  <li><b>Lodev raycasting tutorial</b> — step-by-step explanation of the DDA raycasting algorithm, texture mapping and projection math. The primary technical reference for the renderer.</li>
  <li><b>Michael Abrash's Graphics Programming Black Book</b> — deep dive into the techniques behind Wolfenstein 3D and DOOM; useful for understanding fixed-point math, framebuffer access and optimization strategies.</li>
  <li><b>GitHub</b> — open source cub3D implementations used to cross-check algorithm correctness and understand edge cases.</li>
  <li><b>YouTube</b> — video explanations of raycasting, linear algebra and trigonometry applied to game engines.</li>
  <li><b>Coursera</b> — supplementary material on linear algebra and computer graphics fundamentals.</li>
</ul>

<h4>Use of AI</h4>

AI tools were used as a supplementary resource throughout the project: to clarify concepts, verify expected outputs of mathematical operations, and understand behavior of the MiniLibX API. All core algorithms were studied and implemented by hand before consulting AI, ensuring the understanding was genuine rather than copy-pasted.

<a href="#top">Back to index</a>
