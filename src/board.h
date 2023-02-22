/* Copyright (C) 2023 Lazar Ionut-Radu */
/* lightknight, a simple chess engine */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "types.h"

/*
    Board types:

    -> board[64]:

        8 | 56  57  58  59  60  61  62  63
        7 | 48  49  50  51  52  53  54  55
        6 | 40  41  42  43  44  45  46  47
        5 | 32  33  34  35  36  37  38  39
        4 | 24  25  26  27  28  29  30  31
        3 | 16  17  18  19  20  21  22  23
        2 | 8   9   10  11  12  13  14  15
        1 | 0   1   2   3   4   5   6   7  
        --|--------------------------------
          | A   B   C   D   E   F   G   H

    -> board[120]:

        * | 110 111 112 113 114 115 116 117 118 119
        * | 100 101 102 103 104 105 106 107 108 109
        8 | 90  91  92  93  94  95  96  97  98  99
        7 | 80  81  82  83  84  85  86  87  88  89
        6 | 70  71  72  73  74  75  76  77  78  79
        5 | 60  61  62  63  64  65  66  67  68  69
        4 | 50  51  52  53  54  55  56  57  58  59
        3 | 40  41  42  43  44  45  46  47  48  49
        2 | 30  31  32  33  34  35  36  37  38  39
        1 | 20  21  22  23  24  25  26  27  28  29
        * | 10  11  12  13  14  15  16  17  18  19
        * | 0   1   2   3   4   5   6   7   8   9
        --|-----------------------------------------
          | *   A   B   C   D   E   F   G   H   *
        
    Moving a knight from B1 TO C3 is done by adding 21 to 22 (B1).
    The redundant squares are there as borders, if a piece tries a move that would
    land it outside the board, the addition result is a number < 120, on the border.
*/

/* Returns TRUE if the square is on the board120, FALSE otherwise. */
int is_on_board120(int sq120);

/* Returns TRUE if the square is on the board64, FALSE otherwise. */
int is_on_board64(int sq64);

/* Convert a valid square on a board64 to its equivalent on a board120. */
int square_64_to_120(int sq64);

/* Convert a square on a board120 to a square on a square64. */
int square_120_to_64(int sq120);

/* Sets up the board */

#endif /* _BOARD_H_ */