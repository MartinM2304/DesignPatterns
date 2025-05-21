#pragma once

#define NODISCARD [[nodiscard]]

// --- Iterator ---

template <typename T>
class VectorIterator
{
public:
	using Ptr = T*;
	using Ref = T&;
	using Offset = std::ptrdiff_t;

public:
	VectorIterator(Ptr ptr);

	VectorIterator<T>& operator++();
	VectorIterator<T> operator++(int);

	VectorIterator<T>& operator--();
	VectorIterator<T> operator--(int);

	VectorIterator<T>& operator+=(Offset offset);
	VectorIterator<T>& operator-=(Offset offset);

	NODISCARD Ref operator[](size_t index) noexcept;
	NODISCARD Ptr operator->() noexcept;
	NODISCARD Ref operator*() noexcept;

	NODISCARD bool operator==(const VectorIterator<T>& other) const;
	NODISCARD bool operator!=(const VectorIterator<T>& other) const;

private:
	Ptr ptr;
};

template<typename T>
inline VectorIterator<T>::VectorIterator(Ptr ptr) : ptr(ptr)
{
}

template<typename T>
inline VectorIterator<T>& VectorIterator<T>::operator++()
{
	++ptr;
	return *this;
}

template<typename T>
inline VectorIterator<T> VectorIterator<T>::operator++(int)
{
	VectorIterator toReturn = *this;
	++(*this);
	return toReturn;
}

template<typename T>
inline VectorIterator<T>& VectorIterator<T>::operator--()
{
	--ptr;
	return *this;
}

template<typename T>
inline VectorIterator<T> VectorIterator<T>::operator--(int)
{
	VectorIterator toReturn = *this;
	--(*this);
	return toReturn;
}

template<typename T>
inline VectorIterator<T>& VectorIterator<T>::operator+=(Offset offset)
{
	ptr += offset;
	return *this;
}

template<typename T>
inline VectorIterator<T>& VectorIterator<T>::operator-=(Offset offset)
{
	ptr -= offset;
	return *this;
}

template<typename T>
NODISCARD inline T& VectorIterator<T>::operator[](size_t index) noexcept
{
	return *(ptr + index);
}

template<typename T>
NODISCARD inline T* VectorIterator<T>::operator->() noexcept
{
	return ptr;
}

template<typename T>
NODISCARD inline T& VectorIterator<T>::operator*() noexcept
{
	return *ptr;
}

template<typename T>
NODISCARD inline bool VectorIterator<T>::operator==(const VectorIterator<T>& other) const
{
	return ptr == other.ptr;
}

template<typename T>
NODISCARD inline bool VectorIterator<T>::operator!=(const VectorIterator<T>& other) const
{
	return !(ptr == other.ptr);
}

// --- Const Iterator ---

template <typename T>
class ConstVectorIterator
{
public:
	using ConstPtr = const T*;
	using ConstRef = const T&;
	using Offset = std::ptrdiff_t;

public:
	ConstVectorIterator(ConstPtr ptr);

	ConstVectorIterator<T>& operator++();
	ConstVectorIterator<T> operator++(int);

	ConstVectorIterator<T>& operator--();
	ConstVectorIterator<T> operator--(int);

	ConstVectorIterator<T>& operator+=(Offset offset);
	ConstVectorIterator<T>& operator-=(Offset offset);

	NODISCARD ConstRef operator[](size_t index) const noexcept;
	NODISCARD ConstPtr operator->() const noexcept;
	NODISCARD ConstRef operator*() const noexcept;

	NODISCARD bool operator==(const ConstVectorIterator<T>& other) const;
	NODISCARD bool operator!=(const ConstVectorIterator<T>& other) const;

private:
	ConstPtr ptr;
};

template<typename T>
inline ConstVectorIterator<T>::ConstVectorIterator(ConstPtr ptr) : ptr(ptr)
{
}

template<typename T>
inline ConstVectorIterator<T>& ConstVectorIterator<T>::operator++()
{
	++ptr;
	return *this;
}

template<typename T>
inline ConstVectorIterator<T> ConstVectorIterator<T>::operator++(int)
{
	ConstVectorIterator toReturn = *this;
	++(*this);
	return toReturn;
}

template<typename T>
inline ConstVectorIterator<T>& ConstVectorIterator<T>::operator--()
{
	--ptr;
	return *this;
}

template<typename T>
inline ConstVectorIterator<T> ConstVectorIterator<T>::operator--(int)
{
	ConstVectorIterator toReturn = *this;
	--(*this);
	return toReturn;
}

template<typename T>
inline ConstVectorIterator<T>& ConstVectorIterator<T>::operator+=(Offset offset)
{
	ptr += offset;
	return *this;
}

template<typename T>
inline ConstVectorIterator<T>& ConstVectorIterator<T>::operator-=(Offset offset)
{
	ptr -= offset;
	return *this;
}

template<typename T>
NODISCARD inline const T& ConstVectorIterator<T>::operator[](size_t index) const noexcept
{
	return *(ptr + index);
}

template<typename T>
NODISCARD inline const T* ConstVectorIterator<T>::operator->() const noexcept
{
	return ptr;
}

template<typename T>
NODISCARD inline const T& ConstVectorIterator<T>::operator*() const noexcept
{
	return *ptr;
}

template<typename T>
NODISCARD inline bool ConstVectorIterator<T>::operator==(const ConstVectorIterator<T>& other) const
{
	return ptr == other.ptr;
}

template<typename T>
NODISCARD inline bool ConstVectorIterator<T>::operator!=(const ConstVectorIterator<T>& other) const
{
	return !(ptr == other.ptr);
}
