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
 * Declaration of the fixed A matrix as well as the function to generate it.
 */

#ifndef A_FIXED_H
#define A_FIXED_H

#include "parameters.h"
#include <stddef.h>

/**
 * The fixed A matrix for use inside with the non-ring algorithm when τ=1.
 * This matrix is generated by `create_A_fixed()`.
 */
extern uint16_t *A_fixed;

/**
 * The size (number of elements) of the fixed A matrix, set with `create_A_fixed()`.
 */
extern size_t A_fixed_len;

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Function to generate a fixed A matrix from the given seed.
     *
     * @param[in] seed   the seed to use to generate the fixed A matrix (kappa_bytes bytes)
     * @param[in] params the algorithm parameters for which the fixed A matrix should be generated
     * @return __0__ in case of success
     */
    int create_A_fixed(const unsigned char *seed, const parameters *params);

#ifdef __cplusplus
}
#endif

#endif /* A_FIXED_H */