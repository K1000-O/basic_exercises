def prime_factors(n):
    """Given a positive number n > 1 find the prime factor decomposition of n. The result will be a string with the following form :

        "(p1**n1)(p2**n2)...(pk**nk)"

    Args:
        n (float)

    Returns:
        str: String containing the prime factor decomposition
    """
    str = ""
    cont = 0

    while n % 2 == 0:
        cont += 1
        n = n/2

    str += f"(2**{cont})" if cont > 1 else "(2)"

    if cont == 0: str = ""
    
    cont = 0
    for i in range(3,int(n+2),2):
        if i>n:
            break

        cont = 0
        while n % i == 0:
            cont += 1
            n = n/i

        if cont != 0:
            str += f"({i}**{cont})" if cont > 1 else f"({i})"
            bool=False
    
    return str