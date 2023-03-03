# ECDSA

The Elliptic Curve Digital Signature Algorithm (ECDSA) is the digital signature algorithm used for ordinals and inscriptions on Bitcoin. It is used to prove ownership of private keys and to sign transactions. ECDSA is a variant of the Digital Signature Algorithm (DSA) that uses elliptic curve cryptography. It provides a high level of security while requiring shorter key lengths and computation times compared to other digital signature algorithms like RSA.

# src.cpp

In this example, a new keypair is generated, a message is created, and the message is signed using the sign_data() function provided by libbitcoin. The resulting signature is then verified using the verify_signature() function. This example uses the ec_secret and ec_signature types provided by libbitcoin, which represent the secret and signature components of an ECDSA keypair, respectively.
