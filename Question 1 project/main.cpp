

#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

int main() {

    //variable declaration to accept the value of each pencil price,rate of inflation that increase the price of the pencil

    float each_item_price, starting_inflation_rate, total_price, rateof_inflation;

    //variable  declaration to accept the budget starting and ending year and quantity of pencil
    int sarting_year, budget_endyear, budget_year = 0, numberof_pencile, choice;

    int permmision;//ask the user that he/she want to set budget
ask1:
    cout << "**********WELCOME TO BUDGET SET APPLICATION **********\n\n\n";
    cout << "DO YOU WANT TO SET A BUDGET? ENTER\n1.yes\n2.no\n";
    cin >> permmision;
    cout << endl;
    if (permmision == 1) {
        cout << "Here is the requirements that you should fill to set budget:\n\n";

        cout << "\t\tPlease Enter budget starting year\n";
        cin >> sarting_year;

        cout << "\t\tPlease Enter budget endyear\n";
        cin >> budget_endyear;

        cout << "\t\t Please Enter each pencil price in the starting year(ETB)\n";
        cin >> each_item_price;

        cout << "\t\tPlease Enter estimated inflation rate(%)\n";
        cin >> starting_inflation_rate;

        starting_inflation_rate /= 100;//converting percent to decimal

        cout << "\t\tPlease Enter quantity of pencil \n";
        cin >> numberof_pencile;

        rateof_inflation = starting_inflation_rate;

        total_price = numberof_pencile * each_item_price; //total price of pencil for one year

        budget_year = budget_endyear - sarting_year; //the difference between the starting and ending budget year

        float estimated_price[budget_year]; //array that stores the estimated price of each year

        for (int i = 0; i <= budget_year; i++) {
            estimated_price[i] = total_price + (total_price * rateof_inflation);//calculate and store the estimated price of the 'i'th year
            rateof_inflation *= 2;
        }

        rateof_inflation = starting_inflation_rate;



        system("cls");
    ask:
        cout << "Which year's pencil price budget do you want to see?\n";
        cout << "\t\t1. To see all pencil price\n\t\t2. Enter year\n\t\t3. exit " << endl;
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3) {
            cout << "INVALID INPUT PLEASE TRY AGAIN!!" << endl;
            goto ask;

        }

        if (choice == 1) {
            cout << "YEAR  " << setw(15) << "  NUMBER OF PENCIL  " << setw(15) << "  INFLATION RATE  " << setw(15) << " PRICE OF EACH PENCIL(ETB) " << setw(15) << " ESTIMATED PRICE(ETB) " << endl;
            for (int i = 0; i <= budget_year; i++) {

                cout << sarting_year << setw(15) << numberof_pencile << setw(15) << rateof_inflation << setw(20) << each_item_price << setw(30) << estimated_price[i] << endl;
                sarting_year++;
                each_item_price += each_item_price * rateof_inflation;
                rateof_inflation *= 2;
            }
        }
        else if (choice == 2) {

            int choiseYear;//accepting year from the use to display the given year budget

            cout << "Please Enter year from " << sarting_year << " to " << budget_endyear << " as you want to see the budget?" << endl;
            cin >> choiseYear;

            int checkYear = 0;
            checkYear = sarting_year;
            rateof_inflation = starting_inflation_rate;

            for (int i = 0; i <= budget_year; i++) {


                if (choiseYear == checkYear) {

                    cout << "YEAR  " << setw(15) << "  NUMBER OF PENCIL  " << setw(15) << "  INFLATION RATE  " << setw(15) << " PRICE OF EACH PENCIL(ETB) " << setw(15) << " ESTIMATED PRICE(ETB) " << endl;
                    cout << checkYear << setw(15) << numberof_pencile << setw(15) << rateof_inflation << setw(20) << each_item_price << setw(30) << estimated_price[i] << endl;
                    break;
                }
                each_item_price += each_item_price * rateof_inflation;
                rateof_inflation *= 2;
                checkYear++;
            }

        }
        else if (choice == 3) {

            cout << "THANK YOU" << endl;
        }
    }
    else if (permmision == 2) {

        cout << "THANK YOU! HAVE A NICE TIME!";
    }
    else if (permmision != 1 || permmision != 2) {
        cout << "INVALID INPUT!! PLEASE TRY AGAIN" << endl;
        goto ask1;
    }

    return 0;
}