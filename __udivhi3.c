// Copyright 2019 Ryotaro Banno, Kotaro Matsuoka, Naoki Matsumoto
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * ==========================================================================
 *    This file is copied and modified from compiler-rt project of the LLVM
 * Compiler Infrastructure. The license of the original code is here:
 * ==========================================================================
 *
 * Copyright (c) 2009-2015 by the contributors listed in CREDITS.TXT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "libc.h"

/* Returns: a / b */
/* This function should not call __divhi3! */
unsigned __udivhi3(unsigned n, unsigned d)
{
    /*
     * This is the original implementation in compiler-rt, but it's too big!
     */
    //    const unsigned n_uword_bits = sizeof(unsigned) * 8;
    //    unsigned q;
    //    unsigned r;
    //    unsigned sr;
    //    /* special cases */
    //    if (d == 0) return 0; /* ?! */
    //    if (n == 0) return 0;
    //    sr = __builtin_clz(d) - __builtin_clz(n);
    //    /* 0 <= sr <= n_uword_bits - 1 or sr large */
    //    if (sr > n_uword_bits - 1) /* d > r */
    //        return 0;
    //    if (sr == n_uword_bits - 1) /* d == 1 */
    //        return n;
    //    ++sr;
    //    /* 1 <= sr <= n_uword_bits - 1 */
    //    /* Not a special case */
    //    q = n << (n_uword_bits - sr);
    //    r = n >> sr;
    //    unsigned carry = 0;
    //    for (; sr > 0; --sr) {
    //        /* r:q = ((r:q)  << 1) | carry */
    //        r = (r << 1) | (q >> (n_uword_bits - 1));
    //        q = (q << 1) | carry;
    //        /* carry = 0;
    //         * if (r.all >= d.all)
    //         * {
    //         *      r.all -= d.all;
    //         *      carry = 1;
    //         * }
    //         */
    //        const int s = (int)(d - r - 1) >> (n_uword_bits - 1);
    //        carry = s & 1;
    //        r -= d & s;
    //    }
    //    q = (q << 1) | carry;
    //    return q;

    if (d == 0) return 0;  // ?!
    if (n == 0) return 0;

    unsigned q = 0;
    while (n >= d) {
        n -= d;
        q++;
    }

    return q;
}
