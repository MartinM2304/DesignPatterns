class Working {
public:
	virtual void work() = 0;
};

class Eating {
	virtual void eat() = 0;
};

class Resting {
	virtual void rest() = 0;
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