#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

using namespace std;

//Global Variable
const int NUM_COLUMNS = 8;
const int NUM_ROWS = 9;

//Functions
void displaySeating(const int [][NUM_COLUMNS], int);  //display the current seating

void selectSeat(int array[][NUM_COLUMNS], int NUM_ROWS);  //have the user choose the row and column of a seat

void soldOut(const int array[][NUM_COLUMNS], int NUM_ROWS, bool &noMoreTickets);   //checks to see if the tickets are sold out, returns a bool

int main()
{
    //theater seating array
    int seatingArray[9][8] ={
        { 40, 50, 50, 50, 50, 50, 50, 40 },
        { 30, 30, 40, 50, 50, 40, 30, 30 },
        { 20, 30, 30, 40, 40, 30, 30, 20 },
        { 10, 20, 20, 20, 20, 20, 20, 10 },
        { 10, 20, 20, 20, 20, 20, 20, 10 },
        { 10, 20, 20, 20, 20, 20, 20, 10 },
        { 10, 10, 10, 10, 10, 10, 10, 10 },
        { 10, 10, 10, 10, 10, 10, 10, 10 },
        { 10, 10, 10, 10, 10, 10, 10, 10 } };


    bool noMoreTickets = 0;  //bool for the while loop initially set to zero

    while (noMoreTickets == 0)  //while loop, a bool ends the loop when all tickets are sold out

    {
        cout << "       Available Theater Seating" << endl;
        cout << ""<< endl;

        displaySeating(seatingArray, NUM_ROWS); //call the display Seating function

        cout <<" "<<endl;

        soldOut(seatingArray, NUM_ROWS, noMoreTickets);  //call the sold out function and check to see if the seats are sold out first

        if (noMoreTickets == 0) selectSeat(seatingArray, NUM_ROWS);  //if the seats are not sold out let the user select a seat

        system("CLS");  //clear the screen

    }


    return 0;
}


void displaySeating(const int array[][NUM_COLUMNS], int NUM_ROWS)  //display the current seating arrangement
{
    for (int x = 8; x > -1; x--)  //go through the rows
    {
        for (int y = 0; y < NUM_COLUMNS; y++) //go through the columns
        {
            if (array[x][y] == 0)  //if a seat is sold out already it will be logged as O, display this as the string X
            {
                cout << " X" << "    ";
            }
            else cout << "$" << array[x][y] << "   ";
        }
        cout << endl;
    }
}


 void selectSeat(int array[][NUM_COLUMNS], int NUM_ROWS) //choose the row and column of a seat
{
    int tempRow, tempColumn, loopCounter = 0;  //declare the temporary row and column integers, as well as the loop counter that will  be used to end the while loop

    bool seatAlreadySelected = 0;  //bool to check and see if a seat has already been selected

    while (loopCounter == 0)  //loopCounter is used to end the loop once a proper selection has been made

    {
        cout <<""<< endl;
        cout <<"    Please select a Theater Seat Row : ";
        cin >> tempRow;
        cout <<""<< endl;

        cout <<"    Please select a Theater Seat Column : ";
        cin >> tempColumn;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;

        if (tempRow > 9 || tempRow < 1 || tempColumn > 8 || tempColumn < 1)  //check to see if it is a valid seat option
        {
            cout <<"    ATTENTION: THE SEAT SELECTED, ROW " << tempRow <<", COLUMN " << tempColumn<<" DOES NOT EXIST."<< endl;
        }

        else
        {
            if(array[tempRow - 1][tempColumn - 1] == 0)  //check to see if the seat has already been selected
        {
                cout <<"    ATTENTION: That seat has already been sold"<< endl;
                cout <<"            Please choose another."<< endl;
                seatAlreadySelected = 1;  //set the bool to 1
        }


            if (tempRow < 10 && tempRow > 0 && tempColumn < 9 && tempColumn > 0)  //if the input is valid end the loop
        {
                loopCounter = 1;
        }
        }
    }

    if (seatAlreadySelected == 0)  //check to see if the seat selected has already been chosen, if not proceed

    {
        cout<<"    Thank you for choosing seat # " << tempRow << ":" << tempColumn << endl;

        tempRow = tempRow - 1;  //adjust temp row to display correct array position
        tempColumn = tempColumn - 1; //adjust temp column to display correct array position

        cout <<"    Your ticket price is: $" << array[tempRow][tempColumn];
        cout <<""<<endl;
        cout <<""<<endl;

        array[tempRow][tempColumn] = 0;  //change selected seat to X
    }

    Sleep(2000);  //pause for two seconds

}


void soldOut(const int array[][NUM_COLUMNS], int NUM_ROWS, bool &noMoreTickets)  //checks to see if the tickets are sold out
{
    int ticketsSold = 0;

    for (int x = 8; x > -1; x--)  //go through the rows
    {
        for (int y = 0; y < NUM_COLUMNS; y++)  //go through the columns
        {
            if (array[x][y] == 0)  //check to see if a ticket has been already sold
            {
                ticketsSold = ticketsSold + 1;  //keep track of how many ticket have been sold
            }
        }
    }

    if (ticketsSold >= 72)  //if all 72 tickets have been sold, display the sold out message
    {
        cout <<" "<<endl;
        cout << "ATTENTION:  THE THEATER HAS BEEN SOLD OUT." << endl;
        noMoreTickets = 1;
        Sleep(3000);  //pause for 3 seconds
    }


}
