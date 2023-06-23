def scramble(s1, s2):
    """Complete the function scramble(str1, str2) that returns true if a portion 
    of str1 characters can be rearranged to match str2, otherwise returns false.

    Args:
        s1 (str): String to locate the characters
        s2 (str): String to build

    Returns:
        bool: True if the problem can be solved. 
    """
    dic = {}
    
    for i in s1:
        if i in dic:
            dic[i] += 1
        else:
            dic.update({i:1})
        
    for i in s2:
        if i in dic:
            dic[i] -= 1
            if dic[i] < 0:
                return False
        else:
            return False
        
    return True