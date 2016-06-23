# iPaynow-iOS\_SDK
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
1.支付宝

添加支付宝插件包(开通支付宝渠道可选):

```
AlipaySDK.bundle
AlipaySDK.framework
```
2.微信

添加微信插件包(开通微信渠道可选):

```
libWeChatSDK.a
WXApi.h
WXApiObject.h
```
3.银联

添加银联插件包（开通银联渠道可选):

```
libPaymentControl.a
UPPaymentControl.h
```

4.百度插件包及其依赖三方库(开通百度钱包渠道可选):

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
```































