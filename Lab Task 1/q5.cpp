#include <iostream>
#include <iomanip>  
#include <string>   

using namespace std;

int main() {
    string movieName;
    double adultTicketPrice, childTicketPrice;
    int numAdultTickets, numChildTickets;
    double percentageDonated;

    cout << "Enter the movie name: ";
    getline(cin, movieName);  

    cout << "Enter adult ticket price: $";
    cin >> adultTicketPrice;

    cout << "Enter child ticket price: $";
    cin >> childTicketPrice;

    cout << "Enter number of adult tickets sold: ";
    cin >> numAdultTickets;

    cout << "Enter number of child tickets sold: ";
    cin >> numChildTickets;

    cout << "Enter percentage of gross amount to be donated: ";
    cin >> percentageDonated;

    double grossAmount = (adultTicketPrice * numAdultTickets) + (childTicketPrice * numChildTickets);

    double amountDonated = (percentageDonated / 100) * grossAmount;

    double netSale = grossAmount - amountDonated;

    cout << fixed << setprecision(2);

    cout << left << setw(40) << "Movie Name:" << right << setw(10) << movieName << endl;
    cout << left << setw(40) << "Number of Tickets Sold:" << right << setw(10) << (numAdultTickets + numChildTickets) << endl;
    cout << left << setw(40) << "Gross Amount:" << right << setw(10) << "$" << grossAmount << endl;
    cout << left << setw(40) << "Percentage of Gross Amount Donated:" << right << setw(10) << percentageDonated << "%" << endl;
    cout << left << setw(40) << "Amount Donated:" << right << setw(10) << "$" << amountDonated << endl;
    cout << left << setw(40) << "Net Sale:" << right << setw(10) << "$" << netSale << endl;

    return 0;
}
