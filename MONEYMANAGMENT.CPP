#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Transaction {
    string type; // spent , income //
    double amount; // amount//
    string category; // category //

};


int main() {
    vector<Transaction> transactions;
    double balance = 0.0;

    // prompt user for initial balance
    cout << "Enter your initial balance: ";
    cin >> balance;

    while (true) {
        cout << "Enter transaction type (spent, earned, transfered, wallet, summary, all): ";
        string type;
        cin >> type;

        if (type == "spent" || type == "earned" || type == "transfered" || type == "wallet") {
            if (type == "wallet") {
                cout << "Current balance: " << balance << endl;
            } else {
                cout << "Enter amount: ";
                double amount;
                cin >> amount;

                cout << "Enter category: ";
                string category;
                cin >> category;

                Transaction transaction = {type, amount, category};
                transactions.push_back(transaction);

                if (type == "spent") {
                    balance -= amount;
                } else if (type == "earned") {
                    balance += amount;
                } else if (type == "transfered") {
                    cout << "Enter destination account: ";
                    string dest;
                    cin >> dest;
                }

                cout << "Transaction recorded." << endl;
            }
        } else if (type == "summary") {
            cout << "Balance: " << balance << endl;
            cout << "Transactions:" << endl;
            for (const Transaction& transaction : transactions) {
                cout << "- " << transaction.amount << " " << transaction.type << " on " << transaction.category << endl;
            }
        } else if (type == "all") {
            cout << "Spent Transactions:" << endl;
            for (const Transaction& transaction : transactions) {
                if (transaction.type == "spent") {
                    cout << "- " << transaction.amount << " spent on " << transaction.category << endl;
                }
            }
            cout << "Earned Transactions:" << endl;
            for (const Transaction& transaction : transactions) {
                if (transaction.type == "earned") {
                    cout << "- " << transaction.amount << " earned from " << transaction.category << endl;
                }
            }
             cout << "Transfered Transactions:" << endl;
            for (const Transaction& transaction : transactions) {
                if (transaction.type == "transfered") {
                    cout << "- " << transaction.amount << " transfered on " << transaction.category << endl;
                }
            }
        } else if (type == "quit") {
            break;
        } else {
            cout << "Invalid transaction type. Valid types are: spent, earned, transfered, wallet, summary, all, quit." << endl;
        }
    }

    return 0;
}