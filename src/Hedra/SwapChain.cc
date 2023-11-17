#include <SwapChain.hh>

namespace Hedra {
VOID SwapChain::Flip() {
	VOID *Buffer;

	if (BufferChain.size() < 2)
		return;

	Buffer = BufferChain.front();
	BufferChain.pop_front();
	BufferChain.push_back(Buffer);
}
}