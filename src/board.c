/* Copyright (C) 2023 Lazar Ionut-Radu */
/* lightknight, a simple chess engine */

#include "board.h"

int is_on_board120(int sq120)
{
    return (sq120 > 20) && (sq120 < 100) && ((sq120 % 10) >= 1) && ((sq120 % 10) <= 8);
}

int is_on_board64(int sq64)
{
    return (sq64 >= 0) && (sq64 <= 63);
}

int square_64_to_120(int sq64)
{
    int file = sq64 % 8 + 1;
    int rank = sq64 / 8 + 2;

    int sq120 = rank * 10 + file;
    return sq120;
}

int square_120_to_64(int sq120)
{
    int file = sq120 % 10 - 1;
    int rank = sq120 / 10 - 2;

    int sq64 = rank * 8 + file;
    return sq64;
}