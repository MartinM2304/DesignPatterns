#include <iostream>

enum class PaymentType
{
	DEBIT,
	PAYPAL,
};

class PaymentManagement
{
public:
	void process(PaymentType type)
	{
		switch (type)
		{
		case PaymentType::DEBIT:
			std::cout << "Debit logic" << std::endl;
			break;
		case PaymentType::PAYPAL:
			std::cout << "Paypal logic" << std::endl;
			// etc. ...
		}
	}
};