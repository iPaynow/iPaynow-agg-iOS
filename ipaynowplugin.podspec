Pod::Spec.new do |s|

  
  s.name         = "ipaynowplugin"
  s.version      = "3.0.0"
  s.summary      = "ipaynowplugin SDK"
  s.description  = <<-DESC
                   Help developer to quickly intergrate variety of payment methods
                   DESC
  s.homepage     = "http://www.ipaynow.cn"
  s.license      = "MIT"
  s.author       = { "Chuck" => "lipengchang@ipaynow.cn" }
  s.platform     = :ios, '6.0'
  s.source       = { :git => "https://github.com/iPaynow/iPaynow-agg-iOS.git", :tag => s.version }
  s.default_subspec = 'Core'
  s.requires_arc = true
  
  s.subspec 'Core' do |core|
    core.source_files = "lib/*.h"
    core.public_header_files = "lib/*.h"
    core.vendored_libraries = "lib/iphone+simulator/*.a"
    core.frameworks = "CoreGraphics", "CoreTelephony","QuartzCore","SystemConfiguration","Security","Foundation","UIKit"
    core.ios.library = 'z', 'sqlite3.0','c++', 'stdc++'
    core.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  end

  s.subspec 'Alipay' do |ali|
    ali.vendored_frameworks = 'lib/Channels/AliPayPlugin/AlipaySDK.framework'
    ali.resource = 'lib/Channels/AliPayPlugin/AlipaySDK.bundle'
    ali.frameworks = 'CoreMotion'
    ali.dependency 'ipaynowplugin/Core'
  end
 
  s.subspec 'Weixin' do |wx|
    wx.ios.vendored_libraries = 'lib/Channels/WechatPlugin/*.a'
    wx.source_files = 'lib/Channels/WechatPlugin/*.h'
    wx.public_header_files = 'lib/Channels/WechatPlugin/*.h'
    wx.dependency 'ipaynowplugin/Core'
  end
  
  s.subspec 'Unionpay' do |up|
    up.vendored_libraries = 'lib/Channels/UPPayPlugin/*.a'
    up.source_files = 'lib/Channels/UPPayPlugin/*.h'
    up.dependency 'ipaynowplugin/Core'
  end
  
 

end
