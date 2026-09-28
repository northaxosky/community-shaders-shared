#pragma once

#include <algorithm>
#include <span>
#include <vector>

template <typename T>
class CircularBuffer
{
	std::vector<T> data = {};
	size_t headIdx = 0;

public:
	CircularBuffer(size_t size)
	{
		size = std::max((size_t)1, size);
		data.resize(size);
	}
	CircularBuffer() :
		CircularBuffer(1) {}

	void Resize(size_t newSize)
	{
		if (data.size() == newSize)
			return;
		data.resize(newSize);
		if (headIdx >= newSize)
			headIdx = 0;
	}

	void Push(const T& val)
	{
		data[headIdx++] = val;
		if (headIdx >= data.size())
			headIdx = 0;
	}

	std::span<const T> GetData() const { return { data }; }
	size_t GetHeadIdx() const { return headIdx; }
};
