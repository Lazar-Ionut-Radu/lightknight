/* Copyright (C) 2023 Lazar Ionut-Radu */
/* lightknight, a simple chess engine */

#include "board.h"
#include "types.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

piece_t char_to_piece(char piece_char) {
    piece_t piece;

    switch (piece_char) {
        case 'P':
            piece.piece_type = PAWN;
            piece.color = WHITE;
            break;
        case 'p':
            piece.piece_type = PAWN;
            piece.color = BLACK;
            break;
        case 'B':
            piece.piece_type = BISHOP;
            piece.color = WHITE;
            break;
        case 'b':
            piece.piece_type = BISHOP;
            piece.color = BLACK;
            break;
        case 'N':
            piece.piece_type = KNIGHT;
            piece.color = WHITE;
            break;
        case 'n':
            piece.piece_type = KNIGHT;
            piece.color = BLACK;
            break;
        case 'R':
            piece.piece_type = ROOK;
            piece.color = WHITE;
            break;
        case 'r':
            piece.piece_type = ROOK;
            piece.color = BLACK;
            break;
        case 'Q':
            piece.piece_type = QUEEN;
            piece.color = WHITE;
            break;
        case 'q':
            piece.piece_type = QUEEN;
            piece.color = BLACK;
            break;
        case 'K':
            piece.piece_type = KING;
            piece.color = WHITE;
            break;
        case 'k':
            piece.piece_type = KING;
            piece.color = BLACK;
            break;
        default:
            piece.piece_type = NOPIECE;
            piece.color = 0;
    }

    return piece;
}

int fen_to_pos(position_t* pos, char *fen)
{
    int index = 0;
    int sq64 = 56;

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 7; ++j)
            pos->num_pieces[i][j] = 0;
    
    while (index < strlen(fen)) {

        /* White-spaces are just for separation. */
        if (fen[index] == ' ') {
            sq64 = -1;
            index++;
            continue;
        }

        /* Jump on the write square at the / character. */
        if (fen[index] == '/') {
            sq64 -= 16;
            index++;
            continue;
        }
    
        /* Place pieces on board. */
        if (is_on_board64(sq64) == TRUE) {
            /* For empty squares. */
            if (fen[index] >= '1' && fen[index] <= '8') {
                for (char i = '0'; i < fen[index]; ++i) {
                    pos->board[square_64_to_120(sq64)].piece_type = NOPIECE;
                    sq64++;
                }

                index++;
                continue;
            } 
            else { /* For pieces. */
            
                piece_t piece = char_to_piece(fen[index]);
                pos->board[square_64_to_120(sq64)].color = piece.color;
                pos->board[square_64_to_120(sq64)].piece_type = piece.piece_type;
                
                //pos->num_pieces[piece.color][piece.piece_type]++;

                sq64++;
                index++;
                continue;
            }
        }

        /* Set the turn. */
        if (fen[index] == 'b' || fen[index] == 'w') {
            if (fen[index] == 'w')
                pos->turn = WHITE;
            else
                pos->turn = BLACK;

            index++;
            continue;
        }

        /* Set the castling rights. */
        if (fen[index] == 'K') {
            pos->castleK = TRUE;
            index++;
            continue;
        }

        if (fen[index] == 'k') {
            pos->castlek = TRUE;
            index++;
            continue;
        }

        if (fen[index] == 'Q') {
            pos->castleQ = TRUE;
            index++;
            continue;
        }

        if (fen[index] == 'q') {
            pos->castleq = TRUE;
            index++;
            continue;
        }

        /* TODO en-passant square & half/full move clocks */
        break;
    }

    return TRUE;
}

int init_pos(position_t* pos)
{
    return fen_to_pos(pos, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}
