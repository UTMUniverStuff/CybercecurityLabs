import argparse
import random
from math import gcd


def multiplicative_inverse(e, phi):
    d = 0
    x1 = 0
    x2 = 1
    y1 = 1
    temp_phi = phi

    while e > 0:
        temp1 = temp_phi // e
        temp2 = temp_phi - temp1 * e
        temp_phi = e
        e = temp2

        x = x2 - temp1 * x1
        y = d - temp1 * y1

        x2 = x1
        x1 = x
        d = y1
        y1 = y

    return d + phi


def is_prime(num):
    if num == 2:
        return True
    if num < 2 or num % 2 == 0:
        return False
    for n in range(3, int(num ** 0.5) + 2, 2):
        if num % n == 0:
            return False
    return True


def _validate_input(p, q):
    if not (is_prime(p) and is_prime(q)):
        raise ValueError('Both numbers must be prime.')
    elif p == q:
        raise ValueError('p and q cannot be equal')


def generate_keypair(p: int, q: int):
    _validate_input(p, q)

    n = p * q
    phi = (p - 1) * (q - 1)
    e = random.randrange(2, phi)
    g = gcd(e, phi)
    while g != 1:
        e = random.randrange(2, phi)
        g = gcd(e, phi)

    d = multiplicative_inverse(e, phi)

    return (e, n), (d, n)


def _parse_argv():
    parser = argparse.ArgumentParser()
    parser.add_argument('p', type=int)
    parser.add_argument('q', type=int)

    return parser.parse_args()


if __name__ == '__main__':
    argv = _parse_argv()
    public_key, private_key = generate_keypair(argv.p, argv.q)
    print(public_key[0], private_key[0], private_key[1])
