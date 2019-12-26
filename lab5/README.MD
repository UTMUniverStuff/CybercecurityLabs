~~~bash
# To generate the keys and export them in some vars
read PUBLIC_KEY PRIVATE_KEY RSA_N <  <(python3 src/rsa_keygen.py 5419 5573) && export PUBLIC_KEY PRIVATE_KEY RSA_N

# Print the generated keys (optional)
echo $PUBLIC_KEY $PRIVATE_KEY $RSA_N

# Encrypt & decrypt. The encrypted numbers are sent to decrypt. The keys are taken from environment vars.
python3 src/encrypt.py $PRIVATE_KEY $RSA_N < stalin.txt | python3 src/decrypt.py $PUBLIC_KEY $RSA_N
~~~
