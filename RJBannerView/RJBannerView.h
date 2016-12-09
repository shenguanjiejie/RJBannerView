//
//  RJBannerView.h
//  duDu
//
//  Created by RuiJie on 16/10/11.
//  Copyright © 2016年 youd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RJItemInfo.h"
#import "RJBannerCollectionCell.h"


@protocol RJBannerViewDelegate;
@protocol RJBannerViewDataSource;

@interface RJBannerView : UIView

/**
 default 0
 */
@property (nonatomic, assign) CGFloat minimumLineSpacing;

/**
 default 0
 */
@property (nonatomic, assign) CGFloat minimumInteritemSpacing;

/**
 default YES
 */
@property (nonatomic, assign, getter=isAutoScroll) BOOL autoScroll;

/**
 *  是否分页
 */
@property (nonatomic, assign) BOOL pageingEnabled;

/**
  自动滚动翻页间隔 默认3s
 */
@property (nonatomic, assign) CGFloat timeInterval;

@property (nonatomic, assign) CGSize itemSize;

@property (nonatomic, assign) CGAffineTransform centerCellTransform;

@property (nonatomic, readonly, strong) UICollectionView *collectionView;

@property (nonatomic,weak) id<RJBannerViewDelegate> delegate;

@property (nonatomic,weak) id<RJBannerViewDataSource> dataSource;

@property (nonatomic, strong) UIPageControl *pageControl;

@property (nonatomic, assign) Class customCellClass;

- (void)reloadData;

@end

@protocol RJBannerViewDataSource <NSObject>
@required

- (NSInteger)numberOfItemsInRJBannerView:(RJBannerView *)bannerView;

@optional
- (NSInteger)firstDisplayIndexForRJBannerView:(RJBannerView *)bannerView;

- (RJItemInfo *)RJBannerView:(RJBannerView *)bannerView itemInfoForItemAtIndex:(unsigned long)index;

- (void)setDataForCustomCell:(UICollectionViewCell *)Cell atIndex:(unsigned long)index;

@end

@protocol RJBannerViewDelegateFlowLayout <RJBannerViewDelegate>
@optional
- (CGSize)RJBannerView:(RJBannerView *)bannerView sizeForItemAtIndex:(unsigned long)index;

@end

@protocol RJBannerViewDelegate <NSObject>
@optional

- (void)RJBannerView:(RJBannerView *)bannerView didSelectItemAtIndex:(unsigned long)index;

- (void)RJBannerView:(RJBannerView *)bannerView willAutoScrollToIndex:(unsigned long)index;

- (void)RJBannerView:(RJBannerView *)bannerView willDisplayingCell:(UICollectionViewCell *)cell atIndex:(unsigned long)index;

- (void)RJBannerView:(RJBannerView *)bannerView didEndDisplayingCell:(UICollectionViewCell *)cell atIndex:(unsigned long)index;

- (void)RJBannerView:(RJBannerView *)bannerView willScrollToCell:(UICollectionViewCell *)cell atIndex:(unsigned long)index;

- (void)RJBannerView:(RJBannerView *)bannerView willEndScrollToCell:(UICollectionViewCell *)cell atIndex:(unsigned long)index;

@end
