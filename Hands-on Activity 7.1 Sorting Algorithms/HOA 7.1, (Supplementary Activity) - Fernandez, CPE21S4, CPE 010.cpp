#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void voteCounter(int arr[], int n) {
  int votes[5] = {0};
  int maxVotes = 0;
  int winningCandidate;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) votes[0]++;
    else if (arr[i] == 2) votes[1]++;
    else if (arr[i] == 3) votes[2]++;
    else if (arr[i] == 4) votes[3]++;
    else if (arr[i] == 5) votes[4]++;
  }
  for (int i = 0; i < 5; i++) {
    if (votes[i] > maxVotes) {
      maxVotes = votes[i];
      winningCandidate = i + 1;
    }
  }
  cout << "Votes for each candidate:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "Candidate " << i + 1 << ": " << votes[i] << endl;
  }
  cout << "Winning candidate: " << winningCandidate << endl;
  cout << "Maximum votes: " << maxVotes << endl;
}

int main() {
  srand(time(0));
  int arr[101];
  for (int i = 0; i < 101; i++) {
    arr[i] = rand() % 5 + 1;
  }
  insertionSort(arr, 101);
  voteCounter(arr, 101);
  return 0;
}