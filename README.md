<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>fdf
</h1>
<h3>◦ FDF: Revolutionize Coding!</h3>
<h3>◦ Developed with the software and tools listed below.</h3>

<p align="center">
<img src="https://img.shields.io/badge/C-A8B9CC.svg?style&logo=C&logoColor=black" alt="C" />
</p>
<img src="https://img.shields.io/github/languages/top/zneel/fdf?style&color=5D6D7E" alt="GitHub top language" />
<img src="https://img.shields.io/github/languages/code-size/zneel/fdf?style&color=5D6D7E" alt="GitHub code size in bytes" />
<img src="https://img.shields.io/github/commit-activity/m/zneel/fdf?style&color=5D6D7E" alt="GitHub commit activity" />
<img src="https://img.shields.io/github/license/zneel/fdf?style&color=5D6D7E" alt="GitHub license" />
</div>

---

## 📒 Table of Contents
- [📒 Table of Contents](#-table-of-contents)
- [📍 Overview](#-overview)
- [⚙️ Features](#-features)
- [📂 Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🚀 Getting Started](#-getting-started)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)
- [👏 Acknowledgments](#-acknowledgments)

---


## 📍 Overview

The project is a 3D wireframe projection viewer called "fdf" that uses the mlx graphics library. Its core functionalities include loading and parsing map files, rendering 3D wireframe projections of terrains, and allowing users to interact with the projections through keyboard inputs. The project's purpose is to provide a visually appealing and interactive way to view and explore terrain maps, which can be useful for various applications such as geographical analysis, game development, and virtual reality simulations.

---

## ⚙️ Features

| Feature                | Description                           |
| ---------------------- | ------------------------------------- |
| **⚙️ Architecture**     | The codebase follows a modular design pattern with separate files for different functionalities such as event handling, parsing, drawing, and matrix operations. It uses a graphics library called mlx and a custom library called libft for additional functionality in handling graphics and data structures. The main.c file serves as the entry point for the application and initializes the necessary components. Overall, the architecture seems well-structured and organized.    |
| **📖 Documentation**   | The codebase has a limited amount of documentation. While some individual functions and files are documented, the overall documentation is not comprehensive. There could be more detailed explanations of the system's components, their interdependencies, and usage instructions. Properly documenting the codebase would enhance its maintenance, understanding, and extendibility.    |
| **🔗 Dependencies**    | The codebase relies on two external libraries: mlx for graphical operations and libft for additional functionality. mlx is a library specifically designed for graphics programming in C, while libft is a custom library providing implementations of various standard C library functions. The dependencies seem suitable for fulfilling the requirements of the project.   |
| **🧩 Modularity**      | The codebase is divided into smaller, interchangeable components based on their functionalities. Each component has a specific purpose, such as event handling, parsing, drawing, and matrix operations. This modular approach allows for better organization, code reuse, and maintenance. However, there could be clearer separation between some of the components and better-defined interfaces between them.    |
| **✔️ Testing**          | The codebase does not include any explicit testing strategies or tools. There are no dedicated test files or frameworks mentioned to validate the functionality of the components. Having comprehensive tests would enhance the reliability and robustness of the system, ensuring that it performs as expected in different scenarios.     |
| **⚡️ Performance**      | Given the complexity of rendering and manipulating 3D wireframe models, the codebase performs reasonably well. However, without detailed performance profiling or benchmarks, it is difficult to assess its exact performance characteristics. It would be beneficial to optimize specific sections like drawing and rendering to improve speed, efficiency, and resource usage.   |
| **🔐 Security**        | The codebase does not have explicit measures mentioned for security. Considering that it is an open-source project, developers should be cautious about handling user input, especially when reading map files. Potential vulnerabilities like buffer overflow, input validation, and memory allocation should be carefully addressed to ensure data integrity and system stability.   |
| **🔀 Version Control** | The codebase adopts Git for version control. It is stored in a Git repository hosted on GitHub. Utilizing version control allows multiple contributors to collaborate, track changes, and roll back if necessary, minimizing conflicts and ensuring code integrity. Regular commit practices, branching, and proper documentation of changes can further enhance the version control process.    |
| **🔌 Integrations**    | The codebase primarily interacts with external libraries, mlx and libft, to achieve desired functionalities. As it stands, there are no explicit integrations with external systems or services mentioned. However, being open-source, it

---


## 📂 Project Structure




---

## 🧩 Modules

<details closed><summary>Root</summary>

| File                                                        | Summary                                                                                                                                                                                                                                                                                                         |
| ---                                                         | ---                                                                                                                                                                                                                                                                                                             |
| [Makefile](https://github.com/zneel/fdf/blob/main/Makefile) | This code is for a program called "fdf". It includes multiple source files for event handling, parsing, drawing, and matrix operations. It uses the mlx library and libft for additional functionality. The code can be compiled, cleaned, recompiled, and cleaned again using the corresponding make commands. |

</details>

<details closed><summary>Src</summary>

| File                                                        | Summary                                                                                                                                                                                                                                                                                                                                                                    |
| ---                                                         | ---                                                                                                                                                                                                                                                                                                                                                                        |
| [main.c](https://github.com/zneel/fdf/blob/main/src/main.c) | The main.c file initializes and sets up a 3D representation of a terrain map using the FDF (WireFrame) graphic library. It handles functions such as freeing memory, exiting the program, initializing zoom and structures, opening and parsing a map file, creating and managing the display window, calculating the coordinates of the terrain, and handling user input. |

</details>

<details closed><summary>Draw</summary>

| File                                                                         | Summary                                                                                                                                                                                                                                                                                                                |
| ---                                                                          | ---                                                                                                                                                                                                                                                                                                                    |
| [image.c](https://github.com/zneel/fdf/blob/main/src/draw/image.c)           | The code defines functions for manipulating and displaying images in a graphical interface. It includes functionality to put pixels at specific coordinates with a given color, initialize an image, and draw it on the screen.                                                                                        |
| [bresenham.c](https://github.com/zneel/fdf/blob/main/src/draw/bresenham.c)   | This code includes two functions: "compute_color" calculates the color based on the given z-value, and "draw_line" uses Bresenham's line algorithm to draw a line between two 3D points, with color based on their z-values.                                                                                           |
| [projection.c](https://github.com/zneel/fdf/blob/main/src/draw/projection.c) | The code provides a function to apply isometric projection to given coordinates. The projection is performed based on rotation angle and scaling factors specified in the input. The transformed coordinates are then further adjusted with translation values, and the result is returned.                            |
| [draw.c](https://github.com/zneel/fdf/blob/main/src/draw/draw.c)             | The code is responsible for drawing lines on a FDF (Fil De Fer) representation. The trace function calculates the starting and ending coordinates for each line, and the calc_fdf function iterates through the matrix to trace each point. Overall, the code creates a visual representation of a 3D wireframe model. |

</details>

<details closed><summary>Helpers</summary>

| File                                                                    | Summary                                                                                                                                                                                                                                                                         |
| ---                                                                     | ---                                                                                                                                                                                                                                                                             |
| [number.c](https://github.com/zneel/fdf/blob/main/src/helpers/number.c) | The code contains three functions: max, min, and sign.-The max function returns the maximum value between two inputs.-The min function returns the minimum value between two inputs.-The sign function returns 1 if the first input is smaller than the second and-1 otherwise. |
| [colors.c](https://github.com/zneel/fdf/blob/main/src/helpers/colors.c) | The given code provides a function called "rgb_encode" which takes in three input arguments representing red, green, and blue color values. It combines these values to generate a single encoded integer representing the RGB color code.                                      |
| [vect3.c](https://github.com/zneel/fdf/blob/main/src/helpers/vect3.c)   | The code defines a function to create a 3D vector structure, given a 2D matrix and coordinates. The created vector holds the x, y, and z values of the matrix.The function returns a pointer to the created vector or NULL if memory allocation fails.                          |

</details>

<details closed><summary>Parser</summary>

| File                                                                     | Summary                                                                                                                                                                                                                                                  |
| ---                                                                      | ---                                                                                                                                                                                                                                                      |
| [matrix.c](https://github.com/zneel/fdf/blob/main/src/parser/matrix.c)   | The code includes functions for splitting and counting elements in a matrix, getting the dimensions of the matrix from a file, freeing the matrix memory, and creating a new matrix structure.                                                           |
| [matrix2.c](https://github.com/zneel/fdf/blob/main/src/parser/matrix2.c) | The code contains functions for freeing and splitting strings, as well as parsing integers from a string and storing them in a matrix.                                                                                                                   |
| [map.c](https://github.com/zneel/fdf/blob/main/src/parser/map.c)         | The code implements functionalities to read a file containing a matrix, allocate memory for the matrix, and populate the matrix with data. It includes functions to open the map, allocate memory for the matrix, and populate the matrix from the file. |

</details>

<details closed><summary>Matrix</summary>

| File                                                                           | Summary                                                                                                                                                                                                                                   |
| ---                                                                            | ---                                                                                                                                                                                                                                       |
| [operations.c](https://github.com/zneel/fdf/blob/main/src/matrix/operations.c) | The code defines two functions, get_max and get_min, which calculate the maximum and minimum values within a matrix respectively. These functions iterate through the matrix and compare each value to determine the maximum and minimum. |

</details>

<details closed><summary>Events</summary>

| File                                                                       | Summary                                                                                                                                                                                                                                                                                                                    |
| ---                                                                        | ---                                                                                                                                                                                                                                                                                                                        |
| [loop.c](https://github.com/zneel/fdf/blob/main/src/events/loop.c)         | The code defines a hook loop function that sets up various event handlers and a render function and then enters an infinite loop to handle events using the mlx library.                                                                                                                                                   |
| [handlers.c](https://github.com/zneel/fdf/blob/main/src/events/handlers.c) | The code consists of three main functionalities: 1. key_handler handles keyboard input and closes the window if ESC or Q is pressed.2. close_handler is triggered when the window is closed, and it destroys the window. 3. render is responsible for drawing the image on the window using the data in the fdf structure. |

</details>

<details closed><summary>Include</summary>

| File                                                          | Summary                                                                                                                                                                                                                                          |
| ---                                                           | ---                                                                                                                                                                                                                                              |
| [fdf.h](https://github.com/zneel/fdf/blob/main/include/fdf.h) | This code defines the data structures and functions necessary for a 3D wireframe projection viewer using the mlx graphics library. It includes features such as loading a map, handling input keys, rendering the projection, and drawing lines. |

</details>

<details closed><summary>Test_maps</summary>

| File                                                                                | Summary                                                                                                                                                                                                                                                                                                              |
| ---                                                                                 | ---                                                                                                                                                                                                                                                                                                                  |
| [basictest.fdf](https://github.com/zneel/fdf/blob/main/test_maps/basictest.fdf)     | This code generates a matrix pattern starting with zeroes in the upper diagonal positions and incrementing by one in each subsequent diagonal, going left to right, top to bottom. The matrix is printed with each element separated by spaces.                                                                      |
| [elem-fract.fdf](https://github.com/zneel/fdf/blob/main/test_maps/elem-fract.fdf)   | Prompt exceeds max token limit: 250039.                                                                                                                                                                                                                                                                              |
| [mars.fdf](https://github.com/zneel/fdf/blob/main/test_maps/mars.fdf)               | Prompt exceeds max token limit: 23239.                                                                                                                                                                                                                                                                               |
| [pyramide.fdf](https://github.com/zneel/fdf/blob/main/test_maps/pyramide.fdf)       | The code represents a 2D grid filled with numbers. The numbers increase diagonally, forming a pyramid shape. The highest number is represented by 9, and the pyramid is mirrored across the middle row. The code seems to demonstrate a pattern or algorithm for creating this pyramid.                              |
| [elem-col.fdf](https://github.com/zneel/fdf/blob/main/test_maps/elem-col.fdf)       | The code generates a 2D grid with varying numerical values. Some of these values are highlighted in red. The goal of the code is not explicitly mentioned, but it seems to visually represent a landscape or a picture with color-coded elements.                                                                    |
| [20-60.fdf](https://github.com/zneel/fdf/blob/main/test_maps/20-60.fdf)             | The code is a list of numbers. Its core functionality is to store and manipulate this list, allowing for operations such as adding, subtracting, sorting, and finding specific numbers within the list.                                                                                                              |
| [pylone.fdf](https://github.com/zneel/fdf/blob/main/test_maps/pylone.fdf)           | HTTPStatus Exception: 400                                                                                                                                                                                                                                                                                            |
| [pnp_flat.fdf](https://github.com/zneel/fdf/blob/main/test_maps/pnp_flat.fdf)       | The code represents a 2D array with all elements initialized to 0. It provides a foundation for storing and manipulating data in a grid format.                                                                                                                                                                      |
| [50-4.fdf](https://github.com/zneel/fdf/blob/main/test_maps/50-4.fdf)               | HTTPStatus Exception: 400                                                                                                                                                                                                                                                                                            |
| [10-70.fdf](https://github.com/zneel/fdf/blob/main/test_maps/10-70.fdf)             | The code represents a matrix of integers. Its core functionality is to store a 10x10 matrix and provide access to the individual elements for further processing or analysis.                                                                                                                                        |
| [julia.fdf](https://github.com/zneel/fdf/blob/main/test_maps/julia.fdf)             | Prompt exceeds max token limit: 250039.                                                                                                                                                                                                                                                                              |
| [pentenegpos.fdf](https://github.com/zneel/fdf/blob/main/test_maps/pentenegpos.fdf) | The code generates a grid of numbers from-10 to 10, arranged in rows and columns. Each number is repeated multiple times to form a structured pattern. The goal of the code is to create a grid representation using the given number range.                                                                         |
| [42.fdf](https://github.com/zneel/fdf/blob/main/test_maps/42.fdf)                   | The code showcases a 2-dimensional grid with specific values. The grid represents a game board, where tens indicate positions to be occupied by players. The functionality of the code lies in generating and displaying the game board, initializing player positions, and allowing for gameplay interactions.      |
| [t1.fdf](https://github.com/zneel/fdf/blob/main/test_maps/t1.fdf)                   | Prompt exceeds max token limit: 40039.                                                                                                                                                                                                                                                                               |
| [t2.fdf](https://github.com/zneel/fdf/blob/main/test_maps/t2.fdf)                   | Prompt exceeds max token limit: 10039.                                                                                                                                                                                                                                                                               |
| [pyra.fdf](https://github.com/zneel/fdf/blob/main/test_maps/pyra.fdf)               | The code generates a grid of values representing a 2D plane. It starts from 0 at the center and incrementally increases in each direction, forming a symmetrical pattern. The grid serves as a simple reference system for mapping coordinates and performing calculations on the plane.                             |
| [100-6.fdf](https://github.com/zneel/fdf/blob/main/test_maps/100-6.fdf)             | Prompt exceeds max token limit: 10039.                                                                                                                                                                                                                                                                               |
| [elem2.fdf](https://github.com/zneel/fdf/blob/main/test_maps/elem2.fdf)             | The code represents a 2D grid with varying values. The core functionality is to analyze and manipulate specific elements within the grid.                                                                                                                                                                            |
| [elem.fdf](https://github.com/zneel/fdf/blob/main/test_maps/elem.fdf)               | The code generates a 2D matrix with a specific pattern. Each element in the matrix represents the sum of neighboring elements. The neighboring elements are determined based on their position (north, south, east, west). The matrix has values ranging from 0 to 20, with the highest value located at the center. |
| [10-2.fdf](https://github.com/zneel/fdf/blob/main/test_maps/10-2.fdf)               | The code represents a 10x10 grid of numeric values. Each value represents the presence or absence of a certain feature. The goal is to understand the patterns and relationships within the grid and utilize it for further analysis or processing.                                                                  |
| [plat.fdf](https://github.com/zneel/fdf/blob/main/test_maps/plat.fdf)               | The code represents a 2D grid consisting of all zeros. Its core functionality is to initialize and display this grid.                                                                                                                                                                                                |

</details>

---

## 🚀 Getting Started

### ✔️ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> - `ℹ️ Requirement 1`
> - `ℹ️ Requirement 2`
> - `ℹ️ ...`

### 📦 Installation

1. Clone the fdf repository:
```sh
git clone https://github.com/zneel/fdf
```

2. Change to the project directory:
```sh
cd fdf
```

3. Install the dependencies:
```sh
`ℹ️  INSERT-DESCRIPTION`
```

### 🎮 Using fdf

```sh
`ℹ️  INSERT-DESCRIPTION`
```

### 🧪 Running Tests
```sh
`ℹ️  INSERT-DESCRIPTION`
```

---


## 🗺 Roadmap

> - [X] `ℹ️  Task 1: Implement X`
> - [ ] `ℹ️  Task 2: Refactor Y`
> - [ ] `ℹ️ ...`


---

## 🤝 Contributing

Contributions are always welcome! Please follow these steps:
1. Fork the project repository. This creates a copy of the project on your account that you can modify without affecting the original project.
2. Clone the forked repository to your local machine using a Git client like Git or GitHub Desktop.
3. Create a new branch with a descriptive name (e.g., `new-feature-branch` or `bugfix-issue-123`).
```sh
git checkout -b new-feature-branch
```
4. Make changes to the project's codebase.
5. Commit your changes to your local branch with a clear commit message that explains the changes you've made.
```sh
git commit -m 'Implemented new feature.'
```
6. Push your changes to your forked repository on GitHub using the following command
```sh
git push origin new-feature-branch
```
7. Create a new pull request to the original project repository. In the pull request, describe the changes you've made and why they're necessary.
The project maintainers will review your changes and provide feedback or merge them into the main branch.

---

## 📄 License

This project is licensed under the `ℹ️  INSERT-LICENSE-TYPE` License. See the [LICENSE](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/adding-a-license-to-a-repository) file for additional info.

---

## 👏 Acknowledgments

> - `ℹ️  List any resources, contributors, inspiration, etc.`

---
