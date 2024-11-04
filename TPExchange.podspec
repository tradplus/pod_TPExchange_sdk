Pod::Spec.new do |spec|
  spec.name         = "TPExchange"
  spec.version      = "12.2.10"
  spec.summary      = "TradPlus TPExchange for iOS."
  spec.description  = <<-DESC
            TradPlusSDK TPExchange for iOS. 
                   DESC
  spec.homepage     = "https://github.com/tradplus/pod_TPExchange_sdk"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author             = { "tradplus" => "appleid_ios@tradplus.com" }
  spec.source       = { :git => "https://github.com/tradplus/pod_TPExchange_sdk.git", :tag => spec.version }
  spec.platform     = :ios, '9.0'
  spec.ios.deployment_target = '9.0'
  spec.requires_arc = true
  spec.frameworks = 'SystemConfiguration', 'CoreGraphics','Foundation','UIKit'
  spec.user_target_xcconfig =   {'OTHER_LDFLAGS' => ['-lObjC']}
  spec.vendored_frameworks = 'TPExchange/TPExchange.framework'
  spec.resource = 'TPExchange/TradPlusADX.bundle'
end
