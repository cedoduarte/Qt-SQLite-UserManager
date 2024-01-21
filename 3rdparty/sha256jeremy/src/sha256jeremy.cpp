#include "sha256jeremy.h"
#include "SHA256.h"

QString Sha256jeremy::encode(const QString &input)
{
    SHA256 sha;
    sha.update(input.toStdString());
    std::array<uint8_t, 32> digest = sha.digest();
    std::string hash = SHA256::toString(digest);
    QString result = QString::fromStdString(hash);
    return result;
}
