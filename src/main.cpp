#include <iostream>
#include <vector>
using namespace std;

#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void printMatrix(const string &name, vector<vector<int>> &mat){
    cout << CYAN << "\n" << name << ":\n" << RESET;
    for(auto &row : mat){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << "\n";
    }
}

void printRAG(int processes, int resources, vector<vector<int>> &allocation, vector<vector<int>> &need){
    
    cout << YELLOW;
    cout << "\n======================================\n";
    cout << "      RESOURCE ALLOCATION GRAPH      \n";
    cout << "======================================\n";
    cout << RESET;

    cout << "\nAllocation Edges (Resource -> Process):\n";
    for(int i=0; i<processes; i++){
        for(int j=0; j<resources; j++){
            if(allocation[i][j] > 0){
                cout << "R" << j << " ---> P" << i << "\n";
            }
        }
    }

    cout << "\nRequest Edges (Process -> Resource):\n";
    for(int i=0; i<processes; i++){
        for(int j=0; j<resources; j++){
            if(need[i][j] > 0){
                cout << "P" << i << " ---> R" << j << "\n";
            }
        }
    }

    cout << "\n----------------------------------------\n";
}

int main() {

    int processes, resources;

    cout << YELLOW;
    cout << "======================================\n";
    cout << "      DEADLOCK DETECTION TOOLKIT      \n";
    cout << "======================================\n";
    cout << RESET;


    cout << "\nEnter number of processes: ";
    cin >> processes;

    cout << "Enter number of resources: ";
    cin >> resources;

    vector<vector<int>> allocation(processes, vector<int>(resources));
    vector<vector<int>> maxNeed(processes, vector<int>(resources));
    vector<int> available(resources);

    cout << CYAN << "\nEnter Allocation Matrix:\n" << RESET;
    for(int i = 0; i < processes; i++){
        for(int j = 0; j < resources; j++){
            cin >> allocation[i][j];
        }
    }

    cout << CYAN << "\nEnter Maximum Need Matrix:\n" << RESET;
    for(int i = 0; i < processes; i++){
        for(int j = 0; j < resources; j++){
            cin >> maxNeed[i][j];
        }
    }

    cout << CYAN << "\nEnter Available Resources:\n" << RESET;
    for(int j = 0; j < resources; j++){
        cin >> available[j];
    }

    //--------------------------
    // Calculate Need matrix
    //--------------------------
    
    vector<vector<int>> need(processes, vector<int>(resources));
    
    for(int i=0; i<processes; i++){
        for(int j=0; j<resources; j++){
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    //..show need matrix..
    printMatrix("Need Matrix",need);

    //..show RAG..
    printRAG(processes, resources, allocation, need);

    //--------------------------
    // Safety Algorithm
    //--------------------------
    
    vector<int> work = available;
    vector<bool> finish(processes, false);
    vector<int> safeSequence;

    int count = 0;

    while(count < processes){
        bool found = false;

        for(int p=0; p< processes; p++){
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
                    for(int r=0;r < resources;r++){
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

    cout << "\n=================================================\n";

    if(safe){
        cout << GREEN << "System is in SAFE STSTE.\n" << RESET;
        cout << "Safe Sequence: ";
        for(int i=0; i<processes; i++){
            cout << "p" << safeSequence[i];
            if(i != processes-1) cout << " -> ";
        }
        cout << "\n";
    }
    else{
        cout << RED << "DEADLOCK DETECTED!\n" << RESET;
        cout << "No Safe Sequence exists.\n";
    }

    cout << "=================================================\n";

    return 0;
}
