#import "InternFCSBridge.h"
#include "internship_manager.h"
#include "data_loader.h"
#include "user.h"

@implementation InternshipModel @end

@interface InternFCSBridge () {
    InternshipManager *manager;
    User *currentUser;
}
@end

@implementation InternFCSBridge
- (instancetype)init {
    if (self = [super init]) {
        manager = new InternshipManager();
        currentUser = new User("student_fcs_1");
    }
    return self;
}

- (void)loadData {
    NSString *path = [[NSBundle mainBundle] pathForResource:@"internships" ofType:@"txt"];
    if (path) {
        std::string cppPath = [path UTF8String];
        auto actualData = DataLoader::fetchActualInternships(cppPath);
        for (const auto& i : actualData) {
            manager->addInternship(i);
        }
    }
}

- (NSArray<InternshipModel *> *)getInternshipsByTag:(NSString *)tag {
    std::vector<Internship> filtered;
    if ([tag isEqualToString:@"Все"]) {
        filtered = manager->getAllActive();
    } else {
        filtered = manager->filterByTag([tag.lowercaseString UTF8String]);
    }

    NSMutableArray *result = [NSMutableArray array];
    for (const auto& i : filtered) {
        InternshipModel *m = [InternshipModel new];
        m.id = @(i.id.c_str());
        m.title = @(i.title.c_str());
        m.company = @(i.company.c_str());
        m.desc = @(i.description.c_str());
        m.url = @(i.url.c_str());
        m.deadline = @(i.deadline.c_str());
        m.isFavorite = currentUser->isFavorite(i.id);
        [result addObject:m];
    }
    return result;
}

- (void)toggleFavorite:(NSString *)internshipId {
    std::string c_id = [internshipId UTF8String];
    
    if (currentUser->isFavorite(c_id)) {
        currentUser->removeFavorite(c_id);
    } else {
        currentUser->addFavorite(c_id);
    }
}
@end
