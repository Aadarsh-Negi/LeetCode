class Solution {
public:
    vector<double> convertTemperature(double c) {
        return {c + 273.1500000,c*1.80000 + 32.0000};
    }
};