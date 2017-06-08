/*********************************************************************/
/*                                                                   */
/*Jared Bain                                            Homework 3   */
/*CISC3110                                              Section WQ6  */
/*                                                                   */
/*********************************************************************/



#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct employee
{
       string name;
       double hours;
       double rate;
       int age;
       double wage;
       double tax;
};

int main()
{

    ifstream infile;
    infile.open("datafile.txt");
    int i, k, overtime, maxage = 0, minage = 0;
    double overwage, maxtax = 0;
    string option, taxname;
    cout << "Miser Corporation Payroll" << endl;

    cout << "Will data be inputted through a file? (respond with 'yes' or 'no')" << endl;
    cin >> option;
    cout << "How many employees are in the company?" << endl;
    cin >> i;
    employee emp[i];
    if (option == "no"){
               for (k = 0; k < i; k++){
                                  cout << "Enter Employee Name" << endl;
                                  cin >> emp[k].name;
                                  cout << "Enter Hours Worked" << endl;
                                  cin >> emp[k].hours;
                                  cout << "Enter Rate of Pay" << endl;
                                  cin >> emp[k].rate;
                                  cout << "Enter age" << endl;
                                  cin >> emp[k].age;}}
    else{
         for (k = 0; k < i; k++){
             infile >> emp[k].name;
             infile >> emp[k].hours;
             infile >> emp[k].rate;
             infile >> emp[k].age;
             if (minage == 0)
                minage = emp[k].age;
             else if (minage > emp[k].age)
                  minage = emp[k].age;
             if (maxage < emp[k].age)
                maxage = emp[k].age;}}

    for (k = 0; k < i; k++){
        if (emp[k].hours > 40){
           overtime = emp[k].hours - 40;
           emp[k].wage = 40 * emp[k].rate;
           overwage = overtime * (emp[k].rate * 1.5);
           emp[k].wage += overwage;}
        else
            emp[k].wage = emp[k].hours * emp[k].wage;
        cout << emp[k].name << endl << emp[k].hours << "   " << emp[k].rate << "   " << emp[k].age << endl;}

    for (k = 0; k < i; k++){
        if (emp[k].age > 55)
           emp[k].tax = emp[k].wage * .5;
        else
            emp[k].tax = emp[k].wage * .1;
        if (maxtax < emp[k].tax){
           maxtax = emp[k].tax;
           taxname = emp[k].name;}}


}
