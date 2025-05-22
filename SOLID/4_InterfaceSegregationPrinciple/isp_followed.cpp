class Working {
public:
	virtual void work() = 0;
	
	virtual ~Working() = default;
};

class Eating {
	virtual void eat() = 0;
	
	virtual ~Eating() = default;  
};

class Resting {
	virtual void rest() = 0;
	
	virtual ~Resting() = default
};

class HumanWorker :public Working, public Eating, public Resting {
public:

	void work()override {
	}

	void rest() override {

	}

	void eat()override {

	}
};

class RobotWorker : public Working {
public:
	void work()override;
};