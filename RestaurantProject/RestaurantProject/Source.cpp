#include<iostream>
#include<vector>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class User {
public:
	string username, password;
	User() { }
	User(string name, string pass) {
		username = name;
		password = pass;
	}


};


class Ingredient {

protected:
	string name;
	double fats;
	double protein;
	double carbohydrates;
	int kcal;
public:
	Ingredient() = default;

	Ingredient(string name, double fats, double protein, double carbohydrates, int kcal)
	{
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
	}
#pragma region Setter & Getter

	string GetName() const { return name; }
	double GetFats() const { return fats; }
	double GetProtein() const { return protein; }
	double GetCarbohydrates() const { return carbohydrates; }
	int GetKcal() const { return kcal; }


	void SetName(string name) {
		this->name = name;
	}

	void SetFats(double fats) {
		fats < 0 ? throw "Fats must be great than 0" : this->fats = fats;
	}

	void SetProtein(double protein) {
		protein < 0 ? throw "Protein must be great than 0" : this->protein = protein;
	}

	void SetCarbohydrates(double carbohydrates) {
		carbohydrates < 0 ? throw "Carbohydrates must be great than 0" : this->carbohydrates = carbohydrates;
	}
	void SetKcal(int kcal) {
		kcal < 0 ? throw "Kcal must be great than 0" : this->kcal = kcal;
	}

	friend ostream& operator<<(ostream& out, const Ingredient& i) {
		out << "Name: " << i.name << "\n"
			<< "Fat: " << i.fats << "\n"
			<< "Protein:" << i.protein << "\n"
			<< "Carbohydrates: " << i.carbohydrates << "\n"
			<< "Kcal: " << i.kcal << "\n";
		return out;
	}
#pragma endregion

	virtual ~Ingredient() = 0
	{

	}
};

class Meat :public Ingredient {
public:
	Meat(const string name, double fat, double protein, double carbohydrates, int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {

	}
};

class Spices :public Ingredient {
public:
	Spices(const string name, double fat, double protein, double carbohydrates, int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {

	}

};

class Cheese :public Ingredient {
public:
	Cheese(const string name, double fat, double protein, double carbohydrates, int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {

	}

};

class Tomatoes :public Ingredient {
public:
	Tomatoes(const string name, double fat, double protein, double carbohydrates, int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {

	}

};

class Sausage :public Ingredient {
public:
	Sausage(const string name, double fat, double protein, double carbohydrates, int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {

	}

};

class Egg :public Ingredient {
public:
	Egg(const string name, double fat, double protein, double carbohydrates, int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {

	}
};
class Onion :public Ingredient {
public:
	Onion(const string name, double fat, double protein, double carbohydrates, int kcal) :Ingredient(name, fat, protein, carbohydrates, kcal) {

	}
};
class RecipetItem {
public:
	Ingredient* ingredient; //one object
	int amount;
	RecipetItem(Ingredient* ing, int amount) :ingredient(ing), amount(amount)
	{ }
};


class Dish{
public:
	vector<RecipetItem*>ingredients;
	string name;
	int money;
	static int i;
	Dish(vector<RecipetItem*>& ingredients, string name, int money)
	{
		this->ingredients.insert(this->ingredients.begin(), ingredients.begin(), ingredients.end());
		this->name = name;
		this->money = money;
	}

	void addIngredient(Ingredient* ingredient, int amount) {
		ingredients.push_back(new RecipetItem(ingredient, amount));
	}

	virtual void printRecipe()const {
		cout << name << "\n";
		cout << "***Ingredients***\n";
		for (auto ing : ingredients)
		{
			cout << *ing->ingredient << "";
			cout << "amount: " << ing->amount << "\n\n";
		}
	}
	
	void show() {
		i++;
		if (i>=5)
		{
			i = 1;
		}
		cout << "\n\n" << setw(35) << i << ". " << name << setw(12) << money << " Azn" << right << endl;
		
	}
};

int Dish::i = 0;

class Pizza :public Dish {
public:
	Pizza(vector<RecipetItem*>& ingredients, string name,int money) : Dish(ingredients, name,money) {}

};


class Kabab :public Dish {
public:
	Kabab(vector<RecipetItem*>& ingredients, string name,int money) : Dish(ingredients, name,money) {}

};

class Dolma :public Dish {
public:
	Dolma(vector<RecipetItem*>& ingredients, string name,int money) : Dish(ingredients, name,money) {}

};

class Xengel :public Dish {
public:
	Xengel(vector<RecipetItem*>& ingredients, string name, int money) : Dish(ingredients, name, money) {}
};
void Menu();
void RegisterMenu();
void Choice();
void ChooseMenu();
void SignUp() {
	system("cls");
	system("color c");
	string us;
	cout << "Username: ";
	cin >> us;

	string pass;
	cout << "Password: ";
	cin >> pass;

	ofstream file("user.txt", ios::out);
	if (file.is_open())
	{
		file << us << "#" << pass << endl;
		cout << "User account successfully signed up\n";
		system("pause");
		system("cls");
		RegisterMenu();
	}
	file.close();
}

void SignIn() {
	system("cls");
	system("color 1");
	string us;
	cout << "Username: ";
	cin >> us;

	string pass;
	cout << "Password: ";
	cin >> pass;

	ifstream file("user.txt");
	string name;
	string pas;
	if (file.is_open())
	{
		while (!file.eof())
		{
			string us;
			getline(file, us);
			int f = 0;
			for (int i = 0; i < us.length(); i++)
			{
				if (us[i] != '#' && f == 0)
					name += us[i];
				else if (us[i] != '#' && f == 1)
					pas += us[i];
				else
					f++;
			}
		}
		
		if (name == us && pas == pass)
		{
			system("cls");		
		}
		else
		{
			cout << "Invalid Username or Password\n";
			cout << "Try Again...\n";
			system("pause");
			system("cls");
			RegisterMenu();
		}
	}
	file.close();
}

void RegisterMenu() {
	User u1;
	system("cls");
	system("color e");
	cout << "\n\n\n" << setw(60) << "******** RESTAURANT ********"
		<< "\n\n\n" << setw(50) << "1. Sign In"
		"\n" << setw(51) << "2. Sign Up\n\n";	
	//if (i == 2)
	//{
	//	system("cls");
	//	cout << "Username: ";
	//	cin >> u1.username;
	//	cout << "Password: ";
	//	char p = ' ';
	Choice();
	//	while (true)
	//	{
	//		p = _getch();
	//		if (p == 13)
	//		{
	//			break;
	//		}
	//		else if (p == '\b') {
	//			u1.password.pop_back();
	//			cout << "\b";
	//		}
	//		else
	//		{
	//			u1.password.push_back(p);
	//			cout << "*";
	//		}

	//	}
	//	ofstream file("user.txt", ios::app);
	//	if (file.is_open())
	//	{
	//		file << u1.username << "#" << u1.password << endl;
	//	}
	//}

	//else if (i == 1) {
	//	system("cls");
	//	string u;
	//	cout << "Username: ";
	//	cin >> u;
	//	cout << "Password: ";
	//	string pass;
	//	char p = ' ';
	//	while (true)
	//	{
	//		p = _getch();
	//		if (p == 13)
	//		{
	//			break;
	//		}
	//		else if (p == '\b') {
	//			pass.pop_back();
	//			cout << "\b";
	//		}
	//		else
	//		{
	//			pass.push_back(p);
	//			cout << "*";
	//		}

	//	}
	//	string name, pas;
	//	ifstream file("user.txt");
	//	if (file.is_open()) {
	//		while (!file.eof())
	//		{
	//			
	//			string us;
	//			getline(file, us);
	//			int f = 0;
	//			for (int i = 0; i < us.length(); i++)
	//			{
	//				if (us[i] != '#' && f == 0)
	//					name += us[i];
	//				else if (us[i] != '#' && f == 1)
	//					pas += us[i];
	//				else
	//					f++;
	//			}

	//			if (u1.password == pas && u1.username == name)
	//			{
	//				"Menu->";
	//			}
	//			else
	//			{
	//				cout << "Invalid Username or Password";
	//			}
	//		}

	//	}
	//}
}
void Choice() {
	int i = 0;
	cout << "Choose-> ";
	cin >> i;

	if (i == 2)
	{
		SignUp();

	}
	else if (i == 1) {
		SignIn();
		Menu();
	}
	else
	{
		cout << "\nInvalid choice! "; 
		system("pause");	
		RegisterMenu();
	}
}
int AddSebet() {
	system("color 6");
	cout << "1. Sebete Elave Et" << " || " << "2. Geri Qayit" << endl;
	int ch;
	cin >> ch;
	return ch;
}
void Menu() {
	static int s=0;
	system("color 6");
	cout << "\n\n\n" << setw(75) << "Sebet: "<<s;
	cout << "\n\n\n" << setw(55) << "---Menu---\n";
	vector <RecipetItem*> ing;
	ing.push_back(new RecipetItem(new Spices("pul biber", 10, 10, 10, 10), 3));
	ing.push_back(new RecipetItem(new Tomatoes("pomidor", 110, 20, 35, 20), 5));
	ing.push_back(new RecipetItem(new Meat("dana eti", 13, 45, 10, 22), 2));

	Dish* dolma = new Dolma(ing, "Dolma", 8);
	dolma->show();
	vector <RecipetItem*> ing1;
	ing1.push_back(new RecipetItem(new Spices("pul biber", 10, 15, 13, 20), 5));
	ing1.push_back(new RecipetItem(new Tomatoes("pomidor", 24, 20, 35, 26), 2));
	ing1.push_back(new RecipetItem(new Meat("dana eti", 13, 45, 10, 34), 2));
	ing1.push_back(new RecipetItem(new Cheese("mozarella pendiri", 13, 45, 10, 24), 4));

	Dish* pizza = new Pizza(ing1, "Pepperoni Pizza", 15);
	pizza->show();

	vector <RecipetItem*> ing2;
	ing2.push_back(new RecipetItem(new Spices("pul biber", 10, 15, 13, 20), 5));
	ing2.push_back(new RecipetItem(new Onion("sogan", 15, 25, 23, 13), 4));
	ing2.push_back(new RecipetItem(new Meat("quzu eti", 15, 38, 16, 34), 3));
	ing2.push_back(new RecipetItem(new Meat("quyruq", 25, 15, 3, 16), 2));


	Dish* kabab = new Kabab(ing2, "Lule kabab", 13);
	kabab->show();

	vector <RecipetItem*> ing3;
	ing3.push_back(new RecipetItem(new Spices("istiot", 10, 15, 13, 20), 5));
	ing3.push_back(new RecipetItem(new Onion("sogan", 15, 25, 23, 13), 4));
	ing3.push_back(new RecipetItem(new Meat("dana eti", 15, 38, 16, 34), 3));
	ing3.push_back(new RecipetItem(new Egg("yumurta", 15, 38, 16, 34), 2));

	Dish* xengel = new Xengel(ing3, "Gurcu xengeli", 14);
	xengel->show();

	cout << "\n" << setw(35) << "1-4 Yemek sec, 0-Sebet, Basqa duyme-Geri";
	char c;
	cout <<"\n"<<setw(20)<< "Choose->";
	cin >> c;
	vector<Dish*>sebet; 
	if (c=='1')
	{
		dolma->printRecipe();
		int a = AddSebet();
		if (a == 1)
		{
			sebet.push_back(dolma); system("cls");
			s++;
			Menu();
		}
		else if (a == 2) { system("cls"); Menu(); }
	}
	else if (c=='2')
	{
		pizza->printRecipe();
		int p = AddSebet();
		if (p == 1)
		{
			sebet.push_back(pizza); system("cls");
			s++;
			Menu();
		}
		else if(p == 2) { system("cls"); Menu(); }
	}
	else if (c=='3')
	{
		kabab->printRecipe();
		int k = AddSebet();
		if (k == 1)
		{
			sebet.push_back(kabab); system("cls");
			s++;
			Menu();
		}
		else if (k == 2) { system("cls"); Menu(); }
	}
	else if (c=='4')
	{
		xengel->printRecipe();
		int x = AddSebet();
		if (x == 1)
		{
			sebet.push_back(xengel); system("cls");
			s++;
			Menu();
		}
		else if (x == 2) { system("cls"); Menu(); }
	}
	else if (c=='0')
	{
		for (int i = 0; i < sebet.size(); i++)
		{
			sebet[i]->show();
		}

		system("cls");
		Menu();
	}
	else
	{
		RegisterMenu();
	}
}


void main() {
	RegisterMenu();
	
}