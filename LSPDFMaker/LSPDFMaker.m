//
//  PDFer.m
//  TravelExpenses
//
//  Created by Leejay Schmidt on 2015-08-31.
//  Copyright (c) 2015 Leejay Schmidt. All rights reserved.
//

#import "LSPDFMaker.h"

@implementation LSPDFMaker

- (NSString *)startPDF:(NSString *)pdfName withWidth:(CGFloat)width withHeight:(CGFloat)height {
    _pagesize = CGSizeMake(width, height);
    NSString *name = [NSString stringWithFormat:@"%@.pdf", pdfName];
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    
    NSString *path = [documentsDirectory stringByAppendingPathComponent:name];
    UIGraphicsBeginPDFContextToFile(path, CGRectZero, nil);
    return path;
}

- (void)startPDFToData:(NSMutableData *)data withWidth:(CGFloat)width withHeight:(CGFloat)height {
    _pagesize = CGSizeMake(width, height);
    
    UIGraphicsBeginPDFContextToData(data, CGRectZero, nil);
}

- (void)beginNewPage {
    UIGraphicsBeginPDFPageWithInfo(CGRectMake(0, 0, _pagesize.width, _pagesize.height), nil);
}

- (void)completePDF {
    UIGraphicsEndPDFContext();
}

- (CGRect)addText:(NSString*)text withFrame:(CGRect)frame fontSize:(float)fontSize {
    UIFont *font = [UIFont systemFontOfSize:fontSize];
    NSMutableParagraphStyle *paragStyle = [[NSMutableParagraphStyle alloc] init];
    paragStyle.lineBreakMode = NSLineBreakByWordWrapping;
    paragStyle.alignment = NSTextAlignmentLeft;
    NSDictionary *attributes = @{ NSFontAttributeName : font,
                                  NSParagraphStyleAttributeName : paragStyle};
    CGSize stringSize = [text sizeWithAttributes:attributes];
    
    float textWidth = frame.size.width;
    
    if (textWidth < stringSize.width)
        textWidth = stringSize.width;
    if (textWidth > _pagesize.width)
        textWidth = _pagesize.width - frame.origin.x;
    
    CGRect rect = CGRectMake(frame.origin.x, frame.origin.y, textWidth, stringSize.height);
    
    [text drawInRect:rect withAttributes:attributes];
    
    frame = CGRectMake(frame.origin.x, frame.origin.y, textWidth, stringSize.height);
    return frame;
}

- (CGRect)addImage:(UIImage*)image atPoint:(CGPoint)point {
    CGRect frame = CGRectMake(point.x, point.y, image.size.width, image.size.height);
    [image drawInRect:frame];
    return frame;
}

@end
