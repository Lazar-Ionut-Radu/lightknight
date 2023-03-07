/* Copyright (C) 2023 Lazar Ionut-Radu */
/* lightknight, a simple chess engine */

#ifndef _TYPES_H_
#define _TYPES_H_

#define FALSE 0
#define TRUE 1

typedef enum {
    NOPIECE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
} piece_type_t;

typedef enum {
    BLACK, WHITE
} color_t;

typedef struct {
    piece_type_t piece_type;
    color_t color;
} piece_t;

typedef struct {
    piece_t board[120]; /* Explained in board.h */
    color_t turn;
    int castleK, castleQ; /* Castling rights for white. */
    int castlek, castleq; /* Castling rights for black. */
    int en_passant_file; /* A = 2, B = 3, ..., H = 9, not possible = 0 */
    int num_pieces[2][7]; /* [COLOR][PIECE TYPE] */
} position_t;

typedef struct {
    int fromSquare; /* Origin square. */
    int toSquare; /* Destination square. */
    piece_t capturedPiece;
    int is_promotion;
} move_t;

typedef struct {
    position_t pos; /* Current position. */
    move_t *move_list; /* The list of moves in this game. */
} game_t;

#endif /* _TYPES_H_ */