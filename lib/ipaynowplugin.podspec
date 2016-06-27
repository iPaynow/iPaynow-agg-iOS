Pod::Spec.new do |s|

  
  s.name         = "ipaynowplugin"
  s.version      = "1.7.2"
  s.summary      = "ipaynowplugin SDK"

  
  s.description  = <<-DESC
                   Help developer to quickly intergrate variety of payment methods
                   DESC

  s.homepage     = "http://www.ipaynow.cn"
  

  s.source_files = "*"

  s.license      = "MIT"
  

  s.author       = { "Hstripe" => "huangrui@ipaynow.cn" }
  
  s.platform     = :ios, "6.0"
  

  s.source       = { :git => "https://github.com/iPaynow/iPaynow-agg-iOS.git", :tag => "#1.7.2" }


  s.frameworks = "CoreGraphics", "CoreTelephony","QuartzCore","SystemConfiguration","Security","Foundation","UIKit"

  
  s.libraries = "z", "sqlite3.0"


end
