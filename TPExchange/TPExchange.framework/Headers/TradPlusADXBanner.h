//
//  TradPlusADXBanner.h
//  fluteSDKSample
//
//  Created by xuejun on 2021/11/9.
//  Copyright © 2021 TradPlus. All rights reserved.
//

#import <TPExchange/TradPlusADXBase.h>


NS_ASSUME_NONNULL_BEGIN

@protocol TPADXBannerDelegate;

@interface TradPlusADXBanner : TradPlusADXBase

- (BOOL)isReady;

- (void)loadWithPayload:(NSDictionary *)payload finishBiddingDate:(NSDate *)finishBiddingDate;

- (void)willAddSubView;

@property (nonatomic,weak) id <TPADXBannerDelegate> delegate;
@property (nonatomic,assign) CGSize adSize;
@property (nonatomic,assign) BOOL isClosable;

@property (nonatomic,readonly)NSDictionary *bidcn;
@end

@protocol TPADXBannerDelegate <NSObject>

- (void)ADXLoadFinish:(UIView *)bannerView;
- (void)ADXLoadFailWithError:(NSError *)error;
- (void)ADXImpression;
- (void)ADXShowFailWithError:(NSError *)error;
- (void)ADXClicked;
- (void)ADXClosed;
@end

NS_ASSUME_NONNULL_END
