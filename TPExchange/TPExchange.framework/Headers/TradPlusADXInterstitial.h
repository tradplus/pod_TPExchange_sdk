//
//  TradPlusADXInterstitial.h
//  fluteSDKSample
//
//  Created by xuejun on 2021/10/15.
//  Copyright © 2021 TradPlus. All rights reserved.
//

#import <TPExchange/TradPlusADXBase.h>


NS_ASSUME_NONNULL_BEGIN

@protocol TPADXInterstitialDelegate;

@interface TradPlusADXInterstitial : TradPlusADXBase

- (void)loadWithPayload:(NSDictionary *)payload finishBiddingDate:(NSDate *)finishBiddingDate;

- (void)showAdFromRootViewController:(UIViewController *)rootViewController;
@property (nonatomic,assign) BOOL isMute;
@property (nonatomic,assign) NSInteger skipTime;
@property (nonatomic,weak) id <TPADXInterstitialDelegate> delegate;
- (BOOL)isReady;

@property (nonatomic,readonly)NSDictionary *bidcn;
@end

@protocol TPADXInterstitialDelegate <NSObject>

- (void)ADXLoadFinish;
- (void)ADXLoadFailWithError:(NSError *)error;
- (void)ADXImpression;
- (void)ADXShowFailWithError:(NSError *)error;
- (void)ADXClicked;
- (void)ADXDismissed;
@end

NS_ASSUME_NONNULL_END
