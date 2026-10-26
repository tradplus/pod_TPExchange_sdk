// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "TPExchange",
    platforms: [
        .iOS(.v12),
    ],
    products: [
        .library(
            name: "TPExchange",
            targets: ["TPExchange", "TPExchangeResources"]
        ),
    ],
    targets: [
        // Wrapper target: mirrors the CocoaPods podspec settings and attaches resources.
        .target(
            name: "TPExchangeResources",
            dependencies: [],
            path: ".",
            sources: ["Sources/TPExchangeResources/TPExchangeResources.swift"],
            resources: [
                .copy("TPExchange/TradPlusADX.bundle"),
            ],
            linkerSettings: [
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("CoreGraphics"),
                .linkedFramework("Foundation"),
                .linkedFramework("UIKit"),

                // SwiftPM does not allow unsafe linker flags for versioned dependencies.
                // Integrators should add -ObjC to Other Linker Flags when required.
                // .unsafeFlags(["-ObjC"])
            ]
        ),
        .binaryTarget(
            name: "TPExchange",
            url: "https://github.com/tradplus/pod_TPExchange_sdk/releases/download/13.8.80/TPExchange-13.8.80.xcframework.zip",
            checksum: "e06fb6739632acea5adbdd7df3f7428042f2f2e84b113f62f72f25c1e01ba9da"
        ),
    ]
)
