pkg:setup
keychains = %w[
/System/Library/Keychains/SystemRootCertificates.keychain
]

certs_list = `security find-certificate -a -p #{keychains.join( )}`
certs = certs_list.scan(/-----BEGIN CERTIFICATE-----.*?-----END CERTIFICATE-----/m)

valid_certs = certs.select do |cert|
IO.popen(openssl x509 -inform pem -checkend 0 -noout w) do |openssl_io|
openssl_io.write(cert)
openssl_io.close_write