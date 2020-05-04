/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
const int SIZE=5;

//Structure
struct Payroll
{
    string f_name;
    string M_I;
    string l_name;
    double gross;
    double net;
    double hours;
    double state_tax;
    double fedTax;
    double unionFee;
    double payrate;
    
};
//this function get the info from the employee
void get_info (Payroll employee[])
{
    for (int i=0;i<SIZE;i++)
    {
        cout<<"What is your first name?\n";
        cin>>employee[i].f_name;
        
        cout<<"What is your middle name or initial?\n";
        cin>>employee[i].M_I;
        
        cout<<"What is your last name?\n";
        cin>>employee[i].l_name;
        
        cout<<"How many hours did you work?\n";
        cin>>employee[i].hours;
        if (employee[i].hours<0 || employee[i].hours>60)
            {
                cout<<"invalid input, enter hours ranging from 0-60\n";
                cin>>employee[i].hours;
            }
       
        
        cout<<"What is your hourly pay rate?\n";
        cin>>employee[i].payrate;
        if (employee[i].payrate<0 || employee[i].payrate>50)
            {
                cout<<"invalid input, enter payrate ranging from 0-50\n";
                cin>>employee[i].payrate;
            }
    
    }
}
//this fucntion calculates the grosspay
double grosspay(Payroll employee)
    {
        int gross=0;
      
        if(employee.hours<=40)
        {
        gross=employee.payrate*employee.hours;
        }
        else if (employee.hours>=40)
        {
          gross=employee.payrate*employee.hours*1.5;  
        }
        
        return gross;
      
    }
//this fucntion calculates the state tax
double statetax(Payroll employee)
    {
        double state_tax=0.06*employee.gross;
        
        return state_tax;
    }
//this fucntion calculates the fedral tax
double federalTax(Payroll employee)
    {
        double fedTax=0.12*employee.gross;
        
        return fedTax;
    }
//this fucntion calculates the union fee
double union_fee(Payroll employee)
    {
        double unionFee=0.02*employee.gross;
        
        return unionFee;
    }
//this fucntion calculates the net pay
double netpay(Payroll employee)
    {
        double net= employee.gross-(employee.unionFee+employee.fedTax+employee.state_tax);
        
        return net;
    }

int main()
{
    Payroll employee[SIZE];
    double totalgross=0;
    double avggross=0;
    int stop;
    get_info(employee);
    
     cout << " First Name. ";
     cout << " MI.  ";
     cout << " Last name.  " ;
     cout << " Rate per hour. ";
     cout << " Hours worked.";
     cout << " gross.  ";
     cout << "state tax.   ";
     cout << "federal tax.  ";
     cout << "Union fee.    ";
     cout << "Total Net Worth. ";
     cout << "\n";
     cout << "============================================================================================================================\n";
        
    for (int j=0;j<SIZE;j++)
    {
        //passes the fucntion
        employee[j].gross=grosspay(employee[j]);
        employee[j].state_tax=statetax(employee[j]);
        employee[j].fedTax=federalTax(employee[j]);
        employee[j].unionFee=union_fee(employee[j]);
        employee[j].net=netpay(employee[j]);
        
        //this calculates the total gross for all the employees
        totalgross= totalgross+employee[j].gross;
        
        //displays the outputs
        cout<< employee[j].f_name<<"      "<<employee[j].M_I<<"       "<<employee[j].l_name<<"        "<<employee[j].payrate<<"          "<<employee[j].hours<<"           "<< employee[j].gross<<"            "<< employee[j].state_tax<<"        "<< employee[j].fedTax<<"            "<< employee[j].unionFee<<"          "<< employee[j].net;
        cout<< "\n"; ;
        cout<< "\n"; 
       
    }
    
    //calculates the avg of all the employees gross
    avggross=totalgross/SIZE;
    
    //displays the outputs
    cout<<"The total gross of all employees is "<<totalgross<<"\n";
    cout<<"The average gross of all the employees is "<<avggross;
    
        
    
    

    return 0;
}
