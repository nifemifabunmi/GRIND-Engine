#include "tracker.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;

void GRINDCore::logSession(const string& taskName, int duration, const string& mood) {
    time_t now = time(0);
    sessions.push_back({ taskName, duration, mood, now });
    cout << "Session logged: " << taskName << ", Duration: " << duration << " mins, Mood: " << mood << endl;
}

void GRINDCore::logBudget(const string& category, double amount, const string& type) {
    time_t now = time(0);
    budgetEntries.push_back({ category, amount, type, now });
    cout << "Budget entry logged: " << category << ", Amount: $" << amount << ", Type: " << type << endl;
}

void GRINDCore::exportDailyReport(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << "\n";
        return;
    }

    file << "=== GRIND Daily Report ===\n\n";

    file << "--- Productivity Sessions ---\n";
    for (const auto& s : this->sessions) {
        file << "Task: " << s.taskName
             << ", Duration: " << s.durationMinutes << " mins"
             << ", Mood: " << s.mood << "\n";
    }

    file << "\n--- Budget Entries ---\n";
    for (const auto& b : budgetEntries) {
        file << b.type << " - " << b.category
             << ": $" << b.amount << "\n";
    }

    file << "\n=== End of Report ===\n";
    file.close();
    cout << "Daily report exported to " << filename << "\n";
}

void GRINDCore::saveData() {
    ofstream sessionFile("data/sessions.csv");
    ofstream budgetFile("data/budget.csv");

    for (const auto& s : sessions) {
        sessionFile << s.taskName << "," << s.durationMinutes << "," << s.mood << "," << s.timestamp << "\n";
    }

    for (const auto& b : budgetEntries) {
        budgetFile << b.category << "," << b.amount << "," << b.type << "," << b.timestamp << "\n";
    }

    sessionFile.close();
    budgetFile.close();
    cout << "[💾] Data saved to /data folder.\n";
}

void GRINDCore::loadData() {
    sessions.clear();
    budgetEntries.clear();

    ifstream sessionFile("data/sessions.csv");
    ifstream budgetFile("data/budget.csv");

    string line;
    while (getline(sessionFile, line)) {
        stringstream ss(line);
        string taskName, durationStr, mood, timestampStr;
        getline(ss, taskName, ',');
        getline(ss, durationStr, ',');
        getline(ss, mood, ',');
        getline(ss, timestampStr, ',');

        Session s;
        s.taskName = taskName;
        s.durationMinutes = stoi(durationStr);
        s.mood = mood;
        s.timestamp = stol(timestampStr);
        sessions.push_back(s);
    }

    while (getline(budgetFile, line)) {
        stringstream ss(line);
        string category, amountStr, type, timestampStr;
        getline(ss, category, ',');
        getline(ss, amountStr, ',');
        getline(ss, type, ',');
        getline(ss, timestampStr, ',');

        BudgetEntry b;
        b.category = category;
        b.amount = stod(amountStr);
        b.type = type;
        b.timestamp = stol(timestampStr);
        budgetEntries.push_back(b);
    }

    sessionFile.close();
    budgetFile.close();
    cout << "[📂] Data loaded from /data folder.\n";
}