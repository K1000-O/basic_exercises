def rgb(r, g, b):
    """The rgb function is incomplete. Complete it so that passing in RGB 
    decimal values will result in a hexadecimal representation being returned. 
    Valid decimal values for RGB are 0 - 255. Any values that fall out of that 
    range must be rounded to the closest valid value.

    Args:
        r (int): value between 0 and 255.
        g (int): value between 0 and 255.
        b (int): value between 0 and 255.

    Returns:
        str: string with the RGB in hezadecimal.
    """
    r = 0 if r < 0 else min(r, 255)
    g = 0 if g < 0 else min(g, 255)
    b = 0 if b < 0 else min(b, 255)
    
    return str(hex(r)[2:].zfill(2)+hex(g)[2:].zfill(2)+hex(b)[2:].zfill(2)).upper()