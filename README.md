# Hedra

A fast SIMD-optimized C++ 3D software renderer on the CPU. Primarily uses AVX/AVX2 instructions.

Works on old/non-x86 CPUs using SIMDe.

## Features

- [ ] Triangle rasterization
- Programmable 3D pipeline:
  - [ ] OOP vertex/pixel shaders
  - [ ] Blending
- [ ] Multi-threaded 8x8 block rasterizer
- [ ] OBJ model support

## Dependencies

- [SIMD Everywhere](https://github.com/simd-everywhere/simde)
- [DirectXMath](https://github.com/microsoft/DirectXMath)
- [Vc](https://github.com/VcDevel/Vc) (only for CMake utilities, see [lib/cmake](https://github.com/whypet/Hedra/tree/main/lib/cmake) and [dependencies.sh](https://github.com/whypet/Hedra/blob/main/dependencies.sh))
