#pragma once

#include <stdint.h>
#include <cmath>

#include <list>
#include <tuple>
#include <vector>

#if !__AVX2__
#include <simde/x86/avx2.h>
#endif

#if LIBHEDRA
#define HEDRAPI __declspec(dllexport)
#else
#define HEDRAPI __declspec(dllimport)
#endif

#define FALSE false
#define TRUE  true

using VOID    = void;
using BOOLEAN = bool;
using CHAR8   = char;
using INT8    = int8_t;
using INT16   = int16_t;
using INT32   = int32_t;
using INT64   = int64_t;
using INTN    = ptrdiff_t;
using UINT8   = uint8_t;
using UINT16  = uint16_t;
using UINT32  = uint32_t;
using UINT64  = uint64_t;
using UINTN   = size_t;
using FLOAT   = float;

struct FLOAT2 {
	FLOAT X;
	FLOAT Y;

	FLOAT2() : X(0.0f), Y(0.0f) { }
	FLOAT2(
		FLOAT X,
		FLOAT Y
	) : X(X), Y(Y) { }
};

struct FLOAT3 {
	FLOAT X;
	FLOAT Y;
	FLOAT Z;

	FLOAT3() : X(0.0f), Y(0.0f), Z(0.0f) { }
	FLOAT3(
		FLOAT X,
		FLOAT Y,
		FLOAT Z
	) : X(X), Y(Y), Z(Z) { }
};

struct FLOAT4 {
	FLOAT X;
	FLOAT Y;
	FLOAT Z;
	FLOAT W;

	FLOAT4() : X(0.0f), Y(0.0f), Z(0.0f), W(0.0f) { }
	FLOAT4(
		FLOAT X,
		FLOAT Y,
		FLOAT Z,
		FLOAT W
	) : X(X), Y(Y), Z(Z), W(W) { }
};

struct INT2 {
	INT32 X;
	INT32 Y;

	INT2() : X(0), Y(0) { }
	INT2(
		INT32 X,
		INT32 Y
	) : X(X), Y(Y) { }
};

struct INT3 {
	INT32 X;
	INT32 Y;
	INT32 Z;

	INT3() : X(0), Y(0), Z(0) { }
	INT3(
		INT32 X,
		INT32 Y,
		INT32 Z
	) : X(X), Y(Y), Z(Z) { }
};

struct INT4 {
	INT32 X;
	INT32 Y;
	INT32 Z;
	INT32 W;

	INT4() : X(0), Y(0), Z(0), W(0) { }
	INT4(
		INT32 X,
		INT32 Y,
		INT32 Z,
		INT32 W
	) : X(X), Y(Y), Z(Z), W(W) { }
};