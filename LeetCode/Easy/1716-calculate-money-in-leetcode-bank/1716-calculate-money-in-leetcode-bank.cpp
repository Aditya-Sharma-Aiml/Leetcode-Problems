class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;  // Number of complete weeks
        int days = n % 7;  // Remaining days after full weeks

        // Sum of full weeks:
        // Each week sum = 28, 35, 42, ... -> AP with a1=28, d=7
        // Sum_of_weeks = week/2 * [2*a1 + (week-1)*d]
        // Do integer-safe computation so division happens last:
        // = week * 28 + (7 * week * (week - 1)) / 2
        long long total = 0;
        total = 1LL * week * 28 + (1LL * 7 * week * (week - 1)) / 2;

        // Remaining days:
        // deposits: (week+1), (week+2), ..., (week+days)
        // Sum = days * (2*week + days + 1) / 2  (safe if multiply before divide)
        total += (1LL * days * (2 * week + days + 1)) / 2;

        return (int) total;
    }
};