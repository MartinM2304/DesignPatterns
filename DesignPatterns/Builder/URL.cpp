#include "URL.h"

URL::Builder::Builder(const std::string& protocol, const std::string& sub, const std::string& domain) : protocol(protocol), sub(sub), domain(domain)
{
}

URL::Builder& URL::Builder::setPath(const std::string& path)
{
	this->path = path;
	return *this;
}

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
