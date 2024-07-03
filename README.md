# VideoBreaker

VideoBreaker is a simple, yet engaging game built using C++ and the Raylib graphics library. The game features a classic brick-breaking gameplay with a modern twist. Players control a bar at the bottom of the screen to bounce a ball upwards, breaking blocks and preventing the ball from falling off the screen.

## Features

- **Dynamic Gameplay**: Each game session is unique with randomly placed blocks.
- **Collision Detection**: Implements collision detection between the ball, the bar, and the blocks.
- **Game Over and Restart**: The game detects a game over state and allows restarting.
- **Performance**: Optimized for smooth performance with adjustable Frames Per Second (FPS).

## Getting Started

### Prerequisites

- C++ Compiler (GCC or Clang)
- Make
- Raylib installed and configured

### Compilation

To compile the game, navigate to the project's root directory and run:

```sh
make
```

This will compile the source files and link them with Raylib to create an executable named `VideoBreaker`.

### Running the Game

After compilation, you can start the game by executing:

```sh
./VideoBreaker
```

## Controls

- **Move Bar**: Use left and right arrow keys to move the bar.
- **Restart Game**: Press Enter to restart the game after a game over.

## Contributing

Contributions to VideoBreaker are welcome. Please feel free to fork the repository, make changes, and submit pull requests.

## License

VideoBreaker is open-source software licensed under the MIT license. See the LICENSE file for more details.