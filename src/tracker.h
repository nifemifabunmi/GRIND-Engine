#ifndef TRACKER_H
#define TRACKER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Session {
    string taskName;
    int durationMinutes; // in minutes
    string mood;
    time_t timestamp;
};

struct BudgetEntry {
    string category;
    double amount;
    string type; // "income" or "expense"
    time_t timestamp;
};

class GRINDCore {
private:
    vector<Session> sessions;
    vector<BudgetEntry> budgetEntries;

    // Helper function to convert time_t to a readable format if neede
public:
    void logSession(const string& taskName, int duration, const string& mood);
    void logBudget(const string& category, double amount, const string& description);
    void exportDailyReport(const string& filename);

    // Additional methods for saving/loading data can be added
    // For example, to save sessions and budget entries to a file or database
    // and load them back when the application starts.
    // These methods can be implemented as needed.
    void saveData();
    void loadData();

    
};

#endif // TRACKER_H