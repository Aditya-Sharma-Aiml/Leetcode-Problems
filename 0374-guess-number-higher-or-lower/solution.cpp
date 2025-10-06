/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        int low = 1 , high = n;
        while(low <= high) {

            int mid = low + (high - low ) /2 ;
            int res = guess(mid);

            if(res == 0) return mid;  // found the number
            else if(res == -1) high = mid - 1; //guessed number is too high → search left half.
            else low = mid + 1; //guessed number is too low → search right half.

        }
        return -1;
    }
};
