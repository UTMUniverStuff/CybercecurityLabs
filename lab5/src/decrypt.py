import argparse
import sys
from typing import Iterable, Tuple

from utils import double_expo


def decrypt(encrypted_message: Iterable[int], private_key: Tuple[int, int]):
    key, n = private_key
    return (double_expo(c, key, n) for c in encrypted_message)


def _read_ints():
    for line in sys.stdin:
        yield int(line)


def _parse_argv():
    parser = argparse.ArgumentParser()
    parser.add_argument('key', type=int)
    parser.add_argument('n', type=int)

    return parser.parse_args()


def main():
    argv = _parse_argv()
    encrypted_msg = _read_ints()
    for nb in encrypted_msg:
        message = list(decrypt([nb], (argv.key, argv.n)))
        print(chr(message[0]), end='')


if __name__ == '__main__':
    main()
