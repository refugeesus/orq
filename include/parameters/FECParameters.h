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

#ifndef FECPARAMETERS_H
#define FECPARAMETERS_H

#include <parameters/InternalConstants.h>
#include <parameters/InternalFunctions.h>
#include <parameters/ParameterChecker.h>
#include <parameters/ParameterIO.h>
#include <util/OctetOps.h>

class FECParameters {
	
	public:
	static FECParameters newParameters(uint64_t dataLen, uint16_t symbSize, uint8_t numSrcBs);
	static FECParameters newParameters(uint64_t dataLen, uint16_t symbSize, uint8_t numSrcBs, uint16_t interLen);
	static FECParameters deriveParameters(uint64_t dataLen, uint16_t payLen, uint64_t maxDBMem);
	static FECParameters newLocalInstance(uint64_t F, uint16_t T, uint8_t Z, uint16_t N, uint8_t Al);
	uint64_t dataLength();
	uint16_t symbolSize();
	uint8_t numberOfSourceBlocks();
	uint16_t interleaverLength();
	uint8_t symbolAlignment();
	uint16_t totalSymbols();

	private:
	static uint8_t deriveZ(uint16_t Kt, uint64_t WS, uint16_t T, uint8_t Al, uint16_t topN);
	static int deriveN(uint16_t Kt, uint8_t Z, uint64_t WS, uint16_t T, uint8_t Al, uint16_t topN);
	FECParameters(uint64_t common_fec_oti, uint32_t scheme_spec_fec_oti);
	uint64_t commonFecOTI;
	uint32_t schemeSpecFecOTI;
};

#endif