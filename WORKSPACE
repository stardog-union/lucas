workspace(name = "lucas")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_googletest",
    urls = [
        "https://github.com/google/googletest/archive/release-1.8.1.zip",
    ],
    strip_prefix = "googletest-release-1.8.1",
)

http_archive(
    name = "toolchain",
    urls = [
#        "https://github.com/stardog-union/toolchain/archive/v3.zip",
        "file:///home/james/git/toolchain.tgz",
    ],
#    strip_prefix = "toolchain-3",
    strip_prefix = "toolchain",
)
