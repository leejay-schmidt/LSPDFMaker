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

/*
 Starts a new pdf with the given pdf name(.pdf)
 @param pdfName The filename (without extension) for the pdf
 @param width The number of pixels in width for the pdf document pages
 @param height The number of pixels in height for the pdf document page
 @returns Full filepath string for the pdf
 */
-(nonnull NSString *)startPDF:(nonnull NSString *)pdfName withWidth:(CGFloat)width withHeight:(CGFloat)height;
/*
 Adds a new page to the pdf document (and completes the previous page if applicable)
 */
-(void)beginNewPage;
/*
 Completes the writing of the pdf document, saves, and closes the file/data
 */
-(void)completePDF;
/*
 Adds a text string within a frame that is given
 @param text The desired string to add
 @param frame The frame to bound the text within
 @param fontSize The desired font size for the text constrained by the frame
 @returns Frame that constrains the text
 */
-(CGRect)addText:(nonnull NSString*)text withFrame:(CGRect)frame fontSize:(float)fontSize;
/*
 Adds an image to to the pdf with the top left corner starting at the given point
 @param image The image file to add to the pdf
 @param point The point (x,y) for the top left corner of the image
 @returns Frame of the image on the pdf
 */
-(CGRect)addImage:(nonnull UIImage*)image atPoint:(CGPoint)point;
/*
 Starts a new pdf with the given mutable data
 @param data The mutable data to write the pdf to
 @param width The number of pixels in width for the pdf document pages
 @param height The number of pixels in height for the pdf document page
 */
-(void)startPDFToData:(nonnull NSMutableData *)data withWidth:(CGFloat)width withHeight:(CGFloat)height;
@end

