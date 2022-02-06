//Christopher Flint 2110 Exam 2 Keathly
#include <iostream>
#include <vector>
using namespace std;

class HashLinear
{
	public:
		void Insert(int);
		int Search(int);
		void Delete(int);
		void Print();
		int HashFunc(int);
		void Resize(int);	
		
	protected:
		vector<int> hash;
};

int HashLinear::HashFunc(int key){return key%hash.size();}

void HashLinear::Resize(int size)
{
	hash.resize(size);
	for(int i = 0; i < hash.size(); i++)	//initially fill with -1 b/c i dont know how else to make it work
	{
		hash.at(i) = -1;
	}
}

void HashLinear::Insert(int num)
{
	int pos = HashFunc(num);	
	int probed = 0;
	
	while(probed < hash.size())
	{
		if(hash.at(pos) == -1)
		{
			hash.at(pos) = num;
			return;
		}
		else if(hash.at(pos) == -2)
		{
			hash.at(pos) = num;
			return;
		}
		pos = (pos+1)%5;
		probed++;
	}
	
}
// this is really old code

void HashLinear::Print()
{
	cout << endl << "Hash table: ";
	for(int i = 0; i < hash.size(); i++)
	{
		if(hash.at(i) == -2)
			cout << "<-> ";

		else if(hash.at(i) == -1)
			cout << "_ ";
		else	
			cout << hash.at(i) << " ";
	}
	cout << endl;
}

int HashLinear::Search(int num)
{
	for(int i = 0; i < hash.size(); i++)
	{
		if(hash.at(i) == num)
		{
			cout << "First instance of value exists in position " << i << endl;
			return i;
		}
	}
	cout << "Does not exist" << endl;
	return -1;
}

void HashLinear::Delete(int num)
{
	int pos = Search(num);
	if(pos == -1)
		return;
	
	hash.at(pos) = -2;
	cout << "Deleted" << endl;
}

int main()
{
	int tablesize = 0;
	cout << "Beginning Simulation" << endl;
	cout << "Please enter table size" << endl;
	cin >> tablesize;
	HashLinear Table;
	Table.Resize(tablesize);
	int number = 0;
	int menu = 0;
	
	do
	{
		cout << endl << "Menu" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Print" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter integer value for one menu option: ";
		cin >> menu;
		
		if(menu < 0 || menu > 4)
			cout << "Invalid, please enter between 0 and 4!" << endl;
	
		switch(menu)
		{
			case 1:
				cout << endl;
				cout << "Enter value:";
				cin >> number;
				cout << endl << "Inserting" << endl;
				Table.Insert(number);
				break;
			case 2:
				cout << endl;
				cout << "Enter value: ";
				cin >> number;
				cout << "Searching..." << endl;
				Table.Search(number);
				break;
			case 3:
				cout << endl;
				cout << "Enter value: ";
				cin >> number;
				cout << "Deleting" << endl;
				Table.Delete(number);
				break;
			case 4:
				cout << endl;
				cout << "Printing hash table...";
				Table.Print();
				break;
		}
	}while(menu != 0);
	
	return 0;
}
