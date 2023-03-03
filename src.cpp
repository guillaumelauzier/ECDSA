#include <bitcoin/bitcoin.hpp>

int main() {
    // Generate a new keypair
    bc::ec_secret secret;
    bc::wallet::ec_scalar secret_scalar;
    bc::data_chunk secret_chunk = bc::data_chunk({0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef});
    std::copy(secret_chunk.begin(), secret_chunk.end(), secret_scalar.begin());
    bc::secret_to_public(secret, secret_scalar);

    // Create a message to sign
    std::string message = "Hello, world!";

    // Sign the message
    bc::data_chunk signature_data;
    bc::ec_signature signature;
    bc::hash_digest message_hash;
    bc::sha256_hasher hasher;
    hasher(message);
    hasher.finalize(message_hash);
    bc::sign_data(signature_data, secret, message_hash);
    signature.from_data(signature_data);

    // Verify the signature
    bool verified = bc::verify_signature(secret, message_hash, signature);
    std::cout << "Signature verified: " << verified << std::endl;

    return 0;
}
