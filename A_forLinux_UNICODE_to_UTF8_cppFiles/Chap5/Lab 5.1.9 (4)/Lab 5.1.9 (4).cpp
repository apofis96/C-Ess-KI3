// Lab 5.1.9 (4).cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>

using namespace std;


class ShopItemOrder
{
private:
	string name;
	double price;
	int amount;
public:
	ShopItemOrder(string name, double price, int amount);
	string get_name();
	double get_price();
	int get_amount();
	double get_totalPrice();
	void set_name(string name);
	void set_price(double price);
	void set_amount(int amount);
	void print();

};ShopItemOrder::ShopItemOrder(string name, double price, int amount){	this->name = name;	this->price = price;	this->amount = amount;}string ShopItemOrder::get_name(){	return name;}
double ShopItemOrder::get_price(){	return price;}

int ShopItemOrder::get_amount(){	return amount;}

double ShopItemOrder::get_totalPrice(){	return (price*amount);}

void ShopItemOrder::set_name(string name){	if (name != "")	{		this->name = name;	}}

void ShopItemOrder::set_price(double price){	if (price >=0)	{		this->price = price;	}}

void ShopItemOrder::set_amount(int amount){	if (amount >= 0)	{		this->amount = amount;	}}

void ShopItemOrder::print()
{
	cout << "Item name: " << name << "\nItem unit price: " << price << "\nNumber of items ordered: " << amount << "\nTotal price: " << get_totalPrice() << endl;
}

int main()
{
	ShopItemOrder kek("Ordername1", 9.99, 10);
	kek.set_name("Ordername2");
	kek.print();
    return 0;
}

