#pragma once

template <typename Class>
class BaseSingleton
{
private:
	BaseSingleton();

public:
	static Class& getInstance();

	BaseSingleton(const BaseSingleton& other) = delete;
	BaseSingleton& operator=(const BaseSingleton& other) = delete;

	~BaseSingleton() noexcept;
};

template<typename Class>
inline BaseSingleton<Class>::BaseSingleton() = default;

template<typename Class>
inline Class& BaseSingleton<Class>::getInstance()
{
	static Class instance;
	return instance;
}

template<typename Class>
inline BaseSingleton<Class>::~BaseSingleton() noexcept = default;
