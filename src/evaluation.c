/* Copyright (C) 2023 Lazar Ionut-Radu */
/* lightknight, a simple chess engine */

#include "evaluation.h"
#include "types.h"

int get_phase(int np, int nn, int nb, int nr, int nq)
{
    int totalPhase = piece_phase[PAWN] * 16 +
                     piece_phase[KNIGHT] * 4 +
                     piece_phase[BISHOP] * 4 +
                     piece_phase[ROOK] * 4 +
                     piece_phase[QUEEN] * 2;

    int phase = totalPhase;
    phase -= np * piece_phase[PAWN];
    phase -= nn * piece_phase[KNIGHT];
    phase -= nb * piece_phase[BISHOP];
    phase -= nr * piece_phase[ROOK];
    phase -= nq * piece_phase[QUEEN];

    phase = (phase * 256 + (totalPhase / 2)) / totalPhase;

    return phase;
}

int interpolate(int phase, int mg_eval, int eg_eval)
{
    return ((mg_eval * (256 - phase)) + (eg_eval * phase)) / 256;
}