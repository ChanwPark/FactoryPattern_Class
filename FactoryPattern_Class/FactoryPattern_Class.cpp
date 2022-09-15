// FactoryPattern_Class.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

/*
���丮 �޼��带 Ŭ������ ����
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
		cout << "�۸۸�~~~" << endl; 
	}
};

class Cat : public Animal {
public:
	virtual void speak() override {
		cout << "�߿�~~~" << endl;
	}
};


class Sheep : public Animal {
public:
	virtual void speak() override {
		cout << "��~~ ��~~ " << endl;
	}
};

//�߰��� �κ� --> Open Close  ���� ����
class Cow : public Animal {
public:
	virtual void speak() override {
		cout << "���� ����~~" << endl; 
	}
};

/*Ŭ������ �޼ҵ�� ������*/

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
		throw exception("��ü�� ������ �� �����ϴ�."); 
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

