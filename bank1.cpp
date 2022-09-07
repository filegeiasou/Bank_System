#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;
int sum;
string username;
void valid(string str)
{
	string filename1, usr;
	ifstream file3;
	filename1 = str + ".txt";
	file3.open(filename1.c_str());
	if (!file3.is_open() && file3.fail())
	{
		//cout << "\nYou are not registered, please register before logging in.\n";
		//file1.close();
		return;
	}
	else
	{
		sum++;
		if (sum == 3)
		{
			cout << "\nThis username already exists\nPlease try Again.";
			//file.close();
			return;
		}
		cout << "\nThis username already exists!\nCreate a username:";
		cin >> username;
		//file.close();
		valid(username);
	}

}



string addStrings(string num1, string num2) {

	string result;

	int indexOne = num1.length() - 1;
	int indexTwo = num2.length() - 1;
	int carry = 0;

	while (indexOne >= 0 || indexTwo >= 0 || carry) {
		int current = carry;

		if (indexOne >= 0) {
			current += num1[indexOne] - '0';
		}

		if (indexTwo >= 0) {
			current += num2[indexTwo] - '0';
		}

		carry = current / 10;
		current = current % 10;

		result = (char)(current + '0') + result;

		indexOne--;
		indexTwo--;
	}

	return result;

}

int main()
{
	cout << "\t\t\t\t\t Welcome to filebank " << endl;
	int w = 0, ep, exit = 0, money1, money, money2=0, money3 , carno1 , money4 , money5;
	string usr, password, pass, filename, name, surname, name1, surname1, carno, username1,carno2 , filename1;
	ifstream file1 , file3;
	ofstream file2 , file4;
	stringstream ss;
	ss << money2;
	string s;
	ss >> s;
	while (exit == 0)
	{
		cout << "\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n3. Withdraw(press 3 to select this)\n4. Deposit(press 4 to select this)\n5. Deposit to other account(press 5 to select)\n6. Exit(press 6 to select this)\n";
		cin >> ep;
		if (ep == 1)
		{
			cout << "Give your username" << endl;
			cin >> username;
			cout << "Give your password" << endl;
			cin >> password;
			filename = username + ".txt";
			file1.open(filename.c_str());
			if (!file1.is_open() && file1.fail())
			{
				cout << "\nYou are not registered, please register before logging in.\n";
				file1.close();
				continue;
			}
			getline(file1, usr);
			getline(file1, pass);
			getline(file1, s);
			getline(file1, name1);
			getline(file1, surname1);
			getline(file1, carno);
			if (username == usr && password == pass)
			{
				cout << "\t\t\t\t\t Account details :" << endl;
				cout << "Username: " << username << endl;
				cout << "Password: " << password << endl;
				cout << "Name: " << name1 << endl;
				cout << "Surname: " << surname1 << endl;
				cout << "Money : " << s << endl;
				cout << "Card Number : " << carno << endl;
				file1.close();
			}
			else {
				cout << "\nWrong username or password!\nPlease try Again.\n";
			}
			cout << endl;

		}
		else if (ep == 2)
		{
			cout << "Give your name" << endl;
			cin.ignore();
			getline(cin, name);
			cout << "Give your surname" << endl;
			getline(cin, surname);
			cout << "Give your username" << endl;
			cin >> username;
			valid(username);
			cout << "Give your password" << endl;
			cin >> password;
			srand((unsigned)time(NULL));
			int random = rand() % 1001;
			if (sum < 3)
			{
				filename = username + ".txt";
				file2.open(filename.c_str());
				money = 0;
				file2 << username << endl << password << endl << money << endl << name << endl << surname << endl <<  random << endl;
				cout << "\nYou are successfully registered:)";
				file2.close();
			}
		}
		else if (ep == 3)
		{
			cout << "Give your username" << endl;
			cin >> username;
			cout << "Give your password" << endl;
			cin >> password;
			filename = username + ".txt";
			file1.open(filename.c_str());
			if (!file1.is_open() && file1.fail())
			{
				cout << "\nYou are not registered, please register before logging in.\n";
				file1.close();
				continue;
			}
			getline(file1, usr);
			getline(file1, pass);
			getline(file1, s);
			getline(file1, name1);
			getline(file1, surname1);
			if (username == usr && password == pass)
			{
				money3 = stoi(s);
				if (money3 > 0)
				{
					cout << "How much money do you want to withdraw : " << endl;
					cin >> money1;
					int sum3 = money3 - money1;
					stringstream ss1;
					ss1 << sum3;
					string s2;
					ss1 >> s2;

					file2.open(filename.c_str());
					if (money3 - money1 >= 0)
					{
						file2 << username << endl << password << endl << s2 << endl << name1 << endl << surname1 << endl;
						file2.close();
					}
					else
					{
						cout << "You dont have enough money to withdraw" << endl;
					}
				}
				else
				{
					cout << "You dont have money to withdraw" << endl;
				}
				file1.close();
			}
			else {
				cout << "\nWrong username or password!\nPlease try Again.\n";
			}
			cout << endl;
		}
		else if (ep == 4)
		{
			cout << "Give your username" << endl;
			cin >> username;
			cout << "Give your password" << endl;
			cin >> password;
			filename = username + ".txt";
			file1.open(filename.c_str());
			if (!file1.is_open() && file1.fail())
			{
				cout << "\nYou are not registered, please register before logging in.\n";
				file1.close();
				continue;
			}
			getline(file1, usr);
			getline(file1, pass);
			getline(file1, s);
			getline(file1, name1);
			getline(file1, surname1);
			if (username == usr && password == pass)
			{
				cout << "How much money do you want to deposit : " << endl;
				cin >> money1;
				file2.open(filename.c_str());
				stringstream ss1;
				ss1 << money1;
				string s1;
				ss1 >> s1;
				string sum1 = addStrings(s, s1);
				file2 << username << endl << password << endl << sum1 << endl << name1 << endl << surname1 << endl;
				file2.close();
				file1.close();
			}
			else {
				cout << "\nWrong username or password!\nPlease try Again.\n";
			}
			cout << endl;
		}
		else if (ep == 5)
		{
		cout << "Give your username" << endl;
		cin >> username;
		cout << "Give your password" << endl;
		cin >> password;
		filename = username + ".txt";
		file1.open(filename.c_str());
		if (!file1.is_open() && file1.fail())
		{
			cout << "\nYou are not registered, please register before logging in.\n";
			file1.close();
			continue;
		}
		getline(file1, usr);
		getline(file1, pass);
		getline(file1, s);
		getline(file1, name1);
		getline(file1, surname1);
		getline(file1, carno);
		if (username == usr && password == pass)
		{
			cout << "Give username of account you want to deposit" << endl;
			cin >> username1;
			cout << "Give account number to deposit: " << endl;
			cin >> carno1;
			cout << "How much money do you want to deposit to other account : " << endl;
			cin >> money5;
			money3 = stoi(s);
			int sum3 = money3 - money5;
			stringstream ss3;
			ss3 << sum3;
			string s2;
			ss3 >> s2;
			file2.open(filename.c_str());
			file2 << username << endl << password << endl << s2 << endl << name1 << endl << surname1 << endl << carno << endl;
			file2.close();
			file3.open((username1 + ".txt").c_str());
			getline(file3, usr);
			getline(file3, pass);
			getline(file3, s);
			getline(file3, name1);
			getline(file3, surname1);
			getline(file3, carno2);
			stringstream ss2;
			ss2 << carno1;
			string s3;
			ss2 >> s3;
			int k1 = money5;
			if (usr == username1 && s3 == carno2)
			{
				cout << "okey";
				file4.open((username1 + ".txt").c_str());
				stringstream ss4;
				ss4 << k1;
				string s5;
				ss4 >> s5;
				string sum5 = addStrings(s, s5);
				file4 << username1 << endl << pass << endl << sum5 << endl << name1 << endl << surname1 << endl << s3 << endl;
				file4.close();

			}
			file1.close();
			file3.close();

		}
		else {
			cout << "\nWrong username or password!\nPlease try Again.\n";
		}
		cout << endl;
		}
		else 
		{
			exit = 1;
		}
	}
	cout << "\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
}