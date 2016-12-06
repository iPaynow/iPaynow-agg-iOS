# iPaynow-iOS\_SDK:聚合支付
## 版本要求
iOS SDK要求iOS6.0及以上
## 接入方法
### 自动接入(CocoaPod方式)
####1.添加Podfile文件
```
pod ‘ipaynowplugin’,'~> 2.0.1'
```
默认支持QQ钱包、微信H5渠道，也可以根据自己的需求选择渠道：

`Alipay`           --支付宝

`ApplePay`         --Applepay

`BaiduWallet`      --百度钱包

`Unionpay`         --银联

`Weixin`           --微信SDK

接入方式如下：

```
pod 'ipaynowplugin/Alipay’,’~> 2.0.1’
pod 'ipaynowplugin/Weixin’,’~> 2.0.1’
pod 'ipaynowplugin/Unionpay’,’~> 2.0.1’
pod 'ipaynowplugin/BaiduWallet’,’~> 2.0.1’
pod 'ipaynowplugin/ApplePay’,’~> 2.0.1’
```

**注意：若商户支付宝使用的是独立商户号模式(直接使用商户从支付宝处申请的APP
ID和密钥),无法使用聚合支付2.X版本，请接入1.7.4版本。**

####2.运行 `pod install`
####3.使用 `.xcworkspace`打开工程
####4.设置URL Scheme
在`Xcode`-`TAEGETS`-`Info`-`URL Types`中添加`URL Schemes`,建议起名复杂一些，避免与其它程序重复。
####5.注意事项
1.) 使用微信SDK支付时，应该填写所注册的微信应用程序ID。

2.) 使用百度钱包支付渠道时，需要额外在工程中将`Xcode`-`TARGETS`-`Build Settings`-`Build Options`-`Enable Bitcode`选项设置为`NO`.


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
本文档仅供参考，更详细的接入说明请参考`Documents`中的文档。




























