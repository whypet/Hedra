#pragma once

#include <Hedrabase.hh>

namespace Hedra {
class Vertex;

using Triangle = std::tuple<Vertex, Vertex, Vertex>;

class HEDRAPI Rasterizer {
private:
	__m256 EdgeFunction(
		__m256 X256,
		__m256 Y256,
		const FLOAT2 &V1,
		const FLOAT2 &V2
	);

	VOID Fill(
		UINT32      *Buffer,
		UINTN        BufferStride,
		UINTN        BufferSize,
		const FLOAT2 Points[3],
		const __m128 Colors[3]
	);
public:
	Rasterizer();

	VOID Rasterize(
		const std::vector<Triangle> &Triangles
	);
};
}