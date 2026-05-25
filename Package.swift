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
            url: "https://github.com/tradplus/pod_TPExchange_sdk/releases/download/13.8.70/TPExchange-13.8.70.xcframework.zip",
            checksum: "862dab308cbff8fd494c7d31c52c44f23d16ccd1ac8e776bf80a19a24f5f9d00"
        ),
    ]
)
