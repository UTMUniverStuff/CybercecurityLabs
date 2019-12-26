import argparse
import sys

from decrypt import decrypt
from encrypt import encrypt
from rsa_keygen import generate_keypair


def _parse_argv():
    parser = argparse.ArgumentParser()
    parser.add_argument('--p', type=int)
    parser.add_argument('--q', type=int)

    return parser.parse_args()


def main():
    argv = _parse_argv()

    public_key, private_key = generate_keypair(argv.p, argv.q)
    print(f'Private key: {private_key} Public Key: {public_key}')

    message = sys.stdin.buffer.read()
    print(f'Original msg: {list(message)}')

    encrypted_msg = encrypt(message, public_key)
    print(f'Encrypted message: {encrypted_msg}')

    decrypted_msg = decrypt(encrypted_msg, private_key)
    print(f'Decrypted message: {bytes(decrypted_msg).decode("utf8")}')


# Some test cases
# いあめて お兄ちゃん
if __name__ == '__main__':
    main()
