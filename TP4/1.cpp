#include <iostream>
using namespace std;

class Universal
{
public:
	virtual void pull_in ();
	virtual void pull_of ();
	virtual double view_balance ();
};

class Saving_Account: public Universal
{
private:
	double balance;
public:
	virtual void pull_in (int in)
	{
		balance += in;
	}
	virtual void pull_of (int out)
	{
		if (out <= balance)
			balance -= out;
		else
			cout << "Eror";
	}
	virtual double view_balance ()
	{
		return balance;
	}

};

class Timed_Maturity_Account: public Universal
{
private:
	double balance;
public:
	virtual void pull_in (int in)
	{
		balance += in;
	}
	virtual void pull_of (int out)
	{
		if (out <= (balance - (balance * 0.05)))
			{
				balance -= (out * 1.05) ;
				cout<<" Sorry Fine = 5% ";
		    }
		else
			cout << "Eror";
	}
	virtual double view_balance ()
	{
		return balance;
	}

};

class Checking_Account: public Universal
{
private:
	double balance;
public:
	virtual void pull_in (int in)
	{
		balance += in;
	}
	virtual void pull_of (int out, int n)
	{
		if (out <= balance)
			{
				balance -= out;
				if( n >= 5)
					balance -= 1;
		}
		else
			cout << "Eror";
	}
	virtual double view_balance ()
	{
		return balance;
	}

};

class Overdraft_Account: public Universal
{
private:
	double balance;
public:
	virtual void pull_in (int in)
	{
		balance += in;
	}
	virtual void pull_of (int out, int n)
	{
			if ((balance < 0) && ( n >= 1 ))
				balance -= ( balance * 0.2 );
			balance -= out;

	}
	virtual double view_balance ()
	{
		return balance;
	}

};

int main()
{
	Universal *universals[5];

	
	int i = 0;
	int y = 0;
	int type = 0; 
	for (i = 0; i < 5 ; i++)
	{
		cout << " Enter the account information: " << endl;
		cout << " Account number: " << i+1 << endl;
		cout << " Account type: " << endl;
		cout << " 1.Saving_Account " << endl << "2.Timed_Maturity_Account" << endl << "3.Checking_Account" << endl << "4.Overdraft_Account" << endl;
		cin >> type;

		if ( (type < 1) || (type > 5))
			cout << "Eror";
		if (type = 1)
			universals[i] = new Saving_Account;
		if (type = 2)
			universals[i] = new Timed_Maturity_Account;
		if (type = 3)
			universals[i] = new Checking_Account;
		if (type = 4)
			universals[i] = new Overdraft_Account;

		cout << "Do you want create enother one account?" << endl;
		cout << "1.YES" << endl << "2.NO" << endl;
		cin >> y;
		if (y == 2)
			break;
	}

	return 0;
}