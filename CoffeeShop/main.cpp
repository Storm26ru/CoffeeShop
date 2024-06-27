//                       FACTORY METHOD C++
#include<iostream>
using namespace std;
#define SEPARATOR "-------------------------------------------------------------------------------"


enum class CoffeeType
{
	ESPRESSO,
	AMERICANO,
	CAFFE_LATTE,
	CAPPUCCINO
};
class Coffee // Абстрактый продукт с общим интерфейсом.
{
public:
	virtual void name()const = 0;
	virtual void grindCoffee()const = 0;
	virtual	void makeCoffee()const = 0;
	virtual	void pourInCup()const = 0;
	virtual ~Coffee() {}
};
class AmericanStyleAmericano :public Coffee 
{
public:
	void name()const override
	{
		cout << "Заказ: Americano" << endl;

	}
	void grindCoffee()const override
	{
		cout << "1.Grind Coffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "2.Make Coffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "3.Pour a larger portion into the Cup + marshmallow" << endl;
	}
};
class AmericanStyleCapuccino :public Coffee
{
public:
	void name()const override
	{
		cout << "Заказ: Capuccino" << endl;

	}
	void grindCoffee()const override
	{
		cout << "1.Grind Coffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "2.Make Coffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "3.Pour a larger portion into the Cup + marshmallow" << endl;
	}
};
class AmericanStyleCaffeLatte :public Coffee
{
public:
	void name()const override
	{
		cout << "Заказ: Caffe Latte" << endl;

	}
	void grindCoffee()const override
	{
		cout << "1.Grind Coffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "2.Make Coffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "3.Pour a larger portion into the Cup + marshmallow" << endl;
	}
};
class AmericanStyleEspresso :public Coffee
{
public:
	void name()const override
	{
		cout << "Заказ: Espresso" << endl;

	}
	void grindCoffee()const override
	{
		cout << "1.Grind Coffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "2.Make Coffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "3.Pour a larger portion into the Cup + marshmallow" << endl;
	}
};
class ItalianStyleAmericano :public Coffee
{
public:
	void name()const override
	{
		cout << "Заказ:Americano" << endl;

	}
	void grindCoffee()const override
	{
		cout << "1.Italian Grind Coffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "2.Make Coffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "3.Pour into a Cup" << endl;
	}
};
class ItalianStyleCapuccino :public Coffee
{
public:
	void name()const override
	{
		cout << "Заказ: Capuccino" << endl;

	}
	void grindCoffee()const override
	{
		cout << "1.Italian Grind Coffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "2.Make Coffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "3.Pour into a Cup" << endl;
	}
};
class ItalianStyleCaffeLatte :public Coffee
{
public:
	void name()const override
	{
		cout << "Заказ: Caffe Latte" << endl;

	}
	void grindCoffee()const override
	{
		cout << "1.Italian Grind Coffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "2.Make Coffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "3.Pour into a Cup" << endl;
	}
};
class ItalianStyleEspresso :public Coffee
{
public:
	void name()const override
	{
		cout << "Заказ: Espresso" << endl;

	}
	void grindCoffee()const override
	{
		cout << "1.Italian Grind Coffee" << endl;
	}
	void makeCoffee()const override
	{
		cout << "2.Make Coffee" << endl;
	}
	void pourInCup()const override
	{
		cout << "3.Pour into a Cup" << endl;
	}
};
class CoffeeShop // Абстрактная кофейня с фабричным методом.
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
		cout << SEPARATOR << endl;
		delete coffee;
	}
	virtual ~CoffeeShop() {};
};

//В Американской кофейне порции будут больше и к каждому заказу будет подаваться плавленый зефир
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
// В итальянской кофейне будут использоваться только итальянские кофейные бренды с особым помолом и прожаркой.
class ItalianCofeeShop : public CoffeeShop//
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
	american->ordercoffee(CoffeeType::AMERICANO);
	CoffeeShop* italian = new ItalianCofeeShop();
	italian->ordercoffee(CoffeeType::CAFFE_LATTE);
	delete italian;
	delete american;


}