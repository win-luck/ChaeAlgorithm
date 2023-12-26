import sys
MOD=1000000007

a, b = map(int, input().split())
print((pow(b, a, MOD) - pow(b-1, a, MOD)) % MOD)
