/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 * Hayo Baan
 *
 * All rights reserved. A copyright license for redistribution and use in
 * source and binary forms, with or without modification, is hereby granted for
 * non-commercial, experimental, research, public review and evaluation
 * purposes, provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * Implementation of the random A matrix creation function.
 */

#include "a_random.h"

#include "misc.h"
#include "little_endian.h"
#include "drbg.h"

#include <stdio.h>

int create_A_random(uint16_t *A_random, const unsigned char *seed, const parameters *params) {
    uint32_t num_elements;

    switch (params->tau) {
        case 0:
        case 1:
            num_elements = (uint32_t) (params->d * params->k);
            break;
        case 2:
            num_elements = params->q;
            break;
        default:
            fprintf(stderr, "Error: Wrong tau value for generating A: %hhu.\n", params->tau);
            exit(EXIT_FAILURE);
    }
    drbg_sampler16_2_once(A_random, num_elements, seed, params->kappa_bytes, params->q);

    return 0;
}
