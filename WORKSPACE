workspace(name = "lucas")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


com_google_googletest_version="release-1.8.1"
toolchain_version="bazel_0.26"

http_archive(
    name = "com_google_googletest",
    urls = [
        "https://github.com/google/googletest/archive/%s.zip" % com_google_googletest_version,
    ],
    strip_prefix = "googletest-%s" % com_google_googletest_version,
)

http_archive(
    name = "toolchain",
    urls = [
        "https://github.com/stardog-union/toolchain/archive/%s.zip" % toolchain_version,
    ],
    strip_prefix = "toolchain-%s" % toolchain_version,
)

http_archive(
    name = "toolchain-local",
    urls = [
        "file:///home/james/git/toolchain.tgz",
    ],
    strip_prefix = "toolchain",
)
