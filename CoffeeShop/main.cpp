#include<iostream>
using namespace std;

enum CoffeeType
{
	ESPRESSO,
	AMERICANO,
	CAFFE_LATTE,
	CAPPUCCINO
};
class Coffee
{
public:
	virtual void grindCoffee() = 0;
	virtual	void makeCoffee() = 0;
	virtual	void pourInCup() = 0;
};
class Americano :public Coffee
{
public:
	void grindCoffee()
	{
		cout << "GrindCoffee" << endl;
	}
	void makeCoffee()
	{
		cout << "MakeCoffee" << endl;
	}
	void pourInCup()
	{
		cout << "PourInCup" << endl;
	}
};
class Capuccino :public Coffee
{
public:
	void grindCoffee()
	{
		cout << "GrindCoffee" << endl;
	}
	void makeCoffee()
	{
		cout << "MakeCoffee" << endl;
	}
	void pourInCup()
	{
		cout << "PourInCup" << endl;
	}
};
class CaffeLatte :public Coffee
{
public:
	void grindCoffee()
	{
		cout << "GrindCoffee" << endl;
	}
	void makeCoffee()
	{
		cout << "MakeCoffee" << endl;
	}
	void pourInCup()
	{
		cout << "PourInCup" << endl;
	}
};
class Espresso :public Coffee
{
public:
	void grindCoffee()
	{
		cout << "GrindCoffee" << endl;
	}
	void makeCoffee()
	{
		cout << "MakeCoffee" << endl;
	}
	void pourInCup()
	{
		cout << "PourInCup" << endl;
	}
};

class CoffeeFactory
{
public:
	Coffee* createCoffee(CoffeeType type)
	{
		Coffee* coffee = nullptr;
		switch (type)
		{
		case CAPPUCCINO:
			coffee = new Capuccino(); break;
		case AMERICANO:
			coffee = new Americano(); break;
		case ESPRESSO:
			coffee = new Espresso(); break;
		case CAFFE_LATTE:
			coffee = new CaffeLatte(); 
		}
		return coffee;

	}
};
class coffeeShop
{
	CoffeeFactory coffefactory;
public:
	coffeeShop(CoffeeFactory coffefactory) : coffefactory(coffefactory) {}
	Coffee *ordercoffee(CoffeeType type)
	{
		Coffee* coffee = coffefactory.createCoffee(type);
		coffee->grindCoffee();
		coffee->makeCoffee();
		coffee->pourInCup();
		cout << "Вот ваш кофе! Спасибо, приходите еще! " << endl;
		return coffee;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Coffee *A;
	A = new Americano();
	A->grindCoffee();
}