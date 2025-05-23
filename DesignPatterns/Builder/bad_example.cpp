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
		Builder& setProtocol(const std::string& protocol);

		Builder& setSub(const std::string& sub);

		Builder& setDomain(const std::string& domain);

		Builder& setPath(const std::string& path);

		URL* build();
	};

	URL(Builder* builder);
};

URL* URL::Builder::build()
{
	return new URL(this);
}

URL::URL(Builder* builder)
{
	this->protocol = builder->protocol;
	this->sub = builder->sub;
	this->domain = builder->domain;
	this->path = builder->path;
}

URL::Builder& URL::Builder::setProtocol(const std::string& protocol)
{
	this->protocol = protocol;
	return *this;
}

URL::Builder& URL::Builder::setSub(const std::string& sub)
{
	this->sub = sub;
	return *this;
}

URL::Builder& URL::Builder::setDomain(const std::string& domain)
{
	this->domain = domain;
	return *this;
}

URL::Builder& URL::Builder::setPath(const std::string& path)
{
	this->path = path;
	return *this;
}

int main()
{
	URL* url = URL::Builder().build(); // not fully built, mandatory fields are not set

	return 0;
}