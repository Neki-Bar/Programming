
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Drink
{
public:
	Drink()
	{
		name = ' ';
		price = 0;
		volume = 1;
		perv = price / volume;
		k = 0; 
	}

	Drink(string name, int price, int volume)
	{
		this->name = name;
		this->price = price;
		this->volume = volume;
		this->perv = price / volume;
	}

	Drink(const Drink &other)
	{
		this->name = other.name;
		this->price = other.price;
		this->volume = other.volume;
		this->k = other.k;
		this->perv = other.perv;
	}

	int getPrice()
	{
		return price;
	}

	int getK()
	{
		return k;
	}

	int getVolume()
	{
		return volume;
	}

	string getName()
	{
		return name;
	}

	void addK(int c)
	{
		k = c;
	}

	bool operator <(const Drink &other)
	{
		return (this->perv < other.perv);
	}

	bool operator >(const Drink& other)
	{
		return (this->perv > other.perv);
	}

double perv;
private:
	string name;
	int price;
	int volume;
	
	int k;
};

int main(){
	setlocale(LC_ALL, "rus");
	
	int buget;
	int assorti;
	string name;
	int price;
	int volume;
	int temp;
	int sumvol = 0;
	int minprice = 1000000001;

	cout << "Введите количество денег\n";
	cin >> buget;

	cout << "Введите количество разновидностей напитков\n";
	cin >> assorti;

	vector <Drink> drinks(assorti);

	cout << "Введите наименование напитка, его цену и его объем через пробел, причем каждый новый напиток с новой строки.\n";
	for (int i = 0; i < assorti; i++) {
		cin >> name;
		cin >> price;
		cin >> volume;
		drinks[i] = Drink(name, price, volume);
		if (minprice > price) minprice = price;
	}
	if (minprice > buget) cout << -1;
	else {
		sort(drinks.begin(), drinks.end(), [](Drink a, Drink b) {return a < b; });

		for (int i = 0; i < assorti; i++) {
			drinks[i].addK(buget / drinks[i].getPrice());
			buget %= drinks[i].getPrice();
		}
		cout << "<Название напитка> <количество бутылок>:\n";
		for (int i = 0; i < assorti; i++) {
			temp = drinks[i].getK();
			if (temp) {
				cout << drinks[i].getName() << " " << temp << "\n";
				sumvol += drinks[i].getVolume() * temp;
			}
		}
		cout << "Суммарный объем: " << sumvol << "\n";
		cout << "Остаток денег: " << buget;
	}
}
