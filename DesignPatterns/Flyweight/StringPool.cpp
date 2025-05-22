#include "StringPool.h"

#include <iostream>
#include <stdexcept>
#include <cstring>

StringPool::StringPool() = default;

const char* StringPool::getString(const char* str)
{
	bool found = false;
	size_t idx = find(str, found);

	if (found)
	{
		nodes[idx].refCount++;
		return nodes[idx].data;
	}

	return insert(str, idx);
}

void StringPool::removeString(const char* str)
{
	bool found = false;
	size_t idx = find(str, found);

	if (!found) return;

	if (nodes[idx].refCount <= 1)
	{
		remove(idx);
	}
	else
	{
		nodes[idx].refCount--;
	}
}

void StringPool::print() const
{
	for (size_t i = 0; i < nodes.getSize(); i++)
	{
		std::cout << nodes[i].data << " " << nodes[i].refCount << std::endl;
	}
}

StringPool::~StringPool() noexcept
{
	for (size_t i = 0; i < this->nodes.getSize(); i++)
	{
		delete[] this->nodes[i].data;
	}
}

size_t StringPool::find(const char* str, bool& found) const
{
	if (nodes.getSize() == 0)
	{
		found = false;
		return 0;
	}

	return findInternal(str, found, 0, nodes.getSize() - 1);
}

size_t StringPool::findInternal(const char* str, bool& found, size_t left, size_t right) const
{
	while (left <= right)
	{
		size_t mid = left + (right - left) / 2;
		int cmp = strcmp(nodes[mid].data, str);

		if (cmp == 0)
		{
			found = true;
			return mid;
		}
		else if (cmp > 0)
		{
			if (mid == 0) break;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	found = false;
	return left;
}

const char* StringPool::insert(const char* str, size_t idx)
{
	if (idx > nodes.getSize())
	{
		throw std::out_of_range("Invalid insert index!");
	}

	StringNode node(str, 1);
	nodes.insert(node, idx);
	return nodes[idx].data;
}

void StringPool::remove(size_t idx)
{
	if (idx >= nodes.getSize())
	{
		throw std::out_of_range("Invalid remove index!");
	}

	delete[] this->nodes[idx].data;
	nodes.remove(idx);
}

StringPool::StringNode::StringNode() : data(nullptr), refCount(0)
{
}

StringPool::StringNode::StringNode(const char* str, size_t refCount) : refCount(refCount)
{
	size_t len = strlen(str);
	this->data = new char[len + 1] { '\0' };
	strcpy(this->data, str);
}
