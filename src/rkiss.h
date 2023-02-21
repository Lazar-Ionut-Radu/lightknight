/* Copyright (C) 2023 Lazar Ionut-Radu */
/* lightknight, a simple chess engine */

#ifndef _RKISS_H_
#define _RKISS_H_

#include <stdint.h>

/* RKISS is a pseudo random number generator (PRNG) used to compute hash keys. */
/* It was invented by George Marsaglia in the early 90's. */

uint64_t rkiss1, rkiss2, rkiss3, rkiss4;

/* Shift left opperation */
uint64_t rotate(uint64_t x, uint64_t k) {
    return (x << k) | (x >> (64 - k));
}

/* PRNG */
uint64_t rand64() {
    uint64_t rkiss5 = rkiss1 - rotate(rkiss2, 7);
    rkiss1 = rkiss2 ^ rotate(rkiss3, 13);
    rkiss2 = rkiss3 ^ rotate(rkiss4, 37);
    rkiss3 = rkiss4 + rkiss5;
    rkiss4 = rkiss5 + rkiss1;
    return rkiss4;
}

/* Initialization of the PRNG */
uint64_t sranf64(int seed) {
    rkiss1 = 0xf1ea5eed;
    rkiss2 = rkiss3 = rkiss4 = 0xd4e12c77;

    /* Shuffle a few rounds. */
    for (int i = 0; i < seed; ++i)
        rand64();
}

#endif /* _RKISS_H_ */