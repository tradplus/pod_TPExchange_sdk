TradPlus TPExchange pod仓库

## Swift Package Manager

从 13.8.70 开始支持 Swift Package Manager：

```swift
.package(url: "https://github.com/tradplus/pod_TPExchange_sdk.git", exact: "13.8.70")
```

集成时如遇到 Objective-C category 未加载，请在主工程的 `Other Linker Flags` 中添加 `-ObjC`。
