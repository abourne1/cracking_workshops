# given two strings, 
# write a method to decide if one is a permutation of the other.

# TO RUN:
# >> python CTCI_1.3.py

def ChCount(word):
    # create an array of english aphabet size
    Chs = [0] * 26
    for ch in word:
        # ascii so minut 97 to get the value
        Chs[ord(ch)-97] += 1
    return Chs
        
def CompareCounts(Chs1, Chs2):
    # now just compare the counts for each letter
    for i in range(0, 26):
        if Chs1[i] != Chs2[i]:
            return False
            
    return True

def CheckForPermutation(word1, word2):
    Chs1 = ChCount(word1.lower())
    Chs2 = ChCount(word2.lower())

    if CompareCounts(Chs1, Chs2) == True:
        print(word1+ " "+word2 + " "+ " are permutations of each other")
    else:
        print(word1+ " "+word2 + " "+ " are NOT permutations of each other")


word1 = "coolio"
word2 =  "ooocli"
CheckForPermutation(word1, word2)
CheckForPermutation(word1, word2[:-1]+"a")