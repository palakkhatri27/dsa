/* 
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.
*/

#include <vector>
#include <iostream>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size(), sum_gas = 0, sum_cost = 0, start = 0, curr_gas = 0;
    for(int i=0;i<n;i++) {
        sum_gas += gas.at(i);
        sum_cost += cost.at(i);

        curr_gas += gas.at(i)-cost.at(i);
        if(curr_gas<0) {
            start = i+1;
            curr_gas = 0;
        }
    }
    return sum_gas >= sum_cost ? start : -1;
}

int main() {
    vector<int> gas1 {1,2,3,4,5};
    vector<int> cost1 {3,4,5,1,2};
    cout<<canCompleteCircuit(gas1,cost1)<<endl;
    vector<int> gas2 {2,3,4};
    vector<int> cost2 {3,4,3};
    cout<<canCompleteCircuit(gas2,cost2)<<endl;
    vector<int> gas3 {5,1,2,3,4};
    vector<int> cost3 {4,4,1,5,1};
    cout<<canCompleteCircuit(gas3,cost3)<<endl;
    return 0;
}