#pragma once
#pragma warning (disable: 4996)

#include <iostream>

#include "StringPool.h"

class ImmutableString
{
private:
	const char* data;
	size_t size;

	static StringPool pool;

public:
	ImmutableString();
	ImmutableString(const char* str);

	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other);

	const char& operator[](size_t idx) const;

	const char* c_str() const;

	size_t getSize() const;

	bool isEmpty() const;

	friend bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
	friend bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);

	friend std::ostream& operator<<(std::ostream& os, const ImmutableString& other);

	~ImmutableString() noexcept;
};