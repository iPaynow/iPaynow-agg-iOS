# iPaynow-iOS\_SDK:聚合支付
## 版本要求
iOS SDK要求iOS7.0及以上
## 接入方法
### 自动接入(CocoaPod方式)
#### 1.添加Podfile文件
```
pod ‘ipaynowplugin’,'~> 3.0.3'
```
默认支持微信H5渠道，其它渠道根据自己的需求再接入渠道SDK：

`Alipay`           --支付宝

`Unionpay`         --银联

`Weixin`           --微信SDK

渠道SDK接入方式如下：

```
pod 'ipaynowplugin/Alipay’,’~> 3.0.3’
pod 'ipaynowplugin/Weixin’,’~> 3.0.3’
pod 'ipaynowplugin/Unionpay’,’~> 3.0.3’
```

**注意：若商户支付宝使用的是独立商户号模式(直接使用商户从支付宝处申请的APP
ID和密钥),无法使用聚合支付2.X版本，请接入1.7.4版本。**

#### 2.运行 `pod install`
#### 3.使用 `.xcworkspace`打开工程
#### 4.设置URL Scheme
在`Xcode`-`TAEGETS`-`Info`-`URL Types`中添加`URL Schemes`,建议起名复杂一些，避免与其它程序重复。
#### 5.注意事项
1.) 使用微信SDK支付时，应该填写所注册的微信应用程序ID。



### 手动接入
#### 1.获取SDK 
下载SDK，将获取到的SDK拖入project中。
#### 2.添加所依赖的库文件(必选)：
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
#### 3.添加基础插件包(必选):
```
libIPayNowPlugin.a
IpaynowPluginApi.h
IpaynowPluginDelegate.h
IPNDESUtil.h

```
#### 4.添加可选包(可选):
##### 1.支付宝

添加支付宝插件包(开通支付宝渠道可选):

```
AlipaySDK.bundle
AlipaySDK.framework
```
##### 2.微信

添加微信插件包(开通微信渠道可选):

```
libWeChatSDK.a
WXApi.h
WXApiObject.h
```
##### 3.银联

添加银联插件包（开通银联渠道可选):

```
libPaymentControl.a
UPPaymentControl.h
```


添加三方库文件时，需要根据当前`ARC`项目对非`ARC`的第三方文件设置特定标志，在`Build Phases`对这些文件添加`-fno-objc-arc`。


##### 工程配置
添加URL Schemes:在Xcode中，选中你的工程设置项，选中"TARGETS"一栏，在 "Info" 标签栏的 "URL Types" 添加 "URL Schemes"，建议起名时尽量复杂些避免与其它应用重复。若使用微信，请添加从微信注册的应用程序ID。

### 额外配置
详见文档

### 说明
本文档仅供参考，更详细的接入说明请参考`Documents`中的文档。




























