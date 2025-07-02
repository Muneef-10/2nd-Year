#include <iostream>
using namespace std;

void quickSortAscending(double arr[], int left, int right) {
    if (left < right) {
        double pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);

        int partitionIndex = i + 1;
        quickSortAscending(arr, left, partitionIndex - 1);
        quickSortAscending(arr, partitionIndex + 1, right);
    }
}

void quickSortDescending(double arr[], int left, int right) {
    if (left < right) {
        double pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j] >= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);

        int partitionIndex = i + 1;
        quickSortDescending(arr, left, partitionIndex - 1);
        quickSortDescending(arr, partitionIndex + 1, right);
    }
}

bool searchStockPrice(double arr[], int size, double price) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == price)
            return true;
    }
    return false;
}

int main() {
    int N;
    cout << "Enter the number of companies: ";
    cin >> N;

    double* stockPrices = new double[N];
    bool* priceIncreased = new bool[N];
    int increasedCount = 0, decreasedCount = 0;

    for (int i = 0; i < N; i++) {
        cout << "Enter the stock price of company " << (i + 1) << ": ";
        cin >> stockPrices[i];

        cout << "Did the stock price rise compared to yesterday? (1 for TRUE, 0 for FALSE): ";
        cin >> priceIncreased[i];

        if (priceIncreased[i])
            increasedCount++;
        else
            decreasedCount++;
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display the companies stock prices in ascending order\n";
        cout << "2. Display the companies stock prices in descending order\n";
        cout << "3. Display the total number of companies for which stock prices rose today\n";
        cout << "4. Display the total number of companies for which stock prices declined today\n";
        cout << "5. Search a specific stock price\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double* temp = new double[N];
                for (int i = 0; i < N; i++) temp[i] = stockPrices[i];
                quickSortAscending(temp, 0, N - 1);

                cout << "Stock prices in ascending order: ";
                for (int i = 0; i < N; i++) cout << temp[i] << " ";
                cout << endl;

                delete[] temp;
                break;
            }
            case 2: {
                double* temp = new double[N];
                for (int i = 0; i < N; i++) temp[i] = stockPrices[i];
                quickSortDescending(temp, 0, N - 1);

                cout << "Stock prices in descending order: ";
                for (int i = 0; i < N; i++) cout << temp[i] << " ";
                cout << endl;

                delete[] temp;
                break;
            }
            case 3:
                cout << "Total number of companies whose stock prices rose today: " << increasedCount << endl;
                break;
            case 4:
                cout << "Total number of companies whose stock prices declined today: " << decreasedCount << endl;
                break;
            case 5: {
                double price;
                cout << "Enter the stock price to search: ";
                cin >> price;

                if (searchStockPrice(stockPrices, N, price))
                    cout << "Stock price found." << endl;
                else
                    cout << "Stock price not found." << endl;
                break;
            }
            case 6:
                cout << "Exiting the application." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    delete[] stockPrices;
    delete[] priceIncreased;

    return 0;
}
