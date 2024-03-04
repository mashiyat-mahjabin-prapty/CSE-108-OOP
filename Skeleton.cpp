#include<iostream>
#include<cstring>
using namespace std;

class TaxPayer
{
    ///You can not change the specifier type
    string name;
    int id;
protected:
    int income;
public:
    TaxPayer(string n, int i, int in)
    {
        name=n;
        id=i;
        income=in;
    }
    virtual void printTaxPayer()
    {
        cout<<"Tax Payer Number: "<<id<<endl<<"Tax Payer Name: "<<name<<endl<<"Tax Payer Income: "<<income<<endl;
    }
    int calculateTax()
    {
        int taxableIncome=calculateTaxableIncome();
        if(taxableIncome<=25000) return 0;
        else if(taxableIncome>25000 && taxableIncome<100000) return (taxableIncome-25000)*0.1;
        else return 7500+(taxableIncome-100000)*0.2;
    }
    void printTax()
    {
        int taxableIncome=calculateTaxableIncome();
        cout<<"Taxable Income: "<<taxableIncome<<endl;
        cout<<"Tax Payable: "<<calculateTax()<<endl<<endl;
    }
    ///Add a pure virtual function calculateTaxableIncome() here which will return integer
};

int main()
{
    TaxPayer *tp[10];
    tp[0] = new SalariedTaxPayer("Hasmot",1,50000,"Govt2");
    tp[1] = new SalariedTaxPayer("Keramot",2,40000,"Govt3");
    tp[2] = new SalariedTaxPayer("Padma",3,80000,"Govt1");
    tp[3] = new SalariedTaxPayer("Meghna",4,120000,"Govt1");
    tp[4] = new NonSalariedTaxPayer("Kashem",5,30000,5000);
    tp[5] = new NonSalariedTaxPayer("Bokor",6,60000,15000);
    tp[6] = new InvestorTaxPayer("Faria",7,140000,"Govt1",20000);
    tp[7] = new InvestorTaxPayer("Karim",8,130000,"Govt2",10000);
    tp[8] = new InvestorTaxPayer("Rahim",9,100000,"Govt3",10000);

    int total_tax=0;
    int total_tax_Salaried=0;
    int total_tax_NonSalaried=0;
    int total_tax_Investor=0;

    for(int i=0;i<9;i++)
    {
        ///Implement this main function so that output is shown appropriately
    }
    cout<<"Total Tax: "<<total_tax<<endl;		///40400
    cout<<"Total Tax(Salaried): "<<total_tax_Salaried<<endl;	///38400
    cout<<"Total Tax(Non Salaried): "<<total_tax_NonSalaried<<endl;		///2000
    cout<<"Total Tax(Investor): "<<total_tax_Investor<<endl;		///22600
}
