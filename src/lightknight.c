/* Copyright (C) 2023 Lazar Ionut-Radu */
/* lightknight, a simple chess engine */

#include <stdio.h> 
#include "lightknight.h"
#include "board.h"

void write_board(position_t *pos)
{
    for (int rank = 7; rank >= 0; --rank) {
        for (int file = 0; file <= 7; ++file)
        {   
            int sq64 = rank * 8 + file;
            int color = (*pos).board[square_64_to_120(sq64)].color;

            switch (pos->board[square_64_to_120(sq64)].piece_type)
            {
                case NOPIECE:
                    printf(". ");
                    break;
                
                case PAWN:
                    if (color == WHITE)
                        printf("P ");
                    else
                        printf("p ");
                    break;

                case KNIGHT:
                    if (color == WHITE)
                        printf("N ");
                    else
                        printf("n ");
                    break;

                case BISHOP:
                    if (color == WHITE)
                        printf("B ");
                    else
                        printf("b ");
                    break;

                case ROOK:
                    if (color == WHITE)
                        printf("R ");
                    else
                        printf("r ");
                    break;

                case QUEEN:
                    if (color == WHITE)
                        printf("Q ");
                    else
                        printf("q ");
                    break;
                
                case KING:
                    if (color == WHITE)
                        printf("K ");
                    else
                        printf("k ");
                    break;
            }
        }
        printf("\n");
    }
}

void write_pos_info(position_t *pos)
{
    write_board(pos);
    
    printf("Castling rights: ");
    if (pos->castleK == TRUE)
        printf("K");
    else
        printf("-");
    if (pos->castleQ == TRUE)
        printf("Q");
    else
        printf("-");
    if (pos->castlek == TRUE)
        printf("k");
    else
        printf("-");
    if (pos->castleq == TRUE)
        printf("q");
    else
        printf("-");
    
    printf("\nEn passant: ");
    int file = (*pos).en_passant_file;
    if (file >= 2 && file <= 9)
        printf("%c", file + 'A' - 2);
    else
        printf("-");

    printf("\nTurn: ");
    if ((*pos).turn == WHITE)
        printf("white");
    else
        printf("black");

    printf("\n");
}