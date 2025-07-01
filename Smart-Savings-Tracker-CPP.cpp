#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <limits>
#include <cctype>
#include <string>

using namespace std;

const string GOALS_FILE = "goals.txt";
const string TRANSACTIONS_FILE = "transactions.txt";

struct SavingGoal {
    int id;
    string name;
    double targetAmount;
    double currentAmount;
    string targetDate;
    string createdDate;
};

struct SavingRecord {
    int id;
    int goalId;
    double amount;
    string date;
};

vector<SavingGoal> goals;
vector<SavingRecord> savings;

void loadGoals() {
    ifstream file(GOALS_FILE);
    if (!file) return;

    goals.clear();
    SavingGoal goal;
    string line;

    while (getline(file, line)) {
        goal.id = stoi(line);
        getline(file, goal.name);
        getline(file, line);
        goal.targetAmount = stod(line);
        getline(file, line);
        goal.currentAmount = stod(line);
        getline(file, goal.targetDate);
        getline(file, goal.createdDate);
        goals.push_back(goal);
    }
    file.close();
}

void saveGoals() {
    ofstream file(GOALS_FILE);
    for (const auto& goal : goals) {
        file << goal.id << "\n"
            << goal.name << "\n"
            << goal.targetAmount << "\n"
            << goal.currentAmount << "\n"
            << goal.targetDate << "\n"
            << goal.createdDate << "\n";
    }
    file.close();
}

void loadSavings() {
    ifstream file(TRANSACTIONS_FILE);
    if (!file) return;

    savings.clear();
    SavingRecord record;
    while (file >> record.id >> record.goalId >> record.amount) {
        file.ignore();
        getline(file, record.date);
        savings.push_back(record);
    }
    file.close();
}

void saveSavings() {
    ofstream file(TRANSACTIONS_FILE);
    for (const auto& record : savings) {
        file << record.id << " "
            << record.goalId << " "
            << record.amount << " "
            << record.date << "\n";
    }
    file.close();
}

int getNextGoalId() {
    int maxId = 0;
    for (const auto& goal : goals) {
        if (goal.id > maxId) maxId = goal.id;
    }
    return maxId + 1;
}

int getNextRecordId() {
    int maxId = 0;
    for (const auto& record : savings) {
        if (record.id > maxId) maxId = record.id;
    }
    return maxId + 1;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

double getValidDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cout << "Invalid input! Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int getValidIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cout << "Invalid input! Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

bool isValidDate(const string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (year < 2023 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return true;
}

void addGoal() {
    SavingGoal newGoal;
    newGoal.id = getNextGoalId();
    newGoal.currentAmount = 0.0;

    cout << "\nAdd New Savings Goal:\n";
    cout << "Goal Name: ";
    cin.ignore();
    getline(cin, newGoal.name);

    newGoal.targetAmount = getValidDoubleInput("Target Amount: ");

    while (true) {
        cout << "Target Date (YYYY-MM-DD): ";
        cin >> newGoal.targetDate;
        if (isValidDate(newGoal.targetDate)) {
            break;
        }
        cout << "Invalid date format! Please use YYYY-MM-DD format.\n";
    }

    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    char dateStr[11];
    strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &ltm);
    newGoal.createdDate = dateStr;

    goals.push_back(newGoal);
    saveGoals();

    cout << "Goal added successfully!\n";
}

void addSavings() {
    if (goals.empty()) {
        cout << "No savings goals added yet!\n";
        return;
    }

    SavingRecord newRecord;
    newRecord.id = getNextRecordId();

    cout << "\nAdd New Savings Deposit:\n";

    cout << "Available Goals:\n";
    for (const auto& goal : goals) {
        cout << goal.id << ". " << goal.name << " (Target: "
            << fixed << setprecision(2) << goal.targetAmount
            << ", Saved: " << goal.currentAmount << ")\n";
    }

    newRecord.goalId = getValidIntInput("Select Goal ID: ");

    bool goalExists = false;
    for (auto& goal : goals) {
        if (goal.id == newRecord.goalId) {
            goalExists = true;
            newRecord.amount = getValidDoubleInput("Deposit Amount: ");

            time_t now = time(0);
            tm ltm;
            localtime_s(&ltm, &now);
            char dateStr[11];
            strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &ltm);
            newRecord.date = dateStr;

            goal.currentAmount += newRecord.amount;
            savings.push_back(newRecord);
            saveGoals();
            saveSavings();

            cout << "Savings added successfully!\n";
            return;
        }
    }

    cout << "Invalid Goal ID! No goal found with ID: " << newRecord.goalId << "\n";
}

int daysBetween(const string& startDate, const string& endDate) {
    tm start_tm = {};
    tm end_tm = {};

    istringstream ss_start(startDate);
    ss_start >> get_time(&start_tm, "%Y-%m-%d");

    istringstream ss_end(endDate);
    ss_end >> get_time(&end_tm, "%Y-%m-%d");

    if (ss_start.fail() || ss_end.fail()) {
        return 0;
    }

    time_t t1 = mktime(&start_tm);
    time_t t2 = mktime(&end_tm);

    if (t1 == -1 || t2 == -1) {
        return 0;
    }

    const double seconds_per_day = 60 * 60 * 24;
    double diff = difftime(t2, t1);
    return static_cast<int>(diff / seconds_per_day);
}

void showGoalsReport() {
    if (goals.empty()) {
        cout << "No savings goals found!\n";
        return;
    }

    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    char currentDate[11];
    strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", &ltm);

    cout << "\nSavings Goals Report (" << currentDate << ")\n";
    cout << "=================================================================\n";
    cout << "| " << left << setw(3) << "ID"
        << "| " << setw(20) << "Goal"
        << "| " << setw(10) << "Saved"
        << "| " << setw(10) << "Target"
        << "| " << setw(10) << "Progress"
        << "| " << setw(10) << "Days Left |\n";
    cout << "=================================================================\n";

    for (const auto& goal : goals) {
        double percentage = (goal.currentAmount / goal.targetAmount) * 100.0;
        if (goal.targetAmount == 0) percentage = 0; // Avoid division by zero

        int daysLeft = daysBetween(currentDate, goal.targetDate);

        cout << "| " << setw(3) << goal.id
            << "| " << setw(20) << goal.name
            << "| " << setw(10) << fixed << setprecision(2) << goal.currentAmount
            << "| " << setw(10) << goal.targetAmount
            << "| " << setw(9) << fixed << setprecision(1) << percentage << "%"
            << "| " << setw(10) << (daysLeft > 0 ? to_string(daysLeft) : "Expired") << " |\n";
    }
    cout << "=================================================================\n";
}

void showGoalDetails(int goalId) {
    for (const auto& goal : goals) {
        if (goal.id == goalId) {
            cout << "\nGoal Details: " << goal.name << "\n";
            cout << "----------------------------------------------------------\n";
            cout << "Created Date: " << goal.createdDate << "\n";
            cout << "Target Date:  " << goal.targetDate << "\n";
            cout << "Target Amount: " << fixed << setprecision(2) << goal.targetAmount << "\n";
            cout << "Current Savings: " << fixed << setprecision(2) << goal.currentAmount << "\n";

            double percentage = (goal.targetAmount > 0) ?
                (goal.currentAmount / goal.targetAmount) * 100.0 : 0.0;
            cout << "Progress: " << fixed << setprecision(1) << percentage << "%\n";

            time_t now = time(0);
            tm ltm;
            localtime_s(&ltm, &now);
            char currentDate[11];
            strftime(currentDate, sizeof(currentDate), "%Y-%m-%d", &ltm);

            int daysLeft = daysBetween(currentDate, goal.targetDate);
            if (daysLeft > 0) {
                cout << "Days Remaining: " << daysLeft << "\n";
                double remainingAmount = goal.targetAmount - goal.currentAmount;
                double dailySaving = remainingAmount / daysLeft;
                cout << "Required Daily Savings: " << fixed << setprecision(2) << dailySaving << "\n";
                cout << "Total Remaining Amount: " << fixed << setprecision(2) << remainingAmount << "\n";
            }
            else {
                cout << "Target date has expired!\n";
                if (goal.currentAmount >= goal.targetAmount) {
                    cout << "Congratulations! You've reached your goal!\n";
                }
                else {
                    double deficit = goal.targetAmount - goal.currentAmount;
                    if (deficit > 0) {
                        cout << "You still need: " << fixed << setprecision(2) << deficit << "\n";
                    }
                    else {
                        cout << "You've exceeded your goal by: "
                            << fixed << setprecision(2) << -deficit << "\n";
                    }
                }
            }
            cout << "----------------------------------------------------------\n";

            cout << "\nSavings History:\n";
            cout << "------------------------------------\n";
            cout << "Date       | Amount\n";
            cout << "------------------------------------\n";

            bool found = false;
            for (const auto& record : savings) {
                if (record.goalId == goalId) {
                    cout << record.date << " | +" << fixed << setprecision(2) << record.amount << "\n";
                    found = true;
                }
            }

            if (!found) {
                cout << "No savings records found\n";
            }
            cout << "------------------------------------\n";
            return;
        }
    }
    cout << "Goal not found with ID: " << goalId << "!\n";
}

void showMainMenu() {
    cout << "\n\n SMART SAVINGS TRACKER\n";
    cout << "====================================\n";
    cout << "1. View Goals Report\n";
    cout << "2. Add New Goal\n";
    cout << "3. Add Savings Deposit\n";
    cout << "4. View Goal Details\n";
    cout << "5. Exit\n";
    cout << "====================================\n";
    cout << "Enter your choice: ";
}

int main() {
    // Load data from files
    loadGoals();
    loadSavings();

    int choice;
    do {
        clearScreen();
        showMainMenu();

        choice = getValidIntInput("");

        switch (choice) {
        case 1:
            clearScreen();
            showGoalsReport();
            break;
        case 2:
            clearScreen();
            addGoal();
            break;
        case 3:
            clearScreen();
            addSavings();
            break;
        case 4: {
            clearScreen();
            if (goals.empty()) {
                cout << "No goals available. Please add a goal first.\n";
            }
            else {
                showGoalsReport();
                int goalId = getValidIntInput("\nEnter Goal ID to view details: ");
                showGoalDetails(goalId);
            }
            break;
        }
        case 5:
            cout << "All data saved. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-5.\n";
        }

        if (choice != 5) {
            cout << "\nPress Enter to return to main menu...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 5);

    return 0;
}