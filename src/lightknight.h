/* Copyright (C) 2023 Lazar Ionut-Radu */
/* lightknight, a simple chess engine */

#ifndef _LIGHTKNIGHT_H_
#define _LIGHTKNIGHT_H_

#include "types.h"

/* Writes the board at standard output. */
void write_board(position_t *pos);

/* Writes information about the position at standard output. */
/* This includes: The board, castling rights, the possibility of en passant, the turn. */
void write_pos_info(position_t *pos);

#endif /* _LIGHTKNIGHT_H_ */