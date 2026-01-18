class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> machines(n);
        for(int j=0;j<n;j++)
        {
            machines[j] = {costs[j], capacity[j]};
        }
        sort(machines.begin(), machines.end());

        vector<int> prefixMaxi(n);
        if(n>0){
            prefixMaxi[0] = machines[0].second;
            for(int j=1;j<n;j++)
                prefixMaxi[j] = max(prefixMaxi[j-1], machines[j].second);
        }

        long long maxCap = 0;
        for(int j=0;j<n;j++)
        {
            int currCost = machines[j].first;
            int currCap = machines[j].second;

            if(currCost < budget)
            {
                maxCap = max(maxCap, (long long)currCap);
            }
            int remBudget = budget - currCost; 
            auto it = lower_bound(machines.begin(), machines.end(), remBudget, 
            [](const pair<int, int> &machine, int value)
            {
                return machine.first < value;
            });

            int index = distance(machines.begin(), it);
            int validIndLimit = min(index-1, j-1);

            if(validIndLimit >= 0)
            {
                long long currPairCap = (long long)currCap + prefixMaxi[validIndLimit];
                maxCap = max(maxCap, currPairCap);
            }
        }
        return (int)maxCap;
    }
};