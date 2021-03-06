/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 * Hayo Baan, Jose Luis Torre Arce
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
 * Declaration of the CCA KEM functions.
 */
#ifndef R5_CCA_KEM_H
#define R5_CCA_KEM_H

#include "parameters.h"

#ifdef __cplusplus
extern "C" {
#endif

    /*******************************************************************************
     * Public functions
     ******************************************************************************/

    /**
     * Generates a CCA KEM key pair. Uses the parameters as specified.
     *
     * @param[out] pk     public key
     * @param[out] sk     secret key
     * @param[in]  params the algorithm parameters to use
     * @return __0__ in case of success
     */
    int r5_cca_kem_keygen_p(unsigned char *pk, unsigned char *sk, const parameters *params);

    /**
     * CCA KEM encapsulate. Uses the parameters as specified.
     *
     * @param[out] ct     key encapsulation message (<b>important:</b> the size of `ct` is `ct_size` + `kappa_bytes`!)
     * @param[out] k      shared secret
     * @param[in]  pk     public key with which the message is encapsulated
     * @param[in]  params the algorithm parameters to use
     * @return __0__ in case of success
     */
    int r5_cca_kem_encapsulate_p(unsigned char *ct, unsigned char *k, const unsigned char *pk, const parameters *params);

    /**
     * CCA KEM de-capsulate. Uses the parameters as specified.
     *
     * @param[out] k      shared secret
     * @param[in]  ct     key encapsulation message (<b>important:</b> the size of `ct` is `ct_size` + `kappa_bytes`!)
     * @param[in]  sk     secret key with which the message is to be de-capsulated (<b>important:</b> the size of `sk` is `sk_size` + `kappa_bytes` + `pk_size`!)
     * @param[in]  params the algorithm parameters to use
     * @return __0__ in case of success
     */
    int r5_cca_kem_decapsulate_p(unsigned char *k, const unsigned char *ct, const unsigned char *sk, const parameters *params);

#ifdef __cplusplus
}
#endif

#endif /* R5_CCA_KEM_H */
