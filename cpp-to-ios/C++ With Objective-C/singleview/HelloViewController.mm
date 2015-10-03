//
//  HelloViewController.m
//  singleview
//
//  Created by Nelson Rodrigues on 21/09/15.
//  Copyright © 2015 Nelson Rodrigues. All rights reserved.
//

#import "HelloViewController.hh"

@interface HelloViewController ()

@end

@implementation HelloViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    label.text = [NSString stringWithFormat:@"Init string"];
    
    //C++11
    cppClass_ = shared_ptr<HelloCpp>(new HelloCpp());
    //cppClass_ = new HelloCpp();
}

-(void)viewDidUnload{
   // if(cppClass_ != nullptr )
       // delete cppClass_;
    NSLog(@"viewDidUnload");
}

-(void)viewWillDisappear:(BOOL)animated
{
    //if(cppClass_ != nullptr)
    //    delete cppClass_;
    
    //C++11
    cppClass_.reset();
    NSLog(@"viewWillDisappear");
}

-(void)viewDidDisappear:(BOOL)animated{
   // if(cppClass_ != nullptr)
      //  delete cppClass_;
    NSLog(@"viewDidDisappear");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)button:(id)sender{
    
    NSString* result = [NSString stringWithUTF8String:cppClass_->getStringName().c_str()];
    cppClass_->print();
    label.text = result;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
