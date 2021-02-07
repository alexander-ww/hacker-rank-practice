#include <vector>
#include <string>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/**
 * Gets the rotated version of an index.
 *
 * This method accepts a positive integer
 * representing a current index that has
 * not yet been rotated, a positive integer
 * representing the amount of left shifts
 * to perform for the rotation, and a
 * positive integer representing the size
 * of the array being rotated. Upon the
 * receipt of these inputs, the method
 * returns a positive integer representing
 * the location of the index after rotation
 * has been performed.
 *
 * @param i The current index.
 * @param d The left shifts to perform.
 * @param n The size of the array to rotate.
 *
 * @return The rotated index.
 *
 * Complexity:
 * - O(1) time
 * - O(1) space
 */
 int rotatedIndex(int i, int d, int n) {
 
     /**
      * Get the actual number of spaces
      * that will be moved for each value
      * in the array.
      *
      * Since full movements are effectively
      * non-movement, the remainder or partial
      * movement is the only type of movement
      * that will actually be occuring.
      */
     int remainder = d % n;

     /**
      * All left movements in an array
      * are effectively negative movements
      * when it comes to the array indices.
      * This means that the remainder will
      * be subtracted from the current index
      * in an attempt to get the rotated index.
      */
     int rotated = i - remainder;

     /**
      * Negative values are shifted to the
      * right side of the array (effectively
      * a bounce by the size of the array).
      * Consequently, this statement handles
      * negative index values when subtracting
      * the remainder for left shifting.
      */
     if (rotated < 0) {
         rotated += n;
     }

     return rotated;
 }
 
 /**
  * Rotates an array in-place.
  *
  * This method accepts a positive integer
  * representing the number of left shifts
  * to perform and an array of values to
  * rotate with those left shifts. Upon
  * the receipt of these values, the method
  * rotates the array in-place and returns
  * the rotated array as output.
  *
  * @param d The number of left shifts.
  * @param arr The array to rotate.
  *
  * @return The rotated array.
  *
  * Complexity:
  * - O(n) time
  * - O(1) space
  */
vector<int> rotateLeft(int d, vector<int> arr) {

    /**
     * Prepare loop variables.
     *
     * These variables help to temporarily
     * store data and track the iteration
     * oand current non-rotated index while
     * traversing through the array.
     *
     * Complexity:
     * - O(1) time
     * - O(1) space
     */
    int i = 0;
    int n = arr.size();
    int temporary1 = 0;
    int temporary2 = 0;
    int iterations = 0;

    /**
     * Prepare cycle variables.
     *
     * These variables help to track the
     * current cycle, the number of cycles,
     * and whether a cycle has started. There
     * are cycles when the number of left
     * shifts to perform evenly divides the
     * size of the array to rotate.
     *
     * Complexity:
     * - O(1) time
     * - O(1) space
     */
    int cycle = 0;
    int cycles = n / d;
    bool started = false;

    /**
     * Performs left-rotation.
     *
     * Rotating an array left by a given
     * number of left shifts involves n
     * movements of values. Conceptually,
     * we can view this as performing n
     * swap operations.
     *
     * When a remainder exists for the array
     * size divided by the number of left
     * shifts to perform, the swaps can be
     * performed by jumping from rotated
     * index to rotated index and carrying
     * values that are needed for the swap.
     * With a remainder, this hopping strategy
     * is guaranteed to ensure that all values
     * in the original array are visited and
     * properly swapped. This guarantee comes
     * from the remainder perturbing us out of
     * so-called "swap cycles".
     *
     * When we do not have a remainder, we need
     * to be knowledgeable about the number of
     * cycles that we have and the cycle length.
     * This information is used to actively perturb
     * us out of each swap cycle when they conclude.
     * We still perform a total of n swaps just as
     * before, but we actively perturb when needed.
     *
     * Complexity:
     * - O(n) time
     * - O(1) space
     */
    while (iterations < n) {

        /**
         * Handle cycles.
         *
         * If the size of the array is
         * evenly divisible by the number
         * of left shifts to perform, then
         * we have cycles of swapping that
         * we need to actively perturb out
         * of. This block of code manages
         * that perturbing by incrementing
         * into a new cycle when the current
         * cycle has concluded.
         *
         * Complexity:
         * - O(1) time
         * - O(1) space
         */
        if (n % d == 0) {

            /**
             * Perform cycle transition.
             *
             * Each cycle of swapping is as long as
             * the total number of cycles that exist
             * in the array. This number of cycles is
             * equal in number to the size of the array
             * divided by the number of left shifts to
             * perform.
             *
             * Every time that iteration concludes
             * a cycle that we are transitioning
             * into another cycle by starting that
             * cycle with its first index.
             *
             * Complexity:
             * - O(1) time
             * - O(1) space
             */
             if (iterations % cycles == 0) {
             
                 /**
                  * Handle first cycle.
                  *
                  * The first cycle starts
                  * at the zero index.
                  *
                  * Complexity:
                  * - O(1) time
                  * - O(1) space
                  */
                 if (iterations == 0) {
                     cycle = 0;
                 }
                 
                 /**
                  * Handle subsequent cycles.
                  *
                  * Each subsequent cycle starts an
                  * index that is one index apart from
                  * the previous cycle index. Increments
                  * of 1 ensure that a new cycle is entered.
                  *
                  * Complexity:
                  * - O(1) time
                  * - O(1) space
                  */
                 else {
                     cycle++;
                 }

                 /**
                  * Update index.
                  *
                  * The current index that is
                  * to be rotated will be the
                  * index for the start of the
                  * cycle.
                  *
                  * As we move within the cycle
                  * we will hop to each of the
                  * rotated indices.
                  *
                  * Complexity:
                  * - O(1) time
                  * - O(1) space
                  */
                 i = cycle;
 
                 /**
                  * Indicate cycle start.
                  *
                  * Now that we have started a
                  * new cycle we can indicate its
                  * start and save this state.
                  *
                  * Complexity:
                  * - O(1) time
                  * - O(1) space
                  */
                 started = true;
             }
        }
        
        /**
         * Get rotated index.
         *
         * Rotates the current index by 
         * the number of left rotations
         * to get the new index.
         *
         * Complexity:
         * - O(1) time
         * - O(1) space
         */
        int rotated = rotatedIndex(i, d, n);
        
        /**
         * Perform swap (first iteration)
         *
         * Upon the first iteration overall or
         * for a cycle, the first instance of
         * temporary storage is free for use
         * (we are not yet carrying a value).
         * Consequently, this block makes use
         * of the first instance of temporary
         * storage for the eventual carry when
         * hopping to the rotated index.
         *
         * Complexity:
         * - O(1) time
         * - O(1) space
         */
        if (iterations == 0 || started) {
            temporary1 = arr.at(rotated);
            arr.at(rotated) = arr.at(i);
            started = false;
        }
        
        /**
         * Perform swap (subsequent iterations)
         *
         * Upon each subsequent iteration overall
         * or within a cycle, the first instance
         * of temporary storage is not free because
         * it is carrying a value. Consequnetly, the
         * second instance of temporary storage is
         * used to perform the swap. The first
         * instance of temporary storage is then
         * used again in support of the carry of
         * the next value.
         *
         * Complexity:
         * - O(1) time
         * - O(1) space
         */
        else {
            temporary2 = arr.at(rotated);
            arr.at(rotated) = temporary1;
            temporary1 = temporary2;
        }
        
        /**
         * Hop to next index.
         *
         * This block takes the
         * rotated index and sets
         * it as the next index to
         * rotate.
         *
         * Complexity:
         * - O(1) time
         * - O(1) space
         */
        i = rotated;
        
        /**
         * Update iterations.
         *
         * This block updates the
         * current iteration so that
         * we can halt when we meet n
         * iterations. This ensures
         * that we perform the n swaps.
         *
         * Complexity:
         * - O(1) time
         * - O(1) space
         */
        iterations++;
    }
    
    return arr;
}

int main() {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);
    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
    int n = stoi(first_multiple_input[0]);
    int d = stoi(first_multiple_input[1]);
    string arr_temp_temp;
    getline(cin, arr_temp_temp);
    vector<string> arr_temp = split(rtrim(arr_temp_temp));
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }
    vector<int> result = rotateLeft(d, arr);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int> (isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int> (isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
