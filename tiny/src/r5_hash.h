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
 * Definition of the hash function as used within Round5.
 */

#ifndef R5_HASH_H
#define R5_HASH_H

#include "shake.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * The hash function as used within Round5.
     *
     * @param[out] output      buffer for the output of the hash
     * @param[in]  output_len  the number of hash bytes to produce
     * @param[in]  input       the input to produce the hash for
     * @param[in]  input_len   the number of input bytes
     * @param[in]  kappa_bytes the number of bytes of kappa (used to determine
     *                         the implementation of the hash function)
     */
    inline void hash(uint8_t *output, const size_t output_len, const uint8_t *input, const size_t input_len, const uint8_t kappa_bytes) {
        /* Since without customization, SHAKE == CSHAKE, we can use SHAKE here directly. */
        if (kappa_bytes > 16) {
            shake256(output, output_len, input, input_len);
        } else {
            shake128(output, output_len, input, input_len);
        }
    }

    /**
     * The hash function as used within Round5.
     *
     * @param[out] output            buffer for the output of the hash
     * @param[in]  output_len        the number of hash bytes to produce
     * @param[in]  input             the input to produce the hash for
     * @param[in]  input_len         the number of input bytes
     * @param[in]  customization     the customization string to use
     * @param[in]  customization_len the length of the customization string
     * @param kappa_bytes            the number of bytes of kappa (used to
     *                               determine the the implementation of the
     *                               hash function)
     */
    inline void hash_customization(uint8_t *output, const size_t output_len, const uint8_t *input, const size_t input_len, const uint8_t *customization, const size_t customization_len, const uint8_t kappa_bytes) {
        if (kappa_bytes > 16) {
            cshake256(output, output_len, input, input_len, customization, customization_len);
        } else {
            cshake128(output, output_len, input, input_len, customization, customization_len);
        }
    }
#ifdef __cplusplus
}
#endif

#endif /* R5_HASH_H */
