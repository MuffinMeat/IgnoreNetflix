

#include <iostream>
#include <vector>
using namespace std;

class Hash
{
	public:
		void Insert(int);
		bool Search(int);
		void Delete(int);
		void Print();
		int HashFunc(int);
		
	protected:
		vector<int> table[5];
};

int Hash::HashFunc(int key){return key%5;}

void Hash::Insert(int num)
{
	int pos = HashFunc(num);	
	table[pos].push_back(num);
}

void Hash::Print()
{
	cout << endl << "Hash table: " << endl;
	for(int i = 0; i < 5; i++)				//goes through array
	{
		cout << "Elements at index " << i << ": ";
		for(int j = 0; j < table[i].size(); j++)	//goes through vectors
		{
			cout << table[i].at(j) << " ";
		}
		cout << endl;
	}
}

bool Hash::Search(int num)
{
	int pos = HashFunc(num);
	for(int i = 0; i < table[pos].size(); i++)
	{
		if(table[pos].at(i) == num)		//goes through vector to look for element
		{
			cout << "Value exists in table" << endl;
			return true;
		}
	}
	cout << "Value does not exist in table" << endl;
	return false;
}

void Hash::Delete(int num)
{
	if(Search(num) == false)
		return;
	
	int pos = HashFunc(num);
	for(int i = 0; i < table[pos].size(); i++)
	{
		if(table[pos].at(i) == num)
		{
			table[pos].erase(table[pos].begin() + i);
		}
	}
}

int main()
{
	Hash Table;
	int value;
	int answer;
	
	do
	{
		cout << endl;
		cout << "Menu" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Output" << endl;
		cout << "0. Quit" << endl;
		cout << "Enter integer of menu option: ";
		cin >> answer;
		
		if(answer < 0 || answer > 4)
			cout << "Invalid menu option" << endl;
	
		switch(answer)
		{
			case 1:
				cout << endl;
				cout << "Enter value to insert: ";
				cin >> value;
				cout << endl << "Inserting..." << endl;
				Table.Insert(value);
				break;
			case 2:
				cout << endl;
				cout << "Enter value to search for: ";
				cin >> value;
				cout << "Searching..." << endl;
				Table.Search(value);
				break;
			case 3:
				cout << endl;
				cout << "Enter value to delete: ";
				cin >> value;
				cout << "Deleting..." << endl;
				Table.Delete(value);
				break;
			case 4:
				cout << endl;
				cout << "Outputting...";
				Table.Print();
				break;
		}
	}while(answer != 0);
	
	return 0;
}
