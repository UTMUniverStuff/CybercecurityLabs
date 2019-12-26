def double_expo(base, exponent, modulo):
    result = 1
    while exponent > 0:
        if not exponent & 1:
            base = base**2 % modulo
            exponent >>= 1
        else:
            result = result * base % modulo
            exponent -= 1
    return result
