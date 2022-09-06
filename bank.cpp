#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std; 
int sum;
string username;
void valid(string str)
{
    string filename1 , usr ;
    ifstream file3;
    filename1 = str+".txt";
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
        if(sum==3)
        {
            cout<<"\nThis username already exists\nPlease try Again.";
            //file.close();
            return;
        }
        cout<<"\nThis username already exists!\nCreate a username:";
        cin>>username;
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
	int w = 0 , ep ,exit=0  , money1 , money , money2 ,money3 ;
	string usr, password, pass , filename , name , surname  , name1 , surname1;
	ifstream file1;
	ofstream file2;
    stringstream ss;  
    ss<<money2;  
    string s;  
    ss>>s;  
	while (exit == 0)
	{
        cout<<"\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n3. Withdraw(press 3 to select this)\n4. Deposit(press 4 to select this)\n5. Exit(press 5 to select this)\n";
	    cin>>ep;
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
			getline(file1,s);
			getline(file1, name1);
			getline(file1, surname1);
			if (username == usr && password == pass)
			{
				cout << "\t\t\t\t\t Account details :" << endl;
				cout << "Username: " << username << endl;
				cout << "Password: " << password << endl;
				cout << "Name: " << name1 << endl;
				cout << "Surname: " << surname1 << endl;
				cout << "Money : " << s << endl;
				file1.close();
			}
			else {
				cout << "\nWrong username or password!\nPlease try Again.\n";
			}
			cout << endl;

		}
		else if (ep == 2)
		{
		    cout<<"Give your name"<<endl;
            cin.ignore();
            getline(cin,name);
		    cout<<"Give your surname"<<endl;
            getline(cin,surname);
			cout << "Give your username" << endl;
			cin >> username;
			valid(username);
			cout << "Give your password" << endl;
			cin >> password;
			if (sum<3)
			{
    			filename = username + ".txt";
    			file2.open(filename.c_str());
    			money = 0;
    			file2 <<username<< endl << password <<endl <<  money << endl << name << endl << surname << endl;
    			cout << "\nYou are successfully registered:)";
    			file2.close();
			}
		}
		else if (ep==3)
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
			getline(file1,s);
			getline(file1, name1);
			getline(file1, surname1);
			if (username == usr && password == pass)
			{
			    money3 = stoi(s);
                if (money3>0)
                {
                    cout << "How much money do you want to withdraw : "<<endl;
                    cin >> money1;
                    int sum3 = money3-money1;
                    stringstream ss1;  
                    ss1<<sum3;  
                    string s2;  
                    ss1>>s2;

                    file2.open(filename.c_str());
                    if(money3-money1>=0)
                    {
    			        file2 <<username<< endl << password <<endl <<  s2 << endl << name1 << endl << surname1 << endl;
    			        file2.close();
                    }
                    else
                    {
                        cout<<"You dont have enough money to withdraw"<<endl;
                    }
                }
                else
                {
                    cout<<"You dont have money to withdraw"<<endl;
                }
				file1.close();
			}
			else {
				cout << "\nWrong username or password!\nPlease try Again.\n";
			}
			cout << endl;  
		}
		else if(ep == 4)
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
			getline(file1,s);
			getline(file1, name1);
			getline(file1, surname1);
			if (username == usr && password == pass)
			{
                cout << "How much money do you want to deposit : "<<endl;
                cin >> money1;
                file2.open(filename.c_str());
                stringstream ss1;  
                ss1<<money1;  
                string s1;  
                ss1>>s1;
                string sum1=addStrings(s,s1);
    			file2 <<username<< endl << password <<endl << sum1 << endl << name1 << endl << surname1 << endl;
    			file2.close();
				file1.close();
			}
			else {
				cout << "\nWrong username or password!\nPlease try Again.\n";
			}
			cout << endl; 
		}
		else if(ep == 5)
		{
			exit=1;
		}
	}
	cout << "\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
}