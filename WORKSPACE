workspace(name = "lucas")

http_archive(
    name = "toolchain",
    urls = [
        # The file: URL is useful for testing the build, but is not generally necessary since Bazel handles caching
        # external dependencies.
        # TODO(james): Remove this URL when the Bazel build is stable.
        # "file:///home/james/git/toolchain-master.tgz",
        "https://github.com/stardog-union/toolchain/archive/master.zip",
    ],
    strip_prefix = "toolchain-master",
)
