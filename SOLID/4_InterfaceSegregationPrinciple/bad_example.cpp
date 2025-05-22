class Worker {
public:
	virtual void work() = 0;
	virtual void rest() = 0;
	virtual void eat() = 0;
	
	virtual ~Worker()=default;
};

class HumanWorker :public Worker {
public:

	void work()override {
		
	}

	void rest() override {

	}

	void eat()override {

	}
};

class RobotWorker : public Worker {
public:
	void work()override {}


	/* 
		Няма смисъл  RobotWorker да имплементира rest и eat, защото
		той няма такива функционалности. Това чупи ISP-
		Interface segregation principle - Принцип за разделяне на интерфейсите/
		абстрактните класове. Но в този случай ако RobotWorker не override-ва методите
		то Той ще бъде абстрактен което също не ни върши работа. Това трябва да ни подскаже 
		че имаме грешка в дизайна
	*/
	void rest() override {}
	void eat()override{}
};