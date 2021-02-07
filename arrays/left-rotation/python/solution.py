#!/bin/python3

import math
import os
import random
import re
import sys


def rotatedIndex(i, d, n):
    """ Gets the rotated version of an index.

    This method accepts a positive integer
    representing a current index that has
    not yet been rotated, a positive integer
    representing the amount of left shifts
    to perform for the rotation, and a
    positive integer representing the size
    of the array being rotated. Upon the
    receipt of these inputs, the method
    returns a positive integer representing
    the location of the index after rotation
    has been performed.
    
    :param i: The current index.
    :type i: int
    :param d: The left shifts to perform.
    :type d: int
    :param n: The size of the array to rotate.
    :type n: int

    :return: The rotated index.
    :rtype: int

    Complexity:
    - O(1) time
    - O(1) space
    """

    ##
    # Get the actual number of spaces
    # that will be moved for each value
    # in the array.
    #
    # Since full movements are effectively
    # non-movement, the remainder or partial
    # movement is the only type of movement
    # that will actually be occurring.
    #
    remainder = d % n

    ##
    # All left movements in an array
    # are effectively negative movements
    # when it comes to the array indices.
    # This means that the remainder will
    # be subtracted from the current index
    # in an attempt to get the rotated index.
    #
    rotated = i - remainder

    ##
    # Negative values are shifted to the
    # right side of the array (effectively
    # a bounce by the size of the array).
    # Consequently, this statement handles
    # negative index values when subtracting
    # the remainder for left shifting.
    #
    if rotated < 0:
        rotated += n

    return rotated

def rotateLeft(d, arr):
    """ Rotates an array in-place.

    This method accepts a positive integer
    representing the number of left shifts
    to perform and an array of values to
    rotate with those left shifts. Upon
    the receipt of these values, the method
    rotates the array in-place and returns
    the rotated array as output.

    :param d: The number of left shifts.
    :type d: int
    :param arr: The array to rotate.
    :type arr: list of <int>

    :return: The rotated array.
    :rtype: list of <int>

    Complexity:
    - O(n) time
    - O(1) space
    """

    ##
    # Prepare loop variables.
    #
    # These variables help to temporarily
    # store data and track the iteration
    # and current non-rotated index while
    # traversing through the array.
    #
    # Complexity:
    # - O(1) time
    # - O(1) space
    #
    i = 0
    n = len(arr)
    temporary1 = 0
    temporary2 = 0
    iterations = 0

    ##
    # Prepare cycle variables.
    #
    # These variables help to track the
    # current cycle, the number of cycles,
    # and whether a cycle has started.
    # There are cycles when the number
    # of left shifts to perform evenly
    # divides the size of the array to
    # rotate.
    #
    # Complexity:
    # - O(1) time
    # - O(1) space
    #
    cycle = 0
    cycles = n / d
    started = False

    ##
    # Performs left-rotation.
    #
    # Rotating an array left by a given
    # number of left shifts involves n
    # movements of values. Conceptually,
    # we can view this as performing n
    # swap operations.
    #
    # When a remainder exists for the array
    # size divided by the number of left
    # shifts to perform, the swaps can be
    # performed by jumping from rotated
    # index to rotated index and carrying
    # values that are needed for the swap.
    # With a remainder, this hopping strategy
    # is guaranteed to ensure that all values
    # in the original array are visited and
    # properly swapped. This guarantee comes
    # from the remainder perturbing us out of
    # so-called "swap cycles".
    #
    # When we do not have a remainder, we need
    # to be knowledgeable about the number of
    # cycles that we have and the cycle length.
    # This information is used to actively perturb
    # us out of each swap cycle when the conclude.
    # We still perform a total of n swaps just as
    # before, but we actively perturb when needed.
    #
    # Complexity:
    # - O(n) time
    # - O(1) space
    #
    while iterations < n:

        ##
        # Handle cycles.
        #
        # If the size of the array is
        # evenly divisible by the number
        # of left shifts to perform, then
        # we have cycles of swapping that
        # we need to actively perturb out
        # of. This block of code manages
        # that perturbing by incrementing
        # into a new cycle when the current
        # cycle has concluded.
        #
        # Complexity:
        # - O(1) time
        # - O(1) space
        #
        if n % d == 0:

            ##
            # Perform cycle transition.
            #
            # Each cycle of swapping is as long as
            # the total number of cycles that exist
            # in the array. This number of cycles is
            # equal in number to the size of the array
            # divided by the number of left shifts to
            # perform.
            #
            # Every time that iteration concludes a
            # cycle, we are transitioning into another
            # cycle by starting that cycle with its
            # first index.
            #
            # Complexity:
            # - O(1) time
            # - O(1) space
            #
            if iterations % cycles == 0:
            
                ##
                # Handle first cycle.
                #
                # The first cycle starts
                # at the zero index.
                #
                # Complexity:
                # - O(1) time
                # - O(1) space
                #
                if iterations == 0:
                    cycle = 0

                ##
                # Handle subsequent cycles.
                #
                # Each subsequent cycle starts an
                # index that is one index apart from
                # the previous cycle index. Increments
                # of 1 ensure that a new cycle is entered.
                #
                # Complexity:
                # - O(1) time
                # - O(1) space
                #
                else:
                    cycle++

                ##
                # Update index.
                #
                # The current index that is
                # to be rotated will be the
                # index for the start of the
                # cycle.
                #
                # As we move within the cycle
                # we will hop to each of the
                # rotated indices.
                #
                # Complexity:
                # - O(1) time
                # - O(1) space
                #
                i = cycle

                ##
                # Indicate cycle start.
                #
                # Now that we have started a
                # new cycle we can indicate its
                # start and save this state.
                #
                # Complexity:
                # - O(1) time
                # - O(1) space
                #
                started = True

        ##
        # Get rotated index.
        #
        # Rotates the current index by
        # the number of left rotations
        # to get the new index.
        #
        # Complexity:
        # - O(1) time
        # - O(1) space
        #
        rotated = rotatedIndex(i, d, n)

        ##
        # Perform swap (first iteration)
        #
        # Upon the first iteration overall or
        # for a cycle, the first instance of
        # temporary storage is free for use
        # (we are not yet carrying a value).
        # Consequently, this block makes use
        # of the first instance of temporary
        # storage for the eventual carry when
        # hopping to the rotated index.
        #
        # Complexity:
        # - O(1) time
        # - O(1) space
        #
        if iterations == 0 or started:
            temporary1 = arr[rotated]
            arr[rotated] = arr[i]
            started = False

        ##
        # Perform swap (subsequent iterations)
        #
        # Upon each subsequent iteration overall
        # or within a cycle, the first instance
        # of temporary storage is not free because
        # it is carrying a value. Consequently, the
        # second instance of temporary storage is
        # used to perform the swap. The first
        # instance of temporary storage is then
        # used again in support of the carry of
        # the next value.
        #
        # Complexity:
        # - O(1) time
        # - O(1) space
        #
        else:
            temporary2 = arr[rotated]
            arr[rotated] = temporary1
            temporary1 = temporary2

        ##
        # Hop to next index.
        #
        # This block takes the
        # rotated index and sets
        # it as the next index to
        # rotate.
        #
        # Complexity:
        # - O(1) time
        # - O(1) space
        #
        i = rotated

        ##
        # Update iterations.
        #
        # This block updates the
        # current iteration so that
        # we can halt when we meet n
        # iterations. This ensures that
        # we perform the n swaps.
        #
        # Complexity:
        # - O(1) time
        # - O(1) space
        #
        iterations++

    return arr


if __name__ == '__main__':

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    d = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    result = rotateLeft(d, arr)

    print(' '.join(map(str, result)))
