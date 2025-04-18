#import <Mapbox.h>
#import <XCTest/XCTest.h>
#import "MLNNetworkConfiguration_Private.h"

@interface MLNNetworkConfigurationTests : XCTestCase
@end

@implementation MLNNetworkConfigurationTests

// Regression test for https://github.com/mapbox/mapbox-gl-native/issues/14982
- (void)testAccessingEventsFromMultipleThreads {
    MLNNetworkConfiguration *configuration = [[MLNNetworkConfiguration alloc] init];

    // Concurrent
    dispatch_queue_t queue = dispatch_queue_create("org.maplibre.testAccessingEventsFromMultipleThreads", DISPATCH_QUEUE_CONCURRENT);

    NSUInteger numberOfConcurrentBlocks = 20;

    XCTestExpectation *expectation = [self expectationWithDescription:@"wait-for-threads"];
    expectation.expectedFulfillmentCount = numberOfConcurrentBlocks;

    for (NSUInteger i = 0; i < numberOfConcurrentBlocks; i++) {

        NSString *event = [NSString stringWithFormat:@"test://event-%ld", i];
        NSString *resourceType = @"test";

        dispatch_async(queue, ^{
            [configuration startDownloadEvent:event type:resourceType];

            NSURL *url = [NSURL URLWithString:event];
            NSURLResponse *response = [[NSURLResponse alloc] initWithURL:url MIMEType:nil expectedContentLength:0 textEncodingName:nil];

            [configuration stopDownloadEventForResponse:response];

            dispatch_async(dispatch_get_main_queue(), ^{
                [expectation fulfill];
            });
        });
    }

    [self waitForExpectations:@[expectation] timeout:10.0];
}
@end
