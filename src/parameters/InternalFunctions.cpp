/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Matt Olan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <parameters/InternalFunctions.h>

uint64_t InternalFunctions::getPossibleTotalSymbols(uint64_t F, uint16_t T) {

	return extra_math::ceil_div(F, T);
}

uint64_t InternalFunctions::getTotalSymbols(uint64_t F, uint16_t T) {

	return (uint64_t)extra_math::ceil_div(F, T); // downcast never overflows since F and T are bounded
}

uint16_t InternalFunctions::topInterleaverLength(uint16_t T) {

	uint16_t SStimesAl = T;

	return T / SStimesAl;
}

uint16_t InternalFunctions::KL(uint64_t WS, uint16_t T, uint8_t Al, uint16_t n) {

	uint16_t K_upper_bound = (uint16_t)std::min((uint16_t)InternalConstants::K_max, (uint16_t) (WS / subSymbolSize(T, Al, n)));
	return systematic_indices::floor(K_upper_bound);
}

uint64_t InternalFunctions::minWS(uint16_t Kprime, uint16_t T, uint8_t Al, uint16_t n) {

	return (uint64_t)systematic_indices::ceil(Kprime) * subSymbolSize(T, Al, n);
}

uint16_t InternalFunctions::subSymbolSize(uint16_t T, uint8_t Al, uint16_t n) {

	return Al * extra_math::ceil_div(T, Al * n);
}
