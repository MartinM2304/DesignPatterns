#pragma once

class Singleton
{
private:
	Singleton();

public:
	static Singleton& getInstance();

	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;

	~Singleton() noexcept;
};
