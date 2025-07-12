#include <iostream>
#include "src/tracker.h"
using namespace std;

int main() {
    GRINDCore grind;

    grind.loadData(); // Load existing data if available

    grind.logSession("Studied for Algorithms", 120, "Focused");
    grind.logBudget("Food", 15.50, "Lunch at cafe");
    grind.logBudget ("Freelance", 300.00, "Income:Payment for project");

    grind.saveData(); // Save current data to files

    grind.exportDailyReport("daily_report.txt");

    return 0;
}