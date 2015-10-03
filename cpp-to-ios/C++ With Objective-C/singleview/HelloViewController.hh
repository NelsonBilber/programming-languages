

#import <UIKit/UIKit.h>
#import "HelloCpp.hpp"



@interface HelloViewController : UIViewController{
    IBOutlet UILabel *label;
    
    //c++11
    std::shared_ptr<HelloCpp> cppClass_;
    
    //HelloCpp* cppClass_;
}

-(IBAction)button:(id)sender;

@end
