//
//  YCDownloadItem.h
//  YCDownloadSession
//
//  Created by wangzhen on 17/7/28.
//  Copyright © 2017年 onezen.cc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YCDownloadTask.h"
@class YCDownloadItem;

typedef enum : NSUInteger {
    YCDownloadStatusWaiting,
    YCDownloadStatusDownloading,
    YCDownloadStatusPaused,
    YCDownloadStatusFinished,
    YCDownloadStatusFailed
} YCDownloadStatus;

@protocol YCDownloadItemDelegate <NSObject>

@optional
- (void)downloadItemStatusChanged:(YCDownloadItem *)item;
- (void)downloadItem:(YCDownloadItem *)item downloadedSize:(NSInteger)downloadedSize totalSize:(NSInteger)totalSize;

@end

@interface YCDownloadItem : NSObject<YCDownloadSessionDelegate>

@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, copy) NSString *thumbImageUrl;
@property (nonatomic, copy) NSString *downloadUrl;
@property (nonatomic, assign) NSUInteger fileSize;
@property (nonatomic, assign) NSUInteger *downloadedSize;
@property (nonatomic, assign) YCDownloadStatus downloadStatus;
@property (nonatomic, copy, readonly) NSString *saveName;
@property (nonatomic, weak) id <YCDownloadItemDelegate> delegate;

- (NSString *)savePath;

@end

