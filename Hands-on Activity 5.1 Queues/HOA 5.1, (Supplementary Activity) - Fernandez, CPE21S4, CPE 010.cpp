#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Job {
public:
    int id;
    string username;
    int pages;

    Job(int id, string username, int pages) {
        this->id = id;
        this->username = username;
        this->pages = pages;
    }

    void displayJob() {
        cout << "Job ID: " << id << endl;
        cout << "Username: " << username << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Printer {
private:
    vector<Job> jobs;
    int capacity;

public:
    Printer(int capacity) {
        this->capacity = capacity;
    }

    void addJob(Job job) {
        if (jobs.size() >= capacity) {
            cout << "The queue is full" << endl;
            return;
        }
        jobs.push_back(job);
    }

    void processJobs() {
        while (!jobs.empty()) {
            Job job = jobs.front();
            cout << "Printing..." << endl;
            job.displayJob();
            cout << "The print is done" << endl;
            cout << endl;
            jobs.erase(jobs.begin());
        }
    }
};

int main() {
    Printer printer(5);

    printer.addJob(Job(1, "Adia", 4));
    printer.addJob(Job(2, "Bell", 5));
    printer.addJob(Job(3, "Charles", 6));

    printer.processJobs();
    return 0;
}