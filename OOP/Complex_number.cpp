//https://github.com/Deshnashah27

#include <iostream>
using namespace std;
class Complex
{ 
    public:
        float real;
        float imag;
        Complex(){
            real=0;
            imag=0;
        }
        ~ Complex(){}
        Complex operator +(Complex &obj){
            Complex add;
            add.real=real +obj.real;
            add.imag=imag+obj.imag;
            return add;
        }
        Complex operator *(Complex &obj){
            Complex mult;
            mult.real=real*obj.real-imag*obj.imag;
            mult.imag=real*obj.imag+obj.real*imag;
            return mult;

        }
        friend ostream & operator<<(ostream &out, Complex &c)
        {
            if(c.imag>=0)
                out<<c.real<<"+"<<c.imag<<"i\n";
            else
                out<<c.real<<c.imag<<"i\n";		
            return out;
        }

        friend istream & operator >> (istream &in,  Complex &c)
        {
            cout << "Enter Real Part ";
            in >> c.real;						
            cout << "Enter Imaginary Part ";
            in >> c.imag;
            return in;
        }
};

int main()
{
    Complex c1,c2,c3;
    int ch;
	cout<<c1;			//default constructor
	cout<<c2;
	cin>>c1;		//calling of operator overloading function
	cin>>c2;
    
   do
	{
		cout<<"Enter\n1.Addition\n2.Multiplication\n0.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 0:
			break;
			case 1:
				c3=c1+c2;
				cout<<"Addition: ";
				cout<<c3;
			break;
			case 2:
				c3=c1*c2;
				cout<<"Multiplication: ";
				cout<<c3;
			break;
			default:
				cout<<"Invalid choice\n";
		}
	}while(ch!=0);
    return 0;
}
