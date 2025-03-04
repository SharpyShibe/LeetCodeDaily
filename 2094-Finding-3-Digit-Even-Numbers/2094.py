#Simple, memory efficient solution;;
class Solution(object):
    def findEvenNumbers(self, digits):
        resSet = set()

        for p in itertools.permutations(digits,3):
            n = p[0]*100 + p[1]*10 + p[2]

            if p[0] != 0 and n%2 == 0: 
                resSet.add(n)
    
        return sorted(resSet)
        
