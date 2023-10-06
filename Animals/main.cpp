#include"Mylibrary.h"
/*��:
* 1.������� ����� ������� �� ������ Animal, ����������� ������ ����������
* 2. ������� ����� �������, � ����������� ������ ���������.
* 3. ������� �������, ������� ����� �������� � � �������� ������ �������, � � �������� ������ �������!!

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
		cout << "������� ����� ������\n";
	}
};

void MyFunc(IFly * ptr)
{
	ptr->Fly();
}
int main()
{
   setlocale(0, "ru");
   Parrot obj("������� ����", 1, "����� �������");
   IFly* ptr = &obj;
   MyFunc(&obj);
   Plane plane("Boieng");
   ptr = &plane;
   MyFunc(&plane);
}