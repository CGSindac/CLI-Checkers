# CLI-Chekers
A Command Line Interface Checkers Game created using C++17

## Gameplay
Gameplay requires 2 players, with each player recieving 12 pieces which will be promoted to kings (As per checker's rules) upon reaching the opposite side of the board.

**Pieces**
- White
    - 'W' -> Basic piece for white
    - 'Q' -> King piece for white
- Black
    - 'B' -> Basic piece for black
    - 'q' -> King piece for black

Each move is written in the following notation

```txt
[Piece_Position][Action_Type][Final_Position]
```

**Movement**

Every piece's, when moving, Action_Type is the following... 

*Action Type:* m 

Movements means moving one tile diagonally.

For example, to move White d6 to c5, the input would have to be the following...

```txt
1 | B + B + B + B +  
2 | + B + B + B + B  
3 | B + B + B + B +  
4 | + # + # + # + #  
5 | # + # + # + # +  
6 | + W + W + W + W  
7 | W + W + W + W +  
8 | + W + W + W + W  
& | a b c d e f g h 
Input: d6mc5
```

Which will result in, Same applies to black pieces

```txt
1 | B + B + B + B +  
2 | + B + B + B + B  
3 | B + B + B + B +  
4 | + # + # + # + #  
5 | # + W + # + # +  
6 | + W + # + W + W  
7 | W + W + W + W +  
8 | + W + W + W + W  
& | a b c d e f g h 
Input: 
```

**Capturing**

Every piece's, when capturing, Action_Type is the following... 

*Action Type:* x 

Moreover, players can chain their captures provided that the actions are legal and possible.

For White to capture Black d4 , the input would have to be the following...

```txt
1 | B + B + B + B +  
2 | + B + B + B + B  
3 | B + B + # + B +  
4 | + # + B + # + #  
5 | # + W + # + # +  
6 | + W + # + W + W  
7 | W + W + W + W +  
8 | + W + W + W + W  
& | a b c d e f g h 
Input: c5xe3
```

Which results in a capture, same rules applies to black pieces.

```txt
1 | B + B + B + B +  
2 | + B + B + B + B  
3 | B + B + W + B +  
4 | + # + # + # + #  
5 | # + # + # + # +  
6 | + W + # + W + W  
7 | W + W + W + W +  
8 | + W + W + W + W  
& | a b c d e f g h 
Input: 
```

**Kings**

Same rules for movement and capture is applied to White & Black Kings, with an addition that they can move/capture in all diagonals (Provided that it is legal or possible).

## Installation
Download the repository or clone it using the following...
```bash
git clone https://github.com/CGSindac/CLI-Checkers
```

## Usage
1. Ensure CLI-CHECKERS is the directory

2. To Compile, run the makefile in your terminal
```bash
make
```
If you do not have make in your unit, paste the following

```bash
g++ -o min.exe main.cpp include/say.cpp
```

3. To run Paste the following (For Windows)
```bash
./min
```

## Author

CGSindac
Date Completed 6/22/2026

Made this to practice C++ and Compiling, Learned BFS for this thing (project got delayed due to this).

Will optimize or cleanup code in the future, but currently learning other stuff along with C++.

Some information may lack in the readme, feel free to contact me 

Linkedin: linkedin.com/in/calix-gabriel-sindac-768014383/

***o7***

