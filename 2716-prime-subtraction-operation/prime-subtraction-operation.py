primes = [2, 3, 5, 7, 11, 13]
primeSet = set(primes)

def addPrime():
    cand = primes[-1] + 2
    while not isPrime(cand):
        cand += 2
    primes.append(cand)
    primeSet.add(cand)

def isPrime(x):
    if x in primeSet:
        return True
    elif x <= primes[-1]:
        return False
    while primes[-1] ** 2 < x:
        addPrime()
    for p in primes:
        if x % p == 0:
            return False
        if p ** 2 > x:
            primeSet.add(x)
            return True
    raise ValueError("Invalid State")

class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        it = reversed(nums)
        t = next(it) - 1
        for c in it:
            if c <= t:
                t = c - 1
            else:
                d = c - t
                while primes[-1] < d:
                    addPrime()
                d = primes[bisect_left(primes, d)]
                if d >= c:
                    return False
                t = c - d - 1

        return True