def high(x):
    """Given a string of words, you need to find the highest scoring word.

    Args:
        x (String): String of words

    Returns:
        String: Word with the highest score.
    """
    sum = 0
    aux = None
    sumAux = 0
    
    for i in x.split():
        for y in i:
            sum += (ord(y) - 96)
        
        if sum > sumAux:
            aux = i
            sumAux = sum
            
        sum = 0
    
    return aux