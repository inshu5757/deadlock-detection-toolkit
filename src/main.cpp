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

    //--------------------------
    // Calculate Need matrix
    //--------------------------
    
    vector<vector<int>> need(processes, vector<int>(resources));
    
    for(int i=0;i<processes; i++){
        for(int j=0;j<resources;j++){
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }
    
    
    //--------------------------
    // Safety Algorithm
    //--------------------------

    vector<int> work = available;
    vector<bool> finish(processes, false);
    vector<int> safeSequence;

    int count = 0;

    while(count < processes){
        bool found = false;

        for(int p=0;p< processes;p++){
            if(!finish[p]){
                bool flag = true;
                
                for(int r=0;r<resources;r++){
                    if(need[p][r] > work[r]){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    //..Process can run safely
                    for(int r=0;resources;r++){
                        work[r] += allocation[p][r];
                    }

                    finish[p] = true;
                    safeSequence.push_back(p);
                    found = true;
                    count++;
                }
            }
        }

        if(!found){
            break;
        }
    }

    //--------------------------
    // Check if system is safe
    //--------------------------
    bool safe = true;
    for(int i=0;i<processes;i++){
        if(!finish[i]){
            safe = false;
            break;
        }
    }

    if(safe){
        cout << "\nSystem is in SAFE STSTE.\n";
        cout << "Safe Sequence: ";
        for(int i=0;i<processes;i++){
            cout << "p" << safeSequence[i];
            if(i != processes-1) cout << " -> ";
        }
        cout << "\n";
    }
    else{
        cout << "\nDEADLOCK DETECTED!\n";
        cout << "No Safe Sequence exists.\n";
    }

    return 0;
}
