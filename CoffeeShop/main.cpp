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
	virtual void name()const = 0;
	virtual void grindCoffee()const = 0;
	virtual	void makeCoffee()const = 0;
	virtual	void pourInCup()const = 0;
	virtual ~Coffee(){}
};
class AmericanStyleAmericano :public Coffee
{
public:
	void name()const override
	{
		cout << "Americano" << endl;

	}
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
class AmericanStyleCapuccino :public Coffee
{
public:
	void name()const override
	{
		cout << "Capuccino" << endl;

	}
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
class AmericanStyleCaffeLatte :public Coffee
{
public:
	void name()const override
	{
		cout << "Caffe Latte" << endl;

	}
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
class AmericanStyleEspresso :public Coffee
{
public:
	void name()const override
	{
		cout << "Espresso" << endl;

	}
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
class ItalianStyleAmericano :public Coffee
{
public:
	void name()const override
	{
		cout << "Americano" << endl;

	}
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
class ItalianStyleCapuccino :public Coffee
{
public:
	void name()const override
	{
		cout << "Capuccino" << endl;

	}
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
class ItalianStyleCaffeLatte :public Coffee
{
public:
	void name()const override
	{
		cout << "Caffe Latte" << endl;

	}
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
class ItalianStyleEspresso :public Coffee
{
public:
	void name()const override
	{
		cout << "Espresso" << endl;

	}
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
		coffee->name();
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
	
	AmericanCofeeShop()
	{
		cout << "American Coffee Shop" << endl;
	}
	Coffee* CreateCoffee(CoffeeType type)const override
	{
		Coffee* coffee = nullptr;
		switch (type)
		{
		case CoffeeType:: CAPPUCCINO:
			coffee = new AmericanStyleCapuccino(); break;
		case CoffeeType::AMERICANO:
			coffee = new AmericanStyleAmericano(); break;
		case CoffeeType::ESPRESSO:
			coffee = new AmericanStyleEspresso(); break;
		case CoffeeType::CAFFE_LATTE:
			coffee = new AmericanStyleCaffeLatte();
		}
		return coffee;
	}
};
class ItalianCofeeShop : public CoffeeShop
{
public:
	ItalianCofeeShop()
	{
		cout << "Italian Coffee Shop" << endl;
	}
	Coffee* CreateCoffee(CoffeeType type)const override
	{
		Coffee* coffee = nullptr;
		switch (type)
		{
		case CoffeeType::CAPPUCCINO:
			coffee = new ItalianStyleCapuccino(); break;
		case CoffeeType::AMERICANO:
			coffee = new ItalianStyleAmericano(); break;
		case CoffeeType::ESPRESSO:
			coffee = new ItalianStyleEspresso(); break;
		case CoffeeType::CAFFE_LATTE:
			coffee = new ItalianStyleCaffeLatte();
		}
		return coffee;
	}
};



void main()
{
	setlocale(LC_ALL, "");
	CoffeeShop* american = new AmericanCofeeShop();
	american->ordercoffee(CoffeeType::ESPRESSO);
	CoffeeShop* italian = new ItalianCofeeShop();
	italian->ordercoffee(CoffeeType::CAFFE_LATTE);
	delete italian;
	delete american;


}