#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct Coin {
public:
	int count;
	Coin(int count);
};

struct Rune {
public:
	enum class Element {
		FIRE,
		WATER,
		EARTH,
		AIR
	};
	short int level;
	Rune::Element element;
	Rune(short int level, Element element);
};

struct Weapon {
public:
	int damage;
	short int critical;
	short int durability;
	Weapon(int damage, short int critical, short int durability);
};

struct Armor {
public:
	int guard;
	short int durability;
	Armor(int guard, short int durability);
};

union Info{
		Coin CoinItem;
		Rune RuneItem;
		Weapon WeaponItem;
		Armor ArmorItem;
		Info();
	};

enum class ItemType {
	COIN,
	RUNE,
	WEAPON,
	ARMOR,
};

struct Item {
private:
	ItemType type;
	Info item;

public:
	Item();
	Item(ItemType type, Info item);

		friend Item generateItem();
		friend ostream& operator<<(ostream& os, Item& a);
};

typedef vector<Item> LootBox;

LootBox generateLootBox();
Item generateItem();

Item::Item() {
	this->type = ItemType::COIN;
	this->item = item;
}

Item::Item(ItemType type, Info item) {
	this->type = type;
	this->item = item;
}

Info::Info() {
	this->CoinItem = Coin::Coin(0);
}

Coin::Coin(int count) {
	this->count = count;
}

Rune::Rune(short int level, Element element) {
	this->level = level;
	this->element = element;
}

Weapon::Weapon(int damage, short int critical, short int durability) {
	this->damage = damage;
	this->critical = critical;
	this->durability = durability;
}

Armor::Armor(int guard, short int durability) {
	this->guard = guard;
	this->durability = durability;
}



Item& operator++(Item& a) {
	a = generateItem();
	return a;
}

LootBox& operator<<(LootBox& a, Item& b) {
	a.push_back(b);
	return a;
}

ostream& operator<<(ostream& os, Item& a) {
	switch (a.type) {
	case(ItemType::COIN):
		os << a.item.CoinItem.count << " gold\n";
		break;
	case(ItemType::RUNE):
		os << "Rune of ";
		switch (a.item.RuneItem.element) {
		case(Rune::Element::FIRE):
			os << "fire ";
			break;
		case(Rune::Element::WATER):
			os << "water ";
			break;
		case(Rune::Element::EARTH):
			os << "earth ";
			break;
		case(Rune::Element::AIR):
			os << "air ";
			break;
		}
		os << a.item.RuneItem.level << " lvl\n";
		break;
	case(ItemType::WEAPON):
		switch (a.item.WeaponItem.damage) {
		case(100):
			os << "God Killer\n";
			break;
		case(75):
			os << "Demon Slayer\n";
			break;
		}
		break;
	case(ItemType::ARMOR):
		os << "Bronezhiletka\n";
		break;
	}
	return os;
}

ostream& operator <<(ostream& os, LootBox& a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	return os;
}

LootBox generateLootBox() {
	LootBox TreeItems;
	Item temp;
	for (int i = 0; i < 3; i++){
		TreeItems << ++temp;
	}
	return TreeItems;
}

double getRandom(double min, double max, int precision) {
	srand(time(0));
	double value;
	value = rand() % (int)pow(10, precision);
	value = min + (value / pow(10, precision)) * (max - min);
	cout << value;
	return value;
}

Item generateItem() {
	Item temp;
	double randItem = getRandom(0, 100, 2);
	ItemType type;
	Info item;
	Rune::Element element = Rune::Element::FIRE;
	if (randItem >= 0.0 && randItem < 50.00) {
		type = ItemType::COIN;
		item.CoinItem = Coin(1000);
		temp = Item(type, item);
	}
	if (randItem >= 50.01 && randItem < 56.00) {
		type = ItemType::RUNE;
		element = Rune::Element::FIRE;
		item.RuneItem = Rune(1, element);
	}
	if (randItem >= 56.01 && randItem < 69.00) {
		type = ItemType::RUNE;
		element = Rune::Element::WATER;
		item.RuneItem = Rune(1, element);
	}
	if (randItem >= 69.01 && randItem < 76.00) {
		type = ItemType::RUNE;
		element = Rune::Element::EARTH;
		item.RuneItem = Rune(1, element);
	}
	if (randItem >= 76.01 && randItem < 90.00) {
		type = ItemType::RUNE;
		element = Rune::Element::AIR;
		item.RuneItem = Rune(1, element);
	}
	if (randItem >= 90.01 && randItem < 90.00) {
		type = ItemType::RUNE;
		element = Rune::Element::FIRE;
		item.RuneItem = Rune(5, element);
	}
	if (randItem >= 90.61 && randItem < 91.90) {
		type = ItemType::RUNE;
		element = Rune::Element::WATER;
		item.RuneItem = Rune(5, element);
	}
	if (randItem >= 91.91 && randItem < 92.60) {
		type = ItemType::RUNE;
		element = Rune::Element::EARTH;
		item.RuneItem = Rune(5, element);
	}
	if (randItem >= 92.61 && randItem < 94.00) {
		type = ItemType::RUNE;
		element = Rune::Element::AIR;
		item.RuneItem = Rune(5, element);
	}
	if (randItem >= 94.01 && randItem < 94.06) {
		type = ItemType::RUNE;
		element = Rune::Element::FIRE;
		item.RuneItem = Rune(10, element);
	}
	if (randItem >= 94.07 && randItem < 94.19) {
		type = ItemType::RUNE;
		element = Rune::Element::WATER;
		item.RuneItem = Rune(10, element);
	}
	if (randItem >= 94.20 && randItem < 94.26) {
		type = ItemType::RUNE;
		element = Rune::Element::EARTH;
		item.RuneItem = Rune(10, element);
	}
	if (randItem >= 94.27 && randItem < 94.40) {
		type = ItemType::RUNE;
		element = Rune::Element::AIR;
		item.RuneItem = Rune(10, element);
	}
	if (randItem >= 94.41 && randItem < 95.80) {
		type = ItemType::WEAPON;
		item.WeaponItem = Weapon(100, 0, 100);
	}
	if (randItem >= 95.81 && randItem < 97.20) {
		type = ItemType::WEAPON;
		item.WeaponItem = Weapon(75, 50, 100);
	}
	if (randItem >= 97.21 && randItem < 100.00) {
		type = ItemType::ARMOR;
		item.ArmorItem = Armor(50, 100);
	}
	return temp;
}

int main(){
	setlocale(LC_CTYPE, "rus");
	
	string success;
	while (true) {
		/*cout << "Открыть лутбокс? Yes/No";
		cin >> success;
		if (success == "No" || success == "N" || success == "n" || success == "no") {
			break;
		}*/
		LootBox temp = generateLootBox();
		cout << temp;
	}
	
}