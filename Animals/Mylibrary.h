#pragma once
#include<iostream>
#include<string.h>
using namespace std;

struct IFly   // интерфейс для летающих
{
	virtual void Fly() = 0;
};
struct ISwim   // интерфейс для плавающих
{
	virtual void Swim() = 0;
};

class Animal  // абстрактный класс !!
{
protected:
	char * name;
	int kg;
public:
	Animal() = default;
	Animal(const char * n, int k)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		kg = k;
	}
	void Print()
	{
		cout << "Name: " << name << "Kg: " << kg << endl;
	}	
	virtual void Continent() = 0;
	virtual void Eat() = 0;
	virtual void Sound() = 0;

	~Animal()
	{
		delete[] name;
	}
};

class Pinguin: public Animal, public ISwim
{
	char* continent;

public:
	Pinguin() = default;
	Pinguin(const char *  n, int kg, const char* cont) :Animal(n, kg)
	{
		continent = new char[strlen(cont) + 1];
		strcpy_s(continent, strlen(cont) + 1, cont);
	}
	// реализация интерфейса IAnimal
	virtual void Eat()
	{
		cout << "Пингвины едят рыбу\n";
	}
	virtual void Sound()
	{
		cout << "Пингвины издают какие то звуки\n";
	}
	virtual void Continent()
	{
		cout << "Пингвины живут в Антарктиде\n";
	}
	// реализация интерфейса ISwim

	virtual  void Swim()
	{
		cout << "Пингвины отлично плавают\n";
	}
	~Pinguin()
	{
		delete[] continent;
	}

};
class Parrot : public Animal, public IFly
{
	string continent;

public:
	Parrot() = default;
	Parrot(const char* n, int kg, string cont) :Animal(n, kg)
	{
		continent = cont;
	}
	// реализация интерфейса IAnimal
	virtual void Eat()
	{
		cout << "Попугаи едят насекомых\n";
	}
	virtual void Sound()
	{
		cout << "Попугаи издают какие то звуки\n";
	}
	virtual void Continent()
	{
		cout << "Попугаи живут в Южной Америке\n";
	}
	virtual void Fly()
	{
		cout << "Попугаи могут летать\n";
	}

};