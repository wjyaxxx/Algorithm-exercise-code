import re

def modify_string(s):
    result = re.sub(r'([A-Z]{3,})', lambda x: x.group(0).lower(), s)
    result = re.sub(r'([a-z]{3,})', lambda x: x.group(0).upper(), result)
    return result

# 测试
s = "AABBCCCdddeeeFFF"
result = modify_string(s)
print(result)
