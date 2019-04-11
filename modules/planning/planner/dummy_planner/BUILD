load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "dummy_planner",
    srcs = [
        "dummy_planner.cc",
    ],
    hdrs = [
        "dummy_planner.h",
    ],
    copts = ["-DMODULE_NAME=\\\"planning\\\""],
    deps = [
        "//cyber/common:log",
        "//external:gflags",
        "//modules/common/proto:pnc_point_proto",
        "//modules/common/util",
        "//modules/common/util:factory",
        "//modules/common/vehicle_state:vehicle_state_provider",
        "//modules/planning/common:planning_common",
        "//modules/planning/math/curve1d:quartic_polynomial_curve1d",
        "//modules/planning/planner",
        "//modules/planning/proto:planning_config_proto",
        "//modules/planning/proto:planning_proto",
        "@eigen",
    ],
)

cc_test(
    name = "dummy_planner_test",
    size = "small",
    srcs = [
        "dummy_planner_test.cc",
    ],
    deps = [
        ":dummy_planner",
        "@gtest//:main",
    ],
)

cpplint()
