/* Automatically generated from Squeak on 28 September 2010 2:21:48 pm 
   by VMMaker 3.11.12
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "sqMemoryAccess.h"



/*** Proxy Functions ***/
#define stackValue(i) (interpreterProxy->stackValue(i))
#define stackIntegerValue(i) (interpreterProxy->stackIntegerValue(i))
#define successFlag (!interpreterProxy->failed())
#define success(bool) (interpreterProxy->success(bool))
#define arrayValueOf(oop) (interpreterProxy->arrayValueOf(oop))
#define checkedIntegerValueOf(oop) (interpreterProxy->checkedIntegerValueOf(oop))
#define fetchArrayofObject(idx,oop) (interpreterProxy->fetchArrayofObject(idx,oop))
#define fetchFloatofObject(idx,oop) (interpreterProxy->fetchFloatofObject(idx,oop))
#define fetchIntegerofObject(idx,oop) (interpreterProxy->fetchIntegerofObject(idx,oop))
#define floatValueOf(oop) (interpreterProxy->floatValueOf(oop))
#define pop(n) (interpreterProxy->pop(n))
#define pushInteger(n) (interpreterProxy->pushInteger(n))
#define sizeOfSTArrayFromCPrimitive(cPtr) (interpreterProxy->sizeOfSTArrayFromCPrimitive(cPtr))
#define storeIntegerofObjectwithValue(idx,oop,value) (interpreterProxy->storeIntegerofObjectwithValue(idx,oop,value))
#define primitiveFail() interpreterProxy->primitiveFail()
/* allows accessing Strings in both C and Smalltalk */
#define asciiValue(c) c


/*** Constants ***/
#define IncrementFractionBits 16
#define LoopIndexFractionMask 511
#define LoopIndexScaleFactor 512
#define ScaleFactor 32768
#define ScaledIndexOverflow 536870912

/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SoundGenerationPlugin 28 September 2010 (i)"
#else
	"SoundGenerationPlugin 28 September 2010 (e)"
#endif
;

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveApplyReverb(void);
EXPORT(sqInt) primitiveMixFMSound(void);
EXPORT(sqInt) primitiveMixLoopedSampledSound(void);
EXPORT(sqInt) primitiveMixPluckedSound(void);
EXPORT(sqInt) primitiveMixSampledSound(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off


/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine * getInterpreter(void) {
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static sqInt halt(void) {
	;
}

static sqInt msg(char * s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveApplyReverb(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t3;
    sqInt t6;
    sqInt t11;
    sqInt t4;
    sqInt t9;
    sqInt t7;
    sqInt t5;
    sqInt t10;
    sqInt t8;
    int *tapDelays;
    int *tapGains;
    sqInt tapCount;
    sqInt bufferSize;
    sqInt bufferIndex;
    short int *leftBuffer;
    short int *rightBuffer;

	rcvr = stackValue(3);
	t1 = stackIntegerValue(2);
	t2 = stackIntegerValue(1);
	t3 = stackIntegerValue(0);
	tapDelays = fetchArrayofObject(7, rcvr);
	tapDelays -= 1;
	tapGains = fetchArrayofObject(8, rcvr);
	tapGains -= 1;
	tapCount = fetchIntegerofObject(9, rcvr);
	bufferSize = fetchIntegerofObject(10, rcvr);
	bufferIndex = fetchIntegerofObject(11, rcvr);
	leftBuffer = fetchArrayofObject(12, rcvr);
	leftBuffer -= 1;
	rightBuffer = fetchArrayofObject(13, rcvr);
	rightBuffer -= 1;
	if (!(successFlag)) {
		return null;
	}
	for (t10 = t2; t10 <= ((t2 + t3) - 1); t10 += 1) {
		t4 = t5 = 0;
		for (t11 = 1; t11 <= tapCount; t11 += 1) {
			t6 = bufferIndex - (tapDelays[t11]);
			if (t6 < 1) {
				t6 += bufferSize;
			}
			t7 = tapGains[t11];
			t4 += t7 * (leftBuffer[t6]);
			t5 += t7 * (rightBuffer[t6]);
		}
		t8 = (2 * t10) - 1;
		t9 = (t1[t8]) + (((sqInt) t4 >> 15));
		if (t9 > 32767) {
			t9 = 32767;
		}
		if (t9 < -32767) {
			t9 = -32767;
		}
		t1[t8] = t9;
		leftBuffer[bufferIndex] = t9;
		t8 += 1;
		t9 = (t1[t8]) + (((sqInt) t5 >> 15));
		if (t9 > 32767) {
			t9 = 32767;
		}
		if (t9 < -32767) {
			t9 = -32767;
		}
		t1[t8] = t9;
		rightBuffer[bufferIndex] = t9;
		bufferIndex = (bufferIndex % bufferSize) + 1;
	}
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(11, rcvr, bufferIndex);
	pop(3);
}

EXPORT(sqInt) primitiveMixFMSound(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t3;
    sqInt t4;
    sqInt t5;
    sqInt t6;
    sqInt t11;
    sqInt t9;
    sqInt t12;
    sqInt t10;
    sqInt t8;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt count;
    short int *waveTable;
    sqInt scaledWaveTableSize;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;
    sqInt normalizedModulation;
    sqInt scaledOffsetIndex;
    sqInt scaledOffsetIndexIncr;

	rcvr = stackValue(5);
	t1 = stackIntegerValue(4);
	t2 = stackIntegerValue(3);
	t3 = stackIntegerValue(2);
	t4 = stackIntegerValue(1);
	t5 = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	waveTable = fetchArrayofObject(8, rcvr);
	waveTable -= 1;
	scaledWaveTableSize = fetchIntegerofObject(9, rcvr);
	scaledIndex = fetchIntegerofObject(10, rcvr);
	scaledIndexIncr = fetchIntegerofObject(11, rcvr);
	normalizedModulation = fetchIntegerofObject(14, rcvr);
	scaledOffsetIndex = fetchIntegerofObject(15, rcvr);
	scaledOffsetIndexIncr = fetchIntegerofObject(16, rcvr);
	if (!(successFlag)) {
		return null;
	}
	t6 = (normalizedModulation != 0) && (scaledOffsetIndexIncr != 0);
	for (t12 = t3; t12 <= ((t3 + t1) - 1); t12 += 1) {
		t8 = ((sqInt) (scaledVol * (waveTable[(((sqInt) scaledIndex >> 15)) + 1])) >> 15);
		if (t6) {
			t9 = normalizedModulation * (waveTable[(((sqInt) scaledOffsetIndex >> 15)) + 1]);
			scaledOffsetIndex = (scaledOffsetIndex + scaledOffsetIndexIncr) % scaledWaveTableSize;
			if (scaledOffsetIndex < 0) {
				scaledOffsetIndex += scaledWaveTableSize;
			}
			scaledIndex = ((scaledIndex + scaledIndexIncr) + t9) % scaledWaveTableSize;
			if (scaledIndex < 0) {
				scaledIndex += scaledWaveTableSize;
			}
		} else {
			scaledIndex = (scaledIndex + scaledIndexIncr) % scaledWaveTableSize;
		}
		if (t4 > 0) {
			t10 = (2 * t12) - 1;
			t11 = (t2[t10]) + (((sqInt) (t8 * t4) >> 15));
			if (t11 > 32767) {
				t11 = 32767;
			}
			if (t11 < -32767) {
				t11 = -32767;
			}
			t2[t10] = t11;
		}
		if (t5 > 0) {
			t10 = 2 * t12;
			t11 = (t2[t10]) + (((sqInt) (t8 * t5) >> 15));
			if (t11 > 32767) {
				t11 = 32767;
			}
			if (t11 < -32767) {
				t11 = -32767;
			}
			t2[t10] = t11;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0) && (scaledVol >= scaledVolLimit)) || ((scaledVolIncr < 0) && (scaledVol <= scaledVolLimit))) {
				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
	}
	count -= t1;
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(10, rcvr, scaledIndex);
	storeIntegerofObjectwithValue(15, rcvr, scaledOffsetIndex);
	pop(5);
}

EXPORT(sqInt) primitiveMixLoopedSampledSound(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t3;
    sqInt t4;
    sqInt t5;
    sqInt t13;
    sqInt t11;
    sqInt t16;
    sqInt t9;
    sqInt t14;
    sqInt t7;
    sqInt t12;
    sqInt t17;
    sqInt t10;
    sqInt t15;
    sqInt t8;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt count;
    sqInt releaseCount;
    short int *leftSamples;
    short int *rightSamples;
    sqInt lastSample;
    sqInt loopEnd;
    sqInt scaledLoopLength;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;

	rcvr = stackValue(5);
	t1 = stackIntegerValue(4);
	t2 = stackIntegerValue(3);
	t3 = stackIntegerValue(2);
	t4 = stackIntegerValue(1);
	t5 = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	releaseCount = fetchIntegerofObject(8, rcvr);
	leftSamples = fetchArrayofObject(10, rcvr);
	leftSamples -= 1;
	rightSamples = fetchArrayofObject(11, rcvr);
	rightSamples -= 1;
	lastSample = fetchIntegerofObject(16, rcvr);
	loopEnd = fetchIntegerofObject(17, rcvr);
	scaledLoopLength = fetchIntegerofObject(18, rcvr);
	scaledIndex = fetchIntegerofObject(19, rcvr);
	scaledIndexIncr = fetchIntegerofObject(20, rcvr);
	if (!(successFlag)) {
		return null;
	}
	t14 = leftSamples != rightSamples;
	t10 = ((sqInt) (t4 * scaledVol) >> 15);
	t11 = ((sqInt) (t5 * scaledVol) >> 15);
	t8 = (2 * t3) - 1;
	for (t17 = t3; t17 <= ((t3 + t1) - 1); t17 += 1) {
		t7 = ((sqInt) (scaledIndex += scaledIndexIncr) >> 9);
		if ((t7 > loopEnd) && (count > releaseCount)) {
			t7 = ((sqInt) (scaledIndex -= scaledLoopLength) >> 9);
		}
		if ((t12 = t7 + 1) > lastSample) {
			if (t7 > lastSample) {
				count = 0;
				if (!(successFlag)) {
					return null;
				}
				storeIntegerofObjectwithValue(3, rcvr, scaledVol);
				storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
				storeIntegerofObjectwithValue(7, rcvr, count);
				storeIntegerofObjectwithValue(19, rcvr, scaledIndex);
				pop(6);
				pushInteger(null);
				return null;
			}
			if (scaledLoopLength == 0) {
				t12 = t7;
			} else {
				t12 = (((sqInt) (scaledIndex - scaledLoopLength) >> 9)) + 1;
			}
		}
		t13 = scaledIndex & LoopIndexFractionMask;
		t15 = t16 = ((sqInt) (((leftSamples[t7]) * (LoopIndexScaleFactor - t13)) + ((leftSamples[t12]) * t13)) >> 9);
		if (t14) {
			t15 = ((sqInt) (((rightSamples[t7]) * (LoopIndexScaleFactor - t13)) + ((rightSamples[t12]) * t13)) >> 9);
		}
		if (t4 > 0) {
			t9 = (t2[t8]) + (((sqInt) (t10 * t16) >> 15));
			if (t9 > 32767) {
				t9 = 32767;
			}
			if (t9 < -32767) {
				t9 = -32767;
			}
			t2[t8] = t9;
		}
		t8 += 1;
		if (t5 > 0) {
			t9 = (t2[t8]) + (((sqInt) (t11 * t15) >> 15));
			if (t9 > 32767) {
				t9 = 32767;
			}
			if (t9 < -32767) {
				t9 = -32767;
			}
			t2[t8] = t9;
		}
		t8 += 1;
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0) && (scaledVol >= scaledVolLimit)) || ((scaledVolIncr < 0) && (scaledVol <= scaledVolLimit))) {
				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
			t10 = ((sqInt) (t4 * scaledVol) >> 15);
			t11 = ((sqInt) (t5 * scaledVol) >> 15);
		}
	}
	count -= t1;
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(19, rcvr, scaledIndex);
	pop(5);
}

EXPORT(sqInt) primitiveMixPluckedSound(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t3;
    sqInt t4;
    sqInt t5;
    sqInt t13;
    sqInt t6;
    sqInt t11;
    sqInt t9;
    sqInt t7;
    sqInt t12;
    sqInt t10;
    sqInt t8;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt count;
    short int *ring;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;
    sqInt scaledIndexLimit;

	rcvr = stackValue(5);
	t1 = stackIntegerValue(4);
	t2 = stackIntegerValue(3);
	t3 = stackIntegerValue(2);
	t4 = stackIntegerValue(1);
	t5 = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	ring = fetchArrayofObject(8, rcvr);
	ring -= 1;
	scaledIndex = fetchIntegerofObject(9, rcvr);
	scaledIndexIncr = fetchIntegerofObject(10, rcvr);
	scaledIndexLimit = fetchIntegerofObject(11, rcvr);
	if (!(successFlag)) {
		return null;
	}
	t6 = (t3 + t1) - 1;
	t7 = t8 = scaledIndex;
	for (t13 = t3; t13 <= t6; t13 += 1) {
		t8 = t7 + scaledIndexIncr;
		if (t8 >= scaledIndexLimit) {
			t8 = ScaleFactor + (t8 - scaledIndexLimit);
		}
		t9 = ((sqInt) ((ring[((sqInt) t7 >> 15)]) + (ring[((sqInt) t8 >> 15)])) >> 1);
		ring[((sqInt) t7 >> 15)] = t9;
		t10 = ((sqInt) (t9 * scaledVol) >> 15);
		t7 = t8;
		if (t4 > 0) {
			t11 = (2 * t13) - 1;
			t12 = (t2[t11]) + (((sqInt) (t10 * t4) >> 15));
			if (t12 > 32767) {
				t12 = 32767;
			}
			if (t12 < -32767) {
				t12 = -32767;
			}
			t2[t11] = t12;
		}
		if (t5 > 0) {
			t11 = 2 * t13;
			t12 = (t2[t11]) + (((sqInt) (t10 * t5) >> 15));
			if (t12 > 32767) {
				t12 = 32767;
			}
			if (t12 < -32767) {
				t12 = -32767;
			}
			t2[t11] = t12;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0) && (scaledVol >= scaledVolLimit)) || ((scaledVolIncr < 0) && (scaledVol <= scaledVolLimit))) {
				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
	}
	scaledIndex = t8;
	count -= t1;
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(9, rcvr, scaledIndex);
	pop(5);
}

EXPORT(sqInt) primitiveMixSampledSound(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t3;
    sqInt t4;
    sqInt t5;
    sqInt t6;
    sqInt t11;
    sqInt t9;
    sqInt t7;
    sqInt t12;
    sqInt t10;
    sqInt t8;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt count;
    short int *samples;
    sqInt samplesSize;
    sqInt scaledIndex;
    sqInt indexHighBits;
    sqInt scaledIncrement;

	rcvr = stackValue(5);
	t1 = stackIntegerValue(4);
	t2 = stackIntegerValue(3);
	t3 = stackIntegerValue(2);
	t4 = stackIntegerValue(1);
	t5 = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	samples = fetchArrayofObject(8, rcvr);
	samples -= 1;
	samplesSize = fetchIntegerofObject(10, rcvr);
	scaledIndex = fetchIntegerofObject(11, rcvr);
	indexHighBits = fetchIntegerofObject(12, rcvr);
	scaledIncrement = fetchIntegerofObject(13, rcvr);
	if (!(successFlag)) {
		return null;
	}
	t6 = (t3 + t1) - 1;
	t7 = t3;
	t8 = indexHighBits + (((usqInt) scaledIndex) >> IncrementFractionBits);
	while ((t8 <= samplesSize) && (t7 <= t6)) {
		t9 = ((sqInt) ((samples[t8]) * scaledVol) >> 15);
		if (t4 > 0) {
			t10 = (2 * t7) - 1;
			t11 = (t2[t10]) + (((sqInt) (t9 * t4) >> 15));
			if (t11 > 32767) {
				t11 = 32767;
			}
			if (t11 < -32767) {
				t11 = -32767;
			}
			t2[t10] = t11;
		}
		if (t5 > 0) {
			t10 = 2 * t7;
			t11 = (t2[t10]) + (((sqInt) (t9 * t5) >> 15));
			if (t11 > 32767) {
				t11 = 32767;
			}
			if (t11 < -32767) {
				t11 = -32767;
			}
			t2[t10] = t11;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0) && (scaledVol >= scaledVolLimit)) || ((scaledVolIncr < 0) && (scaledVol <= scaledVolLimit))) {
				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
		scaledIndex += scaledIncrement;
		if (scaledIndex >= ScaledIndexOverflow) {
			t12 = ((usqInt) scaledIndex) >> IncrementFractionBits;
			indexHighBits += t12;
			scaledIndex -= t12 << IncrementFractionBits;
		}
		t8 = indexHighBits + (((usqInt) scaledIndex) >> IncrementFractionBits);
		t7 += 1;
	}
	count -= t1;
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(11, rcvr, scaledIndex);
	storeIntegerofObjectwithValue(12, rcvr, indexHighBits);
	pop(5);
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter) {
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* SoundGenerationPlugin_exports[][3] = {
	{"SoundGenerationPlugin", "primitiveMixPluckedSound", (void*)primitiveMixPluckedSound},
	{"SoundGenerationPlugin", "getModuleName", (void*)getModuleName},
	{"SoundGenerationPlugin", "primitiveMixFMSound", (void*)primitiveMixFMSound},
	{"SoundGenerationPlugin", "primitiveApplyReverb", (void*)primitiveApplyReverb},
	{"SoundGenerationPlugin", "primitiveMixSampledSound", (void*)primitiveMixSampledSound},
	{"SoundGenerationPlugin", "setInterpreter", (void*)setInterpreter},
	{"SoundGenerationPlugin", "primitiveMixLoopedSampledSound", (void*)primitiveMixLoopedSampledSound},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

