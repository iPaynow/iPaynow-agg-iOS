# iPaynow-iOS\_SDK:聚合支付
## 版本要求
iOS SDK要求iOS6.0及以上
## 接入方法
### 手动接入
####1.获取SDK 
下载SDK，将获取到的SDK拖入project中。
####2.添加所依赖的库文件(必选)：
```
libz.dylib
libsqlite3.0.dylib
CoreGraphics.framework
CoreTelephony.framework
QuartzCore.framework
SystemConfiguration.framework
Security.framework
Foundation.framework
UIKit.framework
```
####3.添加基础插件包(必选):
```
ipaynow.bundle
libIPayNowPlugin.a
IpaynowPluginApi.h
IpaynowPluginDelegate.h
IPNPreSignMessageUtil.h
IPNDESUtil.h

```
####4.添加可选包(可选):
#####1.支付宝

添加支付宝插件包(开通支付宝渠道可选):

```
AlipaySDK.bundle
AlipaySDK.framework
```
#####2.微信

添加微信插件包(开通微信渠道可选):

```
libWeChatSDK.a
WXApi.h
WXApiObject.h
```
#####3.银联

添加银联插件包（开通银联渠道可选):

```
libPaymentControl.a
UPPaymentControl.h
```

#####4.百度钱包

添加百度钱包插件包及其依赖三方库(开通百度钱包渠道可选):

```
BaiduWalletSDKBundl.bundle
BDwalletSDKMainManager.h
libBaiduWalletSDK.a
```
百度钱包所依赖的第三方库统一在`Library`文件夹中，需要添加的库有：

```
ASIHttpRequest
JSONKit
TouchJSON
Reachability
SDWebImage
```
添加三方库文件时，需要根据当前`ARC`项目对非`ARC`的第三方文件设置特定标志，在`Build Phases`对这些文件添加`-fno-objc-arc`。

#####5.Apple Pay
接入Apple Pay需要配置几处:

1、升级Xcode版本到7.2或者以上，iOS SDK版本为9.2及以上；

2、iPhone要求iPhone 6/6+,系统版本是iOS9.2及以上；

3、申请苹果商户ID(Merchant IDs)

4、App ID增加Apple Pay Service;

5、添加依赖包到App的工程中:

```
libUPAPayPlugin.a
UPAPayPlugin.h
UPAPayPluginDelegate.h
```
7、在代码里设置MerchantIDs。(详情参见Documents中的文档)

#####工程配置
添加URL Schemes:在Xcode中，选中你的工程设置项，选中"TARGETS"一栏，在 "Info" 标签栏的 "URL Types" 添加 "URL Schemes"，建议起名时尽量复杂些避免与其它应用重复。若使用微信，请添加从微信注册的应用程序ID。

### 额外配置
iOS9限制了Http请求，需要在`info.plist`中添加如下代码:
```
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

### 说明
此文档仅供参考，更详细的接入说明请参考`Documents`中的文档。




























