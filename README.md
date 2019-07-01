# Conway's Game of Life

This is John Conway's Game of Life, a cellular automaton that simulates a basic form of evolution.

## Usage

To run the application, simply invoke it in a terminal:

```console
$ ./life
```

The command line switch `-w` can be used to change the width of the game screen, and `-h` can be used to change the height.

```console
$ ./life -w 20 -h 20
```

`-t` makes the board toroidal.

```console
$ ./life -t
```

`-f` sets the frames per second. If fps is 0 or not specified, vertical synchronization will be enabled. Setting fps to -1 will cause the game to run at maximum speed.

```console
$ ./life -fg 1 -bg 0
```
