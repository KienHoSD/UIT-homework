# Python 3 program for the above approach
 
# Function to calculate total
# number of valid permutations
def validPermutations(str):
    m = {}
 
    # Creating count which is equal to the
    # Total number of characters present and
    # ans that will store the number of unique
    # permutations
    count = len(str)
    ans = 0
 
    # Storing frequency of each character
    # present in the string
    for i in range(len(str)):
        if(str[i] in m):
            m[str[i]] += 1
        else:
            m[str[i]] = 1
    for i in range(len(str)):
       
        # Adding count of characters by excluding
        # characters equal to current char
        ans += count - m[str[i]]
 
        # Reduce the frequency of the current character
        # and count by 1, so that it cannot interfere
        # with the calculations of the same elements
        # present to the right of it.
        m[str[i]] -= 1
        count -= 1
 
    # Return ans+1 (Because the given string
    # is also a unique permutation)
    return ans + 1
 
# Driver Code
if __name__ == '__main__':
    str = input()
    print(validPermutations(str))
 
    # This code is contributed by SURENDRA_GANGWAR.