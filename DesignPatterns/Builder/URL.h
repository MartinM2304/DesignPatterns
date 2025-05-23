#pragma once

#include <iostream>
#include <cstring>

class URL
{
private:
	// Mandatory
	std::string protocol;
	std::string sub;
	std::string domain;

	// Optional
	std::string path;

public:
	static class Builder
	{
	private:
		std::string protocol;
		std::string sub;
		std::string domain;
		std::string path;

		friend class URL;

	public:
		Builder(const std::string& protocol, const std::string& sub, const std::string& domain);

		Builder& setPath(const std::string& path);

		URL* build();
	};

	URL(Builder* builder);
};
