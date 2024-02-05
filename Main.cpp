#include <iostream>

//наследование - это механизм расширения функционала класса путем сужения его специализации, при котором открывается дорога для полиморфизма

//


class base {
public:
	base():base(0,0,0){}
	base(int a, int b, int c) : a(a),b(b),c(c){}
	int a;
	int A() {return a;}
	int B()	{return b;}
	int C() {return c;}
protected:
	int b;
	
private:
	int c;
	
};

class Derived:public base{ //публичное наследование позволяет пользоваться внутри объекта наследника полями родителя в зонах паблик и протектед так как будто они являются его полями паблик и протектед
public:
	Derived() = default;
	Derived(int a, int b, int c, int d):base(a,b,c), d(d){}

	int M00()
	{
		int res{};
		res = a + b; // свободно используем публичные и защищенные поля
		res /= C();  // приватные поля доступны через методы доступа внутри класса
		return res;
	}
	int D() { return d;}
private:
	int d;

};

class Animal {
public:
	void Age(int newAge) { age_ = newAge; }
	int Age()const { return age_; }

	void Name(std::string newName) { name_ = newName; }
	std::string Name()const { return name_; }

	virtual void Say()const { std::cout << "r.\n"; } // virtual - помечают функцию которая должна вызываться у наследников в момент их обработки под видом родителя

private:
	std::string name_;
	int age_;

};

class Kat :public Animal {
public: 
	void Say()const override{ std::cout << "mauw\n"; } // override - дополнительная проверка о том что мы функцию объявили правильно
};


int main() {
	setlocale(LC_ALL, "ru");

	base obj(1,2,5);
	obj.a;
	//obj.b;
	//obj.c;

	Derived dobj(1,2,3,4);
	dobj.B();


	Animal abs;
	abs.Name("Dog");
	abs.Age(2);
	abs.Say();
	
	Kat kat;
	kat.Name("Fluffy");
	kat.Age(5);
	kat.Say(); // по умолчанию вызовет свою реализацию
	kat.Animal::Say();// принудительно вызвали реализацию родителя

	Animal* p = &abs;
	p = &kat;
	p->Say();



	return 0;
}