#include"Mylibrary.h"
/*дз:
* 1.Создать класс Попугай на основе Animal, реализовать нужные интерфейсы
* 2. Создать класс Самолет, и реализовать нужный интерфейс.
* 3. Создать функцию, который может работать и с объектом класса самолет, и с объектом класса попугай!!

*/
class Plane:public IFly
{
	string name;
public:
	Plane() = default;
	Plane(string n) :name(n)
	{};
	virtual void Fly()
	{
		cout << "Самолет может летать\n";
	}
};

void MyFunc(IFly * ptr)
{
	ptr->Fly();
}
int main()
{
   setlocale(0, "ru");
   Parrot obj("Попугай Арра", 1, "Южная Америка");
   IFly* ptr = &obj;
   MyFunc(&obj);
   Plane plane("Boieng");
   ptr = &plane;
   MyFunc(&plane);
}