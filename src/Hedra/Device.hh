#pragma once

#include <Hedrabase.hh>

#include <SwapChain.hh>

namespace Hedra {
class HEDRAPI Device {
private:
	SwapChain &Swap;
public:
	Device(
		SwapChain &SwapChain
	);

	VOID Render();
};
}