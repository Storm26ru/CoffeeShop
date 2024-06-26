#include<iostream>
using namespace std;

enum class CoffeeType
{
	ESPRESSO,
	AMERICANO,
	CAFFE_LATTE,
	CAPPUCCINO
};
class Coffee
{
public:
	virtual void grindCoffee()const = 0;
	virtual	void makeCoffee()const = 0;
	virtual	void pourInCup()const = 0;
	virtual ~Coffee(){}
};
class Americano :public Coffee
{
public:
	void grindCoffee()const override
	{
		cout << "GrindCoffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "MakeCoffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "PourInCup" << endl;
	}
};
class Capuccino :public Coffee
{
public:
	void grindCoffee()const override
	{
		cout << "GrindCoffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "MakeCoffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "PourInCup" << endl;
	}
};
class CaffeLatte :public Coffee
{
public:
	void grindCoffee()const override
	{
		cout << "GrindCoffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "MakeCoffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "PourInCup" << endl;
	}
};
class Espresso :public Coffee
{
public:
	void grindCoffee()const override
	{
		cout << "GrindCoffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "MakeCoffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "PourInCup" << endl;
	}
};

class CoffeeShop
{
public:

	virtual Coffee* CreateCoffee(CoffeeType type)const= 0;
	void ordercoffee(CoffeeType type)
	{
		Coffee* coffee = CreateCoffee(type);
		coffee->grindCoffee();
		coffee->makeCoffee();
		coffee->pourInCup();
		cout << "Вот ваш кофе! Спасибо, приходите еще! " << endl;
		delete coffee;
	}
	virtual ~CoffeeShop() {};
};
class AmericanCofeeShop : public CoffeeShop
{
public:
	Coffee* CreateCoffee(CoffeeType type)const override
	{
		Coffee* coffee = nullptr;
		switch (type)
		{
		case CoffeeType:: CAPPUCCINO:
			coffee = new Capuccino(); break;
		case CoffeeType::AMERICANO:
			coffee = new Americano(); break;
		case CoffeeType::ESPRESSO:
			coffee = new Espresso(); break;
		case CoffeeType::CAFFE_LATTE:
			coffee = new CaffeLatte();
		}
		return coffee;
	}
};




void main()
{
	setlocale(LC_ALL, "");
	CoffeeShop* american = new AmericanCofeeShop();
	american->ordercoffee(CoffeeType::ESPRESSO);
	delete american;


}