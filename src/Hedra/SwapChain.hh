#pragma once

#include <Hedrabase.hh>

namespace Hedra {
class HEDRAPI SwapChain {
private:
	std::list<VOID *> BufferChain;
public:
	VOID Flip();
	virtual VOID Present() = 0;
};
}