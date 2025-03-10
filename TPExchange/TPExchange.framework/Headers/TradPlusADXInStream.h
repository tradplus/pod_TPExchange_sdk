//
//  TradPlusADXInStream.h
//  TradPlusAds
//
//  Created by xuejun on 2023/8/16.
//  Copyright © 2023 TradPlus. All rights reserved.
//

#import <TPExchange/TradPlusADXBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TradPlusADXInStreamDelegate;

@interface TradPlusADXInStream : TradPlusADXBase

@property(nonatomic, readonly) NSTimeInterval duration;

- (BOOL)isReady;

- (void)loadWithPayload:(NSDictionary *)payload finishBiddingDate:(NSDate *)finishBiddingDate mute:(BOOL)mute;

@property (nonatomic,weak) id <TradPlusADXInStreamDelegate> delegate;
@property (nonatomic,assign)BOOL useVideoStreaming;
@property (nonatomic,assign)NSTimeInterval loadVideoTimeout;

- (void)startWithAdView:(nullable UIView *)adView customView:(UIView *)customView;
- (void)pauseAct;
- (void)skipAct;
- (void)resumeAct;
- (void)destoryAct;

@end

@protocol TradPlusADXInStreamDelegate <NSObject>

- (void)ADXLoadFinish;
- (void)ADXLoadFailWithError:(NSError *)error;
- (void)ADXShowFailWithError:(NSError *)error;
- (void)ADXClicked;
- (void)ADXSkiped;
- (void)ADXPause;
- (void)ADXResume;
- (void)ADXTapped;
- (void)ADXStart;
- (void)ADXComplete;
- (void)ADXImpression;
- (void)ADXInStreamCurrentTime:(NSTimeInterval)currentTime duration:(NSTimeInterval)duration;
- (void)ADXInStreamStartBuffering;
- (void)ADXInStreamPlaybackReady;
- (void)ADXInStreamDidBufferToMediaTime:(NSTimeInterval)mediaTime;
@end

NS_ASSUME_NONNULL_END
