#include <iostream>
#include <stack>
#include <queue>
#include <conio.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Data
{
	int accNum;
	string f_name;
	string l_name;
	string city;
	string state;
	int zip;
	long long int telephone;
	int bal;
};

Data input()
{
	Data d1;
	cout << "Enter First Name: ";
	cin >> d1.f_name;
	cout << "Enter Last Name: ";
	cin >> d1.l_name;
	cout << "Enter your city: ";
	cin >> d1.city;
	cout << "Enter your state: ";
	cin >> d1.state;
label1:
	cout << "Enter your zip code: ";
	cin >> d1.zip;
	int n = 1;
	while (n)
	{
		if (!cin >> d1.zip)
		{
			cout << "Please enter a valid input.\n";
			cin.clear();
			cin.ignore(123, '\n');
			goto label1;

		}
		n = 0;
	}
label2:
	cout << "Enter your contact: ";
	cin >> d1.telephone;
	n = 1;
	while (n)
	{
		if (!cin >> d1.telephone)
		{
			cout << "Please enter a valid input.\n";
			cin.clear();
			cin.ignore(123, '\n');
			goto label2;

		}
		n = 0;
	}
	d1.bal = 0;
	srand(time(NULL));
	d1.accNum = rand();
	cout << "Your Account number is " << d1.accNum << " and your balance is " << d1.bal << endl << endl;
	return d1;
}

class node
{
public:
	Data data;
	node* next = NULL;
};

class L_List
{
public:
	node* head;

	L_List()
	{
		head = NULL;
	}

	int insert(Data data)
	{
		node* newNode = new node;
		newNode->data = data;
		int result = empty();
		if (result == 1)
		{
			head = newNode;
			return 1;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	int del(int accNum)
	{
		node* prev = NULL;
		node* curr = head;
		while (curr != NULL && curr->data.accNum != accNum)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != NULL)
		{
			if (prev != NULL)
			{
				prev->next = curr->next;
				delete curr;
				return 1;
			}
			else
			{
				head = curr->next;
				delete curr;
				return 1;
			}
			return 0;
		}
	}

	bool empty()
	{
		{
			if (head == NULL)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
};

class admin
{
public:
	admin()
	{
		cout << "Select any option according to your demand.\n";
		cout << "1. Add an account\n";
		cout << "2. Search an account\n";
		cout << "3. Update an account\n";
		cout << "4. Remove an account\n";
		cout << "5. View all record\n";
		cout << "6.Exit\n";
	}

	int add(queue<Data>& q1, L_List& l1)
	{
		Data d2 = input();
		l1.insert(d2);
		q1.push(d2);
		return 0;
	}

	int search(queue<Data>& q1, int accNum)
	{
		queue<Data> q2;
		bool flag = 0;
		while (!q1.empty())
		{
			if (q1.front().accNum == accNum)
			{
				cout << setw(20) << left << "Account Number" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "City";
				cout << setw(15) << left << "State" << setw(10) << left << "Zip" << setw(15) << "Telephone" << setw(10) << "Balance";
				cout << left << "\n\n";
				cout << setw(20) << left << q1.front().accNum << setw(15) << q1.front().f_name << setw(15) << q1.front().l_name;
				cout << setw(15) << left << q1.front().city << setw(15) << q1.front().state << setw(10) << q1.front().zip << setw(15) << q1.front().telephone;
				cout << setw(10) << left << q1.front().bal << endl;
				flag = 1;
			}
			q2.push(q1.front());
			q1.pop();
		}
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		if (flag == 0)
		{
			cout << "Account not Found.\n";
		}
		return 0;
	}

	int update(L_List& l1, int accNum)
	{
		node* temp = l1.head;
		bool flag = 0;
		while (temp != NULL)
		{
			if (temp->data.accNum == accNum)
			{
				flag = 1;
			label1:
				cout << "Which one do you want to update.\n";
				cout << "1. First Name\n";
				cout << "2. Last Name\n";
				cout << "3. City\n";
				cout << "4. State\n";
				cout << "5. Zip code\n";
				cout << "6. Contact\n";
				int select;
				cout << "Select one: ";
				cin >> select;
				if (select == 1)
				{
					cout << "Enter first Name: ";
					cin >> temp->data.f_name;
					cout << "Your account is updated successfully.\n";
				}
				else if (select == 2)
				{
					cout << "Enter last Name: ";
					cin >> temp->data.l_name;
					cout << "Your account is updated successfully.\n";
				}
				else if (select == 3)
				{
					cout << "Enter City: ";
					cin >> temp->data.city;
					cout << "Your account is updated successfully.\n";
				}
				else if (select == 4)
				{
					cout << "Enter State: ";
					cin >> temp->data.state;
					cout << "Your account is updated successfully.\n";
				}
				else if (select == 5)
				{
					cout << "Enter zip code: ";
					cin >> temp->data.zip;
					cout << "Your account is updated successfully.\n";
				}
				else if (select == 6)
				{
					cout << "Enter contact: ";
					cin >> temp->data.telephone;
					cout << "Your account is updated successfully.\n";
				}
				else
				{
					cout << "Invalid input.\n";
					char choice;
				label:
					cout << "Do you want to enter again(y/n): ";
					cin >> choice;
					if (choice == 'y' || choice == 'Y')
					{
						goto label1;
					}
					else if (choice == 'n' || choice == 'N')
					{

					}
					else
					{
						cout << "Invalid Input.\n";
						goto label;
					}
				}
				char choice;
			label2:
				cout << "do you want to update more: ";
				cin >> choice;
				if (choice == 'y' || choice == 'Y')
				{
					goto label1;
				}
				else if (choice == 'n' || choice == 'N')
				{

				}
				else
				{
					cout << "Invalid Input.\n";
					goto label2;
				}
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "No account found.\n";
		}
		return 0;
	}

	int remove(L_List& l1, int accNum)
	{
		node* temp = l1.head;
		bool flag = 0;
		while (temp != NULL)
		{
			if (temp->data.accNum == accNum)
			{
				flag = 1;
				break;
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "No Account found.\n";
		}
		else
		{
			l1.del(accNum);
		}
		return 0;
	}

	int all(L_List& l1)
	{
		node* temp = l1.head;
		bool flag = 0;
		cout << setw(20) << left << "Account Number" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "City";
		cout << setw(15) << left << "State" << setw(10) << left << "Zip" << setw(15) << "Telephone" << setw(10) << "Balance";
		cout << left << "\n\n";
		while (temp != NULL)
		{
			flag = 1;
			cout << setw(20) << left << temp->data.accNum << setw(15) << temp->data.f_name << setw(15) << temp->data.l_name;
			cout << setw(15) << left << temp->data.city << setw(15) << temp->data.state << setw(10) << temp->data.zip << setw(15) << temp->data.telephone;
			cout << setw(10) << left << temp->data.bal << endl;
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "No any account data available.\n";
		}
		return 0;
	}

};

class accountHolder
{
public:
	accountHolder()
	{
		cout << "Select any option according to your demand.\n";
		cout << "1. View Account\n";
		cout << "2. View current balance\n";
		cout << "3. Deposit money\n";
		cout << "4. Withdraw money\n";
		cout << "5. Transfer money\n";
		cout << "6. Pay utility bills and fee\n";
		cout << "7. Bank Statement\n";
		cout << "8. Exit\n";
	}

	bool viewAccount(queue<Data>& q1, int accNum)
	{
		queue<Data> q2;
		bool flag = 0;
		while (!q1.empty())
		{
			if (q1.front().accNum == accNum)
			{
				cout << setw(20) << left << "Account Number" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "City";
				cout << setw(15) << left << "State" << setw(10) << left << "Zip" << setw(15) << "Telephone" << setw(10) << "Balance";
				cout << left << "\n\n";
				cout << setw(20) << left << q1.front().accNum << setw(15) << q1.front().f_name << setw(15) << q1.front().l_name;
				cout << setw(15) << left << q1.front().city << setw(15) << q1.front().state << setw(10) << q1.front().zip << setw(15) << q1.front().telephone;
				cout << setw(10) << left << q1.front().bal << endl;
				flag = 1;
			}
			q2.push(q1.front());
			q1.pop();
		}
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		if (flag == 0)
		{
			cout << "Account not Found.\n";
		}
		return 0;
	}
	int balance(L_List& l1, int accNum)
	{
		node* temp = l1.head;
		bool flag = 0;
		while (temp != NULL)
		{
			if (temp->data.accNum == accNum)
			{
				cout << "Your current balance is " << temp->data.bal << endl;
				flag = 1;
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "No accoount found.\n";
		}
		return 0;
	}
	int deposit(stack<string>& s1, queue<Data>& q1, L_List& l1, int accNum)
	{
		queue<Data> q2;
		node* temp = l1.head;
		int amount;
		bool flag = 0;
		string str = "";
		while (temp != NULL)
		{
			if (temp->data.accNum == accNum)
			{

				cout << "Please enter the amount which you want to deposit: ";
				cin >> amount;
				temp->data.bal += amount;
				while (!q1.empty())
				{
					if (q1.front().accNum == accNum)
					{
						q1.front().bal = temp->data.bal;
					}
					q2.push(q1.front());
					q1.pop();
				}
				while (!q2.empty())
				{
					q1.push(q2.front());
					q2.pop();
				}
				cout << "The amount is deposited successfully.\n";
				str += to_string(amount);
				str += " is deposited to account number ";
				str += to_string(accNum);
				str += " ";
				s1.push(str);
				flag = 1;
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "No accoount found.\n";
		}
		return 0;
	}
	int withdraw(stack<string>& s1, queue<Data>& q1, L_List& l1, int accNum)
	{
		queue<Data> q2;
		node* temp = l1.head;
		int amount;
		string str = "";
		bool flag = 0;
		while (temp != NULL)
		{
			if (temp->data.accNum == accNum)
			{
				cout << "Please enter the amount which you want to withdraw: ";
				cin >> amount;
				if (amount > temp->data.bal)
				{
					cout << "Your balance is insufficent for this transaction.\n";
					return 0;
				}
				temp->data.bal -= amount;
				while (!q1.empty())
				{
					if (q1.front().accNum == accNum)
					{
						q1.front().bal = temp->data.bal;
					}
					q2.push(q1.front());
					q1.pop();
				}
				while (!q2.empty())
				{
					q1.push(q2.front());
					q2.pop();
				}
				cout << "Your amount has been withdrawn successfully.\n";
				str += to_string(amount);
				str += " has been withdrawn from account number ";
				str += to_string(accNum);
				str = " ";
				s1.push(str);
				flag = 1;
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "No accoount found.\n";
		}
		return 0;
	}
	int transfer(stack<string>& s1, queue<Data>& q1, L_List& l1, int from, int to)
	{
		queue<Data> q2;
		node* temp = l1.head;
		node* temp1 = l1.head;
		int amount;
		string str = "";
		bool flag = 0;
		while (temp != NULL)
		{
			if (temp->data.accNum == from)
			{
				while (temp1 != NULL)
				{
					if (temp1->data.accNum == to)
					{
						cout << "Please enter the amount which you want to transfer: ";
						cin >> amount;
						if (amount < temp->data.bal)
						{
							temp->data.bal -= amount;
							temp1->data.bal += amount;
							cout << "Your amount is transferred successfully.\n";
							while (!q1.empty())
							{
								if (q1.front().accNum == to)
								{
									q1.front().bal = temp1->data.bal;
								}
								if (q1.front().accNum == from)
								{
									q1.front().bal = temp->data.bal;
								}
								q2.push(q1.front());
								q1.pop();
							}
							while (!q2.empty())
							{
								q1.push(q2.front());
								q2.pop();
							}
							str += to_string(amount);
							str += " is transferred from account number ";
							str += to_string(from);
							str += " to account number ";
							str += to_string(to);
							str += " ";
							s1.push(str);
							flag = 1;
						}
						else
						{
							cout << "Enter amount don't have sufficient balance.\n";
						}
					}
					temp1 = temp1->next;
				}
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "No accoount found.\n";
		}
		return 0;
	}
	int bills(stack<string>& s1, queue<Data>& q1, L_List& l1, int accNum)
	{
		int choice;
		int amount;
		queue<Data> q2;
		node* temp = l1.head;
		string str;
		bool flag = 0;
	l:
		cout << "Select the Bill.\n";
		cout << "1. Electricity\n";
		cout << "2. Gas\n";
		cout << "3. Waterr\n";
		cout << "Select anyone.\n";
		cin >> choice;
		if (choice < 1 && choice>3)
		{
			cout << "Invalid Input.\n";
			goto l;
		}
		while (temp != NULL)
		{
			if (temp->data.accNum == accNum)
			{
				cout << "Please enter the amount of bill: ";
				cin >> amount;
				if (amount > temp->data.bal)
				{
					cout << "Your balance is insufficent for this transaction.\n";
					return 0;
				}
				temp->data.bal -= amount;
				cout << "Your bill is paid successfully.\n";
				while (!q1.empty())
				{
					if (q1.front().accNum == accNum)
					{
						q1.front().bal = temp->data.bal;
					}
					q2.push(q1.front());
					q1.pop();
				}
				while (!q2.empty())
				{
					q1.push(q2.front());
					q2.pop();
				}
				str += to_string(amount);
				str += " is detucted to pay bill from account number ";
				str += to_string(accNum);
				str += " ";
				s1.push(str);
				flag = 1;
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "No accoount found.\n";
		}
		return 0;
	}
	void bankStatement(stack<string>& s1, int accNum)
	{
		stack<string> s2;
		string str1[20];
		while (!s1.empty())
		{
			int k = 0;
			int i;
			int l = 0;
			string st = s1.top();
			int length = st.length();
			for (int j = 0, m = 0; j < length && (m < length); j++, m++)
			{
				i = k;

				for (i; s1.top()[i] != ' '; i++)
				{
					str1[j] += s1.top()[i];
					k = i;
				}
				m = i;
				k += 2;
			}
			for (int i = 0; i <= k; i++)
			{
				if (str1[i] == to_string(accNum))
				{
					cout << s1.top() << endl;
					s2.push(s1.top());
					s1.pop();
					break;
				}
			}
			for (int i = 0; i < 20; i++)
			{
				str1[i] = "";
			}
		}
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return;
	}
};

int main()
{
	L_List l1;
	stack<string> s1;
	queue<Data> q1;
	int choice[2];
label1:
l:
	cout << "\t\t\t\tWelcome to UET Bank.ltd\n\n";
	cout << "Who are you?\n1.Bank Worker\n2.Account Holder\n3.Exit\n";
	cin >> choice[0];
	int n = 1;
	while (n)
	{
		if (!cin >> choice[0])
		{
			cout << "Please enter a valid input.\n";
			cin.clear();
			cin.ignore(123, '\n');
			system("cls");
			goto l;
		}
		n = 0;
	}
	if (*choice == 1)
	{
	label2:
		admin obj1;
		cin >> 1[choice];
		if (*(choice + 1) == 1)
		{
			obj1.add(q1, l1);
		}
		else if (*(choice + 1) == 2)
		{
			int accNum;
		l1:
			cout << "Enter account Number: ";
			cin >> accNum;
			int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l1;

				}
				n = 0;
			}
			obj1.search(q1, accNum);
		}
		else if (*(choice + 1) == 3)
		{
			int accNum;
		l2:
			cout << "Enter account Number: ";
			cin >> accNum;
			int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l2;

				}
				n = 0;
			}
			obj1.update(l1, accNum);
		}
		else if (*(choice + 1) == 4)
		{
			int accNum;
		l3:
			cout << "Enter account Number: ";
			cin >> accNum;
			int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l3;

				}
				n = 0;
			}
			obj1.remove(l1, accNum);
		}
		else if (*(choice + 1) == 5)
		{
			obj1.all(l1);
		}
		else if (*(choice + 1) == 6)
		{
			system("cls");
			goto label1;
		}
		else
		{
			cout << "\t\tInvalid Input\n";
			cout << "\t\tEnter again\n";
			system("pause");
			system("cls");
			goto label2;
		}
		system("pause");
		system("cls");
	}

	else if (*choice == 2)
	{
	label3:
		accountHolder obj1;
		cin >> 1[choice];
		if (*(choice + 1) == 1)
		{
			int accNum;
		l5:
			cout << "Enter account Number: ";
			cin >> accNum;
			int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l5;

				}
				n = 0;
			}
			obj1.viewAccount(q1, accNum);
		}
		else if (*(choice + 1) == 2)
		{
			int accNum;
		l6:
			cout << "Enter account Number: ";
			cin >> accNum;
			int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l6;

				}
				n = 0;
			}
			obj1.balance(l1, accNum);
		}
		else if (*(choice + 1) == 3)
		{
			int accNum;
		l7:
			cout << "Enter account Number: ";
			cin >> accNum; int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l7;

				}
				n = 0;
			}
			obj1.deposit(s1, q1, l1, accNum);
		}
		else if (*(choice + 1) == 4)
		{
			int accNum;
		l8:
			cout << "Enter account Number: ";
			cin >> accNum;
			int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l8;

				}
				n = 0;
			}
			obj1.withdraw(s1, q1, l1, accNum);
		}
		else if (*(choice + 1) == 5)
		{
			int from, to;
		l9:
			cout << "Enter the account from where you want to transfer: ";
			cin >> from;
			int n = 1;
			while (n)
			{
				if (!cin >> from)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l9;

				}
				n = 0;
			}
		l10:
			cout << "Enter the account where you wantto transfer: ";
			cin >> to;
			n = 1;
			while (n)
			{
				if (!cin >> to)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l10;

				}
				n = 0;
			}
			obj1.transfer(s1, q1, l1, from, to);
		}
		else if (*(choice + 1) == 6)
		{
			int accNum;
		l11:
			cout << "Enter account Number: ";
			cin >> accNum;
			int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l11;

				}
				n = 0;
			}
			obj1.bills(s1, q1, l1, accNum);
		}
		else if (*(choice + 1) == 7)
		{
			int accNum;
		l12:
			cout << "Enter account Number: ";
			cin >> accNum;
			int n = 1;
			while (n)
			{
				if (!cin >> accNum)
				{
					cout << "Please enter a valid input.\n";
					cin.clear();
					cin.ignore(123, '\n');
					goto l12;

				}
				n = 0;
			}
			obj1.bankStatement(s1, accNum);
		}
		else if (*(choice + 1) == 8)
		{
			system("cls");
			goto label1;
		}
		else
		{
			cout << "\t\tInvalid Input\n";
			cout << "\t\tEnter again\n";
			system("pause");
			system("cls");
			goto label3;
		}
		system("pause");
		system("cls");
	}
	else if (*choice == 3)
	{
		exit(1);
	}
	else
	{
		cout << "\t\tInvalid input\n";
		system("pause");
		system("cls");
	}
	goto label1;
	return 0;
}