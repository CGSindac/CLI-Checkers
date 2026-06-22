# CLI-Chekers
A Command Line Interface Checkers Game created using C++17

## Gameplay
Gameplay requires 2 players, with each player recieving 12 pieces which will be promoted to kings (As per checker's rules) upon reaching the opposite side of the board.

Each move is written in the following notation

**Pieces**
-White
    - 'W' -> Basic piece for white
    - 'Q' -> King piece for white
-Black
    - 'B' -> Basic piece for black
    - 'q' -> King piece for black

```txt
[Piece_Position][Action_Type][Final_Position]
```

**Movement**

*Action Type:* m 

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