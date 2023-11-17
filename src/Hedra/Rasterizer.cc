#include <Rasterizer.hh>

#include <Vertex.hh>

namespace Hedra {
Rasterizer::Rasterizer() {
}

__m256 Rasterizer::EdgeFunction(
	__m256 X256,
	__m256 Y256,
	const FLOAT2 &V1,
	const FLOAT2 &V2
) {
	__m256 A;
	__m256 B;

	A = _mm256_mul_ps(_mm256_set1_ps(V2.X - V1.X), _mm256_sub_ps(Y256, _mm256_set1_ps(V1.Y)));
	B = _mm256_mul_ps(_mm256_set1_ps(V2.Y - V1.Y), _mm256_sub_ps(X256, _mm256_set1_ps(V1.X)));

	return _mm256_sub_ps(B, A);
}

VOID Rasterizer::Fill(
	UINT32      *Buffer,
	UINTN        BufferStride,
	UINTN        BufferSize,
	const FLOAT2 Points[3],
	const __m128 Colors[3]
) {
	UINTN Width;
	UINTN Height;

	UINTN XMin;
	UINTN YMin;
	UINTN XMax;
	UINTN YMax;

	UINTN TriWidth;
	UINTN TriHeight;

	Width  = BufferStride / sizeof(UINT32);
	Height = BufferSize / sizeof(UINT32) / BufferStride;

	XMin = std::max((UINTN)std::min({ Points[0].X, Points[1].X, Points[2].X }), 0ZU);
	YMin = std::max((UINTN)std::min({ Points[0].Y, Points[1].Y, Points[2].Y }), 0ZU);
	XMax = std::min((UINTN)ceilf(std::max({ Points[0].X, Points[1].X, Points[2].X })), Width - 1);
	YMax = std::min((UINTN)ceilf(std::max({ Points[0].Y, Points[1].Y, Points[2].Y })), Height - 1);

	TriWidth  = XMax - XMin;
	TriHeight = YMax - YMin;

	for (UINTN i = 0; i < TriWidth * TriHeight; i += 8) {
		UINTN X;
		UINTN Y;

		__m256 X256;
		__m256 Y256;
		__m256 Edge1;
		__m256 Edge2;
		__m256 Edge3;
		__m256 Zero;
		__m256 Gate;

		X = i % TriWidth + XMin;
		Y = i / TriWidth + YMin;

		X256 = _mm256_set_ps(X + 7, X + 6, X + 5, X + 4, X + 3, X + 2, X + 1, X);
		Y256 = _mm256_set1_ps(Y);

		Edge1 = EdgeFunction(X256, Y256, Points[0], Points[1]);
		Edge2 = EdgeFunction(X256, Y256, Points[1], Points[2]);
		Edge3 = EdgeFunction(X256, Y256, Points[2], Points[0]);

		Zero = _mm256_setzero_ps();
		Gate = _mm256_castsi256_ps(_mm256_set1_epi64x(-1));

		Gate = _mm256_and_ps(Gate, _mm256_cmp_ps(Edge1, Zero, 0x15));
		Gate = _mm256_and_ps(Gate, _mm256_cmp_ps(Edge2, Zero, 0x15));
		Gate = _mm256_and_ps(Gate, _mm256_cmp_ps(Edge3, Zero, 0x15));

		if (!_mm256_testz_si256(_mm256_castps_si256(Gate))) {
			
		}
	}
}

VOID Rasterizer::Rasterize(
	const std::vector<Triangle> &Triangles
) {
	
}
}