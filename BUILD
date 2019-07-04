package(default_visibility = ["//visibility:public"])

PLATFORM_DEFINES = select({
    "@toolchain//:is_target_linux" : [
        "OS_LINUX",
    ],

    "@toolchain//:is_target_osx" : [
        "OS_MACOSX",
    ],

    "@toolchain//:is_target_windows" : [
        "OS_WIN",
    ],

    "//conditions:default": [],
})

cc_library(
    name = "lucas",
    hdrs = ["lucas.h"],
    srcs = ["lucas.cc"],
    defines = PLATFORM_DEFINES,
    linkstatic = True,
    alwayslink = True,
)

cc_library(
    name = "recaman_lib",
    hdrs = ["recaman.h"],
    srcs = ["recaman.cc"],
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

cc_binary(
    name = "recaman",
    deps = [":recaman_lib"],
    defines = PLATFORM_DEFINES,
)
