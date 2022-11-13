class Solution {
public:
    vector<double> convertTemperature(double c) {
        return {c + 273.15000000,c*1.800000 + 32.000000};
    }
};