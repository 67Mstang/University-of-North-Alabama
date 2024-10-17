#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX_INVOICES = 100;
const double FLORENCE_TAX_RATE = 0.095;

struct InvoiceType
{
    int invoiceID, quantity;
    double itemUnitCost;
    string custFirstName, custLastName, itemDescription;
};

void readInvoices(InvoiceType inv[], int &num);
void printSingleInvoice(InvoiceType inv);
void printAllInvoices(InvoiceType inv[], int num);
double findTotalCost(InvoiceType inv[]);
void newInvoice(InvoiceType inv[], int &num);
void writeInvoices(InvoiceType inv[], int num);
void sortByLastName(InvoiceType inv[], int num);

int main()
{
    int numInvoices = 0;
    InvoiceType invoice[MAX_INVOICES];
    readInvoices(invoice, numInvoices);
    printAllInvoices(invoice, numInvoices);
    newInvoice(invoice, numInvoices);
    printAllInvoices(invoice, numInvoices);
    sortByLastName(invoice, numInvoices);
    cout << endl << endl << endl << "SORTED BY LAST NAME: " << endl << endl << endl;
    printAllInvoices(invoice, numInvoices);

    return 0;
}

void newInvoice(InvoiceType inv[], int &num)
{
    cout << "Invoice ID? ";
    cin >> inv[num].invoiceID;
    cout << "Customer first? ";
    cin >> ws;
    getline(cin, inv[num].custFirstName);
    cout << "Customer last? ";
    getline(cin, inv[num].custLastName);
    cout << "Item Description? ";
    getline(cin, inv[num].itemDescription);
    cout << "Item Unit Cost? ";
    cin >> inv[num].itemUnitCost;
    cout << "Quantity Purchased? ";
    cin >> inv[num].quantity;
    num++;
}

double findTotalCost(InvoiceType inv[])
{
    double total = 0;
    //total = inv.itemUnitCost * inv.quantity;
    total = total * (1 + FLORENCE_TAX_RATE);
    return total;
}

void printAllInvoices(InvoiceType inv[], int num)
{
    cout << "Invoice ID  first name  last name    description  unit cost  quantity  total" << endl;
    for(int i = 0; i < num; i++)
    {
        printSingleInvoice(inv[i]);
    }
}

void printSingleInvoice(InvoiceType inv)
{
    cout << setw(10) << inv.invoiceID << "  ";
    cout << left << setw(10) << inv.custFirstName;
    cout << setw(10) << inv.custLastName;
    cout << setw(20) << inv.itemDescription;
    cout << right << setw(10) << setprecision(2) << fixed  << inv.itemUnitCost;
    cout << setw(10) << inv.quantity << endl;
    //cout << setw(10)<< findTotalCost(inv) << endl;
}

void writeInvoices(InvoiceType inv[], int num)
{
    ofstream outfile("invoices.txt");
    for(int i = 0; i < num; i++)
    {
        outfile << inv[i].invoiceID << endl;
        outfile << inv[i].custFirstName << endl;
        outfile << inv[i].custLastName << endl;
        outfile << inv[i].itemDescription << endl;
        outfile << inv[i].itemUnitCost << endl;
        outfile << inv[i].quantity << endl;
    }
    outfile.close();
}

void sortByLastName(InvoiceType inv[], int num)
{
    invoice temp;
    int minIndex = 0;
    for(int i = 0; i < num - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < num; j++)
        {
            if(inv[j].custLastName < inv[minIndex].custLastName)
            {
                minIndex = j;
            }
        }
        temp = inv[i];          // swap structs at positions i and minIndex
        inv[i] = inv[minIndex];
        inv[minIndex] = temp;
    }
}

void readInvoices(InvoiceType inv[], int &num)
{
    num = 0;
    ifstream input("invoices.txt");
    input >> inv[num].invoiceID;
    while(!input.eof())
    {
        input >> ws;            // skips over the end of line char in the file
        getline(input, inv[num].custFirstName);
        getline(input, inv[num].custLastName);
        getline(input, inv[num].itemDescription);
        input >> inv[num].itemUnitCost;
        input >> inv[num].quantity;
        num++;
        input >> inv[num].invoiceID;
    }
    input.close();
}
