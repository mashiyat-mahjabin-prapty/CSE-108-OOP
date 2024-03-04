#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class StringMath
{
	char* p;
	public:
		StringMath()
		{
			p = NULL;
		}
		StringMath(char* s)
		{
			int len = strlen(s);
			p = new char[len];
			strcpy(p, s);
		}
		StringMath(const StringMath& obj) 
		{
			if(p!=NULL) delete [] p;
			int len = strlen(obj.p);
			p = new char[len];
			strcpy(p, obj.p);
		}
		StringMath& operator=(const StringMath& q);
		StringMath operator+(StringMath& q);
		StringMath operator+(int m);
		bool operator>(StringMath& q);
		bool operator>(int m);
		StringMath& operator++(int notused);
		void print()
		{
			cout << p << endl;
		}
		~StringMath()
		{
			delete []p;
		}
		friend StringMath operator+(int n, StringMath& p);
	// Add necessary constructors and destructors and functions

};

StringMath& StringMath::operator=(const StringMath& q)
{
	int len = strlen(q.p);
	delete[] p;
	p = new char[len];
	strcpy(p, q.p);
	return *this;
}

StringMath StringMath::operator+(StringMath& q)
{
	StringMath temp;
	char *end = NULL;
	long long a, b;
	a = strtoull(p, &end, 10);
	b = strtoull(q.p, &end, 10);
	a+=b;
	char arr[80];
	int i, j, k; 
	for(i = 0; a != 0; i++)
	{
	    arr[i] = (a%10)+48;
	    a/=10;
	}
	int len = i;
	temp.p = new char[i];
	for(j = 0, k = i-1; j < i; j++, k--)
	{
	    temp.p[j] = arr[k];
	}
	temp.p[j] = '\0';
	return temp;
}

StringMath StringMath::operator+(int m)
{
	StringMath temp;
	char *end = NULL;
	long long a;
	a = strtoull(p, &end, 10);
	a+=m;
	char arr[80];
	int i, j, k; 
	for(i = 0; a != 0; i++)
	{
	    arr[i] = (a%10)+48;
	    a/=10;
	}
	int len = i;
	temp.p = new char[i];
	for(j = 0, k = i-1; j < i; j++, k--)
	{
	    temp.p[j] = arr[k];
	}
	temp.p[j] = '\0';
	return temp;
}

bool StringMath::operator>(StringMath& q)
{
	return strcmp(p, q.p);
}

bool StringMath::operator>(int m)
{
	char *end = NULL;
	long long a;
	a = strtoull(p, &end, 10);
	return (a>m);
}

StringMath& StringMath::operator++(int notused)
{
	char *end = NULL;
	long long a;
	a = strtoull(p, &end, 10);
	++a;
	char arr[80];
	int i, j, k; 
	for(i = 0; a != 0; i++)
	{
	    arr[i] = (a%10)+48;
	    a/=10;
	}
	int len = i;
	delete []p;
	p = new char[i];
	for(j = 0, k = i-1; j < i; j++, k--)
	{
	    p[j] = arr[k];
	}
	p[j] = '\0';
	return *this;
}

StringMath operator+(int m, StringMath& q)
{
	StringMath temp;
	char *end = NULL;
	long long a;
	a = strtoull(q.p, &end, 10);
	a+=m;
	char arr[80];
	int i, j, k; 
	for(i = 0; a != 0; i++)
	{
	    arr[i] = (a%10)+48;
	    a/=10;
	}
	int len = i;
	temp.p = new char[i];
	for(j = 0, k = i-1; j < i; j++, k--)
	{
	    temp.p[j] = arr[k];
	}
	temp.p[j] = '\0';
	return temp;
}

int main()
{
	StringMath S1;
	StringMath S2("123");
	StringMath S3("757");
	StringMath S4("220");
	StringMath S5;
	int n=345;
	S1=S4;
	S1.print();
	S4.print();
	//Print the character string of S1 and S4
	S1=S2+S3+S4;
	S1.print();
	S2.print();
	S3.print();
	S4.print();
	//Print the character string of S1, S2, S3 and S4, where S1 contains the character string: “1100”
	S5=S4=S3;
	S5.print();
	S4.print();
	S3.print();
	// Print the character string of S5, S4 and S3
	if(S3 > n )
	{
	S5= S3+n;
	}
	S5.print();
	// Print the character string of S5, where S5 contains the character string: “1102”
	S5= n+S2;
	S5.print();
	// Print the character string of S5, where S5 contains the character string: “468”
	if(S5 > S2)
	{
	S5++;
    //Assume prefix increment
	}
	S5.print();
	// Print the character string of S5, where S5 contains the character string: “469”
}
