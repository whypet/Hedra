#pragma once

#include <Hedrabase.hh>

namespace Hedra {
class Vertex {
public:
	virtual __m128 GetPosition() const = 0;
	virtual __m128 GetColorRGBA() const = 0;
};
}