def in_array(array1, array2):    
    """Given two arrays of strings a1 and a2 return a sorted array r in lexicographical order of the strings of a1 which are substrings of strings of a2.

    Example 1:
        a1 = ["arp", "live", "strong"]

        a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

        returns ["arp", "live", "strong"]

    Args:
        array1 (String): strings to search for substrings
        array2 (String): strings to compare

    Returns:
        List: sorted array
    """
    aux = []
    
    for str in array1:
        for x in array2:
            if x.find(str) != -1:
                aux.append(str)
                break
    
    aux = list(set(aux))
    aux.sort()
    
    return aux