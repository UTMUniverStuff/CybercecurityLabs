import argparse
import sys
from typing import Tuple, Iterable

from utils import double_expo


def encrypt(message: Iterable[int], public_key: Tuple[int, int]):
    key, n = public_key
    for m in message:
        yield double_expo(m, key, n)


def _parse_argv():
    parser = argparse.ArgumentParser()
    parser.add_argument('key', type=int)
    parser.add_argument('n', type=int)

    return parser.parse_args()


def main():
    argv = _parse_argv()
    message = sys.stdin.buffer.read()
    encrypted = encrypt(message, (argv.key, argv.n))

    for nb in encrypted:
        print(nb)


if __name__ == '__main__':
    main()

