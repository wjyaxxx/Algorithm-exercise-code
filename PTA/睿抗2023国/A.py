import string
import re
n=int(input())
s=input()

cpys=s
for k in range(n):
    lis=list(s)
    for i in range(len(s)):
        c=lis[i]
        if c in string.ascii_lowercase:
            lis[i]=chr((ord(c)-ord('a')+25)%26+ord('a'))
        elif c in string.ascii_uppercase:
            lis[i]=chr((ord(c)-ord('A')+1)%26+ord('A'))
    s="".join(lis)
    result1= re.sub(r'([A-Z]{3,})', lambda x: x.group(0).lower(), s)
    result2 = re.sub(r'([a-z]{3,})', lambda x: x.group(0).upper(), s)
    ans=""
    for i in range(len(s)):
        c=s[i]
        if c in string.ascii_lowercase:
            ans+=result2[i]
        elif c in string.ascii_uppercase:
            ans+=result1[i]
        else:
            ans+=c
    s=ans
print(cpys)
print(s)

"""


"""

