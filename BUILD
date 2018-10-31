package(default_visibility = ["//visibility:public"])

config_setting(
    name = "linux",
    constraint_values = [
        "@bazel_tools//platforms:linux",
    ],
    visibility = ["//visibility:public"],
)

config_setting(
    name = "osx",
    constraint_values = [
        "@bazel_tools//platforms:osx",
    ],
    visibility = ["//visibility:public"],
)

config_setting(
    name = "windows",
    constraint_values = [
        "@bazel_tools//platforms:windows",
    ],
    visibility = ["//visibility:public"],
)

PLATFORM_DEFINES = select({
    ":linux": [
        "OS_LINUX",
    ],
    ":osx": [
        "OS_MACOSX",
    ],
    ":windows": [
        "OS_WIN",
    ],
    "//conditions:default": [],
})

cc_library(
    name = "lucas",
    hdrs = ["lucas.h"],
    srcs = ["lucas.cc"],
    linkstatic = 1,
    defines = PLATFORM_DEFINES,
)

cc_binary(
    name = "liblucas.so",
    deps = [
        ":lucas",
    ],
    defines = PLATFORM_DEFINES,
    linkshared = True,
    linkopts = [
        "-static-libgcc",
        "-static-libstdc++",
    ],
)

cc_binary(
    name = "fib",
    srcs = ["fib.cc"],
    deps = [":lucas"],
    defines = PLATFORM_DEFINES,
)
