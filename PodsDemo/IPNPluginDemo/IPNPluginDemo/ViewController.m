//
//  ViewController.m
//  IPNPluginDemo
//
//  Created by 黄睿 on 2016/7/22.
//  Copyright © 2016年 iPayNow. All rights reserved.
//

#import "ViewController.h"
#import "IPNPreSignMessageUtil.h"
#import "IpaynowPluginApi.h"
#import "IPNDESUtil.h"

#define KBtn_width        200
#define KBtn_height       80
#define KXOffSet          (self.view.frame.size.width - KBtn_width) / 2
#define KYOffSet          80

#define kBtnFirstTitle    @"获取订单，开始支付"
#define kWaiting          @"正在获取订单,请稍候..."
#define kNote             @"提示"
#define kConfirm          @"确定"
#define kErrorNet         @"网络错误"
#define kResult           @"支付结果："

#define kOrderUrl      @"http://192.168.1.154:8080/api/sign"
#define kSignURL       @"http://posp.ipaynow.cn/ZyPluginPaymentTest_PAY/api/pay2.php"
#define kProductIdentifier @"cn.ipaynow.IpayNowMarket.first"

#define kAppId @"1452824560884487"
#define kAppKey @"vkPcMHOm0FhWqgu8SGdDME02gqWTEWgb"
#define kMerchantID @"merchant.cn.ipaynow.applepay"


@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextField *appID;
@property (weak, nonatomic) IBOutlet UITextField *appKey;
@property (weak, nonatomic) IBOutlet UITextField *txtOrderNo;
@property (weak, nonatomic) IBOutlet UITextField *txtAmt;
@property (weak, nonatomic) IBOutlet UITextField *txtOrderDetail;
@property (weak, nonatomic) IBOutlet UITextField *txtOrderStartTime;
@property (weak, nonatomic) IBOutlet UITextField *txtMhtPreserved;

@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;

@end

@implementation ViewController{
    NSString *_presignStr;
    NSString *_orderNo;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.scrollView.contentSize = CGSizeMake(self.scrollView.frame.size.width, self.scrollView.frame.size.height + 20);
    self.scrollView.showsVerticalScrollIndicator = NO;
    [IpaynowPluginApi setMerchantID:kMerchantID];
    
}

-(void)viewWillAppear:(BOOL)animated{
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyyMMddHHmmss"];
    _txtOrderStartTime.text = [dateFormatter stringFromDate:[NSDate date]];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)pay:(id)sender {
    [self payByType:nil];
}

- (IBAction)alixPayClick:(id)sender {
    [self payByType:@"12"];
}

- (IBAction)weixinPayClick:(id)sender {
    [self payByType:@"13"];
}

- (IBAction)unionPayClick:(id)sender {
    [self payByType:@"11"];
}

- (IBAction)ApplePayClick:(id)sender {
    [self payByType:@"61"];
}

- (IBAction)qqWalletClick:(id)sender {
    [self payByType:@"25"];
}

- (IBAction)inAPPPurchaseClick:(id)sender {
    [self payByType:@"60"];
}

-(void)payByType:(NSString *)payChannelType{
    NSInteger amt=[_txtAmt.text integerValue];
    if (_txtAmt.text ==nil || [_txtAmt.text isEqualToString:@""] || amt==0) {
        [self showAlertMessage:@"请输入金额"];
    }
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyyMMddHHmmss"];
    
    IPNPreSignMessageUtil *preSign=[[IPNPreSignMessageUtil alloc]init];
    preSign.appId=_appID.text;
    
    preSign.mhtOrderNo=[dateFormatter stringFromDate:[NSDate date]];
    preSign.mhtOrderName=_txtOrderNo.text;;
    preSign.mhtOrderType=@"01";
    preSign.mhtCurrencyType=@"156";
    preSign.mhtOrderAmt=_txtAmt.text;
    preSign.mhtOrderDetail=_txtOrderDetail.text;
    preSign.mhtOrderStartTime=_txtOrderStartTime.text;
    preSign.notifyUrl=@"http://localhost:10802/";
    preSign.mhtCharset=@"UTF-8";
    preSign.mhtOrderTimeOut=@"3600";
    preSign.mhtReserved=_txtMhtPreserved.text;
    preSign.consumerId=@"IPN00001";
    preSign.consumerName=@"IpaynowCS";
    if (payChannelType!=nil) {
        preSign.payChannelType=payChannelType;
    }
    
    _presignStr=[preSign generatePresignMessage];
    if (_presignStr==nil) {
        [self showAlertMessage:@"缺少必填字段"];
        return;
    }
    _orderNo=preSign.mhtOrderNo;
    [self payByLocalSign];
}

- (void)payByLocalSign{
    NSString *md5=[IPNDESUtil md5Encrypt:_appKey.text];
    md5=[_presignStr stringByAppendingFormat:@"&%@",md5];
    md5=[IPNDESUtil md5Encrypt:md5];
    md5=[NSString stringWithFormat:@"mhtSignType=MD5&mhtSignature=%@",md5];
    NSString *payData = [_presignStr stringByAppendingFormat:@"&%@",md5];
    [IpaynowPluginApi pay:payData AndScheme:@"IpayNowDemo" viewController:self delegate:self];
}

- (void)payByHttpRequest{
    NSString *outputStr = (NSString *)
    CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,
                                                              (CFStringRef)_presignStr,
                                                              NULL,
                                                              (CFStringRef)@"!*'();:@&=+$,/?%#[]",
                                                              kCFStringEncodingUTF8));
    
    NSString *presignStr=@"paydata=";
    presignStr=[presignStr stringByAppendingString:outputStr];
    
    NSURL* url = [NSURL URLWithString:kSignURL];
    NSMutableURLRequest * urlRequest=[NSMutableURLRequest requestWithURL:url];
    [urlRequest setHTTPMethod:@"POST"];
    urlRequest.HTTPBody=[presignStr dataUsingEncoding:NSUTF8StringEncoding];
    NSURLConnection* urlConn = [[NSURLConnection alloc] initWithRequest:urlRequest delegate:self];
    [urlConn start];
    [self showAlertWait];
}

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse*)response {
    NSHTTPURLResponse* rsp = (NSHTTPURLResponse*)response;
    int code = (int)[rsp statusCode];
    if (code != 200) {
    } else {
        if (mData != nil) {
            mData = nil;
        }
        mData = [[NSMutableData alloc] init];
    }
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    [mData appendData:data];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    [self hideAlert];
    NSString* data = [[NSMutableString alloc] initWithData:mData encoding:NSUTF8StringEncoding];
    NSString* payData=[_presignStr stringByAppendingString:@"&"];
    payData=[payData stringByAppendingString:data];
    
    [IpaynowPluginApi pay:payData AndScheme:@"IpayNowDemo" viewController:self delegate:self];
}

-(void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    [self hideAlert];
    [self showAlertMessage:kErrorNet];
}

-(void)IpaynowPluginResult:(IPNPayResult)result errCode:(NSString *)errCode errInfo:(NSString *)errInfo{
    NSString *resultString=nil;
    switch (result) {
        case IPNPayResultSuccess:
            resultString=@"支付成功";
            break;
        case IPNPayResultCancel:
            resultString=@"支付被取消";
            break;
        case IPNPayResultFail:
            resultString=[NSString stringWithFormat:@"支付失败:\r\n错误码:%@,异常信息:%@",errCode, errInfo];
            break;
        case IPNPayResultUnknown:
            resultString=[NSString stringWithFormat:@"支付结果未知:%@",errInfo];
            break;
            
        default:
            break;
    }
    
    UIAlertView* alert = [[UIAlertView alloc] initWithTitle:kNote
                                                    message:resultString
                                                   delegate:nil
                                          cancelButtonTitle:kConfirm
                                          otherButtonTitles:nil];
    [alert show];
}

- (void)showAlertMessage:(NSString*)msg{
    mAlert = [[UIAlertView alloc] initWithTitle:kNote message:msg delegate:nil cancelButtonTitle:kConfirm otherButtonTitles:nil, nil];
    [mAlert show];
}

- (void)showAlertWait {
    mAlert = [[UIAlertView alloc] initWithTitle:kWaiting message:nil delegate:self cancelButtonTitle:nil otherButtonTitles: nil];
    [mAlert show];
    UIActivityIndicatorView* aiv = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
    aiv.center = CGPointMake(mAlert.frame.size.width / 2.0f - 15, mAlert.frame.size.height / 2.0f + 10 );
    [aiv startAnimating];
    [mAlert addSubview:aiv];
}

- (void)hideAlert {
    if (mAlert != nil){
        [mAlert dismissWithClickedButtonIndex:0 animated:YES];
        mAlert = nil;
    }
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [self.view endEditing:true];
}

@end
