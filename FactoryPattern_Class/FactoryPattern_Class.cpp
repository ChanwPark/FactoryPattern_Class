// FactoryPattern_Class.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

/*
팩토리 메서드를 클래스로 제공
*/

class Animal {
public:
	virtual void speak() = 0;
};

void hey(Animal& animal) {
	animal, speak();
}

class Dog : public Animal {
public:
	virtual void speak() override {
		cout << "멍멍멍~~~" << endl; 
	}
};

class Cat : public Animal {
public:
	virtual void speak() override {
		cout << "야옹~~~" << endl;
	}
};


class Sheep : public Animal {
public:
	virtual void speak() override {
		cout << "매~~ 매~~ " << endl;
	}
};

//추가된 부분 --> Open Close  문제 없음
class Cow : public Animal {
public:
	virtual void speak() override {
		cout << "음매 음매~~" << endl; 
	}
};

/*클래스의 메소드로 구현함*/

class FactoryAnimal {
public:
	static Animal* createAnimal(int type) {
		switch (type)
		{
		case 0:
			return new Cat;
		case 1:
			return new Dog;
		case 2 :
			return new Sheep; 
		case 3: 
			return new Cow; 
		default:
			break;
		}
		throw exception("객체를 생성할 수 없습니다."); 
	}

};

void someA() {
	int type = 0; 
	Animal* pAnimal = FactoryAnimal::createAnimal(type); 

	if (pAnimal) {
		hey(*pAnimal);
		delete pAnimal;
	}
}

void someB() {
	int type = 1; 
	Animal* pAnimal = FactoryAnimal::createAnimal(type); 

	if (pAnimal) {
		hey(*pAnimal);
		delete pAnimal;
	}
}

int main()
{
	someA();
	someB(); 
}

