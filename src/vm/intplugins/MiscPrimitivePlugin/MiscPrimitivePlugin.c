/* Automatically generated from Squeak on 28 September 2010 2:21:45 pm 
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

/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"MiscPrimitivePlugin 28 September 2010 (i)"
#else
	"MiscPrimitivePlugin 28 September 2010 (e)"
#endif
;

/*** Function Prototypes ***/
static sqInt encodeBytesOfinat(sqInt t1, sqInt t2, sqInt t3);
static sqInt encodeIntinat(sqInt t1, sqInt t2, sqInt t3);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char * s);
#pragma export on
EXPORT(sqInt) primitiveCompareString(void);
EXPORT(sqInt) primitiveCompressToByteArray(void);
EXPORT(sqInt) primitiveConvert8BitSigned(void);
EXPORT(sqInt) primitiveDecompressFromByteArray(void);
EXPORT(sqInt) primitiveFindFirstInString(void);
EXPORT(sqInt) primitiveFindSubstring(void);
EXPORT(sqInt) primitiveIndexOfAsciiInString(void);
EXPORT(sqInt) primitiveStringHash(void);
EXPORT(sqInt) primitiveTranslateStringWithTable(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine* anInterpreter);
#pragma export off

static sqInt encodeBytesOfinat(sqInt t1, sqInt t2, sqInt t3) {
    sqInt t4;

	for (t4 = 0; t4 <= 3; t4 += 1) {
		t2[t3 + t4] = ((((usqInt) t1) >> ((3 - t4) * 8)) & 255);
	}
	return t3 + 4;
}

static sqInt encodeIntinat(sqInt t1, sqInt t2, sqInt t3) {
    sqInt t4;

	if (t1 <= 223) {
		t2[t3] = t1;
		return t3 + 1;
	}
	if (t1 <= 7935) {
		t2[t3] = ((((sqInt) t1 >> 8)) + 224);
		t2[t3 + 1] = (t1 % 256);
		return t3 + 2;
	}
	t2[t3] = 255;
	/* begin encodeBytesOf:in:at: */
	for (t4 = 0; t4 <= 3; t4 += 1) {
		t2[(t3 + 1) + t4] = ((((usqInt) t1) >> ((3 - t4) * 8)) & 255);
	}
	return (t3 + 1) + 4;
}


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


/*	Return 1, 2 or 3, if string1 is <, =, or > string2, with the collating order of characters given by the order array. */

EXPORT(sqInt) primitiveCompareString(void) {
    sqInt rcvr;
    unsigned char *string1;
    unsigned char *string2;
    unsigned char *order;
    sqInt len2;
    sqInt len1;
    sqInt c2;
    sqInt i;
    sqInt c1;

	rcvr = stackValue(3);
	string1 = arrayValueOf(stackValue(2));
	string1 -= 1;
	string2 = arrayValueOf(stackValue(1));
	string2 -= 1;
	order = arrayValueOf(stackValue(0));
	order -= 1;
	if (!(successFlag)) {
		return null;
	}
	len1 = sizeOfSTArrayFromCPrimitive(string1 + 1);
	len2 = sizeOfSTArrayFromCPrimitive(string2 + 1);
	for (i = 1; i <= (((len1 < len2) ? len1 : len2)); i += 1) {
		c1 = order[(string1[i]) + 1];
		c2 = order[(string2[i]) + 1];
		if (!(c1 == c2)) {
			if (c1 < c2) {
				if (!(successFlag)) {
					return null;
				}
				pop(4);
				pushInteger(1);
				return null;
			} else {
				if (!(successFlag)) {
					return null;
				}
				pop(4);
				pushInteger(3);
				return null;
			}
		}
	}
	if (len1 == len2) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(2);
		return null;
	}
	if (len1 < len2) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(1);
		return null;
	} else {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(3);
		return null;
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
}

EXPORT(sqInt) primitiveCompressToByteArray(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t7;
    sqInt t6;
    sqInt t5;
    sqInt t10;
    sqInt t4;
    sqInt t9;
    sqInt t3;
    sqInt t8;
    sqInt t41;
    sqInt t42;
    sqInt t43;
    sqInt t44;
    sqInt t45;
    sqInt t46;
    sqInt t47;

	rcvr = stackValue(2);
	t1 = stackIntegerValue(1);
	t2 = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	t3 = sizeOfSTArrayFromCPrimitive(t1 + 1);
	/* begin encodeInt:in:at: */
	if (t3 <= 223) {
		t2[1] = t3;
		t9 = 1 + 1;
		goto l5;
	}
	if (t3 <= 7935) {
		t2[1] = ((((sqInt) t3 >> 8)) + 224);
		t2[1 + 1] = (t3 % 256);
		t9 = 1 + 2;
		goto l5;
	}
	t2[1] = 255;
	/* begin encodeBytesOf:in:at: */
	for (t47 = 0; t47 <= 3; t47 += 1) {
		t2[(1 + 1) + t47] = ((((usqInt) t3) >> ((3 - t47) * 8)) & 255);
	}
	t9 = (1 + 1) + 4;
l5:	/* end encodeInt:in:at: */;
	t4 = 1;
	while (t4 <= t3) {
		t5 = t1[t4];
		t7 = t5 & 255;
		t8 = (((((usqInt) t5) >> 8) & 255) == t7) && ((((((usqInt) t5) >> 16) & 255) == t7) && (((((usqInt) t5) >> 24) & 255) == t7));
		t6 = t4;
		while ((t6 < t3) && (t5 == (t1[t6 + 1]))) {
			t6 += 1;
		}
		if (t6 > t4) {
			if (t8) {
				/* begin encodeInt:in:at: */
				if (((((t6 - t4) + 1) * 4) + 1) <= 223) {
					t2[t9] = ((((t6 - t4) + 1) * 4) + 1);
					t9 += 1;
					goto l1;
				}
				if (((((t6 - t4) + 1) * 4) + 1) <= 7935) {
					t2[t9] = ((((sqInt) ((((t6 - t4) + 1) * 4) + 1) >> 8)) + 224);
					t2[t9 + 1] = (((((t6 - t4) + 1) * 4) + 1) % 256);
					t9 += 2;
					goto l1;
				}
				t2[t9] = 255;
				/* begin encodeBytesOf:in:at: */
				for (t43 = 0; t43 <= 3; t43 += 1) {
					t2[(t9 + 1) + t43] = ((((usqInt) ((((t6 - t4) + 1) * 4) + 1)) >> ((3 - t43) * 8)) & 255);
				}
				t9 = (t9 + 1) + 4;
			l1:	/* end encodeInt:in:at: */;
				t2[t9] = t7;
				t9 += 1;
			} else {
				/* begin encodeInt:in:at: */
				if (((((t6 - t4) + 1) * 4) + 2) <= 223) {
					t2[t9] = ((((t6 - t4) + 1) * 4) + 2);
					t9 += 1;
					goto l2;
				}
				if (((((t6 - t4) + 1) * 4) + 2) <= 7935) {
					t2[t9] = ((((sqInt) ((((t6 - t4) + 1) * 4) + 2) >> 8)) + 224);
					t2[t9 + 1] = (((((t6 - t4) + 1) * 4) + 2) % 256);
					t9 += 2;
					goto l2;
				}
				t2[t9] = 255;
				/* begin encodeBytesOf:in:at: */
				for (t44 = 0; t44 <= 3; t44 += 1) {
					t2[(t9 + 1) + t44] = ((((usqInt) ((((t6 - t4) + 1) * 4) + 2)) >> ((3 - t44) * 8)) & 255);
				}
				t9 = (t9 + 1) + 4;
			l2:	/* end encodeInt:in:at: */;
				/* begin encodeBytesOf:in:at: */
				for (t41 = 0; t41 <= 3; t41 += 1) {
					t2[t9 + t41] = ((((usqInt) t5) >> ((3 - t41) * 8)) & 255);
				}
				t9 += 4;
			}
			t4 = t6 + 1;
		} else {
			if (t8) {
				/* begin encodeInt:in:at: */
				if (((1 * 4) + 1) <= 223) {
					t2[t9] = ((1 * 4) + 1);
					t9 += 1;
					goto l3;
				}
				if (((1 * 4) + 1) <= 7935) {
					t2[t9] = ((((sqInt) ((1 * 4) + 1) >> 8)) + 224);
					t2[t9 + 1] = (((1 * 4) + 1) % 256);
					t9 += 2;
					goto l3;
				}
				t2[t9] = 255;
				/* begin encodeBytesOf:in:at: */
				for (t45 = 0; t45 <= 3; t45 += 1) {
					t2[(t9 + 1) + t45] = ((((usqInt) ((1 * 4) + 1)) >> ((3 - t45) * 8)) & 255);
				}
				t9 = (t9 + 1) + 4;
			l3:	/* end encodeInt:in:at: */;
				t2[t9] = t7;
				t9 += 1;
				t4 += 1;
			} else {
				while ((t6 < t3) && ((t1[t6]) != (t1[t6 + 1]))) {
					t6 += 1;
				}
				if (t6 == t3) {
					t6 += 1;
				}
				/* begin encodeInt:in:at: */
				if ((((t6 - t4) * 4) + 3) <= 223) {
					t2[t9] = (((t6 - t4) * 4) + 3);
					t9 += 1;
					goto l4;
				}
				if ((((t6 - t4) * 4) + 3) <= 7935) {
					t2[t9] = ((((sqInt) (((t6 - t4) * 4) + 3) >> 8)) + 224);
					t2[t9 + 1] = ((((t6 - t4) * 4) + 3) % 256);
					t9 += 2;
					goto l4;
				}
				t2[t9] = 255;
				/* begin encodeBytesOf:in:at: */
				for (t46 = 0; t46 <= 3; t46 += 1) {
					t2[(t9 + 1) + t46] = ((((usqInt) (((t6 - t4) * 4) + 3)) >> ((3 - t46) * 8)) & 255);
				}
				t9 = (t9 + 1) + 4;
			l4:	/* end encodeInt:in:at: */;
				for (t10 = t4; t10 <= (t6 - 1); t10 += 1) {
					/* begin encodeBytesOf:in:at: */
					for (t42 = 0; t42 <= 3; t42 += 1) {
						t2[t9 + t42] = ((((usqInt) (t1[t10])) >> ((3 - t42) * 8)) & 255);
					}
					t9 += 4;
				}
				t4 = t6;
			}
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
	pushInteger(t9 - 1);
	return null;
}

EXPORT(sqInt) primitiveConvert8BitSigned(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t5;
    sqInt t4;

	rcvr = stackValue(2);
	t1 = stackIntegerValue(1);
	t2 = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	for (t5 = 1; t5 <= (sizeOfSTArrayFromCPrimitive(t1 + 1)); t5 += 1) {
		t4 = t1[t5];
		if (t4 > 127) {
			t2[t5] = (((usqInt) (t4 - 256) << 8));
		} else {
			t2[t5] = (((usqInt) t4 << 8));
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(2);
}

EXPORT(sqInt) primitiveDecompressFromByteArray(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t3;
    sqInt t13;
    sqInt t7;
    sqInt t12;
    sqInt t6;
    sqInt t11;
    sqInt t5;
    sqInt t10;
    sqInt t4;
    sqInt t9;
    sqInt t8;

	rcvr = stackValue(3);
	t1 = stackIntegerValue(2);
	t2 = stackIntegerValue(1);
	t3 = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	t4 = t3;
	t9 = sizeOfSTArrayFromCPrimitive(t2 + 1);
	t10 = 1;
	t11 = (sizeOfSTArrayFromCPrimitive(t1 + 1)) + 1;
	while (t4 <= t9) {
		t7 = t2[t4];
		t4 += 1;
		if (!(t7 <= 223)) {
			if (t7 <= 254) {
				t7 = ((t7 - 224) * 256) + (t2[t4]);
				t4 += 1;
			} else {
				t7 = 0;
				for (t12 = 1; t12 <= 4; t12 += 1) {
					t7 = (((usqInt) t7 << 8)) + (t2[t4]);
					t4 += 1;
				}
				null;
			}
		}
		t6 = ((usqInt) t7) >> 2;
		if ((t10 + t6) > t11) {
			primitiveFail();
			return null;
		}
		t5 = t7 & 3;
		t5 == 0;
		if (t5 == 1) {
			t8 = t2[t4];
			t4 += 1;
			t8 = t8 | (((usqInt) t8 << 8));
			t8 = t8 | (((usqInt) t8 << 16));
			for (t12 = 1; t12 <= t6; t12 += 1) {
				t1[t10] = t8;
				t10 += 1;
			}
		}
		if (t5 == 2) {
			t8 = 0;
			for (t12 = 1; t12 <= 4; t12 += 1) {
				t8 = (((usqInt) t8 << 8)) | (t2[t4]);
				t4 += 1;
			}
			for (t12 = 1; t12 <= t6; t12 += 1) {
				t1[t10] = t8;
				t10 += 1;
			}
		}
		if (t5 == 3) {
			for (t13 = 1; t13 <= t6; t13 += 1) {
				t8 = 0;
				for (t12 = 1; t12 <= 4; t12 += 1) {
					t8 = (((usqInt) t8 << 8)) | (t2[t4]);
					t4 += 1;
				}
				t1[t10] = t8;
				t10 += 1;
			}
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
}

EXPORT(sqInt) primitiveFindFirstInString(void) {
    sqInt rcvr;
    unsigned char *aString;
    char *inclusionMap;
    sqInt start;
    sqInt i;
    sqInt stringSize;

	rcvr = stackValue(3);
	aString = arrayValueOf(stackValue(2));
	aString -= 1;
	inclusionMap = arrayValueOf(stackValue(1));
	inclusionMap -= 1;
	start = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	if ((sizeOfSTArrayFromCPrimitive(inclusionMap + 1)) != 256) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(0);
		return null;
	}
	i = start;
	stringSize = sizeOfSTArrayFromCPrimitive(aString + 1);
	while ((i <= stringSize) && ((inclusionMap[(asciiValue(aString[i])) + 1]) == 0)) {
		i += 1;
	}
	if (i > stringSize) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(0);
		return null;
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
	pushInteger(i);
	return null;
}


/*	Answer the index in the string body at which the substring key first occurs, at or beyond start.  The match is determined using matchTable, which can be used to effect, eg, case-insensitive matches.  If no match is found, zero will be returned.

	The algorithm below is not optimum -- it is intended to be translated to C which will go so fast that it wont matter. */

EXPORT(sqInt) primitiveFindSubstring(void) {
    sqInt rcvr;
    unsigned char *key;
    unsigned char *body;
    sqInt start;
    unsigned char *matchTable;
    sqInt startIndex;
    sqInt index;

	rcvr = stackValue(4);
	key = arrayValueOf(stackValue(3));
	key -= 1;
	body = arrayValueOf(stackValue(2));
	body -= 1;
	start = stackIntegerValue(1);
	matchTable = arrayValueOf(stackValue(0));
	matchTable -= 1;
	if (!(successFlag)) {
		return null;
	}
	if ((sizeOfSTArrayFromCPrimitive(key + 1)) == 0) {
		if (!(successFlag)) {
			return null;
		}
		pop(5);
		pushInteger(0);
		return null;
	}
	for (startIndex = start; startIndex <= (((sizeOfSTArrayFromCPrimitive(body + 1)) - (sizeOfSTArrayFromCPrimitive(key + 1))) + 1); startIndex += 1) {
		index = 1;
		while ((matchTable[(asciiValue(body[(startIndex + index) - 1])) + 1]) == (matchTable[(asciiValue(key[index])) + 1])) {
			if (index == (sizeOfSTArrayFromCPrimitive(key + 1))) {
				if (!(successFlag)) {
					return null;
				}
				pop(5);
				pushInteger(startIndex);
				return null;
			}
			index += 1;
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(5);
	pushInteger(0);
	return null;
}

EXPORT(sqInt) primitiveIndexOfAsciiInString(void) {
    sqInt rcvr;
    sqInt anInteger;
    unsigned char *aString;
    sqInt start;
    sqInt pos;
    sqInt stringSize;

	rcvr = stackValue(3);
	anInteger = stackIntegerValue(2);
	aString = arrayValueOf(stackValue(1));
	aString -= 1;
	start = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	stringSize = sizeOfSTArrayFromCPrimitive(aString + 1);
	for (pos = start; pos <= stringSize; pos += 1) {
		if ((asciiValue(aString[pos])) == anInteger) {
			if (!(successFlag)) {
				return null;
			}
			pop(4);
			pushInteger(pos);
			return null;
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
	pushInteger(0);
	return null;
}


/*	Answer the hash of a byte-indexed collection,
	using speciesHash as the initial value.
	See SmallInteger>>hashMultiply.

	The primitive should be renamed at a
	suitable point in the future */

EXPORT(sqInt) primitiveStringHash(void) {
    sqInt rcvr;
    unsigned char *aByteArray;
    sqInt speciesHash;
    sqInt pos;
    sqInt low;
    sqInt byteArraySize;
    sqInt hash;

	rcvr = stackValue(2);
	aByteArray = arrayValueOf(stackValue(1));
	aByteArray -= 1;
	speciesHash = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	byteArraySize = sizeOfSTArrayFromCPrimitive(aByteArray + 1);
	hash = speciesHash & 268435455;
	for (pos = 1; pos <= byteArraySize; pos += 1) {

		/* Begin hashMultiply */

		hash += aByteArray[pos];
		low = hash & 16383;
		hash = ((9741 * low) + ((((9741 * (((usqInt) hash >> 14))) + (101 * low)) & 16383) * 16384)) & 268435455;
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
	pushInteger(hash);
	return null;
}

EXPORT(sqInt) primitiveTranslateStringWithTable(void) {
    sqInt rcvr;
    sqInt t1;
    sqInt t2;
    sqInt t3;
    sqInt t4;
    sqInt t5;

	rcvr = stackValue(4);
	t1 = stackIntegerValue(3);
	t2 = stackIntegerValue(2);
	t3 = stackIntegerValue(1);
	t4 = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	for (t5 = t2; t5 <= t3; t5 += 1) {
		t1[t5] = (t4[(asciiValue(t1[t5])) + 1]);
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
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


void* MiscPrimitivePlugin_exports[][3] = {
	{"MiscPrimitivePlugin", "primitiveCompareString", (void*)primitiveCompareString},
	{"MiscPrimitivePlugin", "primitiveCompressToByteArray", (void*)primitiveCompressToByteArray},
	{"MiscPrimitivePlugin", "primitiveDecompressFromByteArray", (void*)primitiveDecompressFromByteArray},
	{"MiscPrimitivePlugin", "primitiveConvert8BitSigned", (void*)primitiveConvert8BitSigned},
	{"MiscPrimitivePlugin", "primitiveFindFirstInString", (void*)primitiveFindFirstInString},
	{"MiscPrimitivePlugin", "primitiveIndexOfAsciiInString", (void*)primitiveIndexOfAsciiInString},
	{"MiscPrimitivePlugin", "setInterpreter", (void*)setInterpreter},
	{"MiscPrimitivePlugin", "primitiveFindSubstring", (void*)primitiveFindSubstring},
	{"MiscPrimitivePlugin", "primitiveStringHash", (void*)primitiveStringHash},
	{"MiscPrimitivePlugin", "getModuleName", (void*)getModuleName},
	{"MiscPrimitivePlugin", "primitiveTranslateStringWithTable", (void*)primitiveTranslateStringWithTable},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

