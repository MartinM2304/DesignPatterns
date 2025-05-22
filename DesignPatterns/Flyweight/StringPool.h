#pragma once
#pragma warning (disable: 4996)

#include "Vector.hpp"

class StringPool
{
private:
	struct StringNode
	{
		char* data;
		size_t refCount;

		StringNode();
		StringNode(const char* str, size_t refCount);
	};

	Vector<StringNode> nodes;

	size_t find(const char* str, bool& found) const;
	size_t findInternal(const char* str, bool& found, size_t left, size_t right) const;

	const char* insert(const char* str, size_t idx);
	void remove(size_t idx);

public:
	StringPool();

	StringPool(const StringPool& other) = delete;
	StringPool& operator=(const StringPool& other) = delete;

	const char* getString(const char* str);
	void removeString(const char* str);

	void print() const;

	~StringPool() noexcept;
};