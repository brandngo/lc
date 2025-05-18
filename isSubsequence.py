def isSubsequence(s: str, t: str) -> bool:
    ind = 0
    if len(s) == 0:
        return True
    for i in t:
        if i == s[ind]:
            ind+=1
        if ind == len(s):
            return True
    
    return False


print(isSubsequence("", "aebbqet"))