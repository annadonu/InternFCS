#import <Foundation/Foundation.h>

@interface InternshipModel : NSObject
@property (nonatomic, copy) NSString *id;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *company;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *deadline; 
@property (nonatomic, assign) BOOL isFavorite;
@end

@interface InternFCSBridge : NSObject
- (void)loadData;
- (NSArray<InternshipModel *> *)getInternshipsByTag:(NSString *)tag;
- (void)toggleFavorite:(NSString *)internshipId;
@end
