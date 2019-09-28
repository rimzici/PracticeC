//
//  ViewController.swift
//  PracticeC
//
//  Created by Rimnesh Fernandez on 24/08/19.
//  Copyright © 2019 Rimnesh Fernandez. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        print("Hello \(factorial(5))!")
        print("Is 5 even number ? \(isEven(5))!")
        print("Is 10 even number ? \(isEven(10))!")
        testLoopPostInc(3)
        testLoopPreInc(3)
        testMacros(10)
        
        func callbackFunctionSwift() {
            print("inside callbackFunctionSwift");
        }
        triggerCallback(callbackFunctionSwift);
        let n = "/rimz.db";
        let documentsPath = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)[0];
        let d = strdup(documentsPath+n);
        var arr = [d];
        arr.withUnsafeMutableBytes { (p) -> () in
            let pp = p.baseAddress?.assumingMemoryBound(to: UnsafeMutablePointer<Int8>?.self)
            insertStudentRecord(d);
        }
        
    }
}

