class PaymentMethod
{
public:
	virtual void process() = 0;
	virtual ~PaymentMethod() = default;
};

class PaypalPayment : public PaymentMethod
{
public:
	void process() override
	{
		std::cout << "Paypal logic" << std::endl;
	}
};

class DebitPayment : public PaymentMethod
{
public:
	void process() override
	{
		std::cout << "Debit logic" << std::endl;
	}
};

class PaymentManagement
{
public:
	void processPayment(PaymentMethod* payMethod)
	{
		payMethod->process();
	}
};