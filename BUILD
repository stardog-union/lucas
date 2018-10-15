package(default_visibility = ["//visibility:public"])

cc_library(
    name = "lucas",
    hdrs = ["lucas.h"],
)

cc_binary(
    name = "fib",
    srcs = ["fib.cc"],
    deps = [":lucas"],
)
