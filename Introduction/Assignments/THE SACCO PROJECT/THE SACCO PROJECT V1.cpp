#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Function to remove commas and convert to double.
double parseAmount(const string &input)
{
    string cleaned;
    // Remove any commas from the input.
    for (char c : input)
    {
        if (c != ',')
            cleaned.push_back(c);
    }
    // Convert cleaned string to double.
    try
    {
        return stod(cleaned);
    }
    catch (const invalid_argument &)
    {
        cout << "Invalid number format. Defaulting to 0.\n";
        return 0.0;
    }
}

// Class representing a SACCO member.
class Member
{
private:
    int memberID;
    string name;
    double savingsBalance;
    double loanBalance;

public:
    Member(int id, const string &n)
        : memberID(id), name(n), savingsBalance(0.0), loanBalance(0.0) {}

    int getID() const { return memberID; }
    string getName() const { return name; }
    double getSavingsBalance() const { return savingsBalance; }
    double getLoanBalance() const { return loanBalance; }

    // Deposit funds into the savings account.
    void deposit(double amount)
    {
        if (amount > 0)
        {
            savingsBalance += amount;
            cout << "Deposited: " << amount << "\n";
        }
        else
        {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw funds from the savings account.
    bool withdraw(double amount)
    {
        if (amount > 0 && amount <= savingsBalance)
        {
            savingsBalance -= amount;
            cout << "Withdrawn: " << amount << "\n";
            return true;
        }
        else
        {
            cout << "Withdrawal failed: Insufficient funds or invalid amount.\n";
            return false;
        }
    }

    // Apply for a loan.
    void applyLoan(double amount)
    {
        if (amount > 0)
        {
            loanBalance += amount;
            cout << "Loan approved for: " << amount << "\n";
        }
        else
        {
            cout << "Invalid loan amount.\n";
        }
    }

    // Repay an existing loan.
    bool repayLoan(double amount)
    {
        if (amount > 0 && amount <= loanBalance)
        {
            loanBalance -= amount;
            cout << "Repayment successful: " << amount << "\n";
            return true;
        }
        else
        {
            cout << "Repayment failed: Exceeds current loan balance or invalid amount.\n";
            return false;
        }
    }

    // Display member details on separate lines.
    void display() const
    {
        cout << "Member ID: " << memberID << "\n"
             << "Name: " << name << "\n"
             << "Savings: " << savingsBalance << "\n"
             << "Loan Balance: " << loanBalance << "\n\n";
    }
};

// Class representing the SACCO management system.
class SACCO
{
private:
    vector<Member> members;

public:
    // Add a new member to the system.
    void addMember(const Member &m)
    {
        members.push_back(m);
        cout << "Member added successfully.\n";
    }

    // Find a member by their ID.
    Member *findMember(int id)
    {
        for (auto &m : members)
        {
            if (m.getID() == id)
                return &m;
        }
        return nullptr;
    }

    // Display all members.
    void displayMembers() const
    {
        if (members.empty())
        {
            cout << "No members registered.\n";
            return;
        }
        for (const auto &m : members)
        {
            m.display();
        }
    }
};

// Function to show the menu options.
void menu()
{
    cout << "\n Welcome to Our SACCO Management System! \n";
    cout<< "\n Enter a number to perform an action: \n";
    cout << "1. Add Member\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Apply for Loan\n";
    cout << "5. Repay Loan\n";
    cout << "6. Display All Members\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    // Ensure that all floating-point numbers are displayed in fixed-point notation.
    cout << fixed << setprecision(2);

    SACCO sacco;
    int choice;

    do
    {
        menu();
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;
            cout << "\nEnter Member ID: ";
            cin >> id;
            cout << "Enter Member Name: ";
            cin.ignore(); // Clear the newline character left in the buffer.
            getline(cin, name);
            sacco.addMember(Member(id, name));
        }
        else if (choice == 2)
        {
            int id;
            string input;
            cout << "\nEnter Member ID for deposit: ";
            cin >> id;
            Member *member = sacco.findMember(id);
            if (member)
            {
                cout << "Enter deposit amount (e.g., 1,000 or 1000): ";
                cin >> input;
                double amount = parseAmount(input);
                member->deposit(amount);
            }
            else
            {
                cout << "Member not found.\n";
            }
        }
        else if (choice == 3)
        {
            int id;
            string input;
            cout << "\nEnter Member ID for withdrawal: ";
            cin >> id;
            Member *member = sacco.findMember(id);
            if (member)
            {
                cout << "Enter withdrawal amount (e.g., 1,000 or 1000): ";
                cin >> input;
                double amount = parseAmount(input);
                member->withdraw(amount);
            }
            else
            {
                cout << "Member not found.\n";
            }
        }
        else if (choice == 4)
        {
            int id;
            string input;
            cout << "\nEnter Member ID for loan application: ";
            cin >> id;
            Member *member = sacco.findMember(id);
            if (member)
            {
                cout << "Enter loan amount (e.g., 1,000 or 1000): ";
                cin >> input;
                double amount = parseAmount(input);
                member->applyLoan(amount);
            }
            else
            {
                cout << "Member not found.\n";
            }
        }
        else if (choice == 5)
        {
            int id;
            string input;
            cout << "\nEnter Member ID for loan repayment: ";
            cin >> id;
            Member *member = sacco.findMember(id);
            if (member)
            {
                cout << "Enter repayment amount (e.g., 1,000 or 1000): ";
                cin >> input;
                double amount = parseAmount(input);
                member->repayLoan(amount);
            }
            else
            {
                cout << "Member not found.\n";
            }
        }
        else if (choice == 6)
        {
            cout << "\nDisplaying all members:\n";
            sacco.displayMembers();
        }
        else if (choice == 0)
        {
            cout << "\nExiting the system. Goodbye!\n";
        }
        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}