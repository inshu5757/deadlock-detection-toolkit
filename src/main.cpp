#include <iostream>
#include <vector>
using namespace std;

int main() {

    int processes, resources;

    cout << "Enter number of processes: ";
    cin >> processes;

    cout << "Enter number of resources: ";
    cin >> resources;

    vector<vector<int>> allocation(processes, vector<int>(resources));
    vector<vector<int>> maxNeed(processes, vector<int>(resources));
    vector<int> available(resources);

    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < processes; i++){
        for(int j = 0; j < resources; j++){
            cin >> allocation[i][j];
        }
    }

    cout << "\nEnter Maximum Need Matrix:\n";
    for(int i = 0; i < processes; i++){
        for(int j = 0; j < resources; j++){
            cin >> maxNeed[i][j];
        }
    }

    cout << "\nEnter Available Resources:\n";
    for(int j = 0; j < resources; j++){
        cin >> available[j];
    }

    cout << "\nINPUT CAPTURED SUCCESSFULLY!\n";

    return 0;
}
