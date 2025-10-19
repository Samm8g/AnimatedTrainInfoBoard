# Animated Train Info Board

A C++/Qt6 application designed to replicate an animated train information display board, featuring multiple display states and cycling messages.

## Features

-   **Fullscreen Display:** The application runs in fullscreen mode for an immersive experience.
-   **Customizable Layout:** Features distinct top and bottom bars, with a central area dedicated to train information.
-   **Multiple Display States:** Transitions between different information modes:
    -   **Cycling:** Displays general information messages.
    -   **Approaching:** Shows messages for an approaching train.
    -   **At Platform:** Displays information for a train currently at the platform.
    -   **Terminus:** Indicates the final stop and prompts passengers to leave.
-   **Cycling Messages:** Messages within the Cycling, Approaching, At Platform, and Terminus states cycle automatically.
-   **Keybinds for State Transitions:** Easily switch between display states using keyboard shortcuts.
-   **Configurable Interval:** Message cycling interval is currently set to 3 seconds.

## Build Instructions (General Linux)

For a standard Linux distribution, you'll need a C++ compiler, CMake, Qt6 development libraries, and OpenGL development libraries.

1.  **Prerequisites:**
    *   C++ Compiler (e.g., g++ or clang++)
    *   CMake (version 3.16 or higher)
    *   Qt6 development libraries (Qt6 Core, Qt6 Gui, Qt6 Widgets)
    *   OpenGL development libraries

2.  **Install Dependencies (Example for Debian/Ubuntu-based systems):**
    ```bash
    sudo apt update
    sudo apt install build-essential cmake qt6-base-dev libopengl-dev
    ```
    *(Note: Package names may vary for other distributions like Fedora, Arch, etc. Consult your distribution's documentation.)*

3.  **Build Steps:**
    ```bash
    # Navigate to your project directory
    # cd /path/to/AnimatedTrainInfoBoard

    mkdir build
    cd build
    cmake ..
    make -j$(nproc) # Or 'ninja -j$(nproc)' if you have Ninja installed
    ./AnimatedTrainInfoBoard
    ```

## Build Instructions (NixOS)

This project is developed using C++ and Qt6 on NixOS. To build and run the application, ensure your NixOS environment is set up with the necessary Qt6 and OpenGL development libraries.

1.  **Ensure `shell.nix` is configured:**
    Make sure your `shell.nix` file in the project root includes `pkgs.qt6.full`, `pkgs.libGL`, `pkgs.libGLU`, `pkgs.mesa`, and `pkgs.qt6.qtbase.dev` in `buildInputs`, and exports `CMAKE_PREFIX_PATH` for Qt6.

    ```nix
    { pkgs ? import <nixpkgs> {} }:

    pkgs.mkShell {
      buildInputs = [
        pkgs.cmake
        pkgs.gcc
        pkgs.libglvnd
        pkgs.mesa
        pkgs.pkg-config
        pkgs.ninja
        pkgs.libGL
        pkgs.libGLU
        pkgs.qt6.full
        pkgs.qt6.qtbase.dev
      ];

      shellHook = ''
        export QT_PLUGIN_PATH=${pkgs.qt6.full}/lib/qt-6/plugins
        export QML2_IMPORT_PATH=${pkgs.qt6.full}/lib/qt-6/qml
        export LD_LIBRARY_PATH=${pkgs.qt6.full}/lib:$LD_LIBRARY_PATH
        export CMAKE_PREFIX_PATH=${pkgs.qt6.full}:$CMAKE_PREFIX_PATH
      '';
    }
    ```

2.  **Enter the Nix shell:**
    ```bash
    nix-shell
    ```

3.  **Build with CLion:**
    It is recommended to use CLion for building and running this project due to its robust integration with CMake and Qt. Open the project in CLion and use its built-in build functionalities.

## Usage

Once built, run the executable. The application will launch in fullscreen mode.

-   **Spacebar:** Toggles between `Cycling` and `Approaching` states.
-   **'A' Key:** Toggles between `Cycling` and `At Platform` states.
-   **'T' Key:** Toggles between `Cycling` and `Terminus` states.

## TODO

-   [ ] **Dynamic Data:** Implement functionality to fetch and display actual train times, destinations, and other real-time data.
-   [ ] **Advanced Animations:** Explore and implement more sophisticated text animations (e.g., horizontal scrolling, character-by-character reveal, smooth transitions).
-   [ ] **Configuration Options:** Add external configuration (e.g., JSON, INI file) for messages, colors, fonts, animation speeds, and display layouts.
-   [ ] **UI for State Management:** Develop a small, non-intrusive UI (e.g., a hidden debug panel) for managing display states and messages, instead of relying solely on keybinds.
-   [ ] **Error Handling:** Improve robustness with better error handling for data loading and display.
-   [ ] **Platform Specifics:** Optimize for different display hardware or operating system specifics if necessary.
-   [ ] **Code Refinement:** Further refactor and optimize the C++ code for maintainability and performance.
