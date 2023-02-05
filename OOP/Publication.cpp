//https://github.com/Deshnashah27

#include<iostream>
#include<string.h>
using namespace std;

class publication
{
	protected:
	char name[25];
	float price;
	
	public:
	virtual void getdata()=0;
	virtual void display()=0;
	
};

class book:public virtual publication
{
	private:
	int pgcount;
	
	public:
	void getdata()
		{
		cout<<"\nEnter the Title of the Book: ";
		cin>>name;
		try
		{
			cout<<"Enter the Price of the Book: ";
			cin>>price;
			if (price>1000)
			{
				throw price;
			}
		}
		catch (float) 
		{
			cout << "\nPrice is high,Please enter Afforable Price: ";
			cin>>price;
		}
		cout<<"Enter the Page Count of the Book: ";
		cin>>pgcount;
		}

	void display()
		{
		cout<<"Title of Book: "<<name<<endl;
		cout<<"Price of Book: "<<price<<endl;
		cout<<"Page count: "<<pgcount<<endl;
		}
};

class tapes:public virtual publication
{
	private:
	int tapetime;
	
	public:
	void getdata()
		{
		cout<<"\nEnter the Title of the Audio Cassette: ";
		cin>>name;
		
		try
		{
			cout<<"Enter the Price of the Audio Cassette: ";
			cin>>price;
			if (price>1000)
			{
				throw price;
			}
		}
		catch (float) 
		{
			cout << "\nPrice is high,Please enter Afforable Price: ";
			cin>>price;
		}
		cout<<"Enter the Time of Cassette in Minutes: ";
		cin>>tapetime;
		}

	void display()
		{
		cout<<"Title of Audio Cassette: "<<name<<endl;
		cout<<"Price of Audio Cassette: "<<price<<endl;
		cout<<"Time of Audio Cassette: "<<tapetime<<endl;
		}
};
int main()
{
	publication *p[50];
	int choice,n;
	int i=0;
	
	do
	{
		cout<<"\nMenu:"<<endl;
		cout<<"Enter 1 for Book Input";
		cout<<"\nEnter 2 for Audio Cassette Input";
		cout<<"\nEnter 3 for Display";
		cout<<"\nEnter 4 for Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1: cout<<"\n----------------------------------------------------------------------------\n";
					cout<<"\nBook Input :"<<endl;
					p[i]=new book();
					p[i]->getdata();
					i++;
					cout<<"\n----------------------------------------------------------------------------\n";
					break;
			
			case 2: cout<<"\n----------------------------------------------------------------------------\n";
					cout<<"\nAudio Cassette Input :"<<endl;
					p[i]=new tapes();
					p[i]->getdata();
					i++;
					cout<<"\n----------------------------------------------------------------------------\n";
					break;
					
			case 3: cout<<"\nDisplay: "<<endl;
					n=i;
					for (i=0;i<n;i++)	
					{
						cout<<"\n----------------------------------------------------------------------------\n";
						p[i]->display();
						cout<<"\n----------------------------------------------------------------------------\n";
					}
					break;
			case 4: cout<<"\nExit"<<endl;
					break;
					
			}
	}while(choice>=1 && choice<4);
	return 0;

}
