def rot13(message):
    """Function that takes a string and returns the string ciphered with Rot13. 
    If there are numbers or special characters included in the string, they should be returned as they are. 
    Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation".

    Args:
        message (str): String to cipher

    Returns:
        str: String ciphered
    """
    aux = list(message)
    cont = 0
    for i in aux:
        if ord(i) >= 65 and ord(i) <= 90:
            aux[cont] = chr(ord(i)+13) if ord(i)+13 <= 90 else chr(64 + (13 - (90 - ord(i))))
            
        elif ord(i) >= 97 and ord(i) <= 122:
            aux[cont] = chr(ord(i)+13) if ord(i)+13 <= 122 else chr(96 + (13 - (122 - ord(i))))
            
        cont += 1
            
    return "".join(aux)