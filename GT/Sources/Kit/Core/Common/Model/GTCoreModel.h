//
//  GTCoreModel.h
//  GTKit
//
//  Created   on 13-7-30.
// Tencent is pleased to support the open source community by making
// Tencent GT (Version 2.4 and subsequent versions) available.
//
// Notwithstanding anything to the contrary herein, any previous version
// of Tencent GT shall not be subject to the license hereunder.
// All right, title, and interest, including all intellectual property rights,
// in and to the previous version of Tencent GT (including any and all copies thereof)
// shall be owned and retained by Tencent and subject to the license under the
// Tencent GT End User License Agreement (http://gt.qq.com/wp-content/EULA_EN.html).
//
// Copyright (C) 2015 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the MIT License (the "License"); you may not use this file
// except in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//
//
#ifndef GT_DEBUG_DISABLE

#import <Foundation/Foundation.h>
#import "GTDebugDef.h"

@interface GTMonitorObj : NSObject
{
    Class           _aClass;
    BOOL            _on;            //是否打开监控
    NSTimeInterval  _interval;      //监控间隔
    NSTimeInterval  _lastMonitor;
    
//    BOOL            _autoSaveOn;         // 是否自动保存csv
//    NSTimeInterval  _autoSaveInterval;   // 自动保存csv文件间隔
//    NSTimeInterval  _lastAutoSave;
}

@property (nonatomic, assign) Class aClass;
@property (nonatomic, assign) BOOL on;
@property (nonatomic, assign) NSTimeInterval interval;
@property (nonatomic, assign) NSTimeInterval lastMonitor;

@property (nonatomic, assign) BOOL autoSaveOn;
@property (nonatomic, assign) NSTimeInterval autoSaveInterval;
@property (nonatomic, assign) NSTimeInterval lastAutoSave;

@end

@interface GTCoreModel : NSObject
{
    NSMutableDictionary *_monitorDict;
    NSThread            *_monitorThread;
}

M_GT_AS_SINGLETION( GTCoreModel );

- (void)enableMonitor:(Class )aClass withInterval:(NSTimeInterval)interval;
- (void)disableMonitor:(Class )aClass;

- (void)handleTick;

@end

#endif

