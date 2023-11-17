#pragma once

#include <SwapChain.hh>

namespace Hedra {
class NullSwapChain : public SwapChain {
public:
	NullSwapChain() {}

	STATIC VOID Present() {}
};
}