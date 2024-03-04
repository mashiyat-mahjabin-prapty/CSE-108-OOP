#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class StringMath
{
	char *p;
	public:
		StringMath()
		{
			p = NULL;
		}
		StringMath(char *s)
		{
			if(s[0] == '-') 
			{
				cout << "Initialization error\n";
				exit(1);
			}
			int len = strlen(s);
			p = new char[len];
			strcpy(p, s);
		}
		StringMath(const StringMath& s)
		{
			int len = strlen(s.p);
			p = new char[len];
			strcpy(p, s.p);
		}
		StringMath& operator=(const StringMath &q);
		StringMath operator+(StringMath& q);
		StringMath operator+(int m);
		StringMath& operator++(int notused);
		bool operator>(StringMath& q);
		bool operator>(int m);
		void print()
		{
			cout << p << endl;
		}
		~StringMath()
		{
			delete []p;
		}
		friend StringMath operator+(int m, StringMath& q);
};

StringMath& StringMath::operator=(const StringMath& q)
{
	int len = strlen(q.p);
	delete[] p;
	p = new char[len];
	strcpy(p, q.p);
	return *this;
}

bool StringMath::operator>(StringMath& q)
{
	return strcmp(p, q.p);
}

bool StringMath::operator>(int m)
{
	char arr[50];
	itoa(m, arr, 10);
	return strcmp(p, arr);
}

StringMath StringMath::operator+(StringMath& q)
{
	char arr[80];
	int carry=0, a, b, len, i, lena, lenb, j, k;
	len = min(strlen(p), strlen(q.p));
	lena = strlen(p);
	lenb = strlen(q.p);
	for(i = lena-1, j = lenb-1, k=0; i >= lena-len; i--, j--, k++)
	{
		a = p[i]-'0';
		b = q.p[j] - '0';
		if((a+b+carry) > 9)  arr[k] = ((a+b+carry)%10)+'0';
		else arr[k] = (a+b+carry)+'0';
		carry = (a+b+carry)/10;
	}
	if(len < lena) 
	{
		while(i>=0)
		{
			a = p[i] - '0';
			if((a+carry) > 9) arr[k] = ((a+carry)%10)+'0';
			else arr[k] = a+carry+'0';
			carry = (a+carry)/10;
			k++;
			i--;
		}
	}
	else if(len < lenb)
	{
		while(j>=0)
		{
			b = q.p[j] - '0';
			if((b+carry) > 9) arr[k] = ((b+carry)%10)+'0';
			else arr[k] = (b+carry)+'0';
			carry = (b+carry)/10;
			k++;
			j--;
		}
	}
	if(carry > 0) {
		arr[k] = carry+'0';
		k++;
		arr[k] = '\0';
	}
	else{
		arr[k] = '\0';
	}
	//cout << arr[k] << endl;
	StringMath temp;
	delete []p;
	temp.p = new char[k];
	int z;
	for(z = 0; z <= k; z++)
	{
		temp.p[z] = arr[k-z-1];
	}
	//temp.p[z] = '\0';
	//strcpy(temp.p, arr);
	//cout << temp.p << endl;
	return temp;
}

StringMath StringMath::operator+(int m)
{
	char arr[80], buff[30];
	itoa(m, buff, 10);
	StringMath temp;
	temp.p = new char[strlen(buff)];
	strcpy(temp.p, buff);
	temp = temp + (*this);
	return temp;
}

StringMath& StringMath::operator++(int notused)
{
	StringMath temp;
	temp.p = new char[2];
	temp.p[0] = '1';
	temp.p[1] = '\0';
	(*this) = (*this) + temp;
	return *this;
}

StringMath operator+(int m, StringMath& q)
{
	StringMath temp;
	temp = q + m;
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

