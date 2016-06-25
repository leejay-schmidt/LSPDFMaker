//
//  LSPDFMaker.h
//  LSPDFMaker
//
//  Created by Leejay Schmidt on 2016-06-25.
//  Copyright © 2016 Leejay Schmidt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//! Project version number for LSPDFMaker.
FOUNDATION_EXPORT double LSPDFMakerVersionNumber;

//! Project version string for LSPDFMaker.
FOUNDATION_EXPORT const unsigned char LSPDFMakerVersionString[];

@interface LSPDFMaker : NSObject

@property (nonatomic) CGSize pagesize;

-(NSString *)startPDF:(NSString *)pdfName withWidth:(CGFloat)width withHeight:(CGFloat)height;
-(void)beginNewPage;
-(void)completePDF;
-(CGRect)addText:(NSString*)text withFrame:(CGRect)frame fontSize:(float)fontSize;
-(CGRect)addImage:(UIImage*)image atPoint:(CGPoint)point;
-(void)startPDFToData:(NSMutableData *)data withWidth:(CGFloat)width withHeight:(CGFloat)height;
@end

