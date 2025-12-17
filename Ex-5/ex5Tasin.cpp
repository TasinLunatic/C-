#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


int bruteForceSearch(const string &A, const string &B) {
    int m = A.size(), n = B.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && B[i + j] == A[j])
            j++;
        if (j == m)
            return i + 1; 
    }
    return -1;
}


void computeLPSArray(const string &A, int m, int lps[]) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (A[i] == A[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(const string &A, const string &B) {
    int m = A.size(), n = B.size();
    int *lps = new int[m];
    computeLPSArray(A, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (A[j] == B[i]) {
            i++;
            j++;
        }
        if (j == m) {
            delete[] lps;
            return i - j + 1;
        } else if (i < n && A[j] != B[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    delete[] lps;
    return -1;
}


string generateRandomString(int length) {
    string s = "";
    static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++)
        s += charset[rand() % 26];
    return s;
}


int main() {
    srand(time(0));

    string A, B;
    cout << "Enter string A: ";
    cin >> A;
    cout << "Enter string B: ";
    cin >> B;

 
    clock_t start = clock();
    int posBF = bruteForceSearch(A, B);
    clock_t end = clock();
    double timeBF = double(end - start) / CLOCKS_PER_SEC * 1000000;

    cout << "\nBrute Force Result: " << posBF << endl;
    cout << "Execution Time (microseconds): " << timeBF << endl;


    start = clock();
    int posKMP = KMPSearch(A, B);
    end = clock();
    double timeKMP = double(end - start) / CLOCKS_PER_SEC * 1000000;

    cout << "\nKMP Result: " << posKMP << endl;
    cout << "Execution Time (microseconds): " << timeKMP << endl;

  
    cout << "\nPerformance Test with Random Strings\n";
    for (int len = 100; len <= 1000; len += 300) {
        string randA = generateRandomString(len / 10);
        string randB = generateRandomString(len);

        start = clock();
        bruteForceSearch(randA, randB);
        end = clock();
        double bfTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

        start = clock();
        KMPSearch(randA, randB);
        end = clock();
        double kmpTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

        cout << "Length B=" << len 
             << " | BruteForce=" << bfTime 
             << " µs | KMP=" << kmpTime << " µs\n";
    }

    cout << "\nTime Complexity:\n";
    cout << "Brute Force: O(n * m)\n";
    cout << "KMP: O(n + m)\n";

    return 0;
}


