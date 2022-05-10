> Please note that using libsodium on ARM Cortex M0, M3, and M4 CPUs is untested and not recommended if side-channels are a concern.

**不推荐在 MCU 上使用 libsodium，请使用 libhydrogen 替代**.


![libsodium](https://raw.github.com/jedisct1/libsodium/master/logo.png)
============

Sodium is a new, easy-to-use software library for encryption,
decryption, signatures, password hashing and more.

It is a portable, cross-compilable, installable, packageable
fork of [NaCl](http://nacl.cr.yp.to/), with a compatible API, and an
extended API to improve usability even further.

Its goal is to provide all of the core operations needed to build
higher-level cryptographic tools.

Sodium supports a variety of compilers and operating systems,
including Windows (with MingW or Visual Studio, x86 and x64), iOS, Android,
as well as Javascript and Webassembly.

## Documentation

The documentation is available on Gitbook and built from the
[libsodium-doc](https://github.com/jedisct1/libsodium-doc) repository:

* [libsodium documentation](https://doc.libsodium.org) - online, requires Javascript.

## License

[ISC license](https://en.wikipedia.org/wiki/ISC_license).
