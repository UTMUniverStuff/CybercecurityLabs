import argparse
import sys
from typing import Tuple, Iterable

from utils import double_expo


def encrypt(message: Iterable[int], public_key: Tuple[int, int]):
    key, n = public_key
    return (double_expo(m, key, n) for m in message)


def _parse_argv():
    parser = argparse.ArgumentParser()
    parser.add_argument('key', type=int)
    parser.add_argument('n', type=int)

    return parser.parse_args()


def _read_msg():
    for line in sys.stdin:
        for c in line:
            yield ord(c)


def main():
    argv = _parse_argv()
    message = _read_msg()
    encrypted = encrypt(message, (argv.key, argv.n))

    for nb in encrypted:
        print(nb)


if __name__ == '__main__':
    main()

