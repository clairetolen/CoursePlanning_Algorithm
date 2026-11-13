#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std ;
/// number of prereques before course = number of semesters that must be completed before


int main(){
   int totalSem = 0;
    int n = 15; //number of courses

    vector<vector<int>> graph(n+1); //which course unlocks which other course
    vector<int> prereq (n+1, 0); // how many prereqs each course has
    queue<int> ready; //stores order/ course that is ready

    
    
    //////PHASE 2 PREREQS//// 

    // cs4 
    graph[2].push_back(4);
    prereq[4]++; 

    //12
    graph[3].push_back(12);
    prereq[12]++; 

    //CS6 
    graph[3].push_back(6);
    prereq[6]++; 
    graph[1].push_back(6);
    prereq[6]++; 


    /// PHRASE 3 ////

    //CS5 
    graph[4].push_back(5);
    prereq[5]++; 

    /// 7
    graph[4].push_back(7);
    prereq[7]++; 
    
    // 14
     graph[4].push_back(14);
    prereq[14]++; 
     graph[6].push_back(14);
    prereq[14]++; 

    //13
     graph[6].push_back(13);
    prereq[13]++; 

    /// PHASE 4 /////

    //15
    graph[14].push_back(15);
    prereq[15]++; 
    
    /// 8
    graph[6].push_back(8);
    prereq[8]++; 
    graph[5].push_back(8);
    prereq[8]++; 
    
    ///9
    graph[7].push_back(9);
    prereq[9]++; 
    

    /// PHASE 5
    
    //CS10
    graph[9].push_back(10);
    prereq[10]++; 

    //CS 11
    graph[8].push_back(11);
    prereq[11]++; 
    
    ///////////////////////////////////////////////////////////////////


    // start queueing thoe with no prereqs
    for (int i = 1; i<=n ; i++){
        if (prereq[i] == 0){
            ready.push(i);
        }
    }
    
    auto start = chrono::high_resolution_clock::now();  
    //pop all courses from ready (allowed to take this sem)
    while (!ready.empty()){
        int currSem = ready.size();
        totalSem++;

        for (int i = 0; i< currSem; i++){
            int curr = ready.front();
            ready.pop();

            for (int j = 0; j < graph[curr].size(); j++){

                // curr maps to j
                int next = graph[curr][j];

                prereq[next]--;

                if (prereq[next]== 0){
                    /// no more prereqs required, so add to ready queue

                    ready.push(next);
                }
            }
        }

    }
    auto end = chrono::high_resolution_clock::now();  
    chrono::duration<double,milli> runtime = end-start;
    cout << "minimum semesters needed: " << totalSem <<endl;
    cout <<" "<< endl;

    cout<< "running time: " <<runtime.count()<< " ms" <<endl;

}